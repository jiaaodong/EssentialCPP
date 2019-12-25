#include<vector>
#include<iostream>
using namespace std;

void display_vector( const vector<int>& vec){

    for(int ix=0; ix<vec.size(); ++ix){
        cout<<vec[ix]<<' ';
    }
    cout<<endl;
}
