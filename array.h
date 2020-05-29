
template<typename T>
class Array
{
public:
    //default constructor creates an array with default size
    Array();

    //this constructor creates an array whose size equals the parameter for the constructor 
    Array(size_t);

    //this operator returns or sets an arrays element at given position which is the parameter for this operator
    T& operator[] (size_t);

    //this method returns the size of the array
    size_t getSize() const;

private:
    //pointer pointing to the array
    T* pointer = nullptr;

    //helper method for memory allocation 
    void memoryAlloc (size_t );

    //size of the array
    size_t size;

    //default size of the array created by default constructor
    static const size_t defaultSize = 100;
};

