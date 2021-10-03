// Put n items with given weight and value into the knapsack of capacity W to get the maximum total value in the knapsack;

 
#include<iostream>
using namespace std;

int knapsack(int value[],int wt[],int n, int W){

    if(n==0||W==0) return 0;
    if(wt[n-1]>W) return knapsack(value,wt,n-1,W);// if weight of an item is bigger than the capacity

   return max(knapsack(value,wt,n-1,W-wt[n-1])+value[n-1]// when we add an item
   ,knapsack(value,wt,n-1,W));    // when we dont add an item 
 
    
} 

int main()
{
    int wt[]={10,20,30};
    int value[]={100,50,150};
    int W=50;
    cout<<knapsack(value,wt,3,W)<<endl;
    return 0;
}