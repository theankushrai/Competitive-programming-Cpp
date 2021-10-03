 
#include<iostream>
using namespace std;

bool is_safe(int **a,int x, int y,int n){
  if(x < n && y < n && a[x][y] == 1){
        return true;
    }
    return false;    
}

bool rat_in_maze(int **a,int x, int y, int n,int **sol){
    if(x==n-1 && y==n-1){
        sol[x][y]=1;
        return true;
    }
    if(is_safe(a,x,y,n)){
        sol[x][y]=1;
        if(rat_in_maze(a,x+1,y,n,sol)) return true;
        if(rat_in_maze(a,x,y+1,n,sol)) return true;
        sol[x][y]=0;  //backtracking
        return false;
    }
    return false;
}

int main()
{
    int n;
    cin>>n;

    int** a= new int*[n];
    int** sol=new int*[n];
    for(int i =0;i<n;i++){
        a[i] = new int[n];
        sol[i]=new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            cin>>a[i][j];
         sol[i][j]=0;
        }
    }
    
    if(rat_in_maze(a,0,0,n,sol)){
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<sol[i][j]<<" ";
            }cout<<endl;
            
        }
        
    }

    
    return 0;
}