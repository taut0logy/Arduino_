#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\oop_lab_test_a2_b2.cpp"
#include<bits/stdc++.h>
using namespace std;
class Media
{
    public:
    virtual void play()=0;
    virtual void pause()=0;
    virtual void stop()=0;
};
class Book:public Media
{
    string title,author;
    int NumberOfPages;
public:
    Book(string title,string author,int NumberOfPages):title(title),author(author),NumberOfPages(NumberOfPages){}
    void play() override
    {
        cout<<"Opening a book."<<endl;
    }
    void pause() override
    {
        cout<<"Taking a break."<<endl;
    }
    void stop() override
    {
        cout<<"Closing the book."<<endl;
    }
    friend ostream& operator<<(ostream& os,const Book& b);
};
class Movie: public Media
{
    string title,director;
    int DurationInMinutes;
public:
    Movie(string title,string director,int DurationInMinutes):title(title),director(director),DurationInMinutes(DurationInMinutes){}
    void play() override
    {
        cout<<"Playing a movie."<<endl;
    }
    void pause() override
    {
        cout<<"Pausing the movie."<<endl;
    }
    void stop() override
    {
        cout<<"Movie time over."<<endl;
    }
    friend ostream& operator<<(ostream& os,const Movie& m);
};
class Song: public Media
{
    string title,artist;
    int DurationInSeconds;
public:
    Song(string title,string artist,int DurationInSeconds):title(title),artist(artist),DurationInSeconds(DurationInSeconds){}
    void play() override
    {
        cout<<"Playing a song."<<endl;
    }
    void pause() override
    {
        cout<<"Pausing the song."<<endl;
    }
    void stop() override
    {
        cout<<"Song stopped."<<endl;
    }
    friend ostream& operator<<(ostream& os,const Song& s);
};
ostream& operator<<(ostream& os,const Book& b)
{
    os<<"Title: "<<b.title<<endl<<"Author: "<<b.author<<endl<<"Number of pages: "<<b.NumberOfPages<<endl;
}
ostream& operator<<(ostream& os,const Movie& m)
{
    os<<"Title: "<<m.title<<endl<<"Director: "<<m.director<<endl<<"Duration in Minutes: "<<m.DurationInMinutes<<endl;
}
ostream& operator<<(ostream& os,const Song& s)
{
    os<<"Title: "<<s.title<<endl<<"Artist: "<<s.artist<<endl<<"Duration in Seconds: "<<s.DurationInSeconds<<endl;
}
template<typename T>
void showType(const T& x)
{
    const type_info& bt=typeid(Book);
    const type_info& mt=typeid(Movie);
    const type_info& st=typeid(Song);
    if(typeid(x)==bt)
    {
        cout<<"It's a Book."<<endl;
    }
    else if(typeid(x)==mt)
    {
        cout<<"It's a Movie."<<endl;
    }
    else if(typeid(x)==st)
    {
        cout<<"It's a Song."<<endl;
    }
    else
    {
        cout<<"It's not a media."<<endl;
    }
}
int main()
{
    Book b("C++ is not fun","Raufun",100);
    cout<<b;
    b.play();
    showType(b);
    int x=10;
    showType(x);
}