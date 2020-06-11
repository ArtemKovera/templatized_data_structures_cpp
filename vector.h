
/*
  
  !!! This templatized class works in a different way than the vector in STL !!!

*/

#ifndef _VECTOR_H_
#define _VECTOR_H_

#include<stdexcept>
#include<initializer_list>

template<typename T>
class Vector
{
public:
    //default constructor creates a vector with default number of allocated members
    Vector(); 
    
    //this constructor creates a vector whose number of allocated members equals to the argument of the constructor
    Vector(size_t);

    //this constructor creates a vector whose number of allocated members equals to the first argument of the constructor
    //and the values of the elements equal to the second argument
    Vector(size_t, T);

    //initializer-list constructor taking variable number of arguments
    Vector(std::initializer_list<T>);

    virtual ~Vector();

    Vector(const Vector&) = delete;

    Vector& operator=(const Vector&) = delete;

    Vector(Vector&&);

    Vector& operator=(Vector&&);
    
    //inserts a new element at the end of a vector
    void pushBack(T);
    
    //returns the number of allocated members
    size_t getCapacity() const;
    
    //this method returns true if the vector is empty and false otherwise
    bool isEmpty() const;

    //this method returns true if the vector is full and false otherwise
    bool isFull() const;

    //returns the number of vector elements
    size_t getSize() const;

    //this operator sets or returns an element of a vector
    //if the vector is empty or the argument is equal or greater than the size, it throws out_of_range exception
    T& operator[](size_t);
    
    //this operator works with const objects
    //if the vector is empty or the argument is equal or greater than the size, it throws out_of_range exception
    const T& operator[](size_t) const;

    //returns the first element of a vector
    //if the vector is empty, it throws out_of_range exception
    const T& front() const;

    //returns the last element of a vector
    //if the vector is empty, it throws out_of_range exception
    const T& back() const;

    //this method sets the number of allocated members that equals to the argument of this method
    //if the argument is less than the current size, it throws the invalid_argument exception
    void reserve(size_t); 

private:
    //pointer pointing to a vector
    T* pointer = nullptr;
    
    //the number of vector elements
    size_t size;

    size_t numberOfAllocatedMembers;

    //default number of allocated members
    static const size_t defaultNumberOfAllocatedMembers = 100;

    //helper method for freeing memory
    void clean(T*) noexcept;

    //changes the size of a vector
    void resize(size_t);

    //helper method for memory allocation
    void allocateMemory(size_t);   

    //helper method used in move constructor and assignment operator
    void moveFrom(Vector&) noexcept;     
};

template<typename T>
Vector<T>::Vector(): size{0}
{
    allocateMemory(defaultNumberOfAllocatedMembers);
}

template<typename T>
Vector<T>::Vector(size_t s): size{0}
{
    allocateMemory(s);
}

template<typename T>
Vector<T>::Vector(size_t s, T val): size{s}, numberOfAllocatedMembers{s}
{
    pointer = new T[s] {val};
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> args): size{args.size()}
{
    allocateMemory(args.size());
    
    size_t i = 0;
    for(auto el : args)
    {
        pointer[i] = el;
        i++;
    }   
}

template<typename T>
Vector<T>::Vector(Vector&& src) noexcept
{
    moveFrom(src);
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector&& src) noexcept
{
    if(this == &src)
        return *this;

    clean(pointer);
    moveFrom(src);
    return *this;
}

template<typename T>
Vector<T>::~Vector()
{
    clean(pointer);
}

template<typename T>
void Vector<T>::allocateMemory(size_t s)
{
    pointer = new T[s];
    numberOfAllocatedMembers = s;
}

template<typename T>
void Vector<T>::pushBack(T val)
{
    if(size < (numberOfAllocatedMembers - 1))
    {
        pointer[size] = val;
        size++;
    }
    else
    {
        resize(numberOfAllocatedMembers + 10);
        pointer[size] = val;
        size++;
    }
}

template<typename T>
void Vector<T>::resize(size_t s)
{
    T* ptr = pointer;
    allocateMemory(s);
    for(size_t i = 0; i<size; i++)
        pointer[i] = ptr[i];
    clean(ptr);
}

template<typename T>
void Vector<T>::clean(T* ptr) noexcept
{
    delete [] ptr;
    ptr = nullptr;
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
    return numberOfAllocatedMembers;
}

template<typename T>
size_t Vector<T>::getSize() const
{
    return size;
}

template<typename T>
const T& Vector<T>::front() const
{
    if(size == 0)
        throw std::out_of_range("The vector is empty");

    return pointer[0];
}

template<typename T>
const T& Vector<T>::back() const
{
    if(size == 0)
        throw std::out_of_range("The vector is empty");

    return pointer[size-1];    
}

template<typename T>
void Vector<T>::reserve(size_t s)
{
    if(s == size)
        return;
    
    if(s < size)
        throw std::invalid_argument("The size to reserve must not be less than the current size");

    T* ptr = pointer;   
    allocateMemory(s);
    for(size_t i = 0; i < size; i++)
        pointer[i] = ptr[i];

    clean(ptr);
}

template<typename T>
bool Vector<T>::isEmpty() const
{
    if(size == 0)
        return true;
    else
        return false;
}

template<typename T>
bool Vector<T>::isFull() const
{
    if(size == numberOfAllocatedMembers)
        return true;
    else
        return false;
}

template<typename T>
T& Vector<T>::operator[](size_t index)
{
    if(size == 0 || index >= size)
        throw std::out_of_range("Invalid index");
    
    return pointer[index];
}

template<typename T>
const T& Vector<T>::operator[](size_t index) const
{
    if(size == 0 || index >= size)
        throw std::out_of_range("Invalid index"); 

    return pointer[index];
}

template<typename T>
void Vector<T>::moveFrom(Vector& src) noexcept
{
    size = src.size;
    numberOfAllocatedMembers = src.numberOfAllocatedMembers;
    pointer = src.pointer;

    src.size = 0;
    src.numberOfAllocatedMembers = 0;
    src.pointer = nullptr;
}

#endif

