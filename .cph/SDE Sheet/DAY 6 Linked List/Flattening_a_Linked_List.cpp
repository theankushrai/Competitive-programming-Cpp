/*Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer.

 

Example 1:

Input:
5 -> 10 -> 19 -> 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45
Output:  5-> 7-> 8- > 10 -> 19-> 20->
22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation:
The resultant linked lists has every 
node in a single level.
(Note: | represents the bottom pointer.)
 

Example 2:

Input:
5 -> 10 -> 19 -> 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
Output: 5->7->8->10->19->20->22->30->50
Explanation:
The resultant linked lists has every
node in a single level.

(Note: | represents the bottom pointer.)
 

Your Task:
You do not need to read input or print anything. Complete the function flatten() that takes the head of the linked list as input parameter and returns the head of flattened link list.

 

Expected Time Complexity: O(N*M)
Expected Auxiliary Space: O(1)

 

Constraints:
0 <= N <= 50
1 <= Mi <= 20
1 <= Element of linked list <= 103*/


// 1. using merge of merge sort;
//time complexity n*m;
//space complexity n*m


Node* merge(Node* l1, Node* l2){
    Node* head=NULL;
    Node* temp=NULL;
    while(l1!=NULL&&l2!=NULL){
        int val;
        if(l1->data<=l2->data){
            val=l1->data;
            l1=l1->bottom;
        }
        else{
            val=l2->data;
            l2=l2->bottom;
        }
        Node* newNode=new Node(val);
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->bottom=newNode;
            temp=temp->bottom;
        }
    }
    while(l1!=NULL){
        Node* newNode=new Node(l1->data);
        l1=l1->bottom;
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->bottom=newNode;
            temp=temp->bottom;
        }
    }
    while(l2!=NULL){
        Node* newNode=new Node(l2->data);
        l2=l2->bottom;
        if(head==NULL){
            head=newNode;
            temp=head;
        }
        else{
            temp->bottom=newNode;
            temp=temp->bottom;
        }
    }
    return head;
}

Node *flatten(Node *root)
{
    if(root==NULL||root->next==NULL)return root;
    Node* l1=root;
    Node* l2=flatten(root->next);
    l1->next=nullptr;
    return merge(l1,l2);
}

//2. using in place merge;
//time complexity n*m;
//space complexity O(1)


Node* merge(Node* head1,Node* head2){
    Node* l1=head1;
    Node* l2=head2;
    if(l2->data<l1->data){
        l2=head1;
        l1=head2;
    }
    Node* head=l1;
    while(l1->bottom!=NULL){
        if(l1->bottom->data<=l2->data)l1=l1->bottom;
        else{
            Node* temp=l1->bottom;
            l1->bottom=l2;
            l1=l2;
            l2=temp;
        }
    }
    l1->bottom=l2;
    return head;
}
Node *flatten(Node *root)
{
    if(root==NULL||root->next==NULL)return root;
   Node* l1=root;
   Node* l2=flatten(root->next);
   l1->next==NULL;
   return merge(l1,l2);
}
