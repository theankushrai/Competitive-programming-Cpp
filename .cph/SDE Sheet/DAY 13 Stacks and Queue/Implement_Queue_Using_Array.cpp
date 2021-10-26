#include <bits/stdc++.h> 
using namespace std;
 
int main()
{
    int n;
    cout<<"Enter size of queue"<<endl;
    cin>>n;
    int a[n];
    int choice;
    int front=0,rear=0,count=0;
    do
    {
        cout<<"1.push\n2.pop\n3.top\0.exit"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:{
            if(count==n){
                cout<<"Queue is full"<<endl;
            }
            else{
                cout<<"Enter data"<<endl;
                int data;
                cin>>data;
                a[rear]=data;
                rear++;
                count++;
                if(rear==n)rear=0;
            }
        }break;
        case 2:{
            if(count==0)cout<<"Queue is Empty"<<endl;
            else{
                front++;
                count--;
                if(front==n)front=0;
            }
        }break;
        case 3:{
            if(count==0)cout<<"Queue is empty"<<endl;
            else cout<<a[front]<<endl;
        }break;
        default:
            break;
        }
    } while (choice!=0);
    

 return 0;
}