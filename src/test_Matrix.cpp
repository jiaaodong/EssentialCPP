#include"Matrix.h"
#include"iostream"


int main(int argc, char const *argv[])
{
    int row, col;
    std::cout<<"The number of rows: ";
    std::cin>>row;
    std::cout<<"The number of col: ";
    std::cin>>col;
    Matrix my_mat0(row, col);
    my_mat0.fill_mat(0);
    std::cout<<"Mat with 0: "<<std::endl;
    my_mat0.display();
    
    Matrix my_mat1(row, col);
    my_mat1.fill_mat(1);
    std::cout<<"Mat with 1: "<<std::endl;
    my_mat1.display();

    std::cout<<"Mat with 0 previously now becomes: "<<std::endl;
    my_mat0 = my_mat1;
    my_mat0.display();

    return 0;
}
