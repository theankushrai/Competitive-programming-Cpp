
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