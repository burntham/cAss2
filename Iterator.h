#ifndef _ITERATOR_H_
#define _ITERATOR_H_

#include "Bucket.h"

namespace BRNDAN022{

	class iterator{
			friend class Bucket_String;
			friend class Bucket;
			
		private:
			
			//default constructor (must be private)
			
		public:
			iterator(void);		
		
			iterator(int index_);
			int index;
			//char *operator ();
			//prefix
			iterator & operator++ ();
			//postfix
			iterator operator++(int);

			//prefix
			iterator & operator-- ();
			//postfix
			iterator operator--(int);

			//*prt (dereference pointer)
			const char * operator*(void){
			};
			

	};

}


#endif