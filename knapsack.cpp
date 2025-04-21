#include<iostream>
using namespace std;
class knapsack
{
	int n;
	int wt[20], p[20];
	int W;
	int b[20][20];
public:
void accept_data();
void display_data();
void dynamic_programming();
void backtrack();
};

void knapsack::accept_data()
{	int i;
	cout<<"Enter no. of objects ";
	cin>>n;
	cout<<"Enter the knapsack size ";
	cin>>W;
	for(i=1;i<=n;i++)
	{
	cout<<"Enter weight of "<<i<<" ";
	cin>>wt[i];
	cout<<"Enter profit of "<<i<<" ";
	cin>>p[i];
	}
}
void knapsack::display_data()
{
	int i;
	cout<<"Knapsack size "<<W<<endl;
	cout<<"weight"<<" | "<<"profit"<<endl;
	for(i=1;i<=n;i++)
	{
	cout<<wt[i]<<" | "<<p[i]<<endl;;
	}
}
void knapsack::dynamic_programming()
{	int i, w;
	for(i=0; i<=W; i++)
	{
		b[0][i] = 0;
	}
	for(i=1;i<=n;i++)
	{
		b[i][0] = 0;
	}
	for(i=1;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
			if(wt[i]<=w)
			{
				if((p[i] + b[i-1][(w-wt[i])]) > b[i-1][w]){
					b[i][w] = p[i]+b[i-1][(w-wt[i])];
					}
				else	{
					b[i][w] = b[i-1][w];
				}}
			else{
				b[i][w] = b[i-1][w];
				}
			}
}
			
			for(i=0;i<=n;i++)
			{
			for(w=0;w<=W;w++){
			
			cout<<b[i][w]<<" ";
					
		}
		cout<<endl;
}
	
}
void knapsack::backtrack()
{
	int i=n;
	int k = W;
	while(i>0 && k>0)
	{
		if(b[i][k] != b[i-1][k])
		{
			cout<<"element selected"<<i<<endl;
			
		k=k-wt[i];
		i=i-1;
		}
		else{
		i=i-1;
		}}}
int main()
{	
	knapsack k;
	k.accept_data();
	k.display_data();
	k.dynamic_programming();
	k.backtrack();
	return 0;
	}
	
