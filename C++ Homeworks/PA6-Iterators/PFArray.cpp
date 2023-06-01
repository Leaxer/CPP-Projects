#include "PFArray.hpp"

namespace IteratorSpace {
	template<class T>
	PFArray<T>::PFArray() {
		//control for memory allocating
		try
		{
			arrSize = new int;
		}
		catch(bad_alloc &e){
			cout << "Memory couldn't allocate";
		}
		*arrSize = 0;
	}

	template<class T>
	PFArray<T>::PFArray(const int &iSize) {
		//control for memory allocating
		try
		{
			arrSize = new int;
		}
		catch(bad_alloc &e){
			cout << "Memory couldn't allocate";
		}
		*arrSize = iSize;
		//set sPtr to new sharedPtr
		shared_ptr<T> temp(new T[*arrSize]);
		sPtr = temp;
	}

	template<class T>
	PFArray<T>::PFArray(const PFArray<T>& copyObj) {
		//control for memory allocating
		try
		{
			arrSize = new int;
		}
		catch(bad_alloc &e){
			cout << "Memory couldn't allocate";
		}
		*arrSize = copyObj.size();
		//set sPtr to new sharedPtr
		shared_ptr<T> temp(new T[*arrSize]);
		sPtr = temp;
		for(auto i = 0;i < *arrSize;++i)
			sPtr.get()[i] = copyObj.sPtr.get()[i];
	}

	template<class T>
	PFArray<T>::PFArray(PFArray<T>&& copyObj) {
		sPtr = move(copyObj.sPtr)
		*arrSize = copyObj.size();
	}

	template <class T>
    PFArray<T>& PFArray<T>::operator=(PFArray<T> && newP)
    {
        if (this != &newP)
            this->sPtr = move(newP.sPtr); 
		*arrSize = newP.size();
        return *this;
    }

	template<class T>
	bool PFArray<T>::empty() const{
		if(*arrSize == 0) return true;
		return false;
	}

	template<class T>
	int PFArray<T>::size() const{
		return *arrSize;
	}

	template<class T>
	void PFArray<T>::erase(const Iterator<T> &it) {
		int* j = new int;
		if(*arrSize <= 0) throw "invalid size";
		*j = 0;
		//get temp shared_ptr
		shared_ptr<T> temp(new T[*arrSize]);
		// //control each address if they equal don't add this address's value to temp ptr
		for(auto i = sPtr.get();i != sPtr.get() + *arrSize;++i) {
			if(i != it.getPtr()) {
				temp.get()[*j] = *i;
				++*j;
			}
		}
		//set sPtr's address
		sPtr = temp;
		--*arrSize;
		delete j;
	}

	template<class T>
	void PFArray<T>::clear() {
		//control if sPtr is null
		if(sPtr == nullptr) {
			throw runtime_error("Container is already empty");
		}
		sPtr = nullptr;
		*arrSize = 0;
	}

	template<class T>
	T* PFArray<T>::begin() {
		return sPtr.get();
	}

	template<class T>
	T* PFArray<T>::end() {
		// Iterator<T> temp;
		// temp.setAddress(sPtr);
		// temp = temp + *arrSize;
		// return temp;
		return sPtr.get() + *arrSize;
	}

	template<class T>
	const T* PFArray<T>::cbegin() {
		return sPtr.get();
	}
	template<class T>
	const T* PFArray<T>::cend() {
		// Iterator<T> temp;
		// temp.setAddress(sPtr);
		// temp = temp + *arrSize;
		// return temp;
		return sPtr.get() + *arrSize;
	}


	template<class T>
	void PFArray<T>::add(const T& element) {
		try
		{
			if(*arrSize < 0) throw *arrSize;
		}
		catch(const int &e){
			cout << "Size: " << e << endl << "Not enough size";
		}
		++(*arrSize);
		//set old values to new shared ptr
		shared_ptr<T> temp(new T[*arrSize]);
		for(auto i = 0;i < *arrSize - 1;++i) temp.get()[i] = sPtr.get()[i];
		temp.get()[*arrSize - 1] = element;
		//change sPtr's address
		sPtr = temp;
	}

	template<class T>
	PFArray<T>::~PFArray(){
		delete arrSize;
	}
}