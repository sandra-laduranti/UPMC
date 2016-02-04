LIB=$(CGRAPH_DIR)/lib/
INCLUDES=-I$(CGRAPH_DIR)/include/

NAME = morpion 

SRCS =	xmalloc.c \
	xfree.c \
	grid.c \
	complete_grid.c \
	options.c \
	winner.c \
	end_of_game.c \
	Kikoo.c \
	ia.c \
	begin.c

OBJS = $(SRCS.c=.o)

RM = rm -f

all	: $(NAME)

$(NAME)	: $(OBJS)
	gcc  -Wall -o $(NAME) -L$(LIB) $(SRCS) $(INCLUDES) -lm

clean	:
	rm -f *.o $(NAME)

fclean  : clean
	$(RM) $(NAME)

re: fclean all