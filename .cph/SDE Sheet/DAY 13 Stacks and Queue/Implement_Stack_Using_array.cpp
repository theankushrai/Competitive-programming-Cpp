#include <bits/stdc++.h>
using namespace std;



int main()
{
    cout << "Enter the size of the stack : " << endl;
    int n;
    cin >> n;
    int a[n];
    int choice;
    int top = -1;
    do
    {
        cout << "1.push\n2.pop\n3.top : " ;
        cin >> choice;
        cout<<endl;
        switch (choice)
        {
        case 1:
        {
            int data;
            cout << "Enter data : " << endl;
            cin>>data;
            if (top == n - 1)
            cout << "Stack Overflow" << endl;
            else
            {
                top++;
                a[top] = data;
            }
        }break;
        case 2:
        {
            if (top == -1)
            cout << "Stack Underflow" << endl;
            else top--;
        }break;
        case 3:
        {
            if(top==-1)cout<<"Stack Underflow"<<endl;
            cout << a[top];
            
        }break;
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}