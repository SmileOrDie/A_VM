
CC		=	g++
NAME	=	avm
MYPATH	=	$(HOME)
FILES	=	main.cpp					\
			type/Factory.cpp			\
			type/Int8.cpp				\
			type/Int16.cpp				\
			type/Int32.cpp				\
			type/Float.cpp				\
			type/Double.cpp				\
			error/Overflow.cpp			\
			error/Underflow.cpp			\
			error/Division.cpp			\
			error/Modulo.cpp			\
			error/WrongAssert.cpp		\
			error/Print.cpp				\
			error/Type.cpp				\
			error/Pop.cpp				\
			error/Instruction.cpp		\
			error/Syntax.cpp			\
			error/LexicalFunction.cpp	\
			error/LexicalType.cpp		\
			error/MissingArgument.cpp	\
			error/ExtraArgument.cpp		\
			error/AssertEmpty.cpp		\
			error/PrintEmpty.cpp		\
			error/MathError.cpp

INC		=	-I ./includes -I ./srcs/exceptions -I ./srcs/error -I ./srcs/type
CCFLAGS	=	-std=c++11 -Wall -Wextra -Werror

SRCS	=	$(addprefix srcs/, $(FILES))
OBJS	=	$(SRCS:.cpp=.o)

#--------------Actions----------------------#

.PHONY: $(NAME) clean fclean re test

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CCFLAGS) $(INC) $(OBJS) -o $(NAME) $(LIBS) -O3

%.o: %.cpp
	$(CC) $(CCFLAGS) $(INC) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean:	clean
	rm -f $(NAME)

re: fclean all
	make
