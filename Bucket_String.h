#ifndef _BUCKET_LINE_H_
#define _BUCKET_LINE_H_

#include "Iterator.h"
#include "Bucket.h"
#include <ostream>
#include <istream>

namespace BRNDAN022
{
	class Bucket_String 
	{
	private: 
		friend class iterator;

		friend std::size_t length();

		friend std::ostream & operator<<(std::ostream & os, const Bucket_String & bs)
		{

		};
		friend std::istream & operator>>(Bucket_String & bs, std::istream & is)
		{
			while (!is.eof())
			{
				char temp;
				is>>temp;
				
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
	public:
		//default constructor
		Bucket_String(void);
		//constructed with specified size;
		Bucket_String(int bucketSize_);
		//Return iterator pointing at the first character of the string
		iterator begin();
		//return an iterator pointing one location past the last string character
		iterator end();



	//Operator overrides
		char & operator [](int index);

		void replace(iterator first, iterator last, Bucket_String bs);

		void insert(iterator first, Bucket_String bs);

		Bucket_String substr(iterator first, iterator last);
	};
}

#endif