/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
*/

// 1.brute force - find size of array and then find the nth node and then delete it
// time complexity 2n


    int size(ListNode* head){
        int count=1;
        while(head->next!=nullptr){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=size(head);
        if(len==1)return head=nullptr;//if there is only one element
        if(len==n){//if we have to delete first element
            head=head->next;
            return head;
        }
        ListNode* temp=head;
        int count=len-n;
        
        while(count>1){
            temp=temp->next;
            count--;
        }
        temp->next=temp->next->next;
        return head;
    }
//2. via sliding window - place windows n aprt and slide them;
//time complexity n;

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* left=head;
        ListNode* right=head;
        ListNode* prev=nullptr;
        while(n>1){
            right=right->next;
            n--;
        }
        while(right->next!=nullptr){
            prev=left;
            left=left->next;
            right=right->next;
        }
        //if we have to delete head
        if(left==head){
            head=head->next;
            return head;
        }
        //for last and remaining elements
        prev->next=prev->next->next;
        return head;
    }