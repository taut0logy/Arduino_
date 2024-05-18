#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\string_conc.cpp"
#include <bits/stdc++.h>
using namespace std;
class String
{
    char* s;
    int l;

public:
    String()
    {
        s = new char[100];
        s[0] = '\0';
        l = 0;
    }
    String(char* s2)
    {
        s = new char[strlen(s2) + 1];
        strcpy(s, s2);
        l = strlen(s);
    }
    void display()
    {
        cout << s << endl;
    }
    friend String operator+(String &x1, String &x2);
};
String operator+(String &x1, String &x2)
{
    String x;
    x.l = strlen(x1.s) + strlen(x2.s);
    x.s = new char[x.l + 1];
    strcpy(x.s, x1.s);
    strcat(x.s, x2.s);
    return x;
}
int main()
{
    String a, b, c;
    a = String("Raufun ");
    b = String("Ahsan");
    c = a + b;
    c.display();
    return 0;
}