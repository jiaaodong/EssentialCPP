#include<iostream>
#include<vector>
#include<string>
using namespace std;
inline bool range_is_ok(int pos){
    const int max_size = 1024;
    return pos>=0&&pos<1024? true : false;
}
const vector<int> * pentagonal(int size){
    static vector<int> elems;
    if(!range_is_ok(size)){
        return 0;
    }
    for(int ix=elems.size(); ix<size; ++ix){
        elems.push_back(ix * (3.0 * ix - 1) / 2);
    }

    return &elems;
}
void display(const vector<int> & vec, string type = "double"){
    if(type == "double"){
        for(int ix = 0; ix<vec.size(); ++ix){
            cout<<vec[ix]<<" ";
        }
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{   
    int pos;
    bool usr_exit = false;
    while(!usr_exit){
            cout<<"which position do you want?"<<endl;
    cin>> pos;
    if(pos == -1){
        usr_exit == true;
        break;
    }
    const vector<int> * pt = pentagonal(pos);
    display(*pt);
    }

    return 0;
}
