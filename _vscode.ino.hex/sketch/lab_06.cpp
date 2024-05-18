#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\lab_06.cpp"
#include<bits/stdc++.h>
using namespace std;
class uni
{
    public:
    string name;
    string loc;
    uni(string s="__",string l="__"):name(s),loc(l){};
    void get()
    {
        cout<<"Enter the name of the university"<<endl;
        cin>>name;
        cout<<"Enter the location:"<<endl;
        cin>>loc;
    }
    void display()
    {
        cout<<"The name of the university is: "<<name<<endl;
        cout<<"The location of the university is: "<<loc<<endl;
    }
};
class stu:virtual public uni
{
    public:
    string sname;
    int id;
    stu(string un="__",string uloc="__",string name="__",int sid=0):uni(un,uloc),sname(name),id(sid){}
    void get()
    {
        uni::get();
        cout<<"Enter the name of the student"<<endl;
        cin>>sname;

        cout<<"Enter the id of the student"<<endl;
        cin>>id;
    }
    void display()
    {
        uni::display();
        cout<<"The name of the student is: "<<sname<<endl;
        cout<<"The id of the student is: "<<id<<endl;
    }
};
class teacher:virtual public uni
{
    public:
    string tname;
    int age;
    teacher(string un="__",string uloc="__",string tn="__",int ag=0):uni(un,uloc),tname(tn),age(ag){}
    void get()
    {
        uni::get();
        cout<<"Enter the name of the teacher"<<endl;
        cin>>tname;
        cout<<"Enter the age"<<endl;
        cin>>age;
    }
    void display()
    {
        uni::display();
        cout<<"The name of the teacher is: "<<tname<<endl;
        cout<<"The teacher is assigned to: "<<age<<endl;
    }
};
class dept:virtual public stu
{
    public:
    string name;
    dept(string un="__",string uloc="__",string name="__",int sid=0,string dname="__"):stu(un,uloc,name,sid),name(dname){}
    void get()
    {
        stu::get();
        cout<<"Enter the name of the department"<<endl;
        cin>>name;
    }
    void display()
    {
        stu::display();
        cout<<"The name of the department is: "<<name<<endl;
    }
};
class lab: virtual public dept
{
    public:
    int no;
    string *Name;
    lab(string un="__",string uloc="__",string name="__",int sid=0,string dname="__",int n=0):dept(un,uloc,name,sid,dname),no(n)
    {
        Name=new string[no];
    }
    void get()
    {
        dept::get();
        cout<<"Enter the number of courses"<<endl;
        cin>>no;
        Name=new string[no];
        cout<<"Enter the name of the courses"<<endl;
        for(int i=0;i<no;i++)
        {
            cin>>name[i];
        }
    }
    void display()
    {
        dept::display();
        cout<<"The number of courses is: "<<no<<endl;
        cout<<"The name of the courses are: "<<endl;
        for(int i=0;i<no;i++)
        {
            cout<<name[i]<<endl;
        }
    }
};
class course:virtual public dept
{
    public:
    int no;
    string *Name;
    course(string un="__",string uloc="__",string name="__",int sid=0,string dname="__",int n=0):dept(un,uloc,name,sid,dname),no(n)
    {
        Name=new string[no];
    }
    void get()
    {
        dept::get();
        cout<<"Enter the number of courses"<<endl;
        cin>>no;
        Name=new string[no];
        cout<<"Enter the name of the courses"<<endl;
        for(int i=0;i<no;i++)
        {
            cin>>name[i];
        }
    }
    void display()
    {
        dept::display();
        cout<<"The number of courses is: "<<no<<endl;
        cout<<"The name of the courses are: "<<endl;
        for(int i=0;i<no;i++)
        {
            cout<<name[i]<<endl;
        }
    }
};
class hall:virtual public stu
{
    public:
    int status;
    hall(string un="__",string uloc="__",string name="__",int sid=0,int st=0):stu(un,uloc,name,sid),status(st){}
    void get()
    {
        stu::get();
        cout<<"Enter the status of the hall"<<endl;
        cin>>status;
    }
    void display()
    {
        stu::display();
        cout<<"The status of the hall is: "<<status<<endl;
    }
};
int main()
{
    lab x("KUET","Dhaka","Rahim",123,"CSE",3);
    //x.get();
    x.display();
    course y("KUET","Dhaka","Rahim",123,"CSE",3);

    //y.get();
    y.display();
    hall rokeya;
    rokeya.get();
    rokeya.display();
    return 0;
}