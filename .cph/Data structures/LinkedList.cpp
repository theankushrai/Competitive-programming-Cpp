#include<algorithm>
#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    explicit Node(int d){
        data=d;
        next=nullptr;
    }
};


void insertathead(int data, Node* &head){
    Node* newnode =new Node(data);

    newnode->next=head;
    head=newnode;
}

void insertattail(int data, Node* &head){
    Node* newnode =new Node(data);

    if(head==nullptr){
        head=newnode;
    }
    else{

        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newnode;

    }
}

void deleteathead( Node* &head){
    Node* temp=head;
    head=head->next;
    delete temp;
}
void deletion(int val,Node* &head){
    if(head== nullptr){
        cout<<"nothing to delte";
        return;
    }
    if(head->next == nullptr){
        deleteathead(head);
        return;
    }
    Node* temp=head;
        while(temp->next->data!=val){
            temp=temp->next;
        }
        Node* to_delete=temp->next;
        temp->next=temp->next->next;
        delete to_delete;

}

void display( Node* head){
    if(head==nullptr){
        cout<<"nothing to show";
    }
    else{
        Node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

void reverseiterative( Node* &head){
    Node* prevptr=nullptr;
    Node* currentptr=head;
    Node* nextptr;

    while(currentptr!=nullptr){
        nextptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nextptr;
    }
    head=prevptr;
}

Node* reverseRecursive(Node* &h){
    if(h==nullptr || h->next==nullptr){
        return h;
    }

    Node* newhead=reverseRecursive(h->next);
    h->next->next=h;
    h->next=nullptr;
    return newhead;
}

Node* reverseK(Node* head, int k){
    Node* prevptr=nullptr;
    Node* currentptr=head;
    Node* nextptr;

    int count=0;

    while(currentptr!=nullptr && count<k){
        nextptr=currentptr->next;
        currentptr->next=prevptr;
        prevptr=currentptr;
        currentptr=nextptr;
        count++;
    }

    if(nextptr!=nullptr){
     head->next=reverseK(nextptr,k);}

     return prevptr;
}

void makeCycle(Node* &head, int pos){
    Node* temp =head;
    Node* start;

    int count=0;
    while(temp->next!=nullptr){
        
        if(count<=pos){
            start=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=start;
}

// floyds (Hare and Tortoise)  algorithm for detection and removal of cycle

bool detectCycle(Node* &head){
    Node* slowptr=head;
    Node* fastptr=head;

    while(fastptr->next!=nullptr&&fastptr!=nullptr){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;

        if(fastptr==slowptr){
            return true;
        }
    }
    return false;
}

void removecycle(Node* &head){
    Node* slowptr=head;
    Node* fastptr=head;

    while(fastptr->next!=nullptr&&fastptr!=nullptr){
        fastptr=fastptr->next->next;
        slowptr=slowptr->next;

        if(fastptr==slowptr){
            break;
        }
    }
    fastptr=head;

    while(fastptr->next!=slowptr->next){
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }

    slowptr->next=nullptr;
}
int length(Node* &head){
    Node* temp=head;
    int l =0;
    while(temp!=nullptr){
        l++;
        temp=temp->next;
    }
    return l;
}
//bring last k nodes to front of the link list
void kappend(Node* &head, int k){
    int count=length(head) - k;
    Node* temp=head;
    Node* tail=head;
    Node* newhead;
    while(tail->next!=nullptr){
        if(count>1){
            temp=temp->next;
            count--;
        }
        tail=tail->next;
    } 
    temp->next=newhead;
    temp->next=nullptr;
    tail->next=head;
    head=newhead;
}

//intersection between 2 linked lists

int findintersection(Node* &h1,Node* &h2){
    int l1=length(h1);
    int l2=length(h2);
    int d=0;
    Node* ptr1;
    Node* ptr2;
    if(l1>=l2){
        d=l1-l2;
        ptr1=h1;
        ptr2=h2;
    }
    else{
        d=l2-l1;
        ptr1=h2;
        ptr2=h1;
    }

    while(d){
        ptr1=ptr1->next;
        if(ptr1==nullptr){
            return -1;
        }
        d--;
    }

    while(ptr1!=nullptr&&ptr2!=nullptr){
        if(ptr1==ptr2){
            return ptr1->data;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;

}

Node* mergelists(Node* h1, Node* h2){
    Node* p1=h1;
    Node* p2=h2;
    Node* dummynode=new Node(-1);
    Node* p3=dummynode;
    while(p1!=nullptr&&p2!=nullptr){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=nullptr)
    {
        p3->next=p1;
        p1=p1->next;
    }
    while (p2!=nullptr)
    {
     
       p3->next=p2;
       p2=p2->next;   
    }
    return dummynode->next;
    
}

Node* mergelistsRecursion(Node*h1, Node*h2){
    if(h1==nullptr) return h2;
    if(h2==nullptr) return h1;
    Node* result;
    if(h1->data<h2->data){
        result=h1;
        result->next=mergelistsRecursion(h1->next,h2);
    }
    else{
        result=h2;
        result->next=mergelistsRecursion(h1,h2->next);
    }
    return result;
}
//put all the even nos after odd nos
void evenafterodd(Node* head){
    Node* odd=head;
    Node* even=head->next;
    Node* evenstart=even;
    while(odd->next!=nullptr&&even->next!=nullptr){
        odd->next=even->next;
        odd=odd->next;
        even->next=odd->next;
        even=even->next;
    }
    odd->next=evenstart;
    if(odd->next==nullptr){
        even->next=nullptr;
    }

}

int main()
{
    Node* h = nullptr;
    insertattail(1,h);
    insertattail(2,h);
    insertattail(3,h);
    insertattail(4,h);
    insertattail(5,h);
    display(h);
    evenafterodd(h);
    display(h);
    

    return 0;
}