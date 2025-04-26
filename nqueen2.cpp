#include<iostream>
#include<cmath>
using namespace std;
class Nqueen{
    public:
    int X[30];
    int nqueen(int r, int n);
    int place(int r, int c);
    void print(int n);
};
int Nqueen :: place(int r, int c){
    for(int i=1;i<=r-1;i++){
        if(X[i]==c || abs(X[i]-c) == abs(i-r)){
            return 0;
        }
    }
    return (1);
}
int Nqueen :: nqueen(int r, int n){
    for(int c=1; c<=n; c++){
        if(place(r,c)==1){
            X[r]=c;
        }
        if(r==n){
            print(n);
        }
        else{
            nqueen(r+1,n);

        }
    }
    return (0);
}

void Nqueen :: print(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(X[i]==j){
                cout<<"Q";
            }
            else{
                cout<<"_";
            }
        }
    }
}

int main(){
    Nqueen a;
    int n;
    cout<<"Enter the no. of values";
    cin>>n;
    a.nqueen(1,n);
    return 0;
}