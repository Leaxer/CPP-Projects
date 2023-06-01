#ifndef PFArray_HPP
#define PFArray_HPP

#include "iterator.hpp"

namespace IteratorSpace {
	template<class T>
	class PFArray {
		public:
			using value_type = T;
            using difference_type = std::ptrdiff_t;
		public:
			//Constructors
			PFArray();
			PFArray(const int &iSize);
            PFArray(const PFArray<T>& copyObj);
			PFArray(PFArray<T>&& copyObj);
			~PFArray();
			bool empty() const;/*Test whether container is empty*/
			int size() const;/*Return container size */
			void erase(const Iterator<T> &it);/*Erase element pointed by the given Iterator*/
			void clear();/*Clear all content */
			T* begin();/*Return Iterator to beginning */
			T* end();/*Return Iterator to end */
			const T* cbegin();/*Return a constant Iterator to beginning */
			const T* cend();/*Return a constant Iterator to end */
			void add(const T& element);/*add element to shared_ptr*/
			PFArray& operator=(PFArray<T> && newP);
		private:
			shared_ptr<T> sPtr;
			int* arrSize;
	};
}

#endif