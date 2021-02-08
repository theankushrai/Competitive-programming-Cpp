//         1 
//       2 1 2 
//     3 2 1 2 3 
//   4 3 2 1 2 3 4 
// 5 4 3 2 1 2 3 4 5 

#include<iostream>
using namespace std;
 
int main()
{
    for (int i = 1; i <=5; i++)
    {
        for(int j =1;j<=5-i;j++){
            cout<<"  ";
        }
        for(int k =i;k>=1;k--){
            cout<<k<<" ";
        }
        for (int l = 2; l < i+1; l++)
        {
            cout<<l<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}