LadungKondensator: main.o UKon.o
	gcc -o LadungKondensator main.o UKon.o
	#./LadungKondensator

main.o: main.c
	gcc -c -o main.o main.c

UKon.o: UKon.c
	gcc -c -o UKon.o UKon.c

clean:
	rm -f *.o

cleanall:
	rm -f *.o LadungKondensator
