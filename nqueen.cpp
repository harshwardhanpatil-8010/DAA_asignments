#include<iostream>
#include<cmath>
using namespace std;
class NQueen{
    public:
    int X[30];
        void print(int n);
        int place(int r, int c);
        int Nqueen(int r, int n);
};

void NQueen:: print(int n){

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            if(X[i]==j){
                cout<<" Q ";
            }
            else{
                cout<<" - ";
            }

        }
     cout<<"\n";
    }
    cout<<"\n";
}
int NQueen :: place(int r, int c){

    for(int i=1;i<=r-1;i++){
        if((X[i]==c)||abs(X[i]-c)==abs(i-r))
        {
            return 0;
        }
    }
    return (1);
}
int NQueen:: Nqueen(int r, int n){

    for(int c=1;c<=n;c++){
        if(place(r,c)==1){
            X[r] = c;
    
        if(r==n){
            print(n);
                }
        else{
            Nqueen(r+1,n);
        }}
}
return (0);
}
int main(){
 NQueen a;
 int n;
cout<<"Enter the value of n";
cin>>n;

a.Nqueen(1 , n);
return 0;
}