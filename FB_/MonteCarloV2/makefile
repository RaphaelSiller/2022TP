CC=gcc
ARGS=-ansi -std=c99 -Wall -O
ZIEL=pi
OBJECTS=pi.o
CLEAN=rm -f

$(ZIEL): $(OBJECTS)
	$(CC) $(ARGS) $(ZIEL)
	
clean:
	$(CLEAN) $(OBJECTS) 
	
cleanall:
	$(CLEAN) $(OBJECTS) $(ZIEL)