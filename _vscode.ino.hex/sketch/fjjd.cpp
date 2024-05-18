#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\fjjd.cpp"
#include<bits/stdc++.h>
using namespace std;

class university
{
public:
    string name;
    string location;
    
    void setname()
    {
        cout<<"Enter the name of the university"<<endl;
        cin>>name;
    }
    
    void setlocation()
    {
        cout<<"Enter the location of the university"<<endl;
        cin>>location;
    }
    
    void display()
    {
        cout<<name<<" "<<location<<endl;
    }
};

class student: public university
{
public:
    string student_name;
    int rollno;
    
    void setname()
    {
        university::setname();
        cout<<"Enter the name of the student"<<endl;
        cin>>student_name;
    }
    
    void setrollno()
    {
        cout<<"Enter the roll number of the student"<<endl;
        cin>>rollno;
    }
    
    void display()
    {
        cout<<student_name<<" "<<rollno<<endl;
    }
};

class teacher: public university
{
    string teacher_name;
    string research;
public:
    void setname()
    {
        university:: setname();
        cout<<"Enter the name of the teacher"<<endl;
        cin>>teacher_name;
    }
    
    void setresearch()
    {
        cout<<"Enter the research area of the teacher"<<endl;
        cin>>research;
    }
    
    void display()
    {
        university::display();  
        cout<<teacher_name<<" "<<research<<endl;
    }
};

class cse: public student
{
    int marks[3];
public:
    void setmarks()
    {
        cout<<"Enter the marks of the student"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>marks[i];
        }
    }
    
    void display()
    {
        student::display();
        for(int i=0;i<3;i++)
        {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};

class ece: public student
{
    int marks[3];
public:
    void setmarks()
    {
        cout<<"Enter the marks of the student"<<endl;
        for(int i=0;i<3;i++)
        {
            cin>>marks[i];
        }
    }
    
    void display()
    {
        student::display();
        for(int i=0;i<3;i++)
        {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    cse c;
    ece e;
    c.setname();
    c.setrollno();
    c.setmarks();
    c.display();
    return 0;
}