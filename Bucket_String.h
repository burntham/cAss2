#ifndef _BUCKET_STRING_H_
#define _BUCKET_STRING_H_

//#include "Iterator.h"
#include "Bucket.h"
#include <iostream>
#include "math.h"

namespace BRNDAN022
{	//iterator iter;
	class iterator;

	class Bucket_String
	{
	private: 
		friend class iterator;

		friend std::size_t length();

		//friend class Bucket;

		friend std::ostream & operator<<(std::ostream & os, const Bucket_String & bs)
		{
			Bucket * parent = bs.firstBuck;	
			Bucket * hasChild = bs.firstBuck->child;
					while(hasChild)
					{ 
						parent->outAll(os);
						parent = hasChild;
						hasChild = parent->child;
						//parent->outAll(os);
					}

					//return os;
				
				parent->outAll(os);
				return os;		
		};

		//input a string into the buckets
		friend std::istream & operator>>(std::istream & is, Bucket_String & bs)
		{			
			while (!is.eof())
			{	
				char temp ='a';
				is>>temp;	
				if (!is.eof()){
					bs.addChar(temp);
				//std::cout<<temp<<" added"<<std::endl;				
				}
				
			}

			return is;
		};
	//methods
		//Add a character to the Bucket_String
		void addChar(char c);
	//Variables/etc
		Bucket * firstBuck;
		int nOfBuckets;
		int BucketSize;
		int charCount;

	public:
		//default constructor
		Bucket_String(void);
		//constructed with specified size;
		Bucket_String(int bucketSize_);

		//Copy Constructor
		Bucket_String(const Bucket_String & rhs);

		//Return iterator pointing at the first character of the string
		iterator begin();
		//return an iterator pointing one location past the last string character
		iterator end();

		~Bucket_String()
		{
			destroyAll();
		}

		void destroyAll();

			//Operator overrides
		char & operator[] (int index){
			//char * charRef = NULL;
					int bucketIndex = (index/BucketSize);
					//std::cout<<"bucketIndex is "<<bucketIndex-1<<std::endl;
					int contentIndex = index - (BucketSize*(bucketIndex));
					//std::cout<<"contentIndex is "<<contentIndex-1<<std::endl;


					if (index<BucketSize){

						char * charRef= (char*)(&firstBuck->content[index]);
						return *charRef;
					}
					else{
							Bucket * BucketPew =firstBuck;	
						for (int i = 0; i < bucketIndex; ++i)
						{
							BucketPew = BucketPew->child;
						}
						char * charRef= (char*)(&BucketPew->content[contentIndex]);
						return *charRef;
					}

				};

		void replace(iterator first, iterator last, Bucket_String bs);

		void insert(iterator first, Bucket_String bs);

		Bucket_String substr(iterator first, iterator last);
	};

	class iterator{
			friend class Bucket_String;
			friend class Bucket;
			
		private:
			//default constructor (must be private)
			iterator(int index_,Bucket_String * bs);
			iterator(void);	
			Bucket_String * iteratableString;
			

			char * charPTR;
			int index;
			
		public:
			
			//copy constructor
			iterator(const iterator & rhs);
			//copy assignment operator
			iterator & operator=( iterator & rhs){
				return *this; // Return a reference to the existing object!
			};
			
			//char *operator ();
			//prefix WORKING ZOMG
			iterator & operator++ ()
			{
				++index;
				charPTR = &((*iteratableString)[index]);
				return *this;
				

			};
			//postfix			
			iterator operator++(int)
			{
				iterator temp = *this;
				++(*this);
				return temp;
			};

			
			//prefix
			iterator & operator-- ()
			{
				--index;
				charPTR = &((*iteratableString)[index]);
				return *this;

			};

			//postfix
			iterator operator--(int)
			{
				iterator temp = *this;
				--(*this);
				return temp;
			};

			//*prt (dereference pointer)
			 char operator*(void){
				 char  character  = *charPTR;
				return character;
			};
			
		~iterator(){
			//delete charPTR;
		}

	};

	
}

#endif