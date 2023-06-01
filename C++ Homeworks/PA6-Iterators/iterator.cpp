#include "iterator.hpp"

namespace IteratorSpace {
    template<class T>
	Iterator<T>::Iterator(){
        ptrArr = nullptr;
    }

    template<class T>
	Iterator<T>::Iterator(T* ptr) {
        ptrArr = ptr;
    }

    template<class T>
	Iterator<T>::Iterator(shared_ptr<T> ptr) {
        ptrArr = ptr.get();
    }

    template<class T>
	Iterator<T>& Iterator<T>::operator =(const Iterator& secondI) {
        ptrArr = secondI.ptrArr;
        return *this;
    }

    template<class T>
	bool Iterator<T>::operator ==(const Iterator& secondI) const{
        if(ptrArr == secondI.ptrArr) return true;
        return false;
    }

    template<class T>
	bool Iterator<T>::operator !=(const Iterator& secondI) const{
        if(ptrArr == secondI.ptrArr) return false;
        return true;
    }

    template<class T>
	Iterator<T>& Iterator<T>::operator ++(){
        ++ptrArr;
        return *this;
    }

    template<class T>
	Iterator<T> Iterator<T>::operator ++(int){
        auto temp = *this;
        ++ptrArr;
        return temp;
    }

    template<class T>
	Iterator<T>& Iterator<T>::operator --(){
        --ptrArr;
        return *this;
    }

    template<class T>
	Iterator<T> Iterator<T>::operator --(int){
        auto temp = *this;
        --ptrArr;
        return temp;
    }

    template<class T>
    Iterator<T> Iterator<T>::operator +(const int& num) {
        auto temp = ptrArr;
        ptrArr += num;
        auto temp1(*this);
        ptrArr = temp;
        return temp1;
    }

    template<class T>
    Iterator<T> Iterator<T>::operator -(const int& num) {
        auto temp = ptrArr;
        ptrArr -= num;
        auto temp1(*this);
        ptrArr = temp;
        return temp1;
    }

    template<class T>
    T& Iterator<T>::operator *() {
        return *ptrArr;
    }
    template<class T>
    T* Iterator<T>::operator ->() {
        return ptrArr;
    }
}