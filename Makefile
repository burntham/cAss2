FILE = stringFile.txt
CC=g++
FLAGS = -c
OBJECTS = Assignment2.o cmdline_parser.o Bucket_String.o Bucket.o
LIBRARIES = -lboost_program_options
TARGET= testme
RUNNINGARGS =  -d


All: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBRARIES) 

run: All
	clear;echo Compiled, executing...;./$(TARGET) $(RUNNINGARGS) $(FILE)

Assignment2.o: Assignment2.cpp cmdline_parser.o Bucket_String.o
	$(CC) $(FLAGS) Assignment2.cpp 

cmdline_parser.o: cmdline_parser.cpp
	$(CC) $(FLAGS) cmdline_parser.cpp 

Bucket_String.o: Bucket.o Bucket_String.cpp Bucket_String.h
	$(CC) $(FLAGS) Bucket_String.cpp

Bucket.o: Bucket.cpp Bucket.h
	$(CC) $(FLAGS) Bucket.cpp

clean:
	rm -f *.o ; clear

remake: clean
	make

