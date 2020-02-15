#include"Stack.h"

Stack::Stack(){
    _max_elem_num = 100;
};

Stack::~Stack(){

}

bool Stack::push(const std::string& elem){
    if(full()){
        return false;
    }

    else{
        _stack.push_back(elem);
        return true;
    }
};
bool Stack::pop(std::string &elem){
    if(empty()){
        return false;
    }
    else{
        _stack.pop_back();
    }
};
bool Stack::peek(std::string $elem){
    if(empty()){
        return false;
    }
    else{
        return true;
    }
    
};

bool Stack::empty(){
    if(size() == 0){
        return true;
    }
    else{
        return false;
    }
};
bool Stack::full(){
    if(size() == _max_elem_num){
        return true;
    }
    else
    {
        return false;
    }
    
};

