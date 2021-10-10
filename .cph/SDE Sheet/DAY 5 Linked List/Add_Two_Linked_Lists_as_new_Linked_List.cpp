/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/

// 1.time complexity n+m
// space complexity max(n,m)
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=nullptr;
        ListNode* head=nullptr;
        int carry=0;
        while(l1!=nullptr||l2!=nullptr){
            int val1=0,val2=0;
            if(l1!=nullptr)val1=l1->val;
            if(l2!=nullptr)val2=l2->val;
            
                int sum=val1+val2+carry;
                carry=sum/10;
                ListNode* newNode=new ListNode(sum%10);
                if(head==nullptr){
                    temp=newNode;
                    head=temp;
                }
                else{
                    temp->next=newNode;
                    temp=temp->next;
                }
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;
        }
        if(carry){
            ListNode* newNode=new ListNode(carry);
            temp->next=newNode;
        }
        return head;
    }