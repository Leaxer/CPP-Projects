#include <iostream>
#include "iterator.hpp"
#include "iterator.cpp"
#include "PFArray.hpp"
#include "PFArray.cpp"

using namespace IteratorSpace;

int main() {
    PFArray<int> arr; 
    arr.add(2);
    arr.add(6);
    arr.add(3);
    arr.add(9);
    arr.add(8);
    Iterator<int> it;
    cout << "Size: " << arr.size() << endl;
    for (it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << endl;
    }
    if(arr.empty()) cout << "Empty" << endl;
    else cout << "Not empty" << endl;
    cout << "---------for_each----------" << endl;
    std::for_each(arr.begin(), arr.end(), [](int x)
            { cout << x << " "; });
    cout << endl;
    cout << "----------find----------" << endl;
    cout << "Searching for 9" << endl;
    auto f = std::find(arr.begin(), arr.end(), 9);
    if (f != arr.end())
        cout << *f << " found in array" << endl;
    else cout << "Couldn't find" << endl;
    cout << "Searching for 10" << endl;
    auto f1 = std::find(arr.begin(), arr.end(), 10);
    if (f1 != arr.end())
        cout << *f1 << " found in array" << endl;
    else cout << "Couldn't find" << endl;
    cout << endl;
    cout << "--------clear------------" << endl;
    arr.clear();
    cout << "Size: " << arr.size() << endl;
    if(arr.empty()) cout << "Empty" << endl;
    else cout << "Not empty" << endl;
    cout << "--------adding new values------------" << endl;
    arr.add(8);
    arr.add(8);
    arr.add(16);
    arr.add(3);
    arr.add(4);
    arr.add(5);
    arr.add(10);
    for (it = arr.begin(); it != arr.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "--------move function------------" << endl;
    cout << "arr1 = move(arr)" << endl;
    cout << "arr1: " << endl;
    PFArray<int> arr1;
    arr1 = move(arr);
    for (it = arr1.begin(); it != arr1.end(); ++it) {
        cout << *it << endl;
    }
    cout << "--------erase function------------" << endl;
    cout << "Erasing forth element" << endl;
    it = arr1.begin();
    arr1.erase(it + 3);
    for (it = arr1.begin(); it != arr1.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "--------sort function------------" << endl;
    std::sort(arr1.begin(),arr1.end());
    cout << "After sorting.." << endl;
    for (it = arr1.begin(); it != arr1.end(); ++it)
        cout << *it << endl;
    cout << "Size: " << arr1.size() << endl;
    if(arr1.empty()) cout << "Empty" << endl;
    else cout << "Not empty" << endl;
    cout << "--------clear again------------" << endl;
    arr1.clear();
    cout << "Size: " << arr1.size() << endl;
    if(arr1.empty()) cout << "Empty" << endl;
    cout << "--------exception test------------" << endl;
    try
    {
        arr1.erase(it + 2);
    }
    catch (const char *ex)
    {
        cout << "Exception caught: " << ex << endl;
    }
    return 0;
}