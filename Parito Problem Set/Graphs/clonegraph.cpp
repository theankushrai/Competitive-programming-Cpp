
// time complexity - O(n) vertices + edges

class Solution {
public:
    
     Node* dfs(Node* node,unordered_map<Node*,Node*> &map){
            if(map[node]) return map[node];
            Node* copy=new Node(node->val);
            map[node]=copy;
            for(Node* it : node->neighbors){
                copy->neighbors.push_back(dfs(it,map));
            }
            return copy;
        }

        Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> map;
        if(node==nullptr) return nullptr;
        return dfs(node,map);
    }
};

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

from typing import Optional


class Solution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        visited = {}

        def dfs(node):
            if node in visited:
                return visited[node]
            newnode = Node(node.val)
            visited[node] = newnode
            
            for it in node.neighbors:
                newnode.neighbors.append(dfs(it))
            return newnode

        return dfs(node) if node else None
