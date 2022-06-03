
all : exec run


exec : main.o fct_main.o fct.o
	gcc main.o fct_main.o fct.o -o exec

main.o : main.c fct.h fct_main.h
	gcc -c main.c -o main.o

fct_main.o : fct_main.c fct.h fct_main.h
	gcc -c fct_main.c -o fct_main.o

fct.o : fct.c fct.h
	gcc -c fct.c -o fct.o

clean : 
	rm -f *.o
	rm exec
	
run: 
	./exec

