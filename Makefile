CC=g++
FLAGS = -c
OBJECTS = Assignment2.o cmdline_parser.o Bucket_String.o
LIBRARIES = -lboost_program_options
TARGET= testme
#RUNNINGARGS =  


All: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LIBRARIES)

run: All clean
	./$(TARGET)

Assignment2.o: Assignment2.cpp cmdline_parser.o Bucket_String.o
	$(CC) $(FLAGS) Assignment2.cpp 

cmdline_parser.o: cmdline_parser.cpp
	$(CC) $(FLAGS) cmdline_parser.cpp 

Bucket_String.o: Bucket.o Bucket_String.cpp Bucket_String.h
	$(CC) $(FLAGS) Bucket_String.cpp

Bucket.o: Bucket.cpp
	$(CC) $(FLAGS) Bucket.cpp

clean: clear
	rm -f *.o

clear:
	clear
