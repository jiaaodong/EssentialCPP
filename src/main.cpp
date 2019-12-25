#include <iostream>
#include <vector>
using namespace std;
int main(int, char**) {
    int num_cols = 10, num_rows = 5;
    vector<vector<int>> array;
    for(int i = 0; i<num_rows; i++){
        for(int j=0; j<num_cols; j++){
            std::cout << "Hello, world!\n";
        }
    }
    std::cout << "Hello, world!\n";
}
