# Makefile that builds hermit compiler executable
CC		= 	gcc
SRC		= 	lex.yy.c hermit.c util.c y.tab.c print_tree.c trees.c
OBJ		= 	$(SRC:.c=.o)
NAME	=	hermit
RM		=	rm
CFLAGS	= 	-Wall -Werror -Wextra -pedantic

all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
clean:
	$(RM) -f *~ $(NAME)
oclean:
	$(RM) -f *.o
fclean:
	$(RM) -f *.o *~ $(NAME)
re: oclean *.o all

