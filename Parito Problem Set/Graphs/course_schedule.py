# 207. Course Schedule
# Solved
# Medium
# Topics
# Companies
# Hint
# There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

# For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
# Return true if you can finish all courses. Otherwise, return false.

 

# Example 1:

# Input: numCourses = 2, prerequisites = [[1,0]]
# Output: true
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0. So it is possible.
# Example 2:

# Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
# Output: false
# Explanation: There are a total of 2 courses to take. 
# To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

# Constraints:

# 1 <= numCourses <= 2000
# 0 <= prerequisites.length <= 5000
# prerequisites[i].length == 2
# 0 <= ai, bi < numCourses
# All the pairs prerequisites[i] are unique.


#time complexity - O(V+E)
#space complexity - O(V+E)

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:

        adj=collections.defaultdict(list)
        for node in range(0,numCourses):
            adj[node]=[]
        for it in prerequisites:
            adj[it[0]].append(it[1])
        
        vis=set()

        def dfs(node):
            if node in vis:
                return False
            if not adj[node]: return True

            vis.add(node)
            
            for child in adj[node]:
                if not dfs(child): return False
                # adj[node].remove(child) removing the element one by one is child*n

            vis.remove(node)
            adj[node]=[] # reassigning as empty is O(1)

            return True

        for node in range(0,numCourses):
            if not dfs(node):
                return False
        
        return True
    

#lesser time complexity

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adj=collections.defaultdict(list)
        vis=set()
        cycle=set()
        ans=[]

        for i in range(0,numCourses):
            adj[i]=[]

        for i,j in prerequisites:
            adj[i].append(j)

        def dfs(node):
            if node in cycle:
                return False
            if node in vis:
                return True

            cycle.add(node)

            for child in adj[node]:
                if dfs(child)==False:
                    return False

            adj[node]=[]
            cycle.remove(node)
            vis.add(node)
            ans.append(node)
            return True 

        for node in range(0,numCourses):
            if not dfs(node):
                return []
        
        return ans