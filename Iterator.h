#ifndef _ITERATOR_H_
#define _ITERATOR_H_

namespace BRNDAN022{

	class iterator{
		private:
			//default constructor (must be private)
			iterator(void);

		public:

			//char *operator ();
			//prefix
			iterator & operator++ ();
			//postfix
			iterator operator++(int);

			//prefix
			iterator & operator-- ();
			//postfix
			iterator operator--(int);

	};

}


#endif