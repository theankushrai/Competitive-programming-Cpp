# A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.

# The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.

# Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

 

# Example 1:


# Input: favorite = [2,2,1,2]
# Output: 3
# Explanation:
# The above figure shows how the company can invite employees 0, 1, and 2, and seat them at the round table.
# All employees cannot be invited because employee 2 cannot sit beside employees 0, 1, and 3, simultaneously.
# Note that the company can also invite employees 1, 2, and 3, and give them their desired seats.
# The maximum number of employees that can be invited to the meeting is 3. 
# Example 2:

# Input: favorite = [1,2,0]
# Output: 3
# Explanation: 
# Each employee is the favorite person of at least one other employee, and the only way the company can invite them is if they invite every employee.
# The seating arrangement will be the same as that in the figure given in example 1:
# - Employee 0 will sit between employees 2 and 1.
# - Employee 1 will sit between employees 0 and 2.
# - Employee 2 will sit between employees 1 and 0.
# The maximum number of employees that can be invited to the meeting is 3.
# Example 3:


# Input: favorite = [3,0,1,4,1]
# Output: 4
# Explanation:
# The above figure shows how the company will invite employees 0, 1, 3, and 4, and seat them at the round table.
# Employee 2 cannot be invited because the two spots next to their favorite employee 1 are taken.
# So the company leaves them out of the meeting.
# The maximum number of employees that can be invited to the meeting is 4.
 

# Constraints:

# n == favorite.length
# 2 <= n <= 105
# 0 <= favorite[i] <= n - 1
# favorite[i] != i

#1 Cycle Detection with Extended Paths
# Time complexity O(n)
# Space complexity O(n)

class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        
        #1. find longest cycle
        N=len(favorite)
        vis=[False]*N
        longest_cycle=0
        length_2_cycles=[] #finding lenth 2 cycles for the curr code

        for i in range(N):
            curr , start = i, i
            currset=set()

            while not vis[curr]:
                vis[curr]=True
                currset.add(curr)
                curr=favorite[curr]
            
            if curr in currset:
                length=len(currset)

                while start !=curr:
                    length-=1
                    start=favorite[start]
                longest_cycle=max(longest_cycle, length)
                
                if length == 2:
                    length_2_cycles.append([curr, favorite[curr]])


        #2. find sum of the longest non closed circles

        inverted=defaultdict(list)

        for source,destination in enumerate(favorite):
            inverted[destination].append(source)

        def bfs(src, parent): #longest path from this node #parent is 2nd parameter
            q=deque([(src, 0)]) #source and length
            max_len = 0

            while q:
                node , length = q.popleft()
                if node == parent:
                    continue
                max_len = max( max_len, length)

                for n in inverted[node]:
                    q. append((n, length+1))
                
            return max_len

        
        chain_sum=0
        for n1, n2 in length_2_cycles:
            chain_sum += bfs(n1, n2) + bfs(n2, n1) +2
        
        return max(chain_sum, longest_cycle)


# using topological sort