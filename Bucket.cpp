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
	Bucket * Head;
	Bucket * child;
	//char array holding this buckets segment of the string
	char* content;

	int bucket_size;
	int count;

	//Consturctors
	Bucket::Bucket(Bucket * daddy, int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize),Head(daddy),count(0)
	{	
		std::cout<<"Bucket Constructed"<<std::endl;

	}

	Bucket::Bucket(int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize),Head(NULL),child(NULL),count(0)
	{	std::cout<<"Bucket Constructed"<<std::endl;

	}

	//invoked through >>
	void Bucket::addChar(char c){
		//std::cout<<count<<" "<<bucket_size<<std::endl;

		if (count < (bucket_size-1))
		{	count++;
			content[count]=c;
			
		}else
		{	//std::cout<<"duck "<<c<<std::endl;
			if(child==NULL){
				child = new Bucket(this, bucket_size);
				child->addChar(c);
			}else{
				child->addChar(c);
			}
			
			
		}
		//std::cout<<"tested";
	}

	std::ostream & Bucket::outAll(std::ostream & os)
	{
		for (int i = 0; i < count; ++i)
		{
			os<<content[i];
		}
		return os;
	}
}
