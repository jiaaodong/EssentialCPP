#include<iostream>
#include<limits>
#include<vector>
#include"utils.cpp"
using namespace std;
const vector<int>* fibo_seq(int size){
    const int max_size = 1024;
    static vector<int> elems; 
    if(size <= 0 || size > max_size){
        cerr<<"fibo_seq(): oops: invalid size:"
        <<size<<"-- can't fulfill request."<<endl;

        return 0;
    }
    

    
    for(int ix = elems.size(); ix<=size; ++ix){ // Attention: Fibonacci sequence starts from 3rd element;
        if(ix<=1){
            elems.push_back(1);
        }
        else elems.push_back(elems[ix-1] + elems[ix - 2]);
    }
    return &elems;
}

int main(int argc, char const *argv[])
{
    int pos;
    bool usr_exit = false;
    std::cout<<"The maximum value of a integer in this machine is: "<< std::numeric_limits<int>::max() <<std::endl;
    while(!usr_exit){
        std::cout<<"Please enter a position: ";
        std::cin>> pos;
        if(pos == -1){
            usr_exit = true;
        }
        display_vector(*fibo_seq(pos));

    }
    return 0;
}
