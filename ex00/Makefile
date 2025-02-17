NAME = convert

SRC_DIR = ./sources/
SRC = main.cpp ScalarConverter.cpp
OBJ = $(addprefix $(SRC_DIR), $(SRC:.cpp=.o))

INC_DIR = ./includes/
INC = ScalarConverter.hpp
HEADER = $(addprefix $(INC_DIR), $(INC))

CC = c++
RM = rm -f

CPPFLAGS =  -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
