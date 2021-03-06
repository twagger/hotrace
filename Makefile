# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: twagner <twagner@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/01 15:32:48 by twagner           #+#    #+#              #
#    Updated: 2021/12/12 13:37:46 by twagner          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 COMMANDS                                     #
################################################################################
RM			= rm -f
CC			= cc
AR			= ar rcs

################################################################################
#                                 SOURCES                                      #
################################################################################
SRCS		= main.c \
			  utils.c \
			  keyvalue.c \
			  hashtable.c \
			  getnextline.c \
			  getnextline_utils.c

OBJS		= $(SRCS:.c=.o)

################################################################################
#                           EXECUTABLES & LIBRARIES                            #
################################################################################
NAME		= hotrace

################################################################################
#                                 DIRECTORIES                                  #
################################################################################
HEADERS		= .

################################################################################
#                                     FLAGS                                    #
################################################################################
CFLAGS		:= -Wall -Wextra -Werror

ifeq ($(DEBUG), true)
	CFLAGS	+= -fsanitize=address -g3 -O0
endif

################################################################################
#                                    RULES                                     #
################################################################################
.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(HEADERS)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I$(HEADERS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

own_tests:
			$(MAKE) -C 	./test/ all

.PHONY:		all clean fclean c.o re
