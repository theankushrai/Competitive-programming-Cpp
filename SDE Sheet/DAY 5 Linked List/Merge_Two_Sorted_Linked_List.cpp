/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

Example 1:

Input:
N = 4, M = 3 
valueN[] = {5,10,15,40}
valueM[] = {2,3,20}
Output: 2 3 5 10 15 20 40
Explanation: After merging the two linked
lists, we have merged list as 2, 3, 5,
10, 15, 20, 40.
Example 2:

Input:
N = 2, M = 2
valueN[] = {1,1}
valueM[] = {2,4}
Output:1 1 2 4
Explanation: After merging the given two
linked list , we have 1, 1, 2, 4 as
output.
Your Task:
The task is to complete the function sortedMerge() which takes references to the heads of two linked lists as the arguments and returns the head of merged linked list.

Expected Time Complexity : O(n+m)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N, M <= 104
1 <= Node's data <= 105
*/

// 1.merge using mergesort merge
// time complexity n+m;
// space complexity n+m;

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *head=nullptr;
        ListNode *temp;
        while(a!=nullptr&&b!=nullptr){
            ListNode* newNode;
            if(a->val<=b->val){
                newNode= new ListNode(a->val);
                a=a->next;
            }
            else{
                 newNode=new ListNode(b->val);
                 b=b->next;
            }
            if(head==nullptr){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=temp->next;
            }
        }
        while(a!=nullptr){
            ListNode* newNode= new ListNode(a->val);
            
            if(head==nullptr){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=temp->next;
            }
            a=a->next;
        }
        while(b!=nullptr){
            ListNode* newNode= new ListNode(b->val);
            
            if(head==nullptr){
                head=newNode;
                temp=head;
            }
            else{
                temp->next=newNode;
                temp=temp->next;
            }
            b=b->next;
        }
        return head;
    }

//2.optimiaed mergesort merge- merging in place instead of using extra space-
//Time complexity n+m
//space complexity O(1)

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr)return l2;
        if(l2==nullptr)return l1;
        if(l2->val<=l1->val){
            ListNode* temp=l1;
            l1=l2;
            l2=temp;
        }
        ListNode* head=l1;
        while(l1->next!=nullptr){
            if(l1->next->val<=l2->val)l1=l1->next;
            else{
                ListNode * temp=l1->next;
                l1->next=l2;
                l1=l2;
                l2=temp;
            }
        }
        l1->next=l2;
        return head;
    }