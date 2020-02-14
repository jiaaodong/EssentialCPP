#include<iterator>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

/* 
The way to exit input: Enter -> Windows Ctrl + Z / LInux Ctrl + d 
*/
int main(){

    istream_iterator<string> is(cin);
    istream_iterator<string> eof;

    vector<string> text;
    copy(is, eof, back_inserter(text));

    sort(text.begin(), text.end());

    ostream_iterator<string> os(cout, " ");
    copy(text.begin(), text.end(), os);
    
}