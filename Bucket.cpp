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

	//Consturctors
	Bucket::Bucket(Bucket * daddy, int arSize):content(new char[arSize])
	{	
		Head = daddy;

	}

	Bucket::Bucket(int arrSize):content(new char[arrSize])
	{	std::cout<<"Bucket Constructed"<<std::endl;
	  	for (int i = 0; i < 5; ++i)
	  	{
	  		content[i] = 'a';
	  	}
	}

	//invoked through >>
	void Bucket::addChar(char c){

	}
}
