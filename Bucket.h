#ifndef _BUCKET_H_
#define _BUCKET_H_

#include "Iterator.h"

namespace BRNDAN022
{
	class Bucket
	{
	public:
		char * content;
		/*
		*Constructors
		*/
		//Construct a Bucket which is being added to the end of a list
		Bucket(Bucket * Daddy, int arrSize);
		Bucket(int arrSize);
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
		/*
		*Variables
		*/
			//head node?
		Bucket * Head;
			//Array contents (actual string piece)
		
			//next bucket in linked list
		Bucket * child;

		//invoked through >>
		void addChar(char c);
	};

}

#endif