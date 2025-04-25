#include<iostream>
using namespace std;
class graph{
		int cost[10][10];
	public:
		int city;
		void create();
		void display();
		void prims_algo(int s);
		};		
	void graph::create(){
		char ch;
		int i,j;
			cout<<"Enter the number of cities";
			cin>>city;
		for(i=0;i<city;i++)
		{	
			for(j=0; j<city; j++){
			cout<<"Is there connection between"<<i<<"and"<<j<<"?(y/n)";
			cin>>ch;
			if(ch=='y'){
				cout<<"Enter the cost of edge";
				cin>>cost[i][j];
				
				}
				else
				cost[i][j]=9999;}}}
	void graph::display(){
	int i,j;
		cout<<"Adjacency matrix:\n"<<endl;
		for(i = 0; i < city; i++)
	{		for(j = 0; j < city; j++)
		{
				cout<<" " <<cost[i][j]<<" ";	
		}
			cout<<endl;
			}}

 void graph:: prims_algo(int s){
	int nearest[20],min;
	int mincost = 0;
	int i, j, k, l;
	nearest[s]=-1;
	for( i=0;i<city;i++)
	{
		if(i!=s)
		nearest[i]=s;
		}
		
		for(i=0;i<city-1;i++);
		{
			min = 9999;
			for( j=0;j<city;j++)
			{
				if(nearest[j]!=-1 && cost[j][(nearest[j])]<min)
				{	
					min=cost[j][(nearest[j])];
					l=j;
					}}
					mincost = mincost + cost[l][(nearest[l])];
					nearest[l] = -1;
					for(k=0; k<city; k++)
					{	
						if(nearest[k] != -1 && cost[l][k] < cost[(nearest[k])][k])
						{
							nearest[k]=l;
							}}
							cout<<"minimum spanning tree is"<<mincost<<endl;
							}}
							
int main(){
	graph g;
	int s;
	int city;
	g.create();
	g.display();
	cout<<"Enter the starting vertex";
	cin>>s;
	g.prims_algo(s);
	}