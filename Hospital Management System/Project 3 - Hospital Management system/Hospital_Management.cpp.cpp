#include <iostream>
#include <string>
using namespace std;

class Patient{
    int id, age;
    string name, disease;
public:
    Patient(int i=0,string n="",int a=0,string d=""):id(i),age(a),name(n),disease(d){}
    int getId() const{return id;}
    void input(){
        cout<<"ID: ";cin>>id;
        cin.ignore();
        cout<<"Name: ";getline(cin,name);
        cout<<"Age: ";cin>>age;
        cin.ignore();
        cout<<"Disease: ";getline(cin,disease);
    }
    void update(){
        cin.ignore();
        cout<<"New Name: ";getline(cin,name);
        cout<<"New Age: ";cin>>age;
        cin.ignore();
        cout<<"New Disease: ";getline(cin,disease);
    }
    void display() const{
        cout<<"ID: "<<id<<"\nName: "<<name<<"\nAge: "<<age<<"\nDisease: "<<disease<<"\n-----------------\n";
    }
};

struct Node{
    Patient data;
    Node* next;
    Node(Patient p):data(p),next(NULL){}
};

class Hospital{
    Node* head=nullptr;
public:
    ~Hospital(){while(head){Node*t=head;head=head->next;delete t;}}
    void add(){
        Patient p; p.input();
        Node*n=new Node(p);
        if(!head) head=n;
        else{Node*c=head;while(c->next)c=c->next;c->next=n;}
        cout<<"Patient added.\n";
    }
    void display(){
        if(!head){cout<<"No patients.\n";return;}
        for(Node*c=head;c;c=c->next)c->data.display();
    }
    void search(){
        int id; cout<<"Enter ID: ";cin>>id;
        for(Node*c=head;c;c=c->next) if(c->data.getId()==id){c->data.display();return;}
        cout<<"Not found.\n";
    }
    void update(){
        int id; cout<<"Enter ID: ";cin>>id;
        for(Node*c=head;c;c=c->next) if(c->data.getId()==id){c->data.update();cout<<"Updated.\n";return;}
        cout<<"Not found.\n";
    }
    void remove(){
        int id; cout<<"Enter ID: ";cin>>id;
        Node *c=head,*p=nullptr;
        while(c&&c->data.getId()!=id){p=c;c=c->next;}
        if(!c){cout<<"Not found.\n";return;}
        if(!p) head=c->next; else p->next=c->next;
        delete c; cout<<"Deleted.\n";
    }
    void count(){
        int cnt=0; for(Node*c=head;c;c=c->next)cnt++;
        cout<<"Total Patients: "<<cnt<<"\n";
    }
};

int main(){
    Hospital h; int ch;
    do{
        cout<<"\n1.Add\n2.Display\n3.Search\n4.Update\n5.Delete\n6.Count\n7.Exit\nChoice: ";
        cin>>ch;
        switch(ch){
            case 1:h.add();break;
            case 2:h.display();break;
            case 3:h.search();break;
            case 4:h.update();break;
            case 5:h.remove();break;
            case 6:h.count();break;
            case 7:cout<<"Goodbye!\n";break;
            default:cout<<"Invalid choice\n";
        }
    }while(ch!=7);
}
