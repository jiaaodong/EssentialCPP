#ifndef NUM_SEQUENCE_H
#define NUM_SEQUENCE_H
#include<iostream>
class num_sequence
{

public:
    virtual int elem(int pos) const = 0;
    void gen_elems(int pos);
    virtual const char* what_am_i() const = 0;
    std::ostream& print(std::ostream &os=std::cout) const;
    bool check_integrity(int pos);
    static int max_elems();
    virtual ~num_sequence();
};



#endif