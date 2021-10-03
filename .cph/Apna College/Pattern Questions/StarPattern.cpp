//         * 
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *

#include<iostream>
using namespace std;
 
int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j <5-i-1; j++)
        {
            cout<<"  ";
        }
        for (int k = 0; k <=i; k++)
        {
            cout<<"* ";
        }
        for (int l = 0; l <i; l++)
        {
            cout<<"* ";
        }
        
        cout<<endl;
        
    }
    
    return 0;
}