#include<iostream>
using namespace std;
class node{
	
	public:
		string word;
		string mean;
		node* left;
		node* right;
		friend class AVL;
	};
class AVL{
		public:
		AVL(){
		root=NULL;
		}
		node* root;
		void create_AVL();
		node* AVL_rec(node*,node*);
		node* balance(node*);
		int BF(node*);
		int height(node*);
		node* LL_rotation(node*);
		node* RR_rotation(node*);
		node* RL_rotation(node*);
		node* LR_rotation(node*);
		void inorder_traversal(node*);
		void AVL_search();
		void AVL_modify();
		};

void AVL::inorder_traversal(node* root){
	if(root!=NULL){
	inorder_traversal(root->left);
	cout<<root->word<<" ";
	cout<<root->mean;
	inorder_traversal(root->right);
	}
}
node* AVL::RL_rotation(node *temp){
	temp->right=LL_rotation(temp->right);
	return(RR_rotation(temp));
	}


node* AVL::LR_rotation(node *temp){
	temp->left=RR_rotation(temp->left);
	return(LL_rotation(temp));
	}

node* AVL::RR_rotation(node *temp)
{	node* x;
	node* y;
	x=temp->right;
	y=x->left;
	x->left=temp;
	temp->right=y;
	return (x);
	}
	
node* AVL::LL_rotation(node* temp)
{	node* x;
	node* y;
	x=temp->left;
	y=x->right;
	x->right=temp;
	temp->left=y;
	return(x);
	}
	
int AVL::height(node* temp)
{
	if(temp==NULL){
		return (0);
		}
	else{
		return (max(height(temp->left), height(temp->right))+1);
		}
	}
	
int AVL::BF(node* temp)
{
	int bf;
	bf=height(temp->left) - height(temp->right);
	return(bf);
	}

		
node* AVL::balance(node* temp){
	int bf;
	bf=BF(temp);
	if(bf==2)
	{
		if(BF(temp->left)<0){
			temp=LR_rotation(temp);
			}
		else{
			temp=LL_rotation(temp);
			}
			}
	if(bf==-2)
	{
		if(BF(temp->right)>0){
		temp=RR_rotation(temp);
		}
		else{
			temp=RL_rotation(temp);
			}
			}
			cout<<"Balancing factor"<<bf<<endl;
			return(temp);
			}
	
node* AVL::AVL_rec(node* curr,node* root)
{
	if(root==NULL){
		root=new node();
		root->word=curr->word;
		root->mean=curr->mean;
		root->left=root->right=NULL;
		}
	else if(curr->word < root->word)
	{
		root->left=AVL_rec(curr, root->left);
		root=balance(root);
		}
		else{
		root->right=AVL_rec(curr,root->right);
		root=balance(root);
		}
		return root;
		}
		
void AVL::create_AVL(){
	node* curr;
	char ch;
	do{
		curr=new node();
		cout<<"Enter word and its meaning"<<endl;
		cin>>curr->word;
		cin>>curr->mean;
		curr->left=curr->right=NULL;
		root = AVL_rec(curr,root);
		cout<<"do you want to continue"<<endl;
		cin>>ch;
		}while(ch=='y');
			inorder_traversal(root);
		}

void AVL::AVL_search(){
string key;
node* temp;
	cout<<"Enter the keyword to search";
	cin>>key;
	temp=root;
	while(temp!=NULL)
	{
		if(temp->word==key)
		{
			cout<<temp->mean;
			break;
			}
		else if(temp->word > key)
			temp=temp->left;
		else
			temp=temp->right;
			
			}
			}
void AVL::AVL_modify(){
	string newmean;
	string key;
	node *temp;
	cout<<"Enter keyword to modify ";
	cin>>key;
	cout<<"enter new mean ";
	cin>>newmean;
	temp=root;
	while(temp!=NULL){
		if(temp->word==key)
		{
			
			temp->mean=newmean;
			cout<<"New meaning is: "<<temp->mean;
			break;
			}
		else if(temp->word > key)
			temp=temp->left;
		else 
			temp=temp->right;
			
			}
			
			}
int main(){
	AVL a;
	a.create_AVL();
	a.AVL_search();
	a.AVL_modify();
	return 0;
	}