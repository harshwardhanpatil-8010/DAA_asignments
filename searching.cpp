#include<iostream>
#include<string>

using namespace std;
class mobileUser
{
  	private:
  		string username;
  		unsigned long long mobileno;
  		double billamount;
  		int key;
  		
  	public:
  		void accept();
  		void display();
  		void quicksort(mobileUser num[20],int low,int high);
  		int partition(mobileUser num[20], int low, int high);
        void linear_search(mobileUser num[100], long key, int n)
   {	
		for(int i=0; i<n; i++)
		{
			if(num[i].mobileno==key)
				{cout<<"key present at loc "<<i<<endl;
				break;}
			if(i==n)
		cout<<"Key not present"<<endl;
	}}
int binary_search_iterr(mobileUser num[100], int n, long key)
  {
  	int	low =0;
  	int	high=n-1;
  	int mid;
  	while(low<=high){
  	mid=(low + high)/2;
  	if(num[mid].mobileno==key){
		return(mid);
		}
	else if (key < num[mid].mobileno)
		high = mid-1;
	else
		low = mid +1;
	}return(-1);
	}
  	};
  
  void mobileUser::accept()
{
	cout<<"\nEnter the name"<<endl;
	cin>>username;
	cout<<"\nEnter the mobileno."<<endl;
	cin>>mobileno;
	cout<<"\nEnter the bill amount"<<endl;
	cin>>billamount;
	}
  void mobileUser::display()
{
	cout<<"username: "<<username<<"\nmobile no.: "<<mobileno<<"\nBill amount: "<<billamount<<endl;
	}
void mobileUser::quicksort(mobileUser num[20],int low,int high){
	
	if(low<high){
		int j=partition(num,low,high);
		quicksort(num,low,j-1);
		quicksort(num,j+1,high);
		}}
	int mobileUser::partition(mobileUser num[20], int low, int high)
		{	mobileUser pivot;
			int i=low;
			int j=high;
			mobileUser temp;
		
			pivot=num[low];
			while(i<j){
				while(num[i].mobileno<=pivot.mobileno && i<high)
				i++;
				while(num[j].mobileno>pivot.mobileno && j>low)
				j--;
			if(i<j){
				temp = num[i];
				num[i]=num[j];
				num[j]=temp;
				
				}
				}
				temp=num[j];
				num[j]=pivot;
				pivot=temp;
				
				return j;			
				}
	// void mobileUser::Heap_sort(mobileUser )
	// 	{
	// 	for i= (n/2)-
int main()
{	
	int n;
	long key;
	int low=0;
	int high=n-1;
	
	mobileUser m1[100],m2,m3,m4;
	cout<<"Enter the number of users:"<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
	m1[i].accept();
	
	}
	//for(int i=0;i<n;i++){
	
//	m1[i].display();
	//}
	//cout<<"enter the key value"<<endl;
	//cin>>key;
	//int loc = m2.linear_search(m1,key,n);
	//int loc = m2.binary_search_iterr(m1,n,key);
	//cout<<loc;
	//int loc = m3.binary_search_rec(m1,n,key);
	//cout<<loc;
	m2.quicksort(m1,low,high);
	for(int i=0; i<n; i++)
	m1[i].display();

}
	