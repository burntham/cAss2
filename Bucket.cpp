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

	Bucket::Bucket(const Bucket & rhs):content(new char(rhs.bucket_size)),bucket_size(rhs.bucket_size),count(rhs.count),Head(NULL),child(NULL)
	{	
		for (int i = 0; i < count; ++i)
		{
			content[i] = rhs.content[i];
		}

	}

	//invoked through >> operator
	void Bucket::addChar(char c){
		//std::cout<<"attempting to add "<<c<<std::endl;
		//std::cout<<"count is:"<<count<<"bucket_size is"<<bucket_size<<std::endl;

		if (count < (bucket_size))
		{	++count;
			content[count-1]=c;
			if (count==bucket_size && child==NULL)
			{
				child = new Bucket(this,bucket_size);
			}
		}
		else
		{	//std::cout<<"duck "<<c<<std::endl;			
				child->addChar(c);		
			
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

	//used to delete the entire chain of buckets stored in a bucket_String
	void Bucket::destroyAll()
	{
		// if the child is not null, traverse down the chain and delete from bottom up
		if (child!=NULL)
		{
			child->destroyAll();
		}
		delete child;
	}

}
