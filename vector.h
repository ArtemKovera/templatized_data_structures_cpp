
/*
  
  !!!This templatized class works in a different way than the vector in STL!!!

*/

#include<exception>
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
    
    //inserts a new element at the end of a vector
    void pushBack(T);
    
    //returns the number of allocated members
    size_t getCapacity() const;

    //changes the size of a vector
    void resize(size_t)
    
    //this method returns true if the vector is empty and false otherwise
    bool isEmpty() const;

    //returns the number of vector elements
    size_t getSize() const;

    //this operator sets or returns an element of a vector
    T& operator[](size_t);
    
    //this operator works with const objects
    const T& operator[](size_t) const;

    //returns the first element of a vector
    const T& front() const;

    //returns the last element of a vector
    const T& back() const;

private:
    //pointer pointing to a vector
    T* pointer = nullptr;
    
    //helper method for memory allocation
    void allocateMemory(size_t);

    //the number of vector elements
    size_t size;

    size_t numberOfAllocatedMembers;

    //default number of allocated members
    static const size_t defaultNumberOfAllocatedMembers = 100;

    //helper method for freeing memory
    void clean() noexcept;
};

template<typename T>
Vector<T>::Vector(): size{0}, numberOfAllocatedMembers{defaultNumberOfAllocatedMembers}
{
    allocateMemory(defaultNumberOfAllocatedMembers);
}

template<typename T>
Vector<T>::Vector(size_t s): size{0}, numberOfAllocatedMembers{s}
{
    allocateMemory(s);
}

template<typename T>
Vector<T>::Vector(size_t s, T val): size{s}, numberOfAllocatedMembers{s}
{
    pointer = new T[s] {val};
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> args): size{args.size()}, numberOfAllocatedMembers{args.size()}
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
void Vector<T>::allocateMemory(size_t s)
{
    pointer = new T[s];
}
