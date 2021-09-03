// 1. via array element swapping
 void rotate(vector<int>& nums, int k) {
     
        if(nums.size()==1)return ;
        if(k>nums.size())k%=nums.size();

        vector<int> temp;
        int d=nums.size()-k;
        for(int i =0;i<d;i++){
            temp.push_back(nums[i]);
        }
        for(int i =0;i<k;i++){
            nums[i]=nums[i+d];
        }
        for(int i =k;i<nums.size();i++){
            nums[i]=temp[i-k];
        }
    }
// 2. via array reversal

  void reverse(vector<int>& nums,int l, int r){
        while(l<r){
            swap(nums[l++],nums[r--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if(nums.size()==1)return ;
        // if k =5 and array size =2 ; then k =5 will be euqal to k==1
        if(k>nums.size())k%=nums.size(); 

        // reverse the last k elements;
        //reverse the elements except k at last;
        //reverse the whole array
        reverse(nums,0,nums.size()-k-1);
        reverse(nums,nums.size()-k,nums.size()-1);
        reverse(nums,0,nums.size()-1);
    }