// 1. by using sort - NLogN

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
      sort(arr,arr+l);
      return arr[k-1];
    }
};
//2. Using quickselect
class Solution{
    public:
    
    int partition(int arr[],int l , int r){
        int pivot=r,j=l;
        for(int i =l;i<r;i++){
            if(arr[i]<=arr[pivot]){ 
                swap(arr[i],arr[j]);
                j++;
            }
        }
        swap(arr[j],arr[pivot]);
        return j;
    }
    int quickselect(int arr[],int l, int r,int k){
        if(k>0&&k<=r-l+1){//checking if k is in the bounds of the index
            int pivot=partition(arr,l,r);
            if(pivot-l==k-1)return arr[pivot];
            if(k-1<pivot-l)return quickselect(arr,l,pivot-1, k );
            return quickselect(arr,pivot+1,r, k-pivot+l-1);
        }else{return -1;}
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        return quickselect(arr,l,r,k);
    }
};
// 3. by using priority queue
//time complexity n log n 
class Solution{
    public:
    int kthSmallest(int arr[], int l, int r, int k) {
        //putting items upto k in max queue. and removing overflowing items
        priority_queue<int> q;
        for(int i =l;i<=r;i++){
            q.push(arr[i]);
            if(q.size()>k) q.pop();
        }
        return q.top();
    }
};
