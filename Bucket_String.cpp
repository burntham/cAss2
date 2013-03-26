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
	Bucket * firstBuck;

	//Default constructor
	Bucket_String::Bucket_String(void)
	{

	};

	//Construct the bucket string with a specifed bucket size;
	Bucket_String::Bucket_String(int bucketSize_):nOfBuckets(0), BucketSize(bucketSize_), firstBuck(new Bucket(BucketSize))
	{

	};

	//Called by the >> operator!
	void Bucket_String::addChar(char c)
	{

	}
}
