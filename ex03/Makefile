NAME	= Point
SRCS	= main.cpp \
		Fixed.cpp \
		Point.cpp \
		bsp.cpp

CC		= c++
FLAGS	= -Wall -Wextra -Werror -std=c++98

all:		${NAME}

${NAME}:
			${CC} ${FLAGS} ${SRCS} -o ${NAME} 

fclean:	
			rm -f ${NAME}

re:			fclean all

.PHONY:		re fclean all