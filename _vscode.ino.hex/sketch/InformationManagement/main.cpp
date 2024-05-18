#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\InformationManagement\\main.cpp"
#include <bits/stdc++.h>
using namespace std;

string encrypt(const string &s, int key)
{
    string ciphertext;
    for (char ch : s)
    {
        if (std::isalpha(ch))
        {
            char base = std::isupper(ch) ? 'A' : 'a';
            ch = (ch - base + key) % 26 + base;
        }
        ciphertext += ch;
    }
    return ciphertext;
}

string decrypt(const string &s, int key)
{
    return encrypt(s, 26 - key);
}

int generateKey()
{
    std::random_device rd;                                  // Obtain a random seed from the hardware
    std::mt19937 gen(rd());                                 // Initialize a random number generator engine
    std::uniform_int_distribution<int> distribution(1, 26); // Define the range of the random numbers

    return distribution(gen);
}

class SystemException : public std::exception
{
private:
    std::string message;

public:
    SystemException(const std::string &message)
        : message(message) {}

    const char *what() const throw()
    {
        return message.c_str();
    }
};

class date
{
private:
    int day;
    int month;
    int year;

public:
    date(int d = 0, int m = 0, int y = 0)
    {
        day = d;
        month = m;
        year = y;
    }
    string display()
    {
        string s = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
        return s;
    }
    int getday()
    {
        return day;
    }
    int getmonth()
    {
        return month;
    }
    int getyear()
    {
        return year;
    }
    void setday(int d)
    {
        day = d;
    }
    void setmonth(int m)
    {
        month = m;
    }
    void setyear(int y)
    {
        year = y;
    }
    bool operator==(const date &d)
    {
        if (day == d.day && month == d.month && year == d.year)
            return true;
        else
            return false;
    }
    bool operator<(const date &d)
    {
        if (year < d.year)
            return true;
        else if (year == d.year && month < d.month)
            return true;
        else if (year == d.year && month == d.month && day < d.day)
            return true;
        else
            return false;
    }
    bool operator>(const date &d)
    {
        if (year > d.year)
            return true;
        else if (year == d.year && month > d.month)
            return true;
        else if (year == d.year && month == d.month && day > d.day)
            return true;
        else
            return false;
    }
    bool isvalid()
    {
        if (year < 0)
            return false;

        if (month < 1 || month > 12)
            return false;

        if (day < 1)
            return false;

        if (month == 2)
        {
            bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            if (isLeapYear)
            {
                if (day > 29)
                    return false;
            }
            else
            {
                if (day > 28)
                    return false;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            if (day > 30)
                return false;
        }
        else
        {
            if (day > 31)
                return false;
        }

        return true;
    }
};

set<string> database;
int masterkey = 13;
class Person
{
protected:
    date Dateadded;
    string username;
    int id;
    string password;
    string resetkey;

public:
    Person(const std::string &name, const string &password) : username(name), password(password)
    {
        id = generateKey();
        time_t now = time(0);
        tm *ltm = localtime(&now);
        int d = ltm->tm_mday;
        int m = 1 + ltm->tm_mon;
        int y = 1900 + ltm->tm_year;
        Dateadded = date(d, m, y);
        resetkey = "";
    }
    int getId()
    {
        return id;
    }
    void setResetKey(const string &key)
    {
        if (key == "")
            resetkey = key;
    }
    string getResetKey()
    {
        return encrypt(resetkey, id);
    }
    void setPassword(const string &pass)
    {
        password = pass;
        save();
    }
    string getPassword()
    {
        return encrypt(password, id);
    }
    void setdateadded(const date &d)
    {
        Dateadded = d;
    }
    date getDateadded()
    {
        return Dateadded;
    }
    virtual ~Person() = default;
    virtual void save() = 0;
    virtual void display() = 0;
    friend Person *remove(Person *p);
};

int Godmode = 0;

class Admin : public Person
{
    string name;
    const int securitylevel;

public:
    Admin(const string &username, const string &name, const string &password, const int &lvl) : Person(username, password), name(name), securitylevel(lvl) {}
    void setName(const string &n) {}
    void display() override
    {
        cout << "Admin Information:" << endl;
        cout << "------------------" << endl;
        cout << "Name: " << name << endl;
        cout << "Date added: " << Dateadded.getday() << "/" << Dateadded.getmonth() << "/" << Dateadded.getyear() << endl;
        cout << "Security level: " << securitylevel << endl;
    }
    void save() override
    {
        ofstream ff("database.txt", ios::app);
        if (!ff.is_open())
            throw SystemException("Error Accessing File, File saving failed.");
        if (database.find(encrypt(username, masterkey)) == database.end())
            ff << encrypt(username, masterkey) << endl;
        ff.close();
        database.insert(encrypt(username, masterkey));
        ofstream f;
        f.open("Admin/" + encrypt(name, masterkey) + ".txt");
        if (!f.is_open())
            throw SystemException("Error Accessing File, File saving failed.");
        f << securitylevel << endl;
        f << id << endl;
        f << encrypt(username, id) << endl;
        f << encrypt(password, id) << endl;
        f << encrypt(resetkey, id) << endl;
        f << encrypt(Dateadded.display(), id) << endl;
        f << encrypt(name, id) << endl;
    }
};

class User : public Person
{
private:
    string name;
    date dob;
    string fathername;
    string mothername;
    string gender;
    string address;
    long phonenumber;
    string email;

public:
    User(const string &name, const string &password)
        : Person(name, password) {}
    void setName(const string &n)
    {
        name = n;
    }
    void setDob(const date &d)
    {
        dob = d;
    }
    void setFathername(const string &f)
    {
        fathername = f;
    }
    void setMothername(const string &m)
    {
        mothername = m;
    }
    void setGender(const string &s)
    {
        gender = s;
    }
    void setAddress(const string &a)
    {
        address = a;
    }
    void setPhonenumber(const long &p)
    {
        phonenumber = p;
    }
    void setEmail(const string &e)
    {
        email = e;
    }
    date getDob()
    {
        return dob;
    }
    string getFathername()
    {
        return fathername;
    }
    string getMothername()
    {
        return mothername;
    }
    string getGender()
    {
        return gender;
    }
    string getAddress()
    {
        return address;
    }
    long getPhonenumber()
    {
        return phonenumber;
    }
    string getEmail()
    {
        return email;
    }
    void display() override
    {
        cout << "User Information:" << endl;
        cout << "-----------------" << endl;
        cout << "Date added: " << Dateadded.display() << endl;
        cout << "Name: " << name << endl;
        cout << "Date of birth: " << dob.display() << endl;
        cout << "Father's name: " << fathername << endl;
        cout << "Mother's name: " << mothername << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
        cout << "Phone number: " << phonenumber << endl;
        cout << "Email: " << email << endl;
    }
    void save()
    {
        ofstream f("database.txt", ios::app);
        if (!f.is_open())
            throw SystemException("Error Accessing File, File saving failed.");
        f << encrypt(username, masterkey) << endl;
        f.close();
        ofstream of;
        of.open("User/" + encrypt(username, masterkey) + ".txt");
        if (!of.is_open())
            throw SystemException("Error Accessing File, File saving failed.");
        of << id << endl;
        of << encrypt(username, id) << endl;
        of << encrypt(password, id) << endl;
        of << encrypt(resetkey, id) << endl;
        of << encrypt(Dateadded.display(), id) << endl;
        of << encrypt(name, id) << endl;
        of << encrypt(dob.display(), id) << endl;
        of << encrypt(fathername, id) << endl;
        of << encrypt(mothername, id) << endl;
        of << encrypt(gender, id) << endl;
        of << encrypt(address, id) << endl;
        of << encrypt(to_string(phonenumber), id) << endl;
        of << encrypt(email, id) << endl;
        of.close();
    }
};
int loadAdmin(const string &name, const string &password, Person *&p)
{
    if (database.find(name) == database.end())
    {
        p = nullptr;
        return -1;
    }
    ifstream f;
    f.open("Admin/" + encrypt(name, masterkey) + ".txt");
    if (!f.is_open())
        throw SystemException("Error Accessing File, File loading failed.");
    date dd;
    int lvl;
    f >> lvl;
    int id;
    f >> id;
    string un;
    f >> un;
    un = decrypt(un, id);
    if (un != name)
    {
        p = nullptr;
        return -2;
    }
    string pass;
    f >> pass;
    pass = decrypt(pass, id);
    if (pass != password)
    {
        p = nullptr;
        return -3;
    }
    string key;
    f >> key;
    key = decrypt(key, id);
    string date;
    f >> date;
    date = decrypt(date, id);
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    string n;
    f >> n;
    n = decrypt(n, id);
    p=new Admin (un, n, pass, lvl);
    p->setResetKey(key);
    p->setPassword(password);
    dd.setday(day);
    dd.setmonth(month);
    dd.setyear(year);
    p->setdateadded(dd);
    f.close();
    return 0;
}

int loadUser(const string &name, const string &password, Person *&p)
{
    if (database.find(name) == database.end())
    {
        p = nullptr;
        return -1;
    }
    ifstream f;
    f.open("User/" + encrypt(name, masterkey) + ".txt");
    if (!f.is_open())
        throw SystemException("Error Accessing File, File loading failed.");
    date dd;
    int id;
    f >> id;
    string n;
    f >> n;
    n = decrypt(n, id);
    if (n != name)
    {
        p = nullptr;
        return -2;
    }
    string pass;
    f >> pass;
    pass = decrypt(pass, id);
    if (pass != password)
    {
        p = nullptr;
        return -3;
    }
    string key;
    f >> key;
    key = decrypt(key, id);
    string date;
    f >> date;
    date = decrypt(date, id);
    int day, month, year;
    sscanf(date.c_str(), "%d/%d/%d", &day, &month, &year);
    string nam;
    f >> nam;
    p=new User (n, pass);
    dynamic_cast<User *>(p)->setResetKey(key);
    dynamic_cast<User *>(p)->setPassword(password);
    dd.setday(day);
    dd.setmonth(month);
    dd.setyear(year);
    p->setdateadded(dd);
    nam = decrypt(nam, id);
    dynamic_cast<User *>(p)->setName(nam);
    string dob;
    f >> dob;
    dob = decrypt(dob, id);
    sscanf(dob.c_str(), "%d/%d/%d", &day, &month, &year);
    dd.setday(day);
    dd.setmonth(month);
    dd.setyear(year);
    dynamic_cast<User *>(p)->setDob(dd);
    string fathername;
    f >> fathername;
    fathername = decrypt(fathername, id);
    dynamic_cast<User *>(p)->setFathername(fathername);
    string mothername;
    f >> mothername;
    mothername = decrypt(mothername, id);
    string g;
    f >> g;
    g = decrypt(g, id);
    dynamic_cast<User *>(p)->setGender(g);
    dynamic_cast<User *>(p)->setMothername(mothername);
    string address;
    f >> address;
    address = decrypt(address, id);
    dynamic_cast<User *>(p)->setAddress(address);
    string phonenumber;
    f >> phonenumber;
    phonenumber = decrypt(phonenumber, id);
    long ph;
    sscanf(phonenumber.c_str(), "%ld", &ph);
    dynamic_cast<User *>(p)->setPhonenumber(ph);
    string email;
    f >> email;
    email = decrypt(email, id);
    dynamic_cast<User *>(p)->setEmail(email);
    f.close();
    return 0;
}

Person *remove(Person *p)
{
    if (dynamic_cast<Admin *>(p))
    {
        Admin *a = dynamic_cast<Admin *>(p);
        ofstream f;
        f.open("Admin/" + encrypt(a->username, masterkey) + ".txt");
        if (!f.is_open())
            throw SystemException("Error Accessing File, File deleting failed.");
        remove(("Admin/" + encrypt(a->username, masterkey) + ".txt").c_str());
        delete a;
    }
    else
    {
        User *u = dynamic_cast<User *>(p);
        ofstream f;
        f.open("User/" + encrypt(u->username, masterkey) + ".txt");
        if (!f.is_open())
            throw SystemException("Error Accessing File, File deleting failed.");
        remove(("User/" + encrypt(u->username, masterkey) + ".txt").c_str());
        delete u;
    }
    string name = p->username;
    database.erase(name);
    name = encrypt(name, masterkey);
    ofstream temp("temp.txt");
    ifstream f("database.txt");
    string line;
    while (getline(f, line))
    {
        if (line != name)
            temp << line << endl;
    }
    f.close();
    temp.close();
    remove("database.txt");
    rename("temp.txt", "database.txt");
    return nullptr;
}
void mainmenu()
{
    cout << "    Welcome to Your Very Own Information Management System!" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                         Who are you?" << endl;
    cout << "                           1. Admin" << endl;
    cout << "                           2. User" << endl;
    cout << "                    *** Enter 0 to exit ***" << endl;
    cout << "Enter your choice: ";
}

void adminMenu(Admin *a)
{
    cout << "                            Admin Menu" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                            What to do?" << endl;
    cout << "                           1. Add User" << endl;
    cout << "                           2. Remove User" << endl;
    cout << "                           3. Search User" << endl;
    cout << "                           4. Display User Data" << endl;
    if (a->getResetKey() != "")
        cout << "                           5. Reset Password" << endl;
    else
        cout << "                           5. Set Password reset key" << endl;
    cout << "                           7. Logout" << endl;
    cout << "                    *** Enter 0 to exit ***" << endl;
    cout << "Enter your choice: ";
}

void userMenu(User *u)
{
    cout << "                            User Menu" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                            What to do?" << endl;
    cout << "                           1. Enter/Update User Data" << endl;
    if (u->getResetKey() != "")
        cout << "                           2. Change Password" << endl;
    else
        cout << "                           2. Set Password reset key" << endl;
    cout << "                           3. Display User Data" << endl;
    cout << "                           4. Logout" << endl;
    cout << "                    *** Enter 0 to exit ***" << endl;
}

void userchangemenu()
{
    cout << "                            User Menu" << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << "                            What to do?" << endl;
    cout << "                           1. update name" << endl;
    cout << "                           2. update date of birth" << endl;
    cout << "                           3. update father's name" << endl;
    cout << "                           4. update mother's name" << endl;
    cout << "                           5. update gender" << endl;
    cout << "                           6. update address" << endl;
    cout << "                           7. update phone number" << endl;
    cout << "                           8. update email" << endl;
    cout << "                           9. Go back" << endl;
    cout << "                    *** Enter 0 to exit ***" << endl;
}
int main()
{
    try
    {
        database.clear();
        ifstream f("database.txt");
        if (!f.is_open())
            throw SystemException("Error Accessing File, File loading failed.");
        string line;
        while (getline(f, line))
        {
            line = decrypt(line, masterkey);
            if (!line.empty())
                database.insert(line);
        }
        f.close();
        Person* p = NULL;
        char choice;
        do
        {
            system("cls");
            if (database.empty())
            {
                system("cls");
                int mas;
                cout << "Welcome to your very own Information Management System!" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "It looks like you are using this system for the first time!" << endl;
                cout << "Please enter a master key to continue: ";
                cin >> mas;
                if (mas != masterkey)
                {
                    cout << "Invalid master key!" << endl;
                    cout << "Press any key to exit...";
                    cin.ignore();
                    return 0;
                }
                cout << "Master key accepted!" << endl;
                cout << "Enter admin username : ";
                string name;
                cin >> name;
                if (database.find(name) != database.end())
                {
                    cout << "Admin already exists!" << endl;
                    cout << "Press any key to exit...";
                    cin.ignore();
                    return 0;
                }
                cout << "Enter admin password: ";
                string pass;
                cin >> pass;
                p=new Admin(name, name, pass, 1);
                cout << "Admin account created successfully!" << endl;
                p->save();
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                return 0;
            }
            if (p == nullptr)
            {
                system("cls");
                mainmenu();
                cin >> choice;
                switch (choice)
                {
                case '0':
                {
                    system("cls");
                    cout << "Are you sure you want to exit? (Y/N): ";
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                        return 0;
                    break;
                }
                case '1':
                {
                    system("cls");
                    try
                    {
                        string name, password;
                        cout << "Enter your username: ";
                        cin >> name;
                        cout << "Enter your password: ";
                        cin >> password;
                        int x = loadAdmin(name, password, p);
                        if (x == -1)
                            cout << "Admin not found!" << endl;
                        else if (x == -2)
                            cout << "Invalid username!" << endl;
                        else if (x == -3)
                            cout << "Invalid password!" << endl;
                        else
                            cout << "Login successful!" << endl;
                        cout << "Press any key to continue..." << endl;
                        cin.ignore();
                    }
                    catch (const std::exception &e)
                    {
                        std::cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }

                    break;
                }
                case '2':
                {
                    system("cls");
                    try
                    {
                        string name, password;
                        cout << "Enter your username: ";
                        cin >> name;
                        cout << "Enter your password: ";
                        cin >> password;
                        int x = loadUser(name, password, p);
                        if (x == -1)
                            cout << "User not found!" << endl;
                        else if (x == -2)
                            cout << "Invalid username!" << endl;
                        else if (x == -3)
                            cout << "Invalid password!" << endl;
                        else
                            cout << "Login successful!" << endl;
                        cout << "Press any key to continue...";
                        cin.ignore();
                        break;
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                    break;
                }
                default:
                {
                    cout << "Invalid choice!" << endl;
                    cout << "Press any key to continue...";
                    cin.ignore();
                    break;
                }
                }
            }
            else if (dynamic_cast<Admin *>(p))
            {
                system("cls");
                Admin *a = dynamic_cast<Admin *>(p);
                adminMenu(a);
                cin >> choice;
                switch (choice)
                {
                case '0':
                {
                    system("cls");
                    cout << "Are you sure you want to exit? (Y/N): ";
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                        return 0;
                    break;
                }
                case '1':
                {
                    system("cls");
                    try
                    {
                        string name, password, confirm;
                        cout << "Enter username: ";
                        cin >> name;
                        if (database.find(name) != database.end())
                            throw SystemException("User already exists!");
                        cout << "Enter password: ";
                        cin >> password;
                        cout << "Confirm password: ";
                        cin >> confirm;
                        if (password != confirm)
                            throw SystemException("Passwords do not match!");
                        User u(name, password);
                        u.setName(name);
                        u.setPassword(password);
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    break;
                }
                case '2':
                {
                    system("cls");
                    try
                    {
                        string name;
                        cout << "Enter username: ";
                        cin >> name;
                        if (database.find(name) == database.end())
                            throw SystemException("User not found!");
                        Person *p = nullptr;
                        int x = loadUser(name, "", p);
                        if (x == -1)
                            throw SystemException("User not found!");
                        p = remove(p);
                        if (p == nullptr)
                            cout << "User removed successfully!" << endl;
                        else
                            cout << "User removal failed!" << endl;
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    break;
                }
                case '3':
                {
                    system("cls");
                    try
                    {
                        string name;
                        cout << "Enter username: ";
                        cin >> name;
                        if (database.find(name) == database.end())
                            throw SystemException("User not found!");
                        Person *p = nullptr;
                        int x = loadUser(name, "", p);
                        if (x == -1)
                            throw SystemException("User not found!");
                        cout << "User found!" << endl;
                        cout << "User was added on" << p->getDateadded().display() << endl;
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    break;
                }
                case '4':
                {
                    system("cls");
                    try
                    {
                        string name;
                        cout << "Enter username: ";
                        cin >> name;
                        if (database.find(name) == database.end())
                            throw SystemException("User not found!");
                        Person *p = nullptr;
                        int x = loadUser(name, "", p);
                        if (x == -1)
                            throw SystemException("User not found!");
                        p->display();
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    break;
                }
                case '5':
                {
                    system("cls");
                    try
                    {
                        if (a->getResetKey().empty())
                        {
                            string k;
                            cout << "Enter reset key: ";
                            cin >> k;
                            a->setResetKey(k);
                            cout << "Reset key set successfully!" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                        }
                        else
                        {
                            string k;
                            cout << "Enter reset key: ";
                            cin >> k;
                            k = encrypt(k, a->getId());
                            if (k != a->getResetKey())
                                throw SystemException("Invalid reset key!");
                            string pass, pass2;
                            cout << "Enter new password: ";
                            cin >> pass;
                            cout << "Confirm new password: ";
                            cin >> pass2;
                            if (pass != pass2)
                                throw SystemException("Passwords do not match!");
                            a->setPassword(pass);
                            cout << "Password changed successfully!" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                        }
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    break;
                }
                case '6':
                {
                    system("cls");
                    p->save();
                    p = nullptr;
                    cout << "Press any key to continue...";
                    cin.ignore();
                    break;
                }
                default:
                {
                    cout << "Invalid choice!" << endl;
                    cout << "Press any key to continue...";
                    cin.ignore();
                    break;
                }
                }
            }
            else if (dynamic_cast<User *>(p))
            {
                system("cls");
                User *u = dynamic_cast<User *>(p);
                userMenu(u);
                cin >> choice;
                switch (choice)
                {
                case '0':
                {
                    system("cls");
                    cout << "Are you sure you want to exit? (Y/N): ";
                    char c;
                    cin >> c;
                    if (c == 'Y' || c == 'y')
                        return 0;
                    break;
                }
                case '1':
                {
                    system("cls");
                    userchangemenu();
                    cin >> choice;
                    switch (choice)
                    {
                    case '0':
                    {
                        cout << "Are you sure you want to exit? (Y/N): ";
                        char c;
                        cin >> c;
                        if (c == 'Y' || c == 'y')
                            return 0;
                        break;
                    }
                    case '1':
                    {
                        string name;
                        cout << "Enter name: ";
                        cin >> name;
                        u->setName(name);
                        u->save();
                        cout << "Name updated successfully!" << endl;
                        break;
                    }
                    case '2':
                    {
                        int day, month, year;
                        cout << "Enter date of birth: ";
                        cin >> day >> month >> year;
                        date d(day, month, year);
                        u->setDob(d);
                        u->save();
                        cout << "Date of birth updated successfully!" << endl;
                        break;
                    }
                    case '3':
                    {
                        string name;
                        cout << "Enter father's name: ";
                        cin >> name;
                        u->setFathername(name);
                        u->save();
                        cout << "Father's name updated successfully!" << endl;
                        break;
                    }
                    case '4':
                    {
                        string name;
                        cout << "Enter mother's name: ";
                        cin >> name;
                        u->setMothername(name);
                        u->save();
                        cout << "Mother's name updated successfully!" << endl;
                        break;
                    }
                    case '5':
                    {
                        string gndr;
                        cout << "Enter Gender: ";
                        cin >> gndr;
                        u->setGender(gndr);
                        u->save();
                        cout << "Gender updated successfully!" << endl;
                        break;
                    }
                    case '6':
                    {
                        string add;
                        cout << "Enter address: ";
                        cin >> add;
                        u->setAddress(add);
                        u->save();
                        cout << "Address updated successfully!" << endl;
                        break;
                    }
                    case '7':
                    {
                        long ph;
                        cout << "Enter phone number: ";
                        cin >> ph;
                        u->setPhonenumber(ph);
                        u->save();
                        cout << "Phone number updated successfully!" << endl;
                        break;
                    }
                    case '8':
                    {
                        string email;
                        cout << "Enter email: ";
                        cin >> email;
                        u->setEmail(email);
                        u->save();
                        cout << "Email updated successfully!" << endl;
                        break;
                    }
                    case '9':
                    {
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                    }
                    cout << "Press any key to continue...";
                    cin.ignore();
                    break;
                }
                case '2':
                {
                    system("cls");
                    try
                    {
                        if (u->getResetKey().empty())
                        {
                            string k;
                            cout << "Enter reset key: ";
                            cin >> k;
                            u->setResetKey(k);
                            cout << "Reset key set successfully!" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                        }
                        else
                        {
                            string k;
                            cout << "Enter reset key: ";
                            cin >> k;
                            k = encrypt(k, u->getId());
                            if (k != u->getResetKey())
                                ;
                            throw SystemException("Invalid reset key!");
                            string pass, pass2;
                            cout << "Enter new password: ";
                            cin >> pass;
                            cout << "Confirm new password: ";
                            cin >> pass2;
                            if (pass != pass2)
                                throw SystemException("Passwords do not match!");
                            u->setPassword(pass);
                            cout << "Password changed successfully!" << endl;
                            cout << "Press any key to continue...";
                            cin.ignore();
                        }
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                }
                case '3':
                {
                    system("cls");
                    try
                    {
                        u->display();
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                    catch (const std::exception &e)
                    {
                        cout << e.what() << '\n';
                        cout << "Press any key to continue...";
                        cin.ignore();
                    }
                }
                default:
                {
                    cout << "Invalid choice!" << endl;
                    cout << "Press any key to continue...";
                    cin.ignore();
                    break;
                }
                }
            }
        } while (1);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << '\n';
        cout << "Press any key to continue...";
        cin.ignore();
    }

    return 0;
}