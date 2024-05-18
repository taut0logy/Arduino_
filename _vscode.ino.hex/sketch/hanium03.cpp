#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\hanium03.cpp"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class animal
{
    public:
    int age;
    int weight;
    void speak()
    {
        cout<<"speakinng"<<endl;
    }

};
class dog:public animal{

};
int main()
{
    dog d;
    d.speak();
    cout<<d.age<<endl;
    return 0;
}