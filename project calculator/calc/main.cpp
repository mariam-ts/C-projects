#include <iostream>

using namespace std;

int main()
{
    double * n = new(std :: nothrow) double  ; // memory allocation
    double * n2 = new (std :: nothrow) double;
    char c;
    char q;

    cout << "          Calculator"<<endl;

    do
    {
        cout << "  you can use operations: +, -, *, /"<<endl;
    cin >> *n;
    cin >> c;
    cin >> *n2;
    if(cin.fail()) // if user input isn't digit
    {
        cout << "You should enter digits!."<<endl;
    }
     else if(c == '+')
    {
        cout<< "result is " << *n+*n2 << endl;

    }
    else if(c == '-')
    {
        cout<< "result is " << *n-*n2 << endl;

    }
    else if(c == '*')
    {
        cout<< "result is " << *n * *n2 << endl;

    }
    else if(c == '/')
    {
        if(*n2 == 0) // in case of dividing by 0
        {
            cout << "SYNTAX ERROR"<< endl;

        }
        else
        {
            cout<< "result is " << *n / *n2 << endl;

        }

    }

    cout << "Press any key to continue,to quit press  q." << endl;
    cin >> q;
     delete n; //clear
     delete n2;
    }while(q != 'q');

    return 0;
}
