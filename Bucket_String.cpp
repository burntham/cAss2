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
	Bucket * firstBuck;
	int charCount;

	//Default constructor - not currently used for anything...
	Bucket_String::Bucket_String(void):firstBuck(NULL),nOfBuckets(0),BucketSize(0),charCount(0)
	{

	};

	//Construct the bucket string with a specifed bucket size;
	Bucket_String::Bucket_String(int bucketSize_):nOfBuckets(0), BucketSize(bucketSize_), firstBuck(new Bucket(bucketSize_)),charCount(0)
	{
		//std::cout<<"bucketString constructed"<<BucketSize<<std::endl;
	};

	//Copy Constructor - working
	Bucket_String::Bucket_String(const Bucket_String & rhs):nOfBuckets(0), BucketSize(rhs.BucketSize), firstBuck(NULL),charCount(0)
	{
		//Copy the first Bucket
		firstBuck = new Bucket(*(rhs.firstBuck));

		//Copy the rest down the chain!
		if (rhs.firstBuck->child !=NULL)
		{	
			Bucket * copyFrom = rhs.firstBuck->child;
			Bucket * copyTo = firstBuck;
			copyTo->child = new Bucket(*(rhs.firstBuck->child));
			


			while (copyFrom->child!=NULL)
			{
				copyFrom = copyFrom->child;
				copyTo = copyTo->child;
				copyTo->child = new Bucket(*copyFrom);
				//this was needed before to make sure it didn't go too far
				if (copyFrom->child==NULL){
					break;
				}
			}
		}
		

	}

	//Called by the >> operator! - adds new characters to the end of the buckets (or creating new ones if they are full)
	void Bucket_String::addChar(char c)
	{
		firstBuck->addChar(c);
		++charCount;
	}

	//Return iterator pointing at the first character of the string
	iterator Bucket_String::begin()
	{
		iterator test(0, this);
		return test;
	}
	//return an iterator pointing one location past the last string character
	iterator Bucket_String::end()
	{
		//Create an iterator which points to the next address in memory (after the last character)
		iterator test(charCount, this);
		return test;
	}

	void Bucket_String::destroyAll(){
		firstBuck->destroyAll();
	}

///Not sure how to do this:
	void Bucket_String::insert(iterator first, Bucket_String bs)
	{

	};
	
///////////////Iterator class//////////////////////////////////////////////:::

	char * charPTR;

	//default constructor
	iterator::iterator(void):charPTR(NULL),index(0),iteratableString(NULL)
	{
	};

	iterator::iterator(int index_,Bucket_String * bs):charPTR(NULL),index(0),iteratableString(NULL)
	{		
		iteratableString = bs;
		//std::cout<<(*bs)[5]<<"WHAT IS GOING ON!";
			index=index_;
			int bucketIndex = (int)(index/(iteratableString->BucketSize));
			int contentIndex = index - ((iteratableString->BucketSize)*(bucketIndex));

			if (index<(bs->BucketSize)){
				charPTR= &(iteratableString->firstBuck->content[index]);
				//std::cout<<"what should be there?"<<bs->firstBuck->content[index]<<std::endl;
			}
			else{
					Bucket * BucketPew =iteratableString->firstBuck;	
				for (int i = 0; i < bucketIndex; ++i)
				{
					BucketPew = BucketPew->child;
				}
				charPTR= &(BucketPew->content[contentIndex]);
			}
			//std::cout<<*charPTR<<std::endl;
	};

	//Copy Constructor
	iterator::iterator(const iterator & rhs):charPTR(rhs.charPTR), index(rhs.index)
	{
	};

	
}
