/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

// 1.brute force - put all the nodes on hashtable. if any node is already present then we have a cycle
// time complexity n
// space coomplexity n

 bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> temp;
        ListNode* dummy=head;
        
        while(dummy!=nullptr){
            if(temp.find(dummy)!=temp.end())return true;
            temp.insert(dummy);
            dummy=dummy->next;
        }
        return false;
    }

//2. hare and tortoise algorithm
//time complexity n
//space complexity O(1)

    bool hasCycle(ListNode *head) {
        if(head==nullptr)return false;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)return true;
        }
        return false;
    }
