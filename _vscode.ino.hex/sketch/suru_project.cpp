#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\suru_project.cpp"
#include <bits/stdc++.h>
using namespace std;
class user
{
private:
    static int nextid;
    int id;

public:
    user()
    {
        id = nextid++;
    }
    int getid() const
    {
        return id;
    }
};
int user::nextid = 1;
class informationsystem
{
private:
    map<int, map<string, string>> database;
    map<int, user> users;

public:
    int addUser()
    {
        user u;
        users[u.getid()] = u;
        database[u.getid()] = map<string, string>();
        return u.getid();
    }
    void addinformation(int userid, const string &key, const string &value)
    {
        auto it = database.find(userid);
        if (it != database.end())
        {
            it->second[key] = value;
            cout << "information addes successfully" << endl;
        }
        else
        {
            cout << "user not found" << endl;
        }
    }
    void getinformation(int userid, const string &key)
    {
        auto userit = database.find(userid);
        if (userit != database.end())
        {
            auto infoit = userit->second.find(key);
            if (infoit != userit->second.end())
            {
                cout << "Information: " << infoit->second << endl;
            }
            else
            {
                cout << "Information not found" << endl;
            }
        }
        else
        {
            cout << "User not found" << endl;
        }
    }

    void removeinformation(int userid, const string &key)
    {
        auto userit = database.find(userid);
        if (userit != database.end())
        {
            auto infoit = userit->second.find(key);
            if (infoit != userit->second.end())
            {
                userit->second.erase(infoit);
                cout << "information removed successfully" << endl;
            }
            else
            {
                cout << "user not found" << endl;
            }
        }
    }
};
int main()
{
    informationsystem system;
    map<int, int> idtouserid;
    int choice;
    string key, value;
    while (true)
    {
        cout << "----- Information System -----" << endl;
        cout << "1. Add User" << endl;
        cout << "2. Add Information" << endl;
        cout << "3. Get Information" << endl;
        cout << "4. Remove Information" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            int provided_id;
            provided_id = system.addUser();
            cout << "User added with id: " << provided_id << endl;
            idtouserid[provided_id] = provided_id;
            break;
        case 2:
            int userid;
            cout << "Enter user id: ";
            cin >> userid;
            if (idtouserid.find(userid) != idtouserid.end())
            {
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                system.addinformation(userid, key, value);
            }
            else
            {
                cout << "Invalid user id" << endl;
            }
            break;
        case 3:
            cout << "Enter user id: ";
            cin >> userid;
            if (idtouserid.find(userid) != idtouserid.end())
            {
                cout << "Enter key: ";
                cin >> key;
                system.getinformation(userid, key);
            }
            else
            {
                cout << "Invalid user id" << endl;
            }
            break;
        case 4:
            cout << "Enter user id: ";
            cin >> userid;
            if (idtouserid.find(userid) != idtouserid.end())
            {
                cout << "Enter key: ";
                cin >> key;
                system.removeinformation(userid, key);
            }
            else
            {
                cout << "Invalid user id" << endl;
            }
            break;
        case 5:
            cout << "Exiting the program..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
    return 0;
}