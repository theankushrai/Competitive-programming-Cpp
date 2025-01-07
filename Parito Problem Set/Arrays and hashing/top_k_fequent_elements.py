# Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

# Example 1:

# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]
# Example 2:

# Input: nums = [1], k = 1
# Output: [1]
 

# Constraints:

# 1 <= nums.length <= 105
# -104 <= nums[i] <= 104
# k is in the range [1, the number of unique elements in the array].
# It is guaranteed that the answer is unique.
 

# Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.




# using dictionary to count and put that in maxheap and pop k elements
# TC - O(klogn) n for iterating and klogn for taking out k elements
# space complexity - O(n) n for dictionary and n for heap

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter=collections.Counter(nums)
        heap=[(-count,num) for num,count in counter.items()]
        heapq.heapify(heap)
        result=[]
        for _ in range(k):
            count,num=heapq.heappop(heap)
            result.append(num)
        return result
    


# using dictionary to count and put that in count array of n+1 elements - Bucket sort
# TC - O(n) n for iterating and n for taking out k elements
# space complexity - O(n) n for dictionary and n for count array

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter=collections.Counter(nums)
        n=len(nums)
        countarray=[[] for i in range(n+1)]
        result=[]
        for num,count in counter.items():
            countarray[count].append(num)

        for i in range(n,-1,-1):
            if countarray[i] and k>0:
                for it in countarray[i]:
                    result.append(it)
                    k-=1
                
            
        return result