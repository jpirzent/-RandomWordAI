# NAME #
NAME = RandomAI

# PATHS #
SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./inc/


# FILES #
SRC_FILES = main.c\
			generatePopulation.c\
			functions.c\
			calculateFitness.c\
			selection.c\
			newGeneration.c\
			evaluate.c\

OBJ_FILES = $(SRC_FILES:%.c=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))


# COMPILE #
CCFLAGS = -Wall -Werror -Wextra
CC = gcc $(CCFLAGS)

$(NAME): temp $(OBJ)
	@$(CC) -o $@ $(LIBF) $(PRF) $(OBJ) -lm
	@echo "\033[92m"---COMPILED SUCCESFULLY---"\033[0m"


# MAKE COMMANDS #
all: $(NAME)

temp:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) -I $(INC_PATH) -o $@ -c $<
	@echo "\e[31m"MAKING"\e[0m" $@

clean:
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\e[31m"CLEANING"\e[0m" ./objs/

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\e[31m"REMOVING"\e[0m" $(NAME)

re: fclean all

.PHONY: re clean fclean all