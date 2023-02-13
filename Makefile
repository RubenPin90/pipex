# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpinchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/16 10:13:52 by rpinchas          #+#    #+#              #
#    Updated: 2023/02/13 17:15:03 by rpinchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME :=	pipex
CFLAGS := -Werror -Wall -Wextra
DEBUG := -g

#FILES
SRCDIR := src
SRC_F := pipex_main.c \
pipex_utils.c \
pipex_exec.c \
pipex_free.c
SRC := 	${addprefix ${SRCDIR}/, ${SRC_F}}
HEAD := pipex.h
OBJDIR := obj
OBJ_F :=  ${SRC_F:%.c=%.o}
OBJ :=	${addprefix ${OBJDIR}/, ${OBJ_F}}

#LIBFT
LIBFTDIR := libft
LIBFT_F := libft.a
LIBFT := ${addprefix ${LIBFTDIR}/, ${LIBFT_F}}

#COLORS
GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m

ifndef NUM
NUM := file1 'ls -l' 'wc -l' file2
endif

#RULES
all: ${NAME}

${NAME}: ${LIBFT} ${OBJ}
	@echo "${YELLOW}Compiling...${RESET}"
	${CC} ${CFLAGS} ${DEBUG} -o $@ ${OBJ} $< 
	@echo "${GREEN}Run Code${RESET}"
	./$@ ${NUM}  

${OBJDIR}/%.o: ${SRCDIR}/%.c obj_check
	${CC} ${CFLAG} -c $< -o $@

obj_check: 
	@echo "${BLUE}Making object files...${RESET}"
	@mkdir -p ${OBJDIR}

${LIBFT}: ${LIBFTDIR}
	@make -C $^ -s

clean:
	@echo "${GREEN}Removing object files...${RESET}"
	@rm -f ${OBJ}
	@rm -rf ${OBJDIR}
	@make -C ${LIBFTDIR} clean -s
	@echo "${BLUE}DONE!${RESET}"

fclean: clean
	@echo "${GREEN}Removing executables...${RESET}"
	@rm	-rf ${NAME}
	@make -C ${LIBFTDIR} fclean -s
	@echo "${BLUE}DONE!${RESET}"

re: fclean all

.PHONY: all clean fclean re
