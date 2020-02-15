
#ifndef stack_H
#define stack_H
#include<vector>
#include<string>
class Stack
{
private:
    /* data */
    std::vector<std::string> _stack;
    int _max_elem_num;
public:
    Stack(/* args */);
    ~Stack();
    
    bool push(const std::string&);
    bool pop(std::string &elem);
    bool peek(std::string $elem);

    bool empty();
    bool full();

    int size(){return _stack.size();}
};



#endif