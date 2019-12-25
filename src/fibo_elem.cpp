#include<iostream>
#include<limits>

bool fibo_elem(int pos, int& elem){
    if(pos <= 0 || pos > 50){
        elem = 0;
        return false;
    }
    elem = 1;
    int n_2 = 1, n_1 = 1;
    switch (pos)
    {
    case 2:
        std::cout<<"1 ";
    
    case 1:
        std::cout<<"1 ";
        break;
    }
    for(int ix = 3; ix<=pos; ++ix){ // Attention: Fibonacci sequence starts from 3rd element;
        elem  = n_1 + n_2;
        n_2 = n_1;
        n_1 = elem;
        std::cout<<elem<<(!(ix%10)? "\n" : " "); //Attention: The priority of operators need the bracket
    }
    std::cout<<std::endl;
    return true;
}

int main(int argc, char const *argv[])
{
    int pos;
    bool usr_exit;
    std::cout<<"The maximum value of a integer in this machine is: "<< std::numeric_limits<int>::max() <<std::endl;
    while(!usr_exit){
        std::cout<<"Please enter a position: ";
        std::cin>> pos;
        if(pos == -1){
            usr_exit = true;
        }
        int elem;
        if(fibo_elem(pos, elem)){
            std::cout<<"element # "<<pos
            <<" is "<< elem<< std::endl;
        }
        else std::cout<<" Sorry could not calculate element # "<< pos <<std::endl;

    }
    return 0;
}
