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
#include "Bucket.h"
#include <iostream>
 //#include <cstddef>

//Cannot use linked list!
namespace BRNDAN022
{
	int nOfBuckets;
	int BucketSize;
	Bucket * firstBuck=NULL;

	//Default constructor
	Bucket_String::Bucket_String(void)
	{

	};

	//Construct the bucket string with a specifed bucket size;
	Bucket_String::Bucket_String(int bucketSize_):nOfBuckets(0), BucketSize(bucketSize_), firstBuck(new Bucket(BucketSize))
	{
		std::cout<<"bucketString constructed"<<std::endl;
	};

	//Called by the >> operator! - adds new characters to the end of the buckets (or creating new ones if they are full)
	void Bucket_String::addChar(char c)
	{
		firstBuck->addChar(c);
	}
}
