#include<iostream>
#include <string>
#include <cmath>
using namespace std;
class node{
    public:
    string word;
    string mean;
    node * left;
    node * right;
    friend class avl;
};
class avl{
    public:
    node * root;
    avl(){
        root=NULL;
    }
    void create();
    node* avl_rec(node *, node*);
    void inorder_traversal(node*);
    int BF(node *);
    int height(node * );
    node * balance(node *);
    node * LL_rotation(node *);
    node * RR_rotation(node *);
    node * RL_rotation(node *);
    node * LR_rotation(node *);
};

node* avl::LL_rotation(node * temp){
    node* x;
    node* y;
    x=temp->left;
    y=x->right;
  x->right=temp;
    temp->left=y;
    return (x);
}
node* avl::RR_rotation(node* temp){
    node* x;
    node* y;
    x=temp->right;
    y=x->left;
    x->left=temp;
    temp->right=y;
    return (x);

}

node* avl::RL_rotation(node * temp){
    temp->right=RL_rotation(temp->right);
    return (RR_rotation(temp));
}

node * avl::LR_rotation(node * temp){
    temp->left=LR_rotation(temp->left);
    return (LL_rotation(temp));
}

void avl::create(){
node * curr;
char ch;
do{
    cout<<"Enter the word and its meaning";
    cin>>curr->word;
    cin>>curr->mean;
    curr->left=curr->right=NULL;
    root = avl_rec(curr,root);
    cout<<"Do you want to continue";
    cin>>ch;
}while(ch=='y'||ch=='Y');
inorder_traversal(root);
}

node* avl::avl_rec(node * curr, node *root){
    if (root == NULL) {
        root = new node();
        root->word = curr->word;
        root->mean = curr->mean;
        root->left = root->right = NULL;
    }
    else if(root->word > curr->word){
        root->left = avl_rec(curr, root->left);
        root=balance(root);
    }
    else{ 
        root->right = avl_rec(curr, root->right);
        root = balance(root);
    }
    return root;
}

void avl::inorder_traversal(node*root){
    if(root != NULL){
        inorder_traversal(root->left);
        cout<<root->word<<" "<<root->mean<<endl;
        inorder_traversal(root->right);
    }
}
int avl :: height(node * temp){
    if(temp==NULL){
        return 0;
    }
    else
    {
return (max(height(temp->left),height(temp->right))+1);
    }

}

int avl::BF(node * temp){
    int bf;
    bf = (height(temp->left) - height(temp->right));
    return (bf);
}

node* avl::balance(node * temp){
    int bf;
bf=BF(temp);
if(bf==2){
    if(BF(temp->left)<0){
        temp = LR_rotation(temp);
    }
    else{
        temp = LL_rotation(temp);
    }
    if(bf==-2){
        if(BF(temp->right)<0){
            temp = RR_rotation(temp);
        }
        else{
            temp = RL_rotation(temp);
        }
    }
}
cout<<"Balancing factor"<<bf<<endl;
    return (temp);
}
int main(){
    avl a;
    a.create();
    return 0;
}