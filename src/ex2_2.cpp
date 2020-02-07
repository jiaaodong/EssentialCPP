#include<iostream>
#include<vector>
#include"display_vec.cpp"

using namespace std;

int pentagonal(int n){
    return n*(3*n - 1)/2;
}

bool fill_in_sequence(vector<int> &in_vec, int pos){
    const int max_seq = 100;
    if(pos<0 || pos>max_seq){
        cerr<<"The position number is larger than the maximum allowable number!"<<endl;
        return false;
    }

    else{
        for(int i = in_vec.size(); i<pos; i++){
            in_vec.push_back(pentagonal(i));
        }
        return true;
    }
}

int main(int argc, char const *argv[])
{   
    int pos;
    vector<int> sequence_vec;
    cout<<"Input a desirable number to indicate the length of the sequence: "<<endl;
    cin>>pos;
    fill_in_sequence(sequence_vec, pos);
    display_vector(sequence_vec);
    return 0;
}
