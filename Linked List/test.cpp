#include<bits/stdc++.h>       
using namespace std;

class Node{           // a node class for creating a tree
    public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val)      // parameterised constructor 
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void preorderTraversal(Node* root)     // function to traverse the nodes in preorder manner
{
    if (!root)          // if the root is NULL then return 
        return;
 
    stack<Node*> stk;  // create a stack of Node* type
    stk.push(root);     // push the root element into the stack
    
    while(!stk.empty())          // traverse till the stack is not empty
    {
        Node* f=stk.top();       // assign the value of the top most elemnt of stack to a temp node variable
        stk.pop();
        cout<<f->data<<" ";
     
        if (f->right)
            stk.push(f->right);    // pushing the right child so as to process the left child first
        if (f->left)
            stk.push(f->left);      // push the left child of root into the stack
    }

}

int main()
{
    Node* root=new Node(1);     // creating a tree
    root->left=new Node(2);
    root->right=new Node(3);
    
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    
    preorderTraversal(root);    // preorderTraversal function call
    return 0;
}
