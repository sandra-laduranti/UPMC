LIB=$(CGRAPH_DIR)/lib/
INCLUDES=-I$(CGRAPH_DIR)/include/

NAME = arbre

SRCS =	arbre.c \
	main.c 


OBJS = $(SRCS.c=.o)

RM = rm -f

all	: $(NAME)

$(NAME)	: $(OBJS)
	gcc  -Wall -o $(NAME) -L$(LIB) $(SRCS) $(INCLUDES)

clean	:
	rm -f *.o $(NAME)

fclean  : clean
	$(RM) $(NAME)

re: fclean all