#include<exception>

template<typename T>
class Array
{
public:
    //default constructor creates an array with default size
    //elements are zero initialized
    Array();

    //this constructor creates an array whose size equals the argument of the constructor 
    //elements are zero initialized
    Array(size_t);

    //this constructor creates an array whose size equals the first argument of the constructor
    //and the values of the array elements equal to the second argument
    Array(size_t, T);

    //this operator returns or sets an arrays element at given position which is the parameter for this operator
    T& operator[] (size_t);

    //this method returns the size of the array
    size_t getSize() const;

private:
    //pointer pointing to the array
    T* pointer = nullptr;

    //helper method for memory allocation
    //allocates memory for an array 
    //elements are zero initialized 
    void memoryAlloc (size_t);

    //size of the array
    size_t size;

    //default size of the array created by default constructor
    static const size_t defaultSize = 100;
};

template<typename T>
Array<T>::Array()
{
    size = defaultSize;
    memoryAlloc(size);
}

template<typename T>
Array<T>::Array(size_t s)
{
    size = s;
    memoryAlloc(s);
}

template<typename T>
Array<T>::Array(size_t s, T value)
{
    size = s;
    pointer = new T[s];
    
    for(size_t i = 0; i < s; i++)
        pointer[i] = value;
    
}

template<typename T>
void Array<T>::memoryAlloc(size_t s)
{
    pointer = new T[s] {}; 
}

template<typename T>
size_t Array<T>::getSize() const
{
    return size;
}

template<typename T>
T& Array<T>::operator[](size_t index)
{
    if(index >= size)
        throw std::out_of_range("");

    return pointer[index];
}


