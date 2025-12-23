/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:03:45 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/23 12:41:43 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

// Vector
void	AlgoVector(std::vector<int> &vec);
void	ProcessAlgoVector(char **argv);
void	ParseInput(std::string &input, std::vector<int> &vec);
void	printVec(std::vector<int> &vec);
void	printVecFull(std::vector<int> &vec);
void	insertionSort(std::vector<int> &bigSorted, std::vector<int> &vecSmall);
void	mergeSort(std::vector<int> &vecBig, std::vector<int> &bigSorted);
void	mergeSortRecursive(std::vector<int> &vecBig);
void	checkInt(const std::string &intToCheck);
std::vector<int> relevantIndices(std::vector<int> &vecSmall);
void	insertionFordJohnsonVec(std::vector<int> &vecBig, std::vector<int> &vecSmall);

// Deque

void	printDeq(std::deque<int> &deq);
void	printDeqFull(std::deque<int> &deq);
void	insertionSortDeque(std::deque<int> &bigSorted,
			std::deque<int> &deqSmall);
void	mergeSortDeque(std::deque<int> &deqBig, std::deque<int> &bigSorted);
void	mergeSortRecursiveDeque(std::deque<int> &deqBig);
void	ParseInputDeque(std::string &input, std::deque<int> &deq);
void	AlgoDeque(std::deque<int> &deq);
void	ProcessAlgoDeque(char **argv);
void	splittingBigSmallDeque(std::deque<int> &deq, std::deque<int> &deqBig,
			std::deque<int> &deqSmall);
void	insertionFordJohnsonDeq(std::deque<int> &deqBig, std::deque<int> &deqSmall);
