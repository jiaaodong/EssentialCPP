#include<vector>
#include<iostream>
using namespace std;


// This is a wrong version
// const vector<int>* fibo_seq(int size){
//     const int max_size = 1024;
//     static vector<int> elems;
//     const vector<int>* ret_ptr = &elems;
//     for(int ix = elems.size(); ix <size; ++ix){
//         if(ix == 0 || ix == 1){
//             ret_ptr->push_back(1);
//         }
//         else{
//             elems.push_back(elems[ix - 1] + elems[ ix - 2]);
//         }
//     }
//     return &elems;
// }

const vector<int>* fibo_seq(int size){
    const int max_size = 1024;
    static vector<int> elems;
    const vector<int>* ret_ptr = &elems;
    for(int ix = elems.size(); ix <size; ++ix){
        if(ix == 0 || ix == 1){
            elems.push_back(1);
        }
        else{
            elems.push_back(elems[ix - 1] + elems[ ix - 2]);
        }
    }
    return ret_ptr;
}
/* It seems like even if a pointer has been declared to point the const value, if that value is changed, the pointer does not know */
/* However, if the user wants to use the pointer for const value to change the value by dereference, it is not possible */

void display_vector(const vector<int> in_vec){
    for(int i=0; i<in_vec.size(); ++i){
        cout<<in_vec[i]<<" ";
    }
    cout<<endl;
}
int main(int argc, char const *argv[])
{
    const int num_try = 10;
    const vector<int>* fibonacci_sequence;

    /* It seems like even if a pointer has been declared to point the const value, if that value is changed, the pointer does not know */
    /* However, if the user wants to use the pointer for const value to change the value by dereference, it is not possible */
    const int* const_int_ptr;
    int supposed_to_be_const_int = 10;
    const_int_ptr = &supposed_to_be_const_int;
    supposed_to_be_const_int = 5;
    cout<<"after changing the suppose-to-be-const integer: "<<supposed_to_be_const_int<<" dereference its pointer "<<*const_int_ptr<<endl;
    /////

    for(int i = 0; i<num_try; ++i){
        fibonacci_sequence = fibo_seq(i);
        display_vector(*fibonacci_sequence);
    }

    return 0;
    
}
