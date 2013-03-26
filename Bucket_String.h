#ifndef _BUCKET_LINE_H_
#define _BUCKET_LINE_H_

#include "Iterator.h"
#include "Bucket.h"

namespace BRNDAN022
{
	class Bucket_String 
	{
	private: 
		friend class Iterator;
		int nOfBuckets;
		Bucket * Head;
	public:
		Bucket_String(void);
		//Return iterator pointing at the first character of the string
		Iterator begin();
		//return an iterator pointing one location past the last string character
		Iterator end();

		/*
		*Operator Overrides
		*/

	};
}

#endif