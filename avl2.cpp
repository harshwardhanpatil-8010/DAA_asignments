#include<iostream>
#include<algorithm>
using namespace std;
class node{
    public:
    node* left;
    node* right;
    string word;
    string mean;
    friend class AVL;
};
class AVL{
    public:
    node * root;
    void create(); 
    node* AVL_rec(node*, node*);
    void inorder_traversal(node*);
    node* balance(node*);
    int BF(node*);
    int height(node*);
    node* LR_rotation(node*);
    node* LL_rotation(node*);
    node* RR_rotation(node*);
    node* RL_rotation(node*);
};
void AVL::inorder_traversal(node* root){
    if(root!=NULL)
{
    inorder_traversal(root->left);
    cout<<root->word;
    cout<<root->mean;
    inorder_traversal(root->right);
}}

node* AVL::LL_rotation(node* temp){
    node* x;
    node* y;
    x=temp->left;
    y=x->right;
    x->right=temp;
    temp->left=y;
    return(x);
}
node* AVL :: AVL_rec(node* curr, node* root)
{
    if(root=NULL){
        root=new node();
        root->word=curr->word;
        root->mean=curr->mean;
        root->left=root->right=NULL;
    }
    else if(curr->word < root->word){
        root->left=AVL_rec(curr,root->left);
        root=balance(root);
    }
    else{
        root->right=AVL_rec(curr,root->right);
        root=balance(root);
    }
    return(root);

}
node* AVL::balance(node* temp){
    int bf;
    bf=BF(temp);
    if(bf==2){
        if(BF(temp->left)<0){
           temp= LR_rotation(temp);
        }
        else{
            temp=LL_rotation(temp);
        }
    }
    else if(bf==-2){
        if(BF(temp->right)<0){
            temp=RL_rotation(temp);
        }
        else{
            temp=RR_rotation(temp);
        }
    }
    return(temp);

}
int AVL::height(node* temp){
    if(temp==NULL){
        return 0;
    }
    else{
        return (max(height(temp->left),height(temp->right))+1);
    }
}
int AVL::BF(node* temp){
    int bf;
    bf = height(temp->left)-height(temp->right);
    return (bf);
}


void AVL :: create(){
    node * curr;
    char ch;
    do{
        curr=new node();
        cout<<"Enter the word and its meaning";
        cin>>curr->word;
        cin>>curr->mean;
        curr->left=curr->right=NULL;
        root=AVL_rec(curr,root);
        cout<<"do you want to continue";
        cin>>ch;
    }while(ch=='y');
    inorder_traversal(root);
}