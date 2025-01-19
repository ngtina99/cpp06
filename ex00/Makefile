NAME = ex00

SRC = main.cpp Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)
HEADER = Bureaucrat.hpp

CC = c++
RM = rm -f

CPPFLAFGS =  -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re