#include<iostream>
#include<fstream>
using namespace std;

class record {
    public:
    int rollno;
    char name[20];
    int marks;
    
};
class hashing{
    public:
    int rollno;
    int pos;
    hashing(){
        rollno=-1;
        pos=-1;
    }
};

class student{
    int rel=1;
    hashing h[10];
    public:
    void create_wor();
    void create_wr();
    void search();
    void display();
    friend class record;
};

void student::create_wor(){
    record rec;
    fstream fout;
    int i;
    int loc;
    char ch;
    fout.open("student.txt",ios::binary | ios::out);
do{
    cout<<"Enter the details of the student"<<endl;
    cin>>rec.rollno>>rec.name>>rec.marks;
    fout.write((char*)&rec, sizeof(rec));
   loc = rec.rollno%10;
   if(h[loc].rollno==-1){
        h[loc].rollno=rec.rollno;
        h[loc].pos=rel;
        rel++;
   }
   else{
    for(i=loc+1;i!=loc;i=(i+1)%10){ 
        if(h[i].rollno==-1){
            h[i].rollno=rec.rollno;
            h[i].pos=rel;
            rel++;
            break;
        }
    }
   }
   cout<<"do you want to continue"<<endl;
   cin>>ch;
    }while(ch=='y');
    fout.close();

}
void student::display(){
    int i;
    record r;
    fstream fin;
    
    for(i=0;i<10;i++){
        cout<<h[i].rollno<<" "<<h[i].pos<<endl;
    }
    fin.open("student.txt", ios::binary | ios::in);
    while(fin.read((char*)&r,sizeof(r)))
    {
       
        cout<<r.rollno<<" "<<r.name<<" "<<r.marks<<endl;
    }
    fin.close();

}
void student::search() {
    record rec;
    int rollno;
    hashing h[10];
    fstream fin;
    int i;
    cout<<"Enter the rollno to be searched"<<endl;
    cin>>rollno;
    fin.open("student.txt",ios::binary | ios::in);
    
    while(fin.read((char*)&rec,sizeof(rec))) {
        if(rec.rollno==rollno){
            cout<<"Record found "<<endl;
            cout<<rec.rollno<<" "<<rec.name<<" "<<rec.marks<<endl;          
        }
    fin.close();
}
}

void student::create_wr(){
    record rec;
    fstream fout;
    int i;
    int loc, newloc;
    char ch;
    int temproll;
    int temppos;
    fout.open("student.txt",ios::binary | ios::out);
do{
    cout<<"Enter the details of the student"<<endl;
    cin>>rec.rollno>>rec.name>>rec.marks;
    fout.write((char*)&rec, sizeof(rec));
   loc = rec.rollno%10;
   if(h[loc].rollno==-1){
        h[loc].rollno=rec.rollno;
        h[loc].pos=rel;
        rel++;
   }
   else{
    temproll = h[loc].rollno;
    temppos = h[loc].pos;
    newloc = temproll%10;
    if(loc != newloc){
        for(i=loc+1;i!=loc;i=(i+1)%10){
            if(h[i].rollno==-1){
                h[i].rollno=temproll;
                h[i].pos=temppos;
                rel++;
                  break;
            }
        }
    }
    else{
        for(i=loc+1;i!=loc;i=(i+1)%10){
            if(h[i].rollno==-1){
                h[i].rollno=rec.rollno;
                h[i].pos=rel;
                rel++;
                break;
            }
        }
    }
   }
cout<<"do you want to continue"<<endl;
cin>>ch;
   }while(ch=='y');
   fout.close();
}
int main(){
    student s;
  //  s.create_wor();
    s.create_wr();
    s.display();
    s.search();
}