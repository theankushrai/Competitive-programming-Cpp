#include<vector>
#include<deque> 
#include<iostream>
using namespace std;
 
int main()
{
    int k =3;
    vector<int> a={1,3,-1,-3,5,3,6,7};
    vector<int> ans;
    deque<int> q(k);
    //adding the first k elements
    for (int i = 0; i <k ; i++)
    {
        //if element is greater then the first element pop them otherwise push
        while(!q.empty()&&a[i]>a[q.back()]){
            q.pop_front();
        }
        q.push_back(i);
    }
            ans.push_back(a[q.front()]);


    for(int i =k;i<a.size();i++){

    //remove elements out of the current window
        while (!q.empty()&&q.front()<=i-k)
        {
            q.pop_front();
        }
        //remove all the elements smaller than the current element
        while(!q.empty()&&a[i]>=a[q.front()]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);

    }
    for(auto it:ans){
        cout<<it<<" ";
    }
    

    return 0;

}