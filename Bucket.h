#ifndef _BUCKET_H_
#define _BUCKET_H_

#include "Iterator.h"

namespace BRNDAN022
{
	class Bucket
	{
	public:
		/*
		*Constructors
		*/
		Bucket(int arSize);

		/*
		*Methods
		*/
			//Return iterator pointing at the first character of the string
		Iterator begin();
			//return an iterator pointing one location past the last string character
		Iterator end();


		~Bucket()
		{
			delete [] content;
		}
	private:
		friend class Iterator;
		friend class Bucket_String;
		/*
		*Variables
		*/
			//head node?
		Bucket * Head;
			//Array contents (actual string piece)
		char * content;
			//next bucket in linked list
		Bucket * child;
	};

}

#endif