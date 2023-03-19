dict1: driver.c data.o list.o array.o
	gcc -Wall -o dict1 driver.c data.o list.o array.o
dict2: driver.c data.o list.o array.o
	gcc -Wall -o dict2 driver.c data.o list.o array.o
data.o: data.h data.c
	gcc -Wall -c data.c
list.o: list.h list.c
	gcc -Wall -c list.c
array.o: array.h array.c
	gcc -Wall -c array.c
