/*
 * Bucket_String.cpp
 *
 *  Created on: 23/03/2013
 *      Author: Daniel Burnham-King
 *				BRNDAN022
 *	
 *	This is Bucket String Class
 */

#include "Bucket_String.h"

 //#include <cstddef>

//Cannot use linked list!
namespace BRNDAN022
{	

	int nOfBuckets;
	int BucketSize;
	Bucket * firstBuck=NULL;
	int charCount;

	//Default constructor - not currently used for anything...
	Bucket_String::Bucket_String(void)
	{

	};

	//Construct the bucket string with a specifed bucket size;
	Bucket_String::Bucket_String(int bucketSize_):nOfBuckets(0), BucketSize(bucketSize_), firstBuck(new Bucket(bucketSize_)),charCount(0)
	{
		//std::cout<<"bucketString constructed"<<BucketSize<<std::endl;
	};

	//Called by the >> operator! - adds new characters to the end of the buckets (or creating new ones if they are full)
	void Bucket_String::addChar(char c)
	{
		firstBuck->addChar(c);
		++charCount;
	}

	//Return iterator pointing at the first character of the string
	iterator Bucket_String::begin()
	{
		iterator test(7, this);
		return test;
	}
	//return an iterator pointing one location past the last string character
	iterator Bucket_String::end()
	{
		//return iterator(charCount,firstBuck);
	}
	
	/////////Iterator class:::

	char * charPTR=NULL;

	iterator::iterator(void)
	{

	};

	iterator::iterator(int index,Bucket_String * bs):charPTR(NULL)
	{	

			int bucketIndex = (int)(index/(bs->BucketSize));
			//std::cout<<"bucketIndex is "<<bucketIndex<<std::endl;
			int contentIndex = index - ((bs->BucketSize)*(bucketIndex));
			//std::cout<<"contentIndex is "<<contentIndex<<std::endl;

			if (index<(bs->BucketSize)){
				charPTR= &(bs->firstBuck->content[index]);
				std::cout<<"what should be there?"<<bs->firstBuck->content[index]<<std::endl;
			}
			else{
					Bucket * BucketPew =bs->firstBuck;	
				for (int i = 0; i < bucketIndex; ++i)
				{
					BucketPew = BucketPew->child;
				}
				charPTR= &(BucketPew->content[contentIndex]);
			}
			std::cout<<*charPTR<<std::endl;
	};
	
}
