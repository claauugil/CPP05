NAME = Form
SRC = Form.cpp \
	  main.cpp \
	  Bureaucrat.cpp\

OBJ = $(SRC:.cpp=.o)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
CYAN = \033[1;36m
RED	= \033[1;31m
RESET = \033[0m


all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(CYAN)project compiled!$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)clean: removing object files... $(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)fully cleaned: removing all build files... $(RESET)"

re: fclean all

.PHONY: all clean fclean re