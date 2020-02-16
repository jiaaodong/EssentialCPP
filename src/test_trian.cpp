#include"Triangular.h"
#include"Triangular_iterator.h"
#include<iostream>
#include<vector>

using namespace std;
int sum(const Triangular& trian){
    int beg_pos = trian.beg_pos();
    int length = trian.length();
    int val, sum = 0;
    trian.next_reset();
    while(trian.next(val)){
        sum += val;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    // test constructor 
    Triangular my_trian_seq(4);
    cout<<"The begin position of the sequence: "<<my_trian_seq.beg_pos()<<" with length: "<<my_trian_seq.length()<<endl;

    // test sum, next_reset(), next()
    int sum_of_my_trian_seq = sum(my_trian_seq);
    cout<<"The sum of the sequence: "<<sum_of_my_trian_seq << endl;

    // test iterator
    Triangular::iterator it = my_trian_seq.begin(), end_it= my_trian_seq.end();
    while(it!=end_it){
        cout<<*it<<' ';
        ++it;
    }
    cout<<endl;
    return 0;
}
