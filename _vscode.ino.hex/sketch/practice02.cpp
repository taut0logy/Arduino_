#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\practice02.cpp"
#include <iostream>
#include <vector>

class Team
{
protected:
    int num;
    std::vector<std::string> playername;

public:
    static int matchcount;
    Team(int n, const std::vector<std::string> &names) : num(n), playername(names) {}
    virtual void play(Team *opponent) = 0;

    friend std::istream &operator>>(std::istream &is, Team &team);
};

int Team::matchcount = 0;

std::istream &operator>>(std::istream &is, Team &team)
{
    is >> team.num;
    std::cout << "Enter player names (separated by spaces): ";
    std::string playerName;
    while (is >> playerName)
    {
        team.playername.push_back(playerName);
    }
    return is;
}

class Cricket : public Team
{
public:
    Cricket(int n, const std::vector<std::string> &names) : Team(n, names) {}
    void play(Team *opponent) override;
};

void Cricket::play(Team *opponent)
{
    if (dynamic_cast<Cricket *>(opponent))
    {
        ++num;
        ++matchcount;
    }
    std::cout << "Cricket match played." << std::endl;
}

class Football : public Team
{
public:
    Football(int n, const std::vector<std::string> &names) : Team(n, names) {}
    void play(Team *opponent) override;
};

void Football::play(Team *opponent)
{
    if (dynamic_cast<Football *>(opponent))
    {
        ++num;
        ++matchcount;
    }
    std::cout << "Football match played." << std::endl;
}

class Basketball : public Team
{
public:
    Basketball(int n, const std::vector<std::string> &names) : Team(n, names) {}
    void play(Team *opponent) override;
};

void Basketball::play(Team *opponent)
{
    if (dynamic_cast<Basketball *>(opponent))
    {
        ++num;
        ++matchcount;
    }
    std::cout << "Basketball match played." << std::endl;
}

void playGame(Team *team1, Team *team2)
{
    team1->play(team2);
    team2->play(team1);
}

int main()
{
    Cricket c1(1, {"Player1", "Player2", "Player3"});
    Football f1(2, {"Player4", "Player5", "Player6"});
    Basketball b1(3, {"Player7", "Player8", "Player9"});

    Cricket c2(4, {"Player10", "Player11", "Player12"});
    Football f2(5, {"Player13", "Player14", "Player15"});
    Basketball b2(6, {"Player16", "Player17", "Player18"});

    playGame(&c1, &c2);
    playGame(&f1, &f2);
    playGame(&b1, &b2);

    std::cout << "Cricket match count: " << Team::matchcount << std::endl;

    return 0;
}