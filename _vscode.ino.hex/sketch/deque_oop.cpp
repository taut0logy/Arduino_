#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\deque_oop.cpp"
#include<bits/stdc++.h>
using namespace std;
class maxdeque;
class student
{
    int roll;
    string name;
    double cg;
    public:
    student(int r=0,string n="None",double c=0.0)
    {
        roll=r;
        name=n;
        cg=c;
    }
    void display()
    {
        cout<<roll<<" "<<name<<" "<<cg<<" "<<endl;
    }
    friend class maxdeque;
    friend struct greater<student>;
};
namespace std
{
    template<>
    struct greater<student>
    {
        bool operator()(const student& p1, const student& p2) const
        {
            return p1.cg < p2.cg;
        }
    };
}
class maxdeque
{
    deque<student> dq;
    priority_queue<student,vector<student>,greater<student>> max;
    public:
    bool empty()
    {
        return dq.empty();
    }
    void push_back(student s)
    {
        dq.push_back(s);
        max.push(s);
    }
    void push_front(student s)
    {
        dq.push_front(s);
        max.push(s);
    }
    void pop_back()
    {
        if(dq.empty())
        {
            cout<<"Deque is empty"<<endl;
            return;
        }
        stack<student> temp;
        while(max.top().cg!=dq.back().cg)
        {
            temp.push(max.top());
            max.pop();
        }
        max.pop();
        dq.pop_back();
        while(!temp.empty())
        {
            max.push(temp.top());
            temp.pop();
        }
    }
    void pop_front()
    {
        if(dq.empty())
        {
            cout<<"Deque is empty"<<endl;
            return;
        }
        stack<student> temp;
        while(max.top().cg!=dq.front().cg)
        {
            temp.push(max.top());
            max.pop();
        }
        max.pop();
        dq.pop_front();
        while(!temp.empty())
        {
            max.push(temp.top());
            temp.pop();
        }
    }
    student getmax()
    {
        return max.top();
    }
    void display()
    {
        for(auto i:dq)
        {
            i.display();
        }
    }
};
int main()
{
    student s1(1,"A",3.5);
    student s2(2,"B",3.6);
    student s3(3,"C",3.7);
    student s4(4,"D",3.8);
    student s5(5,"E",3.9);
    maxdeque md;
    md.push_back(s1);
    md.push_front(s2);
    md.push_back(s3);
    md.push_front(s4);
    md.push_back(s5);
    md.display();
    cout<<endl;
    md.getmax().display();
    md.pop_back();
    md.getmax().display();
    md.pop_front();
    md.getmax().display();
    return 0;
}