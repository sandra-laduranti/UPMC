LIB=$(CGRAPH_DIR)/lib/
INCLUDES=-I$(CGRAPH_DIR)/include/

NAME = big

SRCS =	xmalloc.c \
	xfree.c   \
	affichage_binaire.c \
	comparer_binaire.c \
	initialiser.c \
	affecter_bit.c \
	calcul_bit.c \
	somme.c \
	soustraction.c \
	librairie_bignum.c

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