/*Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Example 2:


Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []
 

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

// 1.iteratively 
//time complexity n

 ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        
        while(curr!=nullptr){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt!=nullptr)nxt=nxt->next;
            
        }
        return prev;   
    }

//2.recursively
//time complexiy n

 ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr)return head;
        ListNode* newhead=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newhead;
    }