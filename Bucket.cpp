/*
 * Bucket.cpp
 *
 *  Created on: 23/03/2013
 *      Author: Daniel Burnham-King
 *				BRNDAN022
 *	
 *	This is Bucket class
 */

#include "Bucket.h"
#include "iostream"

namespace BRNDAN022
{
	Bucket * Head=NULL;
	Bucket * child=NULL;
	//char array holding this buckets segment of the string
	char* content;

	int bucket_size;
	int count;

	//Consturctors
	Bucket::Bucket(Bucket * daddy, int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize)
	{	
		Head = daddy;

	}

	Bucket::Bucket(int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize)
	{	std::cout<<"Bucket Constructed"<<std::endl;

	}

	//invoked through >>
	void Bucket::addChar(char c){
		if (count < bucket_size-1)
		{
			content[count]=c;
		}else
		{
			child = new Bucket(this, bucket_size);
			child->addChar(c);
		}
	}

	void Bucket::outAll(std::ostream & os)
	{
		for (int i = 0; i < count; ++i)
		{
			os<<content[i];
		}
	}
}
