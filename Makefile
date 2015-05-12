###################################################################
#
# freeman.justin@gmail.com 
#
##################################################################

OBJ=	./src/breed.o \
	./src/breed_xover.o \
	./src/copy_struct.o \
	./src/graphics.o \
	./src/main.o \
	./src/malloc2d.o \
	./src/stats.o \
	./src/obj_func.o \
	./src/rand.o \
	./src/rank_population.o \
	./src/sort.o

# compliler flags
INC=    -I./include 

CFLAGS=	-g -O3 -Wall

CC=	gcc -DHAVEPGPLOT $(CFLAGS) $(INC) 

# Libraries 
LFLAGS= -L/usr/X11R6/lib -lX11 -lgfortran /apps/pgplot/5.2.0/libcpgplot.a /apps/pgplot/5.2.0/libpgplot.a	

# executable
EXEC=	./bin/evol	

$(EXEC):$(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(LFLAGS)

clean:
	rm $(OBJ)
	rm $(EXEC)
