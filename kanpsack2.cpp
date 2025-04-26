#include<iostream>
using namespace std;
class Knapsack{
    public:
    int n;
    int W;
    int wt[20],p[20];
    int b[20][20];
    void accept();
    void display();
    void knapsack();
};

void Knapsack ::accept(){
    cout<<"Enter the no. of objects";
    cin>>n;
    cout<<"Enter the knapsack size";
    cin>>W;
    for (int i=1;i<=n;i++)
    {
        cout<<"Enter the weight of object";
        cin>>wt[i];
        cout<<"Enter the profit";
        cin>>p[i];
    }

}
void Knapsack::display(){
    cout<<"Knapsack size "<<W;
    cout<<"No.of objects "<<n;
    cout<<"Weight    | Profit";
    for(int i=1;i<=n;i++){
        cout<<wt[i]<<"   |   "<<p[i]<<endl;;
    }
}

void Knapsack :: knapsack(){
int i,j;
for(i=0; i<=n;i++){
    b[i][0]=0;
}
for(i=1;i<=W;i++){
    b[0][i]=0;
}
for(i=1;i<=n;i++){
    for(j=0;j<=W;j++){
        if(wt[i]<=j){
            if(p[i]+b[i-1][j-wt[i]] >b[i-1][j])
            {
                b[i][j]=p[i]+b[i-1][j-wt[i]];
            }
            else{
                b[i][j]=b[i-1][j];
            }
        }
        else{
            b[i][j]=b[i-1][j];
        }
    }
}
for(i=0;i<=n;i++){
    for(j=0;j<=W;j++){
        cout<<b[i][j]<<" ";
    }
    cout<<endl;
}
}

int main(){
    Knapsack k;
    k.accept();
    k.display();
    k.knapsack();
    return 0;
}


