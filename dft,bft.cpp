#include<string>
#include<iostream>

using namespace std;
class node{
	int userid;
	string name;
	node *next;
public:
	node(){
		userid=0;
		next=NULL;
}
friend class FB;
	};
class FB{
public:
	node *Head[100];
	int noofusers;
	

	void create_adjlist();
	void display_adjlist();
	void DFT(int n2);
	void BFT(int startingvertex);
	void DFS_r(int n2, int visited[100]);
	
	
friend class stack;
friend class Queue;
};
class Queue{
	
	public:
	int Queue[100];
	int f=-1;
	int r=-1;
		void insert (int userid)
		{	
			r++;
			Queue[r]=userid;
		}
		int Qdelete()
		{
			int t;
			f++;
			t=Queue[f];
			
			return(t);
		}
		int Qempty()
		{
			if(f==r)
				return(1);
			else
				return(0);
				
		}
};

class stacks{
	int stack[100];
	int top=-1;
public:
	int full(){
		if(top==99)
		return 1;
		else
		return 0;
		}
	int empty(){
	if(top==-1)
	return 1;
	else 
	return 0;
	}
	void push(int temp){
		if(full()==0)
		{
			top++;
			stack[top]=temp;
			}
		}
	int pop(){
		int temp;
		if(empty()==0){
		temp=stack[top];
		top--;
		return temp;
		}
		return 0;
		}
		
};
	void FB::create_adjlist()
	{	int i;
		char ch;
		node *curr;
		node *temp;
		cout<<"Enter number of users"<<endl;
		cin>>noofusers;
		for(i=0;i<noofusers;i++)
		{
			Head[i]=new node();
			cout<<"Enter the userid and name";
			cin>>Head[i]->userid>>Head[i]->name;
			Head[i]->next=NULL;
		}
		for(i=0;i<noofusers;i++)
		{
			temp=Head[i];
			do{
				cout<<"does user"<<Head[i]->userid<<"Has any friends"<<endl;
				cin>>ch;
				if(ch=='y')
				{	
					curr=new node();
					curr->next=NULL;
					cout<<"Friend details: id and name"<<endl;
					cin>>curr->userid>>curr->name;
					temp->next=curr;
					temp = curr;
					}
					}while(ch=='y');
					}
}
	void FB::display_adjlist()
{	int i;
	node *temp;
	for(i=0;i<noofusers;i++)
	{
		temp=Head[i];
		while(temp!=NULL)
		{	
			cout<<"->"<<temp->userid<<" "<<temp->name<<endl;
			temp=temp->next;
			}
	}
}
	
	void FB::DFT(int n2)
	{	node *temp;
		int visited[100];
		stacks s;
		int i;
		
		int v;
		s.push(n2);
		for(i=0;i<noofusers;i++)
		{
			visited[i]=0;
			}
		while(s.pop()==0)
		{
			v = s.pop();
			if(visited[v]==0)
				cout<<Head[v]->userid<<" "<<Head[v]->name;
				visited[v]=1;
			temp=Head[v]->next;
				while(temp!=NULL);
				{
					if(visited[temp->userid]==0)
						s.push(temp->userid);						
						}
						temp=temp->next;
						}
						}	
	void FB::BFT(int startingvertex)
	{	int v,u;
		int i;
		node *temp;
		int visited[100];
		Queue q;
		q.insert(startingvertex);
		for(i=0; i<noofusers; i++)
		{
			visited[i]=0;
			
			}
		while(q.Qempty()==0)
		{
			v=q.Qdelete();
			
				cout<<Head[v]->userid<<Head[v]->name;
				visited[v]=1;
			temp=Head[v]->next;
			while(temp!=NULL){
			if(visited[temp->userid]=0)
				q.insert(temp->userid);
				temp=temp->next;
				
			}	}
	}
	void FB::DFS_r(int n2, int visited[100])
		{	node *temp;
			cout<<Head[n2]->userid<<Head[n2]->name;
			visited[n2]=1;
			temp=Head[n2]->next;
			while(temp!=NULL)
			{
				if(visited[temp->userid]==0)
				DFS_r(temp->userid, visited);
				temp=temp->next;
				}
	
		
}
int main()
{	int n2,i,visited[100];
	FB n1;
	int ch;
	n1.create_adjlist();
	n1.display_adjlist();
	cout<<"enter the operation which you want to select";
	cin>>ch;
	switch(ch){
		case 1: 
			cout<<"Enter the starting node";
			cin>>n2;
			n1.DFT(n2);
			
			break;
		case 2: 
			cout<<"Enter the starting vertex for BFT";
			cin>>n2;
			n1.BFT(n2);
			
			break;
		case 3: 
			for(i=0;i<n1.noofusers;i++)
				{
					visited[i]=0;
					}
			cout<<"Enter the starting node for DFS_reccursive"<<endl;
			cin>>n2;
			n1.DFS_r(n2, visited);
			
			break;
		default:
			cout<<"Enter a valid choice";
			break;
			}
	return 0;
	}						