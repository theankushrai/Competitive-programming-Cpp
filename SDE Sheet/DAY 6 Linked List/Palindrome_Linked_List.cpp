/*Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 */

// 1.brute force - add all elements in vector and check if its palindrome or not
//time complexity - 2n
//space complexity n
 
    bool palindrome(vector<int>& a){
        int i=0;
        int j =a.size()-1;
        while(i<j){
            if(a[i]!=a[j])return false;
            i++;j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)return true;
        vector<int> temp;
        ListNode* dummy=head;
        while(dummy!=nullptr){
            temp.push_back(dummy->val);
            dummy=dummy->next;
        }
        return palindrome(temp);
        
    }
//2. sliding window- find middle and then reverse elements far then reverse;
//time complexity n;
//space complexity O(1);

ListNode* middlenode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=nullptr&&fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    bool palindrome(ListNode* i,ListNode* j){
        while(j!=nullptr){
            if(i->val!=j->val)return false;
            i=i->next;
            j=j->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* head){
        if(head->next==nullptr)return head;
        ListNode* temp=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==nullptr)return true;
        ListNode* middle=middlenode(head);
        middle->next=reverse(middle->next);
        return palindrome(head,middle->next);
    }
