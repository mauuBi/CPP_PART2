/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:03:47 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/23 12:41:43 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Vector

void	ProcessAlgoVector(char **argv)
{
	std::vector<int> vec;
	for (size_t i = 1; argv[i]; i++)
	{
		std::string input = argv[i];
		ParseInput(input, vec);
	}
	AlgoVector(vec);
}

void	ParseInput(std::string &input, std::vector<int> &vec)
{
	std::istringstream iss(input);
	std::string word;
	while (iss >> word)
	{
		checkInt(word);
		if (std::atoi(word.c_str()) < 0)
			throw std::runtime_error("This argument is not a positive digit : ");
		vec.push_back(std::atoi(word.c_str()));
	}
}

void	checkInt(const std::string &intToCheck)
{
	for (size_t i = 0; i < intToCheck.size(); i++)
	{
		if ((!isdigit(intToCheck[i])))
			throw(std::runtime_error("One of the argument contain an invalid token"));
	}
}

void	splittingBigSmall(std::vector<int> &vec, std::vector<int> &vecBig,
		std::vector<int> &vecSmall)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (vec.size() % 2 != 0) ? (vec.size() - 1) : vec.size();
	while (i < len)
	{
		if (vec[i] > vec[i + 1])
		{
			vecBig.push_back(vec[i]);
			vecSmall.push_back(vec[i + 1]);
			i += 2;
			continue ;
		}
		else if (vec[i] < vec[i + 1])
		{
			vecBig.push_back(vec[i + 1]);
			vecSmall.push_back(vec[i]);
			i += 2;
			continue ;
		}
		else
		{
			vecBig.push_back(vec[i + 1]);
			vecSmall.push_back(vec[i]);
		}
		i += 2;
	}
	if (vec.size() % 2 != 0)
		vecBig.push_back(vec[i]);
	mergeSortRecursive(vecBig);
	insertionFordJohnsonVec(vecBig, vecSmall);
}

std::vector<size_t> listJacobsthal(std::vector<int> &vecSmall)
{
	std::vector<size_t> listJacobsthal;
	listJacobsthal.push_back(0);
	listJacobsthal.push_back(1);
	for (size_t i = 0 , j = 2; i < vecSmall.size(); i++)
	{
		size_t indexToPush = listJacobsthal[j - 1] + 2 * listJacobsthal[j - 2];
		listJacobsthal.push_back(indexToPush);
		j++;
	}
	return listJacobsthal;
}

void addIndexMissing(std::vector<int> &orderOfInsertion, std::vector<int> &vecSmall)
{
	std::vector<int>::iterator it;
	while (orderOfInsertion.size() < vecSmall.size() - 1)
	{
		bool found = false;
		for (size_t i = vecSmall.size() - 1; i > 0 && (orderOfInsertion.empty() || (int)i > orderOfInsertion[orderOfInsertion.size() - 1]); i--)
		{
			it = std::find(orderOfInsertion.begin(), orderOfInsertion.end(), i);
			if (it == orderOfInsertion.end())
			{
				orderOfInsertion.push_back(i);
				found = true;
				break;
			}
		}
		if (!found)
			break;
	}
}

std::vector<int> orderOfInsertion(std::vector<int> & relevantIndices, std::vector<int> &vecSmall)
{
	std::vector<int> orderOfInsertion = relevantIndices;
	int alreadyPushed = 0;
	for (size_t i = 1; i < relevantIndices.size(); i++)
	{
		size_t indexToPush = relevantIndices[i - 1] + 1;
		orderOfInsertion.insert(orderOfInsertion.begin() + i + 1 + alreadyPushed, indexToPush);
		alreadyPushed++;
	}
	if (orderOfInsertion.size() != relevantIndices.size())
	{
		addIndexMissing(orderOfInsertion, vecSmall);
	}
	orderOfInsertion.push_back(0);
	return orderOfInsertion;
}

std::vector<int> relevantIndices(std::vector<int> &vecSmall)
{
	std::vector<size_t> list = listJacobsthal(vecSmall);
	std::vector<int> indicesUtiles;
	std::vector<int>::iterator it;

	for (size_t i = 1; i < list.size(); i++)
	{
		it = std::find(indicesUtiles.begin(), indicesUtiles.end(), list[i]);
		if (it == indicesUtiles.end() && list[i] < vecSmall.size())
		{
			indicesUtiles.push_back(list[i]);
		}
	}
	return (indicesUtiles);
}

void	insertionFordJohnsonVec(std::vector<int> &vecBig, std::vector<int> &vecSmall)
{
	std::vector<int> indicesUtiles = relevantIndices(vecSmall);
	std::vector<int> finalOrder = orderOfInsertion(indicesUtiles, vecSmall);

	for (size_t i = 0; i < finalOrder.size(); i++)
	{
		int index = finalOrder[i];
		if (index < 0 || static_cast<size_t>(index) >= vecSmall.size())
			continue;
		int value = vecSmall[index];
		std::vector<int>::iterator itPos = std::lower_bound(vecBig.begin(),
				vecBig.end(), value);
		vecBig.insert(itPos, value);
	}
	std::cout << "After : ";
	printVec(vecBig);
	// Print FULL
	// printVecFull(vecBig);
	std::cout << "Time to process a range of " << vecBig.size()
		<< " elements with std::vector : ";
}

void	insertionFordJohnsonDeq(std::deque<int> &deqBig, std::deque<int> &deqSmall)
{
	std::vector<int> smallCopy(deqSmall.begin(), deqSmall.end());
	std::vector<int> indicesUtilesVec = relevantIndices(smallCopy);
	std::vector<int> finalOrder = orderOfInsertion(indicesUtilesVec, smallCopy);

	for (size_t i = 0; i < finalOrder.size(); i++)
	{
		int index = finalOrder[i];
		if (index < 0 || static_cast<size_t>(index) >= deqSmall.size())
			continue;
		int value = deqSmall[index];
		std::deque<int>::iterator itPos = std::lower_bound(deqBig.begin(),
				deqBig.end(), value);
		deqBig.insert(itPos, value);
	}
	std::cout << "After : ";
	printDeq(deqBig);
	std::cout << "Time to process a range of " << deqBig.size()
		<< " elements with std::deque : ";
}

void sortPairs(std::vector<std::pair<int, int> > &pairsToSort)
{
	std::vector<std::pair<int, int> >::iterator it;
	for (it = pairsToSort.begin(); it != pairsToSort.end(); it++)
	{
		if (it->first > it->second && it->second != -1)
		{
			std::swap(it->first, it->second);
		}
	}
}

void mergeSortRecursive(std::vector<int> &vecBig)
{
	if (vecBig.size() <= 1)
		return ;

	std::size_t mid = vecBig.size() / 2;
	std::vector<int> left(vecBig.begin(), vecBig.begin() + mid);
	std::vector<int> right(vecBig.begin() + mid, vecBig.end());

	mergeSortRecursive(left);
	mergeSortRecursive(right);

	std::size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			vecBig[k++] = left[i++];
		else
			vecBig[k++] = right[j++];
	}
	while (i < left.size())
		vecBig[k++] = left[i++];
	while (j < right.size())
		vecBig[k++] = right[j++];
}

void	mergeSort(std::vector<int> &vecBig, std::vector<int> &bigSorted)
{
	size_t	j;

	
	bigSorted.push_back(vecBig[0]);
	for (size_t i = 1; i < vecBig.size(); i++)
	{
		j = 0;
		while (j < bigSorted.size() && vecBig[i] > bigSorted[j])
			j++;
		bigSorted.insert(bigSorted.begin() + j, vecBig[i]);
		if (bigSorted.size() == vecBig.size())
			break ;
	}
}

void	insertionSort(std::vector<int> &bigSorted, std::vector<int> &vecSmall)
{
	for (size_t i = 0; i < vecSmall.size(); i++)
	{
		std::vector<int>::iterator itPos = std::lower_bound(bigSorted.begin(),
				bigSorted.end(), vecSmall[i]);
		bigSorted.insert(itPos, vecSmall[i]);
	}
	std::cout << "After : ";
	printVec(bigSorted);
	// Full Vector 
	printVecFull(bigSorted);
	std::cout << "Time to process a range of " << bigSorted.size() << " elements with std::vector : ";
}

void	printVec(std::vector<int> &vec)
{
	size_t lenVec = vec.size();
	if (lenVec > 5)
		lenVec = 5;
	for (size_t i = 0; i < lenVec; i++)
		std::cout << vec[i] << " ";
	if (lenVec == 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	printVecFull(std::vector<int> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

void	AlgoVector(std::vector<int> &vec)
{
	clock_t	start;
	clock_t	end;
	double	realTime;

	start = clock();
	std::cout << "Before : ";
	printVec(vec);
	std::vector<int> vecSmall;
	std::vector<int> vecBig;
	splittingBigSmall(vec, vecBig, vecSmall);
	end = clock();
	realTime = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC;
	std::cout << std::fixed << realTime * 100 << " us" << std::endl;
}



// Deque

void	mergeSortDeque(std::deque<int> &deqBig, std::deque<int> &bigSorted)
{
	size_t	j;

	bigSorted.push_back(deqBig[0]);
	for (size_t i = 1; i < deqBig.size(); i++)
	{
		j = 0;
		while (j < bigSorted.size() && deqBig[i] > bigSorted[j])
			j++;
		if (j != bigSorted.size())
			bigSorted.insert(bigSorted.begin() + j, deqBig[i]);
		else
			bigSorted.push_back(deqBig[i]);
		if (bigSorted.size() == deqBig.size())
			break ;
	}
}

void mergeSortRecursiveDeque(std::deque<int> &deqBig)
{
	if (deqBig.size() <= 1)
		return ;

	std::size_t mid = deqBig.size() / 2;
	std::deque<int> left(deqBig.begin(), deqBig.begin() + mid);
	std::deque<int> right(deqBig.begin() + mid, deqBig.end());

	mergeSortRecursiveDeque(left);
	mergeSortRecursiveDeque(right);

	std::size_t i = 0, j = 0, k = 0;
	while (i < left.size() && j < right.size())
	{
		if (left[i] <= right[j])
			deqBig[k++] = left[i++];
		else
			deqBig[k++] = right[j++];
	}
	while (i < left.size())
		deqBig[k++] = left[i++];
	while (j < right.size())
		deqBig[k++] = right[j++];
}

void	insertionSortDeque(std::deque<int> &bigSorted,
		std::deque<int> &deqSmall)
{
	for (size_t i = 0; i < deqSmall.size(); i++)
	{
		std::deque<int>::iterator itPos = std::lower_bound(bigSorted.begin(),
				bigSorted.end(), deqSmall[i]);
		bigSorted.insert(itPos, deqSmall[i]);
	}
	std::cout << "After : ";
	printDeq(bigSorted);
	//PRINT FULL DEQ
	printDeqFull(bigSorted);
	std::cout << "Time to process a range of " << bigSorted.size() << " elements with std::deque : ";
}

void	printDeq(std::deque<int> &deq)
{
	size_t lenDeq = deq.size();
	if (lenDeq > 5)
		lenDeq = 5;
	for (size_t i = 0; i < lenDeq; i++)
		std::cout << deq[i] << " ";
	if (lenDeq == 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	printDeqFull(std::deque<int> &deq)
{
	for (size_t i = 0; i < deq.size(); i++)
		std::cout << deq[i] << " ";
	std::cout << std::endl;
}

void	ParseInputDeque(std::string &input, std::deque<int> &deq)
{
	std::istringstream iss(input);
	std::string word;
	while (iss >> word)
	{
		checkInt(word);
		if (std::atoi(word.c_str()) < 0)
			throw std::runtime_error("This argument is not a positive digit : ");
		deq.push_back(std::atoi(word.c_str()));
	}
}
void	splittingBigSmallDeque(std::deque<int> &deq, std::deque<int> &deqBig,
		std::deque<int> &deqSmall)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = (deq.size() % 2 != 0) ? (deq.size() - 1) : deq.size();
	while (i < len)
	{
		if (deq[i] > deq[i + 1])
		{
			deqBig.push_back(deq[i]);
			deqSmall.push_back(deq[i + 1]);
			i += 2;
			continue ;
		}
		else if (deq[i] < deq[i + 1])
		{
			deqBig.push_back(deq[i + 1]);
			deqSmall.push_back(deq[i]);
			i += 2;
			continue ;
		}
		else
		{
			deqBig.push_back(deq[i + 1]);
			deqSmall.push_back(deq[i]);
		}
		i += 2;
	}
	if (deq.size() % 2 != 0)
		deqBig.push_back(deq[i]);
	mergeSortRecursiveDeque(deqBig);
	insertionFordJohnsonDeq(deqBig, deqSmall);
}

void	AlgoDeque(std::deque<int> &deq)
{
	clock_t	start;
	clock_t	end;
	double	realTime;

	start = clock();
	std::cout << "Before : ";
	printDeq(deq);
	std::deque<int> deqSmall;
	std::deque<int> deqBig;
	splittingBigSmallDeque(deq, deqBig, deqSmall);
	end = clock();
	realTime = static_cast<double>(end - start) / (double)CLOCKS_PER_SEC;
	std::cout << std::fixed << realTime * 100 << " µs" << std::endl;
}

void	ProcessAlgoDeque(char **argv)
{
	std::deque<int> deq;
	for (size_t i = 1; argv[i]; i++)
	{
		std::string input = argv[i];
		ParseInputDeque(input, deq);
	}
	AlgoDeque(deq);
}
