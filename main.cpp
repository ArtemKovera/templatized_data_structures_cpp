 //demonstrating the work of vactor.h and array.h
 
 #include <iostream>
 #include<utility>
 #include "array.h"
 #include "vector.h"
 

int main ()
{
    
    Array<int> arr1;
    std::cout << "the size of arr1 " << arr1.getSize() << std::endl;

    Array<int> arr2(20);
    std::cout << "the size of arr2 " << arr2.getSize() << std::endl;

    Array<int> arr3(10, 10);
    std::cout << "the size of arr3 " << arr3.getSize() << std::endl;

    std::cout << "arr3[0] = " << arr3[0] << std::endl;
    arr3[1] = 25;
    std::cout << "arr3[1] = " << arr3[1] << std::endl;

    const Array<int> arr4(10, 20);
    std::cout << "arr4[1] = " << arr4[1] << std::endl;  

    Array<int> arr5(30, 100);

    arr3 = std::move(arr5);
    std::cout << "arr3 after reassining has " << arr3.getSize() << " elements" << std::endl;
    std::cout << "arr3[10] = " << arr3[10] << std::endl;
    std::cout << std::endl;

    Array<int> arr6{1, 2, 3, 4, 5, 6, 7};
    std::cout << "arr6 has " << arr6.getSize() << " elements" << std::endl;
    std::cout << "arr6[3] has " << arr6[3] << " | arr6[4] = " << arr6[4] << std::endl;
    Array<int> arr7(arr6);
    std::cout << "arr7 has " << arr7.getSize() << " elements" << std::endl;
    std::cout << "arr7[3] has " << arr7[3] << " | arr7[4] = " << arr7[4] << std::endl; 
    arr7 = arr2;
    std::cout << "arr7 has " << arr7.getSize() << " elements" << std::endl;
    std::cout << "arr7[3] has " << arr7[3] << " | arr7[4] = " << arr7[4] << std::endl;
    std::cout<<std::endl;

    std::cout << "---------------------------------" << std::endl;
    std::cout<<std::endl;
     

    Vector<int> vec1(10);

    vec1.pushBack(1);
    vec1.pushBack(2);
    vec1.pushBack(3);

    std::cout<<"The size of vec1 is " << vec1.getSize() << std::endl;
    std::cout<<"The capacity of vec1 is " << vec1.getCapacity() << std::endl;
    std::cout<<"vec1[0]: "<< vec1[0]<<std::endl;
    std::cout<<"vec1[1]: "<< vec1[1]<<std::endl;
    std::cout<<"vec1[2]: "<< vec1[2]<<std::endl;

    vec1.reserve(20);
    std::cout<<"The size of vec1 is " << vec1.getSize() << std::endl;
    std::cout<<"But now the capacity of vec1 is " << vec1.getCapacity() << std::endl;
    std::cout<<"vec1[0]: "<< vec1[0]<<std::endl;
    std::cout<<"vec1[1]: "<< vec1[1]<<std::endl;
    std::cout<<"vec1[2]: "<< vec1[2]<<std::endl;
    std::cout << std::endl;

    Vector<int> vec2;
    vec2.pushBack(233);
    vec2.pushBack(456);
    vec2.pushBack(4789);

    Vector<int> vec3 = std::move(vec2);
    std::cout<<"The size of vec3 is " << vec3.getSize() << std::endl;
    std::cout<<"The capacity of vec3 is " << vec3.getCapacity() << std::endl;
    std::cout<<"vec3[0]: "<< vec3[0]<<std::endl;
    std::cout<<"vec3[1]: "<< vec3[1]<<std::endl;
    std::cout<<"vec3[2]: "<< vec3[2]<<std::endl;
    std::cout << std::endl;

    Vector<int> vec4(vec3);
    std::cout<<"The size of vec4 is " << vec4.getSize() << std::endl;
    std::cout<<"The capacity of vec4 is " << vec4.getCapacity() << std::endl;
    std::cout<<"vec4[0]: "<< vec4[0]<<std::endl;
    std::cout<<"vec4[1]: "<< vec4[1]<<std::endl;
    std::cout<<"vec4[2]: "<< vec4[2]<<std::endl;
    std::cout << std::endl;
    
    Vector<int> vec5(10);
    vec5.pushBack(98);
    vec5.pushBack(99);
    vec5.pushBack(100);
    vec5.pushBack(101);
    vec5.pushBack(102); 
    vec4 = vec5;   
    std::cout<<"Now the size of vec4 is " << vec4.getSize() << std::endl;
    std::cout<<"And the capacity of vec4 is " << vec4.getCapacity() << std::endl;
    std::cout<<"now vec4[0]: "<< vec4[0]<<std::endl;
    std::cout<<"now vec4[1]: "<< vec4[1]<<std::endl;
    std::cout<<"now vec4[2]: "<< vec4[2]<<std::endl; 

    return 0; 
}