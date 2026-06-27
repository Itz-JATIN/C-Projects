#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class Student {
    int rollNo, age;
    string name, branch;
    float cgpa;
public:
    Student() {}
    Student(int r,string n,int a,string b,float c):rollNo(r),age(a),name(n),branch(b),cgpa(c){}
    int getRollNo() const { return rollNo; }
    void display() const{
        cout<<"Roll: "<<rollNo<<"\nName: "<<name<<"\nAge: "<<age<<"\nBranch: "<<branch<<"\nCGPA: "<<cgpa<<"\n\n";
    }
    friend class StudentManager;
};

class StudentManager{
    vector<Student> students;
public:
    void load(){
        ifstream fin("students.txt");
        Student s;
        while(fin>>s.rollNo>>s.name>>s.age>>s.branch>>s.cgpa) students.push_back(s);
    }
    void save(){
        ofstream fout("students.txt");
        for(auto &s:students)
            fout<<s.rollNo<<" "<<s.name<<" "<<s.age<<" "<<s.branch<<" "<<s.cgpa<<"\n";
    }
    void add(){
        Student s;
        cout<<"Roll: ";cin>>s.rollNo;
        cout<<"Name: ";cin>>s.name;
        cout<<"Age: ";cin>>s.age;
        cout<<"Branch: ";cin>>s.branch;
        cout<<"CGPA: ";cin>>s.cgpa;
        students.push_back(s);
    }
    void display(){
        if(students.empty()){ cout<<"No records.\n"; return; }
        for(auto &s:students) s.display();
    }
    void search(){
        int r; cout<<"Roll: "; cin>>r;
        for(auto &s:students)
            if(s.rollNo==r){ s.display(); return; }
        cout<<"Student not found.\n";
    }
    void update(){
        int r; cout<<"Roll: "; cin>>r;
        for(auto &s:students){
            if(s.rollNo==r){
                cout<<"New Name: ";cin>>s.name;
                cout<<"New Age: ";cin>>s.age;
                cout<<"New Branch: ";cin>>s.branch;
                cout<<"New CGPA: ";cin>>s.cgpa;
                return;
            }
        }
        cout<<"Student not found.\n";
    }
    void removeStudent(){
        int r; cout<<"Roll: "; cin>>r;
        auto it=remove_if(students.begin(),students.end(),[&](Student &s){return s.rollNo==r;});
        if(it!=students.end()){students.erase(it,students.end()); cout<<"Deleted.\n";}
        else cout<<"Student not found.\n";
    }
};

int main(){
    StudentManager sm; sm.load();
    int ch;
    do{
        cout<<"\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1: sm.add(); break;
            case 2: sm.display(); break;
            case 3: sm.search(); break;
            case 4: sm.update(); break;
            case 5: sm.removeStudent(); break;
            case 6: sm.save(); cout<<"Data saved.\n"; break;
            default: cout<<"Invalid choice.\n";
        }
    }while(ch!=6);
}
