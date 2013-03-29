Daniel Burnham-King
c++ Assignment 2
Pointers

Compilation:
	navigate to the folder in which the below mentioned .cpp files are stored (assuming that by you reading this, the tarball is already extracted). Typing make will compile the program, or make run (which will both compile and run the program)

Execution: 
	This program is intended to be executed directly or via the make file. It also reads a string from a textfile.

	When running from the make file (typing make run in terminal), the file name can be changed by changing the FILE setting in the makefile prior to calling 'make run'

	When executing from terminal directly (./testme), the program may be executed without arguments (defaulting the file that it reads a string from to stringFile.txt). or it may be run as: ./testme -d <FILENAME> ,where <FILENAME> is the file name (eg string.txt) - for example "./testme -d string.txt".

	Upon execution a bunch of stuff will print - this is how I've decided to test my code and show you that everything works.

FileList:
Assignment2.txt, Bucket_String.cpp, Bucket_String.h, Bucket.cpp, Bucket.h, Makefile,cmdline_parser.h, cmdline_parser.cpp,Readme.txt

Class Descriptions:
1. The Bucket_String class: - Bucket_String.cpp Bucket_String.h
	the >>operator allows for information to be added to the bucket list eg. istringsteamthingy >> bucketlistObject will add the contents to the bucket string, creating new buckets if it sees fit :) Bucket String will apped if an input stream is >> into it again. Operator overloading is defined in header file.

2. The iterator class: - Bucket_String.cpp Bucket_String.h
	This class is used to create the iterators. Operator overloading of this class is defined in the header file (most other methods etc, should be defined in the .cpp file)

3. The Bucket class: - Bucket.cpp Bucket.h
	This class is used to form a linked list of buckets ( each bucket constains a char array of specified size)

4. cmd_line parser does as it did in the previous assignment (code given to us by lecturer).

5. Assignment2: this is the driver class:
	The classes intention was to show that all required functionality has been added.

NOTE:
For the variety of iterator ranges(for replace, substr and insert, I have written the code so that it is dependant on the size of the array that is input into it.) (to test a slightly different range, use a text file with a longer string...)