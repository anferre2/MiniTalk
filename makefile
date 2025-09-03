# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anferre2 <anferre2@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 15:40:03 by anferre2          #+#    #+#              #
#    Updated: 2025/08/12 15:26:47 by anferre2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  Compiler                                    #
#==============================================================================#
CC     = cc
CFLAGS = -Wall -Wextra -Werror -g
RM     = rm -rf

#==============================================================================#
#                               Files and Paths                                #
#==============================================================================#
NAME_SERVER = server
NAME_CLIENT = client

SRCS_SERVER = server.c utils.c utils1.c
SRCS_CLIENT = client.c utils.c utils1.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

#==============================================================================#
#                                    Rules                                     #
#==============================================================================#
all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)
	@echo "[OK] Server compilado"
$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)
	@echo "[OK] Client compilado"
clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	@echo "[CLEAN] Objetos removidos"
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	@echo "[CLEAN] Executáveis removidos"
	
re: fclean all

.PHONY: all clean fclean re