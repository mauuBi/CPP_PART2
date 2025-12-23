NAME = RPN

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp RPN.cpp
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