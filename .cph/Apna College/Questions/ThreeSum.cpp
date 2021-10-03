//chech whether the sum of 3 no in an array is equal to the given sum 
 
#include<vector>
#include<algorithm> 
#include<iostream>
using namespace std;
 
bool threesum(vector<int> a,int sum){
    sort(a.begin(),a.end());
    
    for (int i = 0; i < a.size(); i++)
    {
        int low=i+1;
        int high=a.size()-1;
        while(low<high){
            int current=a[i]+a[low]+a[high];
            if(current==sum){
                return true;
            }
            else if(current<sum){
                low++;
            }
            else{
                high--;
            }
        }    
    }
    return false;
    

} 

int main()
{
    vector<int> v ={1,2,3,4,5,6};
    int sum =6;
    cout<<threesum(v,sum);
    return 0;
}