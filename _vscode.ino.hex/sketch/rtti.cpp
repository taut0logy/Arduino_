#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\rtti.cpp"
#include <bits/stdc++.h>
using namespace std;

class Character
{
public:
    virtual void attack() = 0;
    virtual ~Character() {}
};

class Knight : public Character
{
public:
    void attack() override
    {
        // Perform knight-specific attack
        std::cout << "Knight performs a melee attack!" << std::endl;
    }
};

class Mage : public Character
{
public:
    void attack() override
    {
        // Perform mage-specific attack
        std::cout << "Mage casts a fireball!" << std::endl;
    }
};

class Archer : public Character
{
public:
    void attack() override
    {
        // Perform archer-specific attack
        std::cout << "Archer shoots an arrow!" << std::endl;
    }
};

int main()
{
    vector<Character *> characters;
    characters.push_back(new Knight());
    characters.push_back(new Mage());
    characters.push_back(new Archer());

    for (Character *character : characters)
    {
        // Check the actual type using dynamic_cast
        if (Knight *knight = dynamic_cast<Knight *>(character))
        {
            knight->attack();
        }
        else if (Mage *mage = dynamic_cast<Mage *>(character))
        {
            mage->attack();
        }
        else if (Archer *archer = dynamic_cast<Archer *>(character))
        {
            archer->attack();
        }
        else
        {
            // Handle unknown character type
            cout << "Unknown character type!" << std::endl;
        }
    }

    // Cleanup
    for (Character *character : characters)
    {
        delete character;
    }

    return 0;
}
