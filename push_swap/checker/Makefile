# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 19:14:49 by asouchet          #+#    #+#              #
#    Updated: 2023/03/03 21:20:00 by asouchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = checker.c 
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME = checker_exec
AR = ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/ -I push_swap/includes/ -I ../libft/

OPTIONS = -L push_swap -lpush_swap
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de checker...$(RESETTXT)"
		@cd push_swap/ && $(MAKE) bonus 
		@gcc $(CFLAGS) $(INCLUDES) $(OPTIONS) $(OBJS) -o $@ 
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

clean:
		$(ECHO) "$(RED)$(BOLD)Suppression !!!$(RESETTXT)"
		@$(RM) $(OBJS)

fclean:	clean
		$(ECHO) "$(RED)$(BOLD)Suppression TOTAL!!!!!!! $(RESETTXT)"
		@$(RM) $(NAME)
		@cd push_swap/ && $(MAKE) fclean

re:		fclean all

.PHONY: all clean fclean re 