#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\practice.cpp"
#include<bits/stdc++.h>
#include<typeinfo>
using namespace std;
class team
{
    int nump;
    vector<string> pname;
    public:
    static int matchcnt;
    team()
    {
        nump=11;
    }
    team(int nump,vector<string> pname)
    {
        this->nump=nump;
        this->pname=pname;
    }
    virtual void play()=0;
    void updatematch()
    {
        matchcnt++;
    }
    friend istream& operator>>(istream& in,team& t)
    {
        in>>t.nump;
        for(int i=0;i<t.nump;i++)
        {
            string s;
            in>>s;
            t.pname.push_back(s);
        }
        return in;
    }
};
int team::matchcnt=0;   
class cricket:public team
{
    int matchplayed,run,wicket;
    public:
    cricket()
    {
        matchplayed=0;
        run=0;
        wicket=0;
    }
    cricket(int nump,vector<string> pname,int matchplayed,int run,int wicket):team(nump,pname)
    {
        this->matchplayed=matchplayed;
        this->run=run;
        this->wicket=wicket;
    }
    void play()
    {
        cout<<"cricket"<<endl;
        matchplayed++;
        updatematch();
    }
    friend istream& operator>>(istream& in,cricket& c)
    {
        in>>dynamic_cast<team&>(c);
        in>>c.matchplayed>>c.run>>c.wicket;
        return in;
    }
};
class football:public team
{
    int matchplayed,goal,assist;
    public:
    football()
    {
        matchplayed=0;
        goal=0;
        assist=0;
    }
    football(int nump,vector<string> pname,int matchplayed,int goal,int assist):team(nump,pname)
    {
        this->matchplayed=matchplayed;
        this->goal=goal;
        this->assist=assist;
    }
    void play()
    {
        cout<<"football"<<endl;
        matchplayed++;
        updatematch();
    }
    friend istream& operator>>(istream& in,football& f)
    {
        in>>dynamic_cast<team&>(f);
        in>>f.matchplayed>>f.goal>>f.assist;
        return in;
    }
};
class basketball:public team
{
    int matchplayed,point,rebound;
    public:
    basketball()
    {
        matchplayed=0;
        point=0;
        rebound=0;
    }
    basketball(int nump,vector<string> pname,int matchplayed,int point,int rebound):team(nump,pname)
    {
        this->matchplayed=matchplayed;
        this->point=point;
        this->rebound=rebound;
    }
    void play()
    {
        cout<<"basketball"<<endl;
        matchplayed++;
        updatematch();
    }
    friend istream& operator>>(istream& in,basketball& b)
    {
        in>>dynamic_cast<team&>(b);
        in>>b.matchplayed>>b.point>>b.rebound;
        return in;
    }
};
void playgame(team* t1,team* t2)
{
    //use dynamic casting to determine if they are from the same team and increase match count
    if(dynamic_cast<cricket*>(t1)!=NULL && dynamic_cast<cricket*>(t2)!=NULL)
    {
        cout<<"cricket"<<endl;
        t1->play();
        t2->play();
    }
    else if(dynamic_cast<football*>(t1)!=NULL && dynamic_cast<football*>(t2)!=NULL)
    {
        cout<<"football"<<endl;
        t1->play();
        t2->play();
    }
    else if(dynamic_cast<basketball*>(t1)!=NULL && dynamic_cast<basketball*>(t2)!=NULL)
    {
        cout<<"basketball"<<endl;
        t1->play();
        t2->play();
    }
    else
    {
        cout<<"not same"<<endl;
    }
}
int main()
{
    team* t1;
    team* t2;
    football x;
    cin>>x;
    t1=&x;
    cricket y;
    cin>>y;
    t2=&y;
    playgame(t1,t2);
    cout<<team::matchcnt<<endl;
    return 0;
}
