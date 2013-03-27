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
	Bucket::Bucket(Bucket * daddy, int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize),Head(daddy),child(NULL),count(0)
	{	
		//std::cout<<"Bucket Constructed"<<std::endl;

	}

	Bucket::Bucket(int bucketsize):content(new char[bucketsize]),bucket_size(bucketsize),Head(NULL),child(NULL),count(0)
	{	//std::cout<<"Bucket Constructed"<<std::endl;

	}

	//invoked through >> operator
	void Bucket::addChar(char c){
		//std::cout<<"attempting to add "<<c<<std::endl;
		//std::cout<<"count is:"<<count<<"bucket_size is"<<bucket_size<<std::endl;

		if (count < (bucket_size))
		{	++count;
			content[count-1]=c;
			
		}
		else
		{	//std::cout<<"duck "<<c<<std::endl;
			if(child==NULL){
				child = new Bucket(this,bucket_size);
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
