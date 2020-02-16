# The Notes and Exercises of <Essential CPP>

## Chapter 1 
## Chapter 2 
The pointer to const value does not really influence the value change of the pointed variable, but if changing the pointed variable by dereferencing the pointer, CPP does not allow to.

## Chapter 3
STD is made by two parts: 1. Containers 2. Generic Algorithms

Generic Algorithms:
    
    1. Generic from data type:

        By function template

    2. Generic from container type:

        By defining Iterator 

Container has two types: 

    1. consecutive containers.

        vector, list

    2. linked containers

        map:

            Check key-value

        set:

            Check availability

Map Container:

    Three ways to check one key:

        1) Use key as index <-- Not recommended
        
        2) Use map::iterator map::find()

        3) Use map::count

Set Container: 

    Use `insert` to add new elements.

## Chapter 4 Object-based Programming

Class has two parts. The private parts are details users don't need to know, while public components are interface for end users.

Private members can be accessed only inside class member functions and friend classes.

### File Organization

The decalaration of a class is in header file "Stack.h". This header file contains `#ifndefine` `#define` `#endif` macro to avoid repeatedly including header files. If the header file needs other libraries, such as vector/string, `#include<vector>` and `#include<string>` are also needed.

The implementation of a class is in cpp file "Stack.cpp". This file defines implementation by using namespace of the class (putting `Stack::` before any member function).

The main function just needs to include header file. The library that contains implementation of `Stack` is compiled by `Stack.cpp` and linked with main function. To accomplish this linking, in CMakeLists.txt add_executable() the cpp file `Stack.cpp` should also be specified. However, if Stack is already compiled into a library, it can be added by `link_directories` (now deprecated) or `target_link_libraries`.

## Data member initialization is default choice
When making a new class (especially when making its constructor), the programmer should consider whether default member data initialization does fulfill the purpose. If not, the copy constructor should be defined to override.

The copy constructor:
```c++
Matrix::Matrix(const Matrix& rhs)
```

When using equality sign for initialization, the constructor would be invoked, rather than the assignment operator override.

__Complaints: different parts of one program is disposed everywhere in a chapter__
__Complaints: There is no clear functionality definitions of one class at the very begining of a chapter. The functionality evolvs according to the knowledge__

Two pitfalls:
1. Cross-file mutrually include
2. inline function cannot be compiled from different source files


