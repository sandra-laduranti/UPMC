LIB=$((CGRAPH_DIR)/lib/
INCLUDES=-I$(CGRAPH_DIR)/include/

NAME=Nahal

SRCS= main.c \
	menu.c 	\
	game.c \
	getevent.c \
	getmap.c \
	getchar.c

LIBS= -lSDL_ttf \
	-lfreetype

OBJS= $(SRCS.c=.o)

RM = rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	gcc -Wall -o $(NAME) -L$(LIB) $(SRCS) $(INCLUDES) `sdl-config --cflags --libs` $(LIBS)

clean : 
	rm -f *.o $(NAME)

fclean : clean
	$(RM) $(NAME)

re: fclean all

