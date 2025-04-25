#include<iostream>
using namespace std;
class NQueen{
    public:
        int X[30];
        int place(int r, int c);
        void nqueen(int r, int n);
        void print(int n);
};

void NQueen::nqueen(int r, int n){

    for(int c=1;c<=n;c++){
        if(place(r,c)==1){
            X[r]=c;
            if(r==n){
                print(n);
            }
            else{
                nqueen(r+1,n);
            }
        }
    }
}

int NQueen::place(int r, int c){
    for (int i=1 ; i<=r-1;i++){
        if((X[i]==c) || abs(X[i]-c)==abs(i-r)){
            return 0;
        }
        else{
            return 1;
        }
    }
}

void NQueen::print(int n){
    for (int i=1;i<=n;i++){
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
NQueen a;
int n;
cout<<"Enter the number of queens";
cin>>n;
if(n==2 || n==3){
    cout<<"No solution exists for "<<n<<" queens."<<endl;
}
else{
    cout<<"The possible solutions are:"<<endl;
    a.nqueen(1,n);
}

return 0;
}