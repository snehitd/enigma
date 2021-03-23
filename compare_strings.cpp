// Example program
#include <iostream>
using namespace std;
 
void relationalOperation(string s1, string s2)
{
 
    if (s1 != s2) 
    {
        cout << s1 << " is not equal to " << s2 << endl;
        if (s1 > s2)
            cout << s1 << " is greater than " << s2 << endl; //alphabetical order - s2,s1
        else
            cout << s2 << " is greater than " << s1 << endl; //alpahbetical order s1,s2
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}

void compareFunction(string s1, string s2)
{
    // comparing both using inbuilt function
    int x = s1.compare(s2); // x=0 - equal 
                            //x > 0 - s1 > s2 i.e s2,s1 alphabetical order 
                            // x < 0 - s2 > s1 i.e s1,s2 alphabetical order
    if (x != 0) {
        cout << s1 
             << " is not equal to "
             << s2 << endl;
        if (x > 0)
            cout << s1 
                 << " is greater than "
                 << s2 << endl;
        else
            cout << s2 
                 << " is greater than "
                 << s1 << endl;
    }
    else
        cout << s1 << " is equal to " << s2 << endl;
}
// Driver code
int main()
{
    cout << "Enter two strings to compare" << endl;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    relationalOperation(s1, s2);
    //compareFunction(s1,s2);
    return 0;
}
