NAME = Abstract

CC = c++

CFLAGS = -Werror -Wextra -Wall -std=c++98 -Wshadow

SRC = AAnimal.cpp \
	Brain.cpp \
	Cat.cpp \
	Dog.cpp \
	main.cpp \
	WrongAAnimal.cpp \
	WrongCat.cpp

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(SRC))

OBJ_DIR = obj

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re