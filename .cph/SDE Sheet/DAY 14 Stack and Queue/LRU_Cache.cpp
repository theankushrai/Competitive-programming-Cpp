/*Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the cache and Q denotes the number of queries. Query can be of two types:

SET x y : sets the value of the key x with value y
GET x : gets the key of x if present else returns -1.

The LRUCache class has two methods get() and set() which are defined as follows.

get(key)   : returns the value of the key if it already exists in the cache otherwise returns -1.
set(key, value) : if the key is already present, update its value. If not present, add the key-value pair to the cache. If the cache reaches its capacity it should invalidate the least recently used item before inserting the new item.
In the constructor of the class the capacity of the cache should be intitialized.
 

Example 1:

Input:
cap = 2
Q = 2
Queries = SET 1 2 GET 1
Output: 2
Explanation: 
Cache Size = 2

SET 1 2 GET 1
SET 1 2 : 1 -> 2

GET 1 : Print the value corresponding
to Key 1, ie 2.

Example 2:

Input:
cap = 2
Q = 8
Queries = SET 1 2 SET 2 3 SET 1 5
SET 4 5 SET 6 7 GET 4 SET 1 2 GET 3
Output: 5 -1
Explanation: 
Cache Size = 2
SET 1 2 : 1 -> 2

SET 2 3 : 1 -> 2, 2 -> 3 (the most recently 
used one is kept at the rightmost position) 

SET 1 5 : 2 -> 3, 1 -> 5

SET 4 5 : 1 -> 5, 4 -> 5 (Cache size is 2, hence 
we delete the least recently used key-value pair)

SET 6 7 : 4 -> 5, 6 -> 7 

GET 4 : Prints 5 (The cache now looks like
6 -> 7, 4->5)

SET 1 2 : 4 -> 5, 1 -> 2 
(Cache size is 2, hence we delete the least 
recently used key-value pair)

GET 3 : No key value pair having 
key = 3. Hence, -1 is printed.

Your Task:
You don't need to read input or print anything . Complete the constructor and get(), set() methods of the class LRUcache. 


Expected Time Complexity: O(1) for both get() and set().
Expected Auxiliary Space: O(1) for both get() and set(). 
(Although, you may use extra space for cache storage and implementation purposes).


Constraints:
1 <= cap <= 1000
1 <= Q <= 100000
1 <= x, y <= 1000*/

// 1.using hashap and doubly linked list
//time complexity linear

class LRUCache
{
    public:
    
    class node{
        public:
        int key,val;
        node* prev;
        node* next;
        
        node(int _key,int _val){
            key=_key;
            val=_val;
        }
    };
    
    int cap;
    unordered_map<int,node*> temp;
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    void addnode(node* newnode){
            node* temp=head->next;
            temp->prev=newnode;
            head->next=newnode;
            newnode->next=temp;
            newnode->prev=head;
    }
    void deletenode(node* thisnode){
        thisnode->prev->next=thisnode->next;
        thisnode->next->prev=thisnode->prev;
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int _cap)
    {
        cap=_cap;
        head->next=tail;
        tail->prev=head;
    }
    
    //Function to return value corresponding to the key.
    int get(int key)
    {
        if(temp.find(key)!=temp.end()){
            node* thisnode=temp[key];
            int ans=thisnode->val;
            temp.erase(key);
            deletenode(thisnode);
            addnode(thisnode);
            temp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void set(int key, int val)
    {
        if(temp.find(key)!=temp.end()){
            node* thisnode=temp[key];
            temp.erase(key);
            deletenode(thisnode);
        }
        if(temp.size()==cap){
            temp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,val));
        temp[key]=head->next;
    }
};
