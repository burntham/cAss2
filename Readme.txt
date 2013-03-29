Daniel Burnham-King
c++ Assignment 2
Pointers

Compilation:
	navigate to the folder in which the below mentioned .cpp files are stored (assuming that by you reading this, the tarball is already extracted).

1. The Bucket_String class: - Bucket_String.cpp Bucket_String.h
	the >>operator allows for information to be added to the bucket list eg. istringsteamthingy >> bucketlistObject will add the contents to the bucket string, creating new buckets if it sees fit :) Bucket String will apped if an input stream is >> into it again. Operator overloading is defined in header file.

2. The iterator class: - Bucket_String.cpp Bucket_String.h
	This class is used to create the iterators. Operator overloading of this class is defined in the header file (most other methods etc, should be defined in the .cpp file)

3. The Bucket class: - Bucket.cpp Bucket.h
	This class is used to form a linked list of buckets ( each bucket constains a char array of specified size)

4. cmd_line parser does as it did in the previous assignment (code given to us by lecturer).

5. Assignment2: this is the driver class:
	The classes intention was to show that all required functionality has been added.