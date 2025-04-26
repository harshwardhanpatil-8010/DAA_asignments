#include <iostream>
#include<fstream>
using namespace std;
class records{
    public:
        int rollno;
        char name[20];
        int marks;
};
class hashing{
    public:
        int pos;
        int rollno;
        hashing(){
            rollno=-1;
            pos=-1;
    }
};
class student {
    public:
    int rel=0;
    hashing h[10];
        void accept();
        void create_wr();
        void display();
};

void student::accept(){
   fstream fout;
   records rec;
   char ch;
   int loc, i;
   fout.open("students.txt", ios::binary | ios::out);
    do{
        cout<<"Enter the details"<<endl;
        cin>>rec.rollno>>rec.name>>rec.marks;
        fout.write((char *)&rec, sizeof(rec));
        loc=rec.rollno%10;
        if(h[loc].rollno == -1){
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
cout<<"do you want to continue";
cin>>ch;

    }while(ch =='y'|| ch =='Y');
    fout.close();
}

void student::display(){
    fstream fin;
    int i;
    records r;
    for(i=0;i<10;i++){
        cout<<h[i].rollno<<" "<<h[i].pos<<endl;
    }
   
    fin.open("student.txt",ios::binary | ios::in);
    while(fin.read((char *)& r, sizeof(r))){
        cout<<r.rollno<<" "<<r.name<<" "<<r.marks<<endl;
    }
    fin.close();
}
void student:: create_wr(){
    fstream fout;
    records rec;
    char ch;
    int loc, i, temproll, temppos, newloc;
    fout.open("students.txt", ios::binary | ios::out);
     do{
         cout<<"Enter the details"<<endl;
         cin>>rec.rollno>>rec.name>>rec.marks;
         fout.write((char *)&rec, sizeof(rec));
         loc=rec.rollno%10;
         if(h[loc].rollno == -1){
             h[loc].rollno=rec.rollno;
             h[loc].pos=rel;
             rel++;
         }
         else{
            temproll=h[loc].rollno;
            temppos=h[loc].pos;
            newloc=temproll%10;
            if(newloc!=loc){
                for(i=(loc+1)%10;i!=loc;i=(i+1)%10){
                    if(h[i].rollno==-1){
                        h[i].rollno=temproll;
                        h[i].pos=temppos;
                        h[loc].rollno=rec.rollno;
                        h[loc].pos=rel;
                        rel++;
                        break;
                    }
                }
            }else{
                for(i=(loc+1)%10;i!=loc;i=(i+1)%10){
                    if(h[i].rollno==-1){
                    h[i].rollno=rec.rollno;
                    h[i].pos=rel;
                    rel++;
                    break;
                    }
                }
            }

         }
         cout<<"do you want to continue";
         cin>>ch;
        }while(ch == 'y' || ch=='Y');
}
int main(){
    student s;
    //s.accept();
    s.create_wr();
    s.display();
    
}