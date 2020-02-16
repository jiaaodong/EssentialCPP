
#ifndef Triangular_H
#define Triangular_H
#include<vector>
#include<algorithm>
#include<iostream>
#include"Triangular_iterator.h"
class Triangular
{
private:
    /* data */
    int _begin_pos; 
    int _length;
    mutable int _next;  // This value needs to be modified by some member functions defined by const, however modification of this value does not change the essence of the class, thus it is not considered as contradictory to const.
    static std::vector<int> _elems; 
    static const int _max_elems;
    // friend int Triangular_iterator::operator*() const;
    friend class Triangular_iterator;
    // friend void Triangular_iterator::check_integrity() const;

public:
    typedef Triangular_iterator iterator;
    Triangular(int len = 1, int bp = 1); 
    Triangular(const Triangular& rhs); // Member-wise initialization
    Triangular& copy(const Triangular & rhs); // TODO: Why using &? Does this mean returning a reference rather than returning the (copied) value, analogous to passing arguments by reference?
    ~Triangular();
    int length() const{return _length;}  // must be declared as const, otherwise when using const class object reference this function cannot be invoked
    // Defined inside decalaration -> inline
    bool next(int &val) const;
    void next_reset() const {_next = _begin_pos - 1;}
    int beg_pos() const{return _begin_pos;}
    static void gen_elements(int length);
    static void gen_elems_to_value(int value);
    static bool is_elem(int value); // Declared as static: can be used without initializing a class object
    Triangular_iterator begin() const{return Triangular_iterator(_begin_pos);} // Begin function for its iterator
    Triangular_iterator end() const{return Triangular_iterator(_begin_pos + _length);}
};

#endif