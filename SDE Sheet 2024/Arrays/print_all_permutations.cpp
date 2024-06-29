
TAKE A CHECK ARRAY -> CHECK IF ELEMENTS ARE USED OR NOT. THEN ADD IT TO DATA __cpp_structured_bindings
TAKE AN INDEX VARIABLE. SWAP IT WITH OTHER ELEMENTS. THEN PASS INDEX +1 INTO NEXT PERMUTATION

//------------------------------------------------------------------------------------------------------------

// print all permutations of a given number

//method 1 using an extra data structure - print lexographically
//Time complexity O(n*n!)
//Space complexity O(2n)

void recur_permutation(vector<int> &nums, vector<int> &temparr, vector<vector<int>> &resultarr, vector<bool> &checkarr){
    
    if(temparr.size()==nums.size()){
        resultarr.push_back(temparr);
        return;
    }
    for(int i =0;i<nums.size();i++){
        if(!checkarr[i]){
            checkarr[i]=true;
            temparr.push_back(nums[i]);
            recur_permutation(nums,temparr,resultarr,checkarr);
            temparr.pop_back();
            checkarr[i]=false;
        }
    }
}

//method 2 : without using extra space
//Time complexity O(n!*n)
//space complexity o(1)
void recur_permutation(int index, vector<int> & nums,vector<vector<int>> & resultarr){

    if(index==nums.size()){
        resultarr.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {   
        swap(nums[i],nums[index]);
        recur_permutation(index+1,nums,resultarr);
        swap(nums[i],nums[index]);

    }
    
}

