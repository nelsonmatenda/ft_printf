# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfigueir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/31 11:46:43 by nfigueir          #+#    #+#              #
#    Updated: 2024/05/31 12:52:51 by nfigueir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

#paths
HEADER = ./includes
DIR_LIBFT = libft/
DIR_LIBFT_H = $(addprefix $(DIR_LIBFT),$(HEADER))
DIR_SRC = src/
DIR_OBJ = obj/
#c files
FILES_SRC = ft_abs.c ft_printf.c ft_putaddress.c\
					ft_putbase_fd.c ft_putchar.c\
					ft_puthexa.c ft_putnbr.c \
					ft_putstr.c ft_putunsigned.c ft_util.c
					
SOURCERS = $(addprefix $(DIR_SRC),$(FILES_SRC))
OBJECTS = $(addprefix $(DIR_OBJ),$(FILES_SRC:.c=.o))

# comandos
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
REMOVE = rm -rf

all: $(NAME)
$(NAME): $(OBJECTS)
		@make -C $(DIR_LIBFT) --no-print-directory
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJECTS)
$(DIR_OBJ)%.o:	$(DIR_SRC)%.c 
					@mkdir -p $(DIR_OBJ)
					@$(CC) -c $(FLAGS) -I $(HEADER) -I $(DIR_LIBFT_H) -o $@ $<


clean:
		@$(REMOVE) -rf $(DIR_OBJ)
		@make clean -C $(DIR_LIBFT) --no-print-directory

fclean:			clean
					@$(REMOVE) -f $(NAME)
					@$(REMOVE) -f libft/libft.a

re: 	fclean all

#CHECK norminette
checker:
					@norminette $(SOURCERS) $(HEADER) $(DIR_LIBFT) | grep -v Norme -B1 || true

#DECLARATION tags
.PHONY:			all bonus clean fclean re checker