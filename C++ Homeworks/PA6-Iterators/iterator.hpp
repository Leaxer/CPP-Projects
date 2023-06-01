#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>
#include <memory>
#include <cstddef>
#include <algorithm>

using namespace std;

namespace IteratorSpace {
    template<class T>
	class Iterator
	{
        public:
            using value_type = T;
            // using difference_type = std::ptrdiff_t;
            using difference_type = T;
            using pointer = T*;
            using reference = T&;
            using iterator_category = std::random_access_iterator_tag;
	    public:
            Iterator();
            Iterator(T* ptr);
            Iterator(shared_ptr<T> ptr);
            Iterator& operator =(const Iterator& secondI);/*set ptrArr to parameter's ptrArr's address*/
            Iterator& operator =(T* ptr) {ptrArr = ptr;return *this;}/*set ptrArr to parameter's ptrArr's address*/
            bool operator ==(const Iterator& secondI) const;/*check Iterators are equal*/
            bool operator !=(const Iterator& secondI) const;
            Iterator operator +(const int& num);/*increase ptrArr's address*/
            Iterator& operator ++();/*increase one ptrArr's address*/
            Iterator operator ++(int);
            difference_type operator-(const Iterator<T> rawIterator) {return std::distance(ptrArr,rawIterator.ptrArr);}
            Iterator operator -(const int& num);/*decrease ptrArr's address*/
            Iterator& operator --();/*decrease one ptrArr's address*/
            Iterator operator --(int);
            T& operator *();/*ptrArr's value*/
            T* operator ->();
            T* getPtr() const {return ptrArr;};
            void setAddress(shared_ptr<T> obj) {ptrArr = obj.get();}/*set ptrArr's address*/
	    private:
	        T* ptrArr;
	};
}

#endif