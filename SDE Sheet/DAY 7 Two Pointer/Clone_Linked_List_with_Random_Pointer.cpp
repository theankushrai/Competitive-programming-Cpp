/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 

Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
Example 4:

Input: head = []
Output: []
Explanation: The given linked list is empty (null pointer), so return null.
 

Constraints:

0 <= n <= 1000
-10000 <= Node.val <= 10000
Node.random is null or is pointing to some node in the linked list.
*/

//1.brute force - use hashtable
//time complexity 2n;
// space complexity n for hashtable;

Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* temp=head;
        unordered_map<Node*,Node*> map;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            map[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        Node* newHead=nullptr;
        while(temp!=nullptr){
            if(newHead==nullptr)newHead=map[temp];
            map[temp]->next=map[temp->next];
            map[temp]->random=map[temp->random];
            temp=temp->next;
        }
        return newHead;
    }
//2. optimal- by placing new at right of old;

    Node* copyRandomList(Node* head) {
        if(head==nullptr)return head;
        Node* curr=head;
        Node* nxt=head->next;
        //adding nodes in old list
        while(curr!=nullptr){
            Node* newNode=new Node(curr->val);
            curr->next=newNode;
            newNode->next=nxt;
            curr=nxt;
            if(nxt!=nullptr)nxt=nxt->next;
        }
        Node* newHead=head->next;
        Node* old=head;
        Node* copy=head->next;
        //adding random pointers in new nodes;
        while(old!=nullptr){
            if(old->random==nullptr)copy->random=nullptr;
            else copy->random=old->random->next;
            old=old->next->next;
            if(old!=nullptr)copy=copy->next->next;
        }
        old=head;
        copy=newHead;
        //separating old and new lists;
        while(copy->next!=nullptr){
            old->next=old->next->next;
            copy->next=copy->next->next;
            old=old->next;
            copy=copy->next;
        }
        old->next=nullptr;
        return newHead;
    }