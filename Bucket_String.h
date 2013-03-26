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
		friend std::ostream & operator<<(std::ostream & os, const Bucket_String & bs);
		friend std::istream & operator>>(const Bucket_String & bs, std::istream & is);

		int nOfBuckets;
	public:
		Bucket_String(void);
		//Return iterator pointing at the first character of the string
		iterator begin();
		//return an iterator pointing one location past the last string character
		iterator end();

		/*
		*Operator Overrides
		*/
		friend std::ostream & operator<<(std::ostream & os, const Bucket_String & bs)
		{
			return os;
		};
		friend std::istream & operator>>(const Bucket_String & bs, std::istream & is)
		{
			return is;
		};

		char & operator [](int index)
		{
			char * ptr = new char[5];
			char & ref = *ptr;
			return ref;
		}	

		replace(iterator first, iterator last, Bucket_String bs)
		{

		}

		insert(iterator first, Bucket_String bs)
		{

		}

		Bucket_String substr(iterator first, iterator last)
		{
			Bucket_String buck;
			return buck;
		}


	};
}

#endif