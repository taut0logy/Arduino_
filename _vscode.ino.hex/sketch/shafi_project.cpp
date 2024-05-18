#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\shafi_project.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Book
{
public:
    virtual void displayDetails() = 0;
    virtual ~Book() {}
};

class TextBook : public Book
{
private:
    string bookId;
    string bookTitle;
    string authorName;
    int quantity;

public:
    TextBook(string id, string title, string author, int qty)
        : bookId(id), bookTitle(title), authorName(author), quantity(qty) {}

    void displayDetails() override
    {
        cout << "Book ID: " << bookId << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author Name: " << authorName << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

class Novel : public Book
{
private:
    string bookId;
    string bookTitle;
    string authorName;
    string genre;

public:
    Novel(string id, string title, string author, string g)
        : bookId(id), bookTitle(title), authorName(author), genre(g) {}

    void displayDetails() override
    {
        cout << "Book ID: " << bookId << endl;
        cout << "Book Title: " << bookTitle << endl;
        cout << "Author Name: " << authorName << endl;
        cout << "Genre: " << genre << endl;
    }
};

class BookShop
{
public:
    void controlPanel();
    void addBook();
    void showBooks();
    void checkBook();
    void updateBook();
    void deleteBook();
};

void BookShop::controlPanel()
{
    system("cls");
    cout << "________________________" << endl;
    cout << "|  BOOKSHOP MANAGEMENT  |" << endl;
    cout << "|_______________________|" << endl;
    cout << "|                       |" << endl;
    cout << "|     1. Add Book       |" << endl;
    cout << "|     2. Show Books     |" << endl;
    cout << "|     3. Check Book     |" << endl;
    cout << "|     4. Update Book    |" << endl;
    cout << "|     5. Delete Book    |" << endl;
    cout << "|     6. Exit           |" << endl;
    cout << "|_______________________|" << endl;
}

void BookShop::addBook()
{
    system("cls");
    ofstream file("books.txt", ios::app);
    if (!file)
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookId, bookTitle, authorName;
    int quantity;
    string genre;

    cout << "Add New Book" << endl;
    cout << "------------" << endl;

    cout << "Book ID: ";
    cin >> bookId;

    cout << "Book Title: ";
    cin.ignore();
    getline(cin, bookTitle);

    cout << "Author Name: ";
    getline(cin, authorName);

    cout << "Quantity: ";
    cin >> quantity;

    cout << "Genre (for novels): ";
    cin.ignore();
    getline(cin, genre);

    if (genre.empty())
    {
        file << "TextBook " << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
    }
    else
    {
        file << "Novel " << bookId << " " << bookTitle << " " << authorName << " " << genre << endl;
    }

    file.close();
    cout << "Book added successfully!" << endl;
}

void BookShop::showBooks()
{
    system("cls");
    ifstream file("books.txt");
    if (!file)
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookType, bookId, bookTitle, authorName, genre;
    int quantity;

    cout << "Display Books" << endl;
    cout << "-------------" << endl;

    cout << setw(12) << "Book Type" << setw(12) << "Book ID" << setw(30) << "Book Title" << setw(25) << "Author Name" << setw(10) << "Quantity";
    cout << setw(15) << "Genre" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;

    while (file >> bookType >> bookId >> bookTitle >> authorName)
    {
        Book *book = nullptr;

        if (bookType == "TextBook")
        {
            file >> quantity;
            book = new TextBook(bookId, bookTitle, authorName, quantity);
        }
        else if (bookType == "Novel")
        {
            file >> genre;
            book = new Novel(bookId, bookTitle, authorName, genre);
        }

        if (book)
        {
            book->displayDetails();
            delete book;
        }
    }

    file.close();
}

void BookShop::checkBook()
{
    system("cls");
    ifstream file("books.txt");
    if (!file)
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    string bookType, bookId, bookTitle, authorName, searchId;
    int quantity;
    string genre;
    bool found = false;

    cout << "Check Specific Book" << endl;
    cout << "--------------------" << endl;

    cout << "Enter Book ID: ";
    cin >> searchId;

    while (file >> bookType >> bookId >> bookTitle >> authorName)
    {
        Book *book = nullptr;

        if (bookType == "TextBook")
        {
            file >> quantity;
            book = new TextBook(bookId, bookTitle, authorName, quantity);
        }
        else if (bookType == "Novel")
        {
            file >> genre;
            book = new Novel(bookId, bookTitle, authorName, genre);
        }

        if (book && bookId == searchId)
        {
            book->displayDetails();
            found = true;
            delete book;
            break;
        }

        delete book;
    }

    file.close();

    if (!found)
    {
        cout << "Book ID not found!" << endl;
    }
}

void BookShop::updateBook()
{
    system("cls");
    ifstream inputFile("books.txt");
    if (!inputFile)
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Error opening the file." << endl;
        inputFile.close();
        return;
    }

    string bookType, bookId, bookTitle, authorName, searchId;
    int quantity;
    string genre;
    bool found = false;

    cout << "Update Book Record" << endl;
    cout << "------------------" << endl;

    cout << "Enter Book ID to update: ";
    cin >> searchId;

    while (inputFile >> bookType >> bookId >> bookTitle >> authorName)
    {
        Book *book = nullptr;

        if (bookType == "TextBook")
        {
            inputFile >> quantity;
            book = new TextBook(bookId, bookTitle, authorName, quantity);
        }
        else if (bookType == "Novel")
        {
            inputFile >> genre;
            book = new Novel(bookId, bookTitle, authorName, genre);
        }

        if (book && bookId == searchId)
        {
            cout << "Enter New Book Title: ";
            cin.ignore();
            getline(cin, bookTitle);

            cout << "Enter New Author Name: ";
            getline(cin, authorName);

            if (bookType == "TextBook")
            {
                cout << "Enter New Quantity: ";
                cin >> quantity;
                tempFile << "TextBook " << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
            }
            else if (bookType == "Novel")
            {
                cout << "Enter New Genre: ";
                cin.ignore();
                getline(cin, genre);
                tempFile << "Novel " << bookId << " " << bookTitle << " " << authorName << " " << genre << endl;
            }

            cout << "Book updated successfully!" << endl;
            found = true;
        }
        else
        {
            if (bookType == "TextBook")
            {
                inputFile >> quantity;
                tempFile << "TextBook " << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
            }
            else if (bookType == "Novel")
            {
                inputFile >> genre;
                tempFile << "Novel " << bookId << " " << bookTitle << " " << authorName << " " << genre << endl;
            }
        }

        delete book;
    }

    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Book ID not found!" << endl;
        remove("temp.txt");
    }
    else
    {
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
}

void BookShop::deleteBook()
{
    system("cls");
    ifstream inputFile("books.txt");
    if (!inputFile)
    {
        cerr << "Error opening the file." << endl;
        return;
    }

    ofstream tempFile("temp.txt");
    if (!tempFile)
    {
        cerr << "Error opening the file." << endl;
        inputFile.close();
        return;
    }

    string bookType, bookId, bookTitle, authorName, searchId;
    int quantity;
    string genre;
    bool found = false;

    cout << "Delete Book Record" << endl;
    cout << "------------------" << endl;

    cout << "Enter Book ID to delete: ";
    cin >> searchId;

    while (inputFile >> bookType >> bookId >> bookTitle >> authorName)
    {
        Book *book = nullptr;

        if (bookType == "TextBook")
        {
            inputFile >> quantity;
            book = new TextBook(bookId, bookTitle, authorName, quantity);
        }
        else if (bookType == "Novel")
        {
            inputFile >> genre;
            book = new Novel(bookId, bookTitle, authorName, genre);
        }

        if (book && bookId == searchId)
        {
            cout << "Book deleted successfully!" << endl;
            found = true;
        }
        else
        {
            if (bookType == "TextBook")
            {
                inputFile >> quantity;
                tempFile << "TextBook " << bookId << " " << bookTitle << " " << authorName << " " << quantity << endl;
            }
            else if (bookType == "Novel")
            {
                inputFile >> genre;
                tempFile << "Novel " << bookId << " " << bookTitle << " " << authorName << " " << genre << endl;
            }
        }

        delete book;
    }

    inputFile.close();
    tempFile.close();

    if (!found)
    {
        cout << "Book ID not found!" << endl;
        remove("temp.txt");
    }
    else
    {
        remove("books.txt");
        rename("temp.txt", "books.txt");
    }
}

int main()
{
    BookShop bookShop;
    int choice;

    do
    {
        bookShop.controlPanel();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bookShop.addBook();
            break;
        case 2:
            bookShop.showBooks();
            break;
        case 3:
            bookShop.checkBook();
            break;
        case 4:
            bookShop.updateBook();
            break;
        case 5:
            bookShop.deleteBook();
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

        cout << "Press Enter key to continue...";
        cin.ignore();
        cin.get();

    } while (choice != 6);

    return 0;
}