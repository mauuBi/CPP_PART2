NAME = convert

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = ScalarConverter.cpp	main.cpp ConverterChar.cpp ConverterInt.cpp ConverterFloat.cpp ConverterDouble.cpp
INC_FILES = .

OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_FILES)
	$(CC) -I$(INC_FILES) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all