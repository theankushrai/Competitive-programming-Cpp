#include<queue> 
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

int heightOftree(Node* root){
    if(root==nullptr) return 0;
    int lh=heightOftree(root->left);
    int rh=heightOftree(root->right);
    return max(lh,rh)+1;
}

// time complexity of this function will be O(n2) as the time complexity for height funciotn is O(n) and we are calling height funcion for n nos;
int DiameterofTree(Node* root){

    if(root==nullptr)return 0;

    // case 1 : when we consider root node in diameter
    // the diameter will be height of left subtree and height of right subtree
    
    int lh=heightOftree(root->left);
    int rh = heightOftree(root->right);
    int currentDiameter= lh+rh+1;

    //case 2: when we dont consider root node in diameter

    int rd=DiameterofTree(root->right);
    int ld=DiameterofTree(root->left);
    
    return max(currentDiameter,max(rd,ld));
}

// in this function we calculate the height of the tree along with the diameter so the complexity will be reduced
// the complexity for this function will be O(n)

int calcDiam(Node* root, int* height){

    if(root==nullptr){
       *height=0;
        return 0;
    }

    int lh=0,rh=0;

    int ld=calcDiam(root->left,&lh) ;
    int rd=calcDiam(root->right,&rh) ;

    int currDiam= lh+rh+1;
    *height=max(lh,rh)+1;
    return max(currDiam,max(ld,rd));
    

}
int main()
{
    Node* node=new Node(1);
    node->left=new Node(2);
    node->right=new Node(3);
    node->left->left=new Node(4);
    node->left->right=new Node(5);
    node->right->left=new Node(6);
    node->right->right=new Node(7);
    int h=0;
    cout<<calcDiam(node,&h);
    return 0;
}