#include<iostream>
using namespace std;

class Knapsack{
    int n, W;
    int wt[30], p[30];
    int b[30][30];
    public:
    void accept();
    void display();
    void knapsack();
    void backtrack();
};

void Knapsack::accept(){
    cout<<"Enter the Knapsack Size";
    cin>>W;
    cout<<"Enter the number of objects";
    cin>>n;
    for(int i=1;i<=n;i++){
        cout<<"Enter the weight of item"<<i<<" ";
        cin>>wt[i];
        cout<<"Enter the profit of object"<<i<<" ";
        cin>>p[i];
    }
}

void Knapsack::display(){
    cout<<"Knapsack Size = "<<W<<endl;
    cout<<"Number of objects = "<<n<<endl;
    cout<<"Weight       |       Profit"<<endl;
    for(int i=1;i<=n;i++){
        cout<<wt[i]<<"       |       "<<p[i]<<endl;
    }
}
void Knapsack::knapsack(){
    int j,i;
    for( i=0;i<=W;i++){
        b[0][i]=0;
    }
    for(i=0;i<=n;i++){
        b[i][0]=0;
    }
  
    for(i=1;i<=n;i++){
        for( j=0;j<=W;j++){
                if(wt[i]<=j){
                    if(p[i]+b[i-1][j-wt[i]] > b[i-1][j]){
                        b[i][j]=p[i]+b[i-1][(j-wt[j])];

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
                    cout<<b[i][j]<<"  ";
                }
            cout<<endl;
    }
}

void Knapsack::backtrack(){
    int i=n;
    int j=W;
    while(i>0 && j>0){
        if(b[i][j] != b[i-1][j]){
            cout<<"Element Selected"<<i;
            j=j-wt[i];
            i=i-1;

        }
        else{
            i=i-1;
        }
    }
}
int main(){
    Knapsack k;
    k.accept();
    k.display();
    k.knapsack();
    k.backtrack();
    return 0;
}
