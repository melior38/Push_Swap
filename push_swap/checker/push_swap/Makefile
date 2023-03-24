# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 02:15:22 by trubat-d          #+#    #+#              #
#    Updated: 2023/03/03 21:40:08 by asouchet         ###   ########.fr        #
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
SRC = parsing.c list_utils.c list.c sort_utils.c sort_utils_2.c sort_utils_3.c algorythme_utils.c \
		algorythme.c parsing_2.c algorythme_utils_2.c sort_utils_4.c algorythme_utils_3.c free.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME 	= push_swap
AR 		= ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/ -I ../../libft/

OPTIONS = -L ../../libft -lft
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de push_swap...$(RESETTXT)"
		@ cd ../../libft && $(MAKE)
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

bonus: $(NAME)
		@cd ../../libft && cp libft.a ../checker/push_swap/libpush_swap.a
		@$(AR) libpush_swap.a $(OBJS)

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJS)
		@cd ../../libft && $(MAKE) clean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de push_swap et libft.a...$(RESETTXT)"
		@$(RM) $(NAME)
		@cd ../../libft && $(MAKE) fclean
		$(RM) libpush_swap.a
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"
		
re:		fclean all

.PHONY: all clean fclean re 
