
CC		= gcc
CFLAGS	= -Wall -Werror
LDFLAGS =

SRC 	= 	main.c

OBJ 	= $(SRC:.c=.o)

EXE 	= test

all: $(SRC) $(EXE)
	
$(EXE): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

clean:
	rm *.o

fclean:
	rm $(EXE)

re: fclean all