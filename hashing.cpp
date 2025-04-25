#include<iostream>
#include<fstream>
using namespace std;
class record{
    public:
        int rollno;
        char name[20];
        int marks;

};
class hashing{
   public:
    int rollno, pos;
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
        void display();
        void search();
        void create_wr();
};

void student::create_wor(){
    int loc;
    char ch;
    record rec;
    int i;
    fstream fout;
    fout.open("student.txt",ios::binary | ios::out);

 do{
    cout<<"Enter rollno, name and marks";
    cin>>rec.rollno>>rec.name>>rec.marks;
    fout.write((char*)&rec, sizeof(rec));

    loc=rec.rollno%10;
    if(h[loc].rollno==-1){
        h[loc].rollno=rec.rollno;
        h[loc].pos=rel;
        rel++;
    }
   else{
    for(i=loc+1;i!=loc;i=(i+1)%10)
    {
        if(h[i].rollno==-1){
            h[i].rollno=rec.rollno;
            h[i].pos=rel;
            rel++;
            break;
        }
    }
   }
 
    cout<<"do you want to continue(y/n)";
    cin>>ch;
}while(ch=='y');
fout.close();
}

void student::display(){
    fstream fin;
    record r;
    for(int i=0;i<10;i++){
        cout<<h[i].rollno<<" "<<h[i].pos<<endl;
    }
    fin.open("student.txt",ios::binary | ios::in);
    while(fin.read((char *)& r, sizeof(r))){
        cout<<r.rollno<<" "<<r.name<<" "<<r.marks<<endl;
    }
    fin.close();
}
void student::search(){
    int rollno;
    int loc;
    record rec;
    int r;
    fstream fin;
    cout<<"Enter the rollno to be searched";
    cin>>rollno;
    fin.open("student.txt",ios::in);
    loc=rollno%10;
for(int i=0;i<=10;i++){
    if(h[loc].rollno==rollno)
    {
        r=(h[loc].pos-1) * sizeof(rec);
        fin.seekg(r, ios::beg);
        fin.read((char*) & rec, sizeof(rec));
        cout<<rec.rollno<<" "<<rec.name<<" "<<rec.marks<<endl;
       break;
    }
    else{
        loc = loc+1;
    }}

}   
void student::create_wr() {
    int loc, newloc, temproll, tempos, i;
    char ch;
    record rec;
    fstream fout;
    fout.open("student1.txt", ios::binary | ios::out);

    do {
        cout << "Enter rollno, name and marks: ";
        cin >> rec.rollno >> rec.name >> rec.marks;
        fout.write((char *)&rec, sizeof(rec));

        loc = rec.rollno % 10;
        if (h[loc].rollno == -1) {
            h[loc].rollno = rec.rollno;
            h[loc].pos = rel++;
        } else {
            temproll = h[loc].rollno;
            tempos = h[loc].pos;
            newloc = temproll % 10;

            if (loc != newloc) {
             
                for (i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    if (h[i].rollno == -1) {
                        h[i].rollno = temproll;
                        h[i].pos = tempos;
                        h[loc].rollno = rec.rollno;
                        h[loc].pos = rel++;
                        break;
                    }
                }
            } else {
                
                for (i = (loc + 1) % 10; i != loc; i = (i + 1) % 10) {
                    if (h[i].rollno == -1) {
                        h[i].rollno = rec.rollno;
                        h[i].pos = rel++;
                        break;
                    }
                }
            }
        }

        cout << "Do you want to add more records (y/n)? ";
        cin >> ch;
    } while (ch == 'y');

    fout.close();
}



int main()
{
    student s;
    // s.create_wor();
    s.create_wr();
    s.display();
    s.search();
    return 0;
}