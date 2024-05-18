/*
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
Example 2:


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.
Example 3:


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.
 

Constraints:

The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.
*/

// 1.brute force - hash table to find first node in loop
//time complexity n;
//space complexity n;

ListNode *detectCycle(ListNode *head) {
        ListNode* dummy=head;
        unordered_set<ListNode*> set;
        while(dummy!=nullptr){
            if(set.find(dummy)!=set.end()) return dummy;
            set.insert(dummy);
            dummy=dummy->next;
        }
        return nullptr;
    }
//2. hare and tortoise algorithm
//time complexity n;
//space complexity n;

ListNode *detectCycle(ListNode *head) {
        if(head==nullptr)return head;
        ListNode* slow=head;
        ListNode* fast=head;
        do{
            if(fast->next==nullptr||fast->next->next==nullptr)return nullptr;
            slow=slow->next;
            fast=fast->next->next;
        }while(slow!=fast);
        
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }