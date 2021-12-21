#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{    
    cout << "Press Enter 3 times to reveal your future.";
    cin.get();
    cin.get();
    cin.get();
    srand(time(0));
    int grade = rand()%9;
    if(grade == 0) cout << "You will get A in this 261102.";
    else if(grade ==1) cout << "You will get B+ in this 261102.";
    else if(grade ==2) cout << "You will get B in this 261102.";
    else if(grade ==3) cout << "You will get C+ in this 261102.";
    else if(grade ==4) cout << "You will get C in this 261102.";
    else if(grade ==5) cout << "You will get D+ in this 261102.";
    else if(grade ==6) cout << "You will get D in this 261102.";
    else if(grade ==7) cout << "You will get F in this 261102.";
    else if(grade ==8) cout << "You will get W in this 261102.";
    return 0;
}