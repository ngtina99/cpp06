NAME = serializer

SRC_DIR = ./sources/
SRC = main.cpp Serializer.cpp
OBJ = $(addprefix $(SRC_DIR), $(SRC:.cpp=.o))

INC_DIR = ./includes/
INC = Serializer.hpp Data.hpp
HEADER = $(addprefix $(INC_DIR), $(INC))

CC = c++
RM = rm -f

CPPFLAGS =  -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)



clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re