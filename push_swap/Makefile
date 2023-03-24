# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asouchet <asouchet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 02:15:22 by trubat-d          #+#    #+#              #
#    Updated: 2023/03/03 21:41:09 by asouchet         ###   ########.fr        #
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

NAME = global

all: $(NAME)

$(NAME):
		@cd ./push_swap && $(MAKE) && cp pushswap ../pushswap

bonus: $(NAME)
		@cd checker && $(MAKE) && cp checker_exec ../checker_exec
		
puclean:
		$(ECHO) "$(RED)Suppression des push_swap...$(RESETTXT)"
		@rm -f pushswap
		@cd ./push_swap && $(MAKE) fclean && cd ..
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

chclean:	clean
		$(ECHO) "$(RED)Suppression de checker...$(RESETTXT)"
		@rm -f checker_exec
		@cd ./checker && $(MAKE) fclean
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:		puclean chclean
		
re:		chclean puclean all bonus

.PHONY: all clean fclean re 