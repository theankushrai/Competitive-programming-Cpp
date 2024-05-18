/*
Given the head of a linked list, rotate the list to the right by k places.

 

Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]
 

Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

// 1.brute force - go to the last node and place that nodein the first;
//time complexity nk;

ListNode* rotate(ListNode* head,ListNode* prev){
        ListNode* newNode=prev->next;    
        prev->next=nullptr;
        newNode->next=head;
        return newNode;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        for(int i =0;i<k;i++){
            ListNode* tail=head;
            ListNode* prev;
            while(tail->next!=nullptr){
                prev=tail;
                tail=tail->next;
            }
            head=rotate(head,prev);
        }
        return head;
    }
//2. optimized brut force - take k%length so that we may reduce no of rotations;
//time complexity nk- but better then previous

ListNode* rotate(ListNode* head,ListNode* prev){
        ListNode* newNode=prev->next;    
        prev->next=nullptr;
        newNode->next=head;
        return newNode;
    }
    int len(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        k%=len(head);
        for(int i =0;i<k;i++){
            ListNode* tail=head;
            ListNode* prev;
            while(tail->next!=nullptr){
                prev=tail;
                tail=tail->next;
            }
            head=rotate(head,prev);
        }
        return head;
    }
//3.change the links for k rotations - sliding window;
//time complexity 2n;
ListNode* rotate(ListNode* head,ListNode* left,ListNode* right){
        ListNode* newNode=left->next;    
        left->next=nullptr;
        right->next=head;
        return newNode;
    }
    int len(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=nullptr){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr)return head;
        int size=len(head);
        k%=size;
        if(size==k||k==0)return head;
        
        ListNode* right=head;
        for(int i =k;i>0;i--) right=right->next;
        ListNode* left=head;
        while(right->next!=nullptr){
            left=left->next;
            right=right->next;
        }
        return rotate(head,left,right);
        
    }