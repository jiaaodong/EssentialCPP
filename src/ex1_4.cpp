#include<iostream>
#include<string>

using namespace std;
int main(int argc, char const *argv[])
{
    /* code */
    string user_first_name, user_last_name;
    cout<<"PLease enter your first name: ";
    cin>>user_first_name;
    cout<<"And your last name: ";
    cin>>user_last_name;
    
    cout<<endl
        <<"Hello, "
        <<user_first_name
        <<" "
        <<user_last_name
        <<".... and goodbye!"
        <<endl;
        
    return 0;
}
