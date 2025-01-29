class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        n=numCourses
        adj=defaultdict(list)
        vis=[False]*n
        path_vis=[False]*n
        result=[]

        for a,b in prerequisites:
            adj[a].append(b)

        def hascycle(curr): #hascycle 
            if path_vis[curr]:
                return True
            if vis[curr]:
                return False
            vis[curr]=True
            path_vis[curr]=True

            for nei in adj[curr]:
                if hascycle(nei):
                    return True
            
            path_vis[curr]=False
            result.append(curr)
            return False


        for i in range(n):
            if not vis[i]:
                if hascycle(i):
                    return []
        
        return result