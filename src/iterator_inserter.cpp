#include<iterator>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;


vector<int> filter_container(const vector<int> &vec,
                    int val, less<int> &lt){
                        vector<int> nvec;
                        vector<int>::const_iterator iter = vec.begin();

                        while((iter = find_if(
                            iter, vec.end(), bind2nd( lt, val)
                        ))!= vec.end()){
                            nvec.push_back(*iter);
                            iter++;
                        }
                    }

template<typename InputIterator, typename OutputIterator, typename ElemType, typename Comp>
OutputIterator filter(InputIterator first, InputIterator last, OutputIterator at, const ElemType &val, Comp pred){
    while((first = find_if(first, last, bind2nd(pred, val)))!=last){
        cout<< "found value: "<<*first << endl;
        *at++ = *first++;
    }
}
int main(int argc, char const *argv[])
{
    const int elem_size = 8;
    int ia[elem_size] = {12, 8, 43, 0, 6, 21, 3, 7};
    vector<int> ivec(ia, ia+elem_size);

    int ia2[elem_size];
    vector<int> ivec2(1);
    cout<<"Filtering integer array for values less than 8\n";
    filter(ia, ia+elem_size, ia2, elem_size, less<int>());
    int ca1[2], ca2[2]; // allocate consecutive space in stack
    ca2[0] = 1; // give them a initial value to check if they change later 
    ca2[1] = 2;
    cout<<"Filtering integer ector for values greater than 8"<<endl;
    vector<int>::const_iterator ivec2_iter;
    filter(ivec.begin(), ivec.end(), back_inserter(ivec2), elem_size, greater<int>());
    cout<<"Filtering integer ector for values greater than 8 to a container not large enough"<<endl;
    cout<<"The target container is: "<<ca1[0]<<" "<<ca2[1]<<endl;
    cout<<"before filtering, the first space after after the target container: "<<ca2[0]<<" the second is: "<<ca2[1]<<endl;
    filter(ivec.begin(), ivec.end(), ca1, elem_size, greater<int>());

    cout<<"after filtering, the first space after the target container: "<< ca2[0]<<" the second is: "<<ca2[1]<<endl;
    
    return 0;
}
