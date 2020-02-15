#include<iostream>
#include<fstream>
#include<iterator>
#include<map>
#include<set>
#include<string>


using namespace std;
int main(int argc, char const *argv[])
{
    ifstream in_file("resources/ex3_1_dict.txt");
    ofstream out_file("resources/ex3_1_output.txt");

    istream_iterator<string> is(in_file);
    istream_iterator<string> eof;
    map<string, int> word_stats;
    map<string, int>::iterator i_stats;
    const int num_avoid = 6;
    string avoid[num_avoid] = {"a", "an", "or", "the", "and", "but"};
    set<string> word_forbid(avoid, avoid + num_avoid);
    while(is!=eof){
        if(!word_forbid.count(*is))
            word_stats[*is]++;        
        ++is;
    }
    for(i_stats = word_stats.begin(); i_stats!=word_stats.end(); i_stats++){
        cout<<i_stats->first<<": "<<i_stats->second<<endl;
    }
        
    return 0;
}
