
#ifndef Triangular_iterator_H
#define Triangular_iterator_H
#include<vector>
#include<algorithm>
#include<iostream>

class Triangular_iterator
{
private:
    /* data */
    int _index;
    void check_integrity() const;
public:
    Triangular_iterator(int index): _index(index - 1){{}}; // why minus 1 ?
    ~Triangular_iterator();
    bool operator==(const Triangular_iterator&) const;
    bool operator!=(const Triangular_iterator&) const;
    int operator*() const;
    Triangular_iterator& operator++(); // Prefix
    Triangular_iterator operator++(int); // Postfix
};



#endif