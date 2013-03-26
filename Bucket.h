#ifndef _BUCKET_H_
#define _BUCKET_H_

#include "Iterator.h"
#include <iostream>

namespace BRNDAN022
{
	class Bucket
	{
	public:
		char * content;
		//next bucket in linked list
		Bucket * child;
		/*
		*Constructors
		*/
		//Construct a Bucket which is being added to the end of a list
		Bucket(Bucket * Daddy, int bucketsize);
		Bucket(int bucketsize);
		std::ostream & outAll(std::ostream & os);
		/*
		*Methods
		*/
			//Return iterator pointing at the first character of the string
		iterator begin();
			//return an iterator pointing one location past the last string character
		iterator end();


		~Bucket()
		{
			delete [] content;
		}

	private:
		friend class iterator;
		friend class Bucket_String;
		//how many items are currently stored?
		int count;
		int bucket_size;
		/*
		*Variables
		*/
			//head node?
		Bucket * Head;
			//Array contents (actual string piece)
		


		//invoked through >>
		void addChar(char c);
	};

}

#endif