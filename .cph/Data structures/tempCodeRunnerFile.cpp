
struct node
{
    int data;
    struct node* left;
    struct node* right;

    node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
