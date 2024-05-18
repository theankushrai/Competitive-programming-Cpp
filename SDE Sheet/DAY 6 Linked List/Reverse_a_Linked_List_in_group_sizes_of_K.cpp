/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
Example 3:

Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]
Example 4:

Input: head = [1], k = 1
Output: [1]
 

Constraints:

The number of nodes in the list is in the range sz.
1 <= sz <= 5000
0 <= Node.val <= 1000
1 <= k <= sz
*/

// 1.optimal approach 
//time complexity n;


int len(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            temp=temp->next;
            count++;
        }
        return count;
    }
    ListNode* reverse(ListNode* head, int k, int size){
        if(k>size||head==nullptr)return head;
        ListNode* prev=nullptr;
        ListNode* curr=head;
        ListNode* nxt=head->next;
        for(int i =0;i<k;i++){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt==nullptr)break;
            nxt=nxt->next;
            
        }
        head->next=reverse(curr,k,size-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k==1||head==nullptr||head->next==nullptr)return head;
        return reverse(head,k,len(head));
    }