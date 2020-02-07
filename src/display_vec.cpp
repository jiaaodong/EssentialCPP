#include<vector>
#include<iostream>
using namespace std;
void display_vector(const vector<int> in_vec){
    for(int i=0; i<in_vec.size(); ++i){
        cout<<in_vec[i]<<" ";
    }
    cout<<endl;
}