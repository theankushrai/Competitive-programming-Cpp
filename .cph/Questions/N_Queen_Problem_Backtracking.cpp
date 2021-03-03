// we have to place n queens in sq martix of nxn such that no queens attack each other 
#include<iostream>
using namespace std;

bool isSafe(int** arr, int x, int y ,int n){
    for(int row=0;row<x;row++){
        if(arr[row][y]==1){
            return false;
        }
    }
    int row=x;
    int col=y;

    //checking left digonal
    while(row>=0&&col>=0){
        if(arr[row][col]==1) return false;
        row--;
        col--;
    }

    row=x;
    col=y;
//checking right digonal
    while(row>=0&&col<n){
        if(arr[row][col]==1)return false;
        row--;
        col++;
    }

    return true;
}
bool nQueen(int** arr, int x , int n){
    if(x>=n) return true;

    //checking if it is safe to place the queen in the given column
    for(int col=0;col<n;col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col]=1;

             //checking if we can place the queen in other columns
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][col]=0;//back tracking
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    int** a=new int*[n];
    for(int i =0;i<n ; i++){
        a[i]=new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j]=0;
        }
    }

    if(nQueen(a,0,n)){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<a[i][j]<<" "; 
            }
            cout<<endl;
            
        }
        
    }
    else cout<<" not possible";
    return 0;
}
