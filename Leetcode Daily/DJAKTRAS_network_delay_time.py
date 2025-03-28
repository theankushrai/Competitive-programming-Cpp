# 743. Network Delay Time
# Solved
# Medium
# Topics
# Companies
# Hint
# You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

# We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

# Example 1:


# Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
# Output: 2
# Example 2:

# Input: times = [[1,2,1]], n = 2, k = 1
# Output: 1
# Example 3:

# Input: times = [[1,2,1]], n = 2, k = 2
# Output: -1
 

# Constraints:

# 1 <= k <= n <= 100
# 1 <= times.length <= 6000
# times[i].length == 3
# 1 <= ui, vi <= n
# ui != vi
# 0 <= wi <= 100
# All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

#Time Complexity: O((v+e)logv) where E is the number of edges in the graph
#space complexity: O(v+e) where v is the number of vertices in the graph

class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        adj=defaultdict(list)
        for u,v,w in times:
            adj[u].append((w,v))
        
        res=[0]*n
        minheap=[(0,k)] # weight, node
        visit=set()
        t=0
        while minheap:
            time,node = heapq.heappop(minheap)
            if node not in visit:
                visit.add(node)
                t=max(t,time)
                for nei_time, nei in adj[node]:
                    heapq.heappush(minheap,(time+nei_time , nei))
        
        return t if len(visit)==n else -1
                