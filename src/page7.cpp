#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
using namespace std;
int main(int argc, char const *argv[])
{
    string usr_first_name, usr_last_name;
    int usr_val;
    int num_tries = 0;
    int num_right = 0;
    double usr_score = 0.0;
    char usr_more;
    bool go_for_it = true;
    bool go_for_next = true;
    bool got_it = false;
    int choose_seq, choose_ind;
    int usr_guess;
    cout<<"Please enter your first name: ";
    std::cin>>usr_first_name;
    cout<<endl;
    cout<<"and your last name: ";
    std::cin>>usr_last_name;
    ifstream infile("resources/seq_data.txt");
    const int seq_size = 8;
    const int max_seq = 6;
    string seq_names[max_seq] = {
        "Fibonacci",
        "Lucas",
        "Pell",
        "Triangular",
        "Square",
        "Pentagonal"
    };
    int fibo_values[seq_size] = {
        1, 1, 2, 3, 5, 8, 13, 21
    };
    int luca_values[seq_size] = {
        1, 3, 4, 7, 11, 18, 29, 47
    };
    int pell_values[seq_size] = {
        1, 2, 5,12,29,70,169,408
    };
    int tria_values[seq_size] = {
        1, 3, 6, 10, 15, 21, 28, 36
    };
    int squa_values[seq_size] = {
        1, 4, 9, 16, 25, 36, 49, 64
    };
    int pent_values[seq_size] = {
        1, 5, 12, 22, 35, 51, 70, 92
    };
    vector<int> fibonacci(fibo_values, fibo_values + seq_size);
    vector<int> lucas(luca_values, luca_values + seq_size);
    vector<int> pell(pell_values, pell_values + seq_size);
    vector<int> triangular(tria_values, tria_values + seq_size);
    vector<int> square(squa_values, squa_values + seq_size);
    vector<int> pentagonal(pent_values, pent_values + seq_size);

    vector<int> * seq_addrs[max_seq] = {
        &fibonacci, &lucas, &pell,
        &triangular, &square, &pentagonal
    };
    vector<int> * pv;

    if(!infile){
        
    }
    else{
        string saved_usr_first_name, saved_usr_last_name;
        int saved_num_tries, saved_num_right;
        while(infile>>saved_usr_first_name){
            infile>>saved_usr_last_name>>saved_num_tries>>saved_num_right;
            if(saved_usr_first_name == usr_first_name){
                usr_first_name = saved_usr_first_name;
                num_tries = saved_num_tries;
                num_right = saved_num_right;
                cout<<"Welcom back, "<< usr_first_name<<" "<<usr_last_name<<endl;
                cout<<"Your current score is: "<< num_right <<" ";
                cout<<"out of "<< num_tries<<" ";

            }
        }
    }

    while(go_for_next){
        choose_seq = rand() % max_seq;
        choose_ind = rand() % (seq_size - 2);
        vector<int> seq = *seq_addrs[choose_seq];
        int value1 = seq[choose_ind];
        int value2 = seq[choose_ind + 1];
        int answer = seq[choose_ind + 2];
        std::cout<<"The first two values of the sequences are: "<<value1<<" and "<<value2<<endl
            <<"Please guess the following value: ";
        got_it = false;
        go_for_it = true;
        while (!got_it && go_for_it)
        {   num_tries += 1;
            cin>>usr_guess;
            if(usr_guess == answer){
                got_it = true;
                num_right += 1;
                usr_score = num_right/num_tries;
                std::cout<<"Congratulations the answer is correct! Current_score: "<<usr_score<<" Do you want another question? (N/Y)"<<endl;
                cin>>usr_more;
                if(usr_more == 'N' || usr_more == 'n'){
                    go_for_next = false;
                }
                else if(usr_more == 'Y' || usr_more == 'y'){
                    go_for_next = true;
                }
            }
            else{
                usr_score = num_right/num_tries;
                std::cout<<"Sorry you didn't enter the right answer! Current_score: "<<usr_score<<" , do you want to try again? (N/Y)"<<endl;
                cin>>usr_more;
                if(usr_more == 'N' || usr_more == 'n'){
                    go_for_it = false;
                }
                else if(usr_more == 'Y' || usr_more == 'y'){
                    go_for_it = true;
                }
            }

        }
    }

    
    return 0;
}
