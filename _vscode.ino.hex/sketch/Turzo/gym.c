#line 1 "C:\\Users\\LENOVO\\OneDrive\\Documents\\C\\_VScode\\Turzo\\gym.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random_geenerate()
{
    srand(time(NULL));
    int r = rand() % 1000;
    return r;
}

struct member
{
    int id;
    char password[15];
    char name[100];
    char phone_number[15];
    char mail[50];
    char join_date[15];
    int age;
    int height;
    int weight;
} m[1000];

const int master_password = 1234;

static int member_count = 0;

int idlist[1000];

FILE *user, *curUser;
struct member curMember;
int current_id = -1;

void toString(char *str, int num)
{
    int i, rem, len = 0, n;
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}

char *encrypt(char *pass, int key)
{
    int i;
    for (i = 0; i < strlen(pass); i++)
    {
        pass[i] = (pass[i] + key) % 128;
    }
    return pass;
}

char *decrypt(char *pass, int key)
{
    int i;
    for (i = 0; i < strlen(pass); i++)
    {
        pass[i] = (pass[i] - key) % 128;
    }
    return pass;
}

double BMI(int height, int weight)
{
    double h = (double)height / 100;
    double bmi = (double)weight / (h * h);
    return bmi;
}

char *BMI_category(int height, int weight)
{
    double bmi = BMI(height, weight);
    if (bmi < 18.5)
    {
        return "Underweight";
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        return "Normal weight";
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        return "Overweight";
    }
    else if (bmi >= 30)
    {
        return "Obesity";
    }
}

void loadMembers()
{
    int i;
    for (i = 0; i < member_count; i++)
    {
        int id = idlist[i];
        m[i].id = idlist[i];
        char filename[20];
        toString(filename, id);
        char location[20] = "data/";
        strcat(filename, ".txt");
        strcat(location, filename);
        FILE *curr = fopen(location, "r");
        fscanf(curr, "%[^\n]%*c", m[i].password);
        fscanf(curr, "%[^\n]%*c", m[i].name);
        fscanf(curr, "%[^\n]%*c", m[i].phone_number);
        fscanf(curr, "%[^\n]%*c", m[i].mail);
        fscanf(curr, "%[^\n]%*c", m[i].join_date);
        fscanf(curr, "%d", &m[i].age);
        fscanf(curr, "%d", &m[i].height);
        fscanf(curr, "%d", &m[i].weight);
        fclose(curr);
    }
}

void updateUser()
{
    user = fopen("data/user.txt", "w");
    int i;
    for (i = 0; i < member_count; i++)
    {
        fprintf(user, "%d\n", idlist[i]);
    }
    fclose(user);
}

int add_member()
{
    char filename[20];
    toString(filename, m[member_count].id);
    char location[20] = "data/";
    strcat(location, filename);
    strcat(location, ".txt");
    FILE *curUser = fopen(location, "w");
    if (curUser == NULL)
    {
        printf("Error opening file\n");
        return 0;
    }
    fprintf(curUser, "%s\n", encrypt(m[member_count].password, m[member_count].id));
    fprintf(curUser, "%s\n", m[member_count].name);
    fprintf(curUser, "%s\n", m[member_count].phone_number);
    fprintf(curUser, "%s\n", m[member_count].mail);
    fprintf(curUser, "%s\n", m[member_count].join_date);
    fprintf(curUser, "%d\n", m[member_count].age);
    fprintf(curUser, "%d\n", m[member_count].height);
    fprintf(curUser, "%d\n", m[member_count].weight);
    fclose(curUser);
    member_count++;
    updateUser();
    return 1;
}

void add_member_helper()
{
    getchar();
    printf("Add new member:\n\n");
    printf("Enter member data:\n\n");
    m[member_count].id = random_geenerate();
    idlist[member_count] = m[member_count].id;
    printf("ID: %d\n", m[member_count].id);
    printf("\nEnter your name: ");
    gets(m[member_count].name);
    printf("\nEnter your phone number: ");
    gets(m[member_count].phone_number);
    printf("\nEnter your mail: ");
    gets(m[member_count].mail);
    printf("\nInput a password: ");
    gets(m[member_count].password);
    printf("\nEnter Date: ");
    gets(m[member_count].join_date);
    printf("\nInput your age, height and weight: ");
    scanf("%d %d %d", &m[member_count].age, &m[member_count].height, &m[member_count].weight);
    printf("\nData submitted successfully\n");
    int done = add_member();
    if (done == 0)
    {
        printf("Error adding member\n");
    }
    else
    {
        printf("Member added successfully\n");
    }
}

void view_all()
{
    printf("Total members: %d\n", member_count);
    printf("All members:\n\n");
    int i;
    for (i = 0; i < member_count; i++)
    {
        int id = idlist[i];
        char filename[20];
        toString(filename, id);
        char location[20] = "data/";
        strcat(filename, ".txt");
        strcat(location, filename);
        FILE *curr = fopen(location, "r");
        struct member m;
        fscanf(curr, "%[^\n]%*c", m.password);
        fscanf(curr, "%[^\n]%*c", m.name);
        fscanf(curr, "%[^\n]%*c", m.phone_number);
        fscanf(curr, "%[^\n]%*c", m.mail);
        fscanf(curr, "%[^\n]%*c", m.join_date);
        fscanf(curr, "%d", &m.age);
        fscanf(curr, "%d", &m.height);
        fscanf(curr, "%d", &m.weight);
        printf("Member %d:\n", i + 1);
        printf("ID: %d\t Name: %s\t Joined: %s\t Phone: %s\t Email: %s\n", id, m.name, m.join_date, m.phone_number, m.mail);
        fclose(curr);
    }
}

void edit_member(struct member mem)
{
    curMember = mem;
    fseek(curUser, 0, SEEK_SET);
    fprintf(curUser, "%s\n", encrypt(mem.password, mem.id));
    fprintf(curUser, "%s\n", mem.name);
    fprintf(curUser, "%s\n", mem.phone_number);
    fprintf(curUser, "%s\n", mem.mail);
    fprintf(curUser, "%s\n", mem.join_date);
    fprintf(curUser, "%d\n", mem.age);
    fprintf(curUser, "%d\n", mem.height);
    fprintf(curUser, "%d\n", mem.weight);
}

void edit_member_helper()
{
    struct member mem;
    char name[100], pass[15], phone[10], mail[100], join_date[1000];
    int age, height, weight;
    printf("If you don't want to change a field, just press enter.\n");
    printf("\nNew name: ");
    getchar();
    gets(name);
    if (strcmp(name, "") != 0)
    {
        strcpy(mem.name, name);
    }
    else
        strcpy(mem.name, curMember.name);
    printf("\nNew phone number: ");
    gets(phone);
    if (strcmp(phone, "") != 0)
    {
        strcpy(mem.phone_number, phone);
    }
    else
        strcpy(mem.phone_number, curMember.phone_number);
    strcpy(mem.join_date, curMember.join_date);
    printf("\nNew mail: ");
    gets(mail);
    if (strcmp(mail, "") != 0)
    {
        strcpy(mem.mail, mail);
    }
    else
        strcpy(mem.mail, curMember.mail);
    printf("\nNew password: ");
    gets(pass);
    if (strcmp(pass, "") != 0)
    {
        strcpy(mem.password, encrypt(pass, curMember.id));
    }
    else
        strcpy(mem.password, curMember.password);
    printf("\nNew age(0 to skip): ");
    scanf("%d", &age);
    if (age != 0)
    {
        mem.age = age;
    }
    else
        mem.age = curMember.age;
    printf("\nNew height(0 to skip): ");
    scanf("%d", &height);
    if (height != 0)
    {
        mem.height = height;
    }
    else
        mem.height = curMember.height;
    printf("\nNew weight(0 to skip): ");
    scanf("%d", &weight);
    if (weight != 0)
    {
        mem.weight = weight;
    }
    else
        mem.weight = curMember.weight;
    char conf[15];
    printf("\nEnter old password to confirm: ");
    scanf("%s", conf);
    if (strcmp(encrypt(conf, curMember.id), curMember.password) != 0)
    {
        printf("Invalid password!\n");
        return;
    }
    printf("\nData submitted successfully\n");
    edit_member(mem);
}

int del_member(int id)
{
    int i;
    for (i = 0; i < member_count; i++)
    {
        if (id == idlist[i])
        {
            break;
        }
    }
    if (i == member_count)
    {
        printf("Member not found.\n");
        return 0;
    }
    for (; i < member_count - 1; i++)
    {
        idlist[i] = idlist[i + 1];
    }
    member_count--;
    char filename[20];
    toString(filename, id);
    strcat(filename, ".txt");
    char location[20] = "data/";
    strcat(location, filename);
    printf("%s\n", location);
    FILE *f = fopen(location, "w");
    fprintf(f, "%s", "deleted");
    fclose(f);
    int r = remove(filename);
    updateUser();
    printf("Member deleted successfully\n");
    return 1;
}

void del_member_helper()
{
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    int ps;
    printf("Enter master password: ");
    scanf("%d", &ps);
    if (ps != master_password)
    {
        printf("Invalid password!\n");
        return;
    }
    del_member(id);
}

void search_member()
{
    int id, i;
    printf("\nEnter ID to search: ");
    scanf("%d", &id);
    for (i = 0; i < member_count; i++)
    {
        if (id == idlist[i])
        {
            char filename[20];
            toString(filename, id);
            strcat(filename, ".txt");
            char location[20] = "data/";
            strcat(location, filename);
            FILE *fp = fopen(location, "r");
            if(fp == NULL) 
            {
                printf("Member not found.\n");
                return;
            }
            struct member memb;
            fscanf(fp, "%[^\n]%*c", memb.password);
            fscanf(fp, "%[^\n]%*c", memb.name);
            fscanf(fp, "%[^\n]%*c", memb.phone_number);
            fscanf(fp, "%[^\n]%*c", memb.mail);
            fscanf(fp, "%[^\n]%*c", memb.join_date);
            fscanf(fp, "%d", &memb.age);
            fscanf(fp, "%d", &memb.height);
            fscanf(fp, "%d", &memb.weight);
            printf("\nMember ID: %d\n", id);
            printf("Name: %s\nJoined: %s\nPhone: %s\nEmail: %s\n", memb.name, memb.join_date, memb.phone_number, memb.mail);
            fclose(fp);
            return;
        }
    }
    printf("Member not found.\n");
}

int login()
{
    int id, i;
    char p[15];
    printf("Login:\n");
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter password: ");
    scanf("%s", p);
    char* pass = encrypt(p, id);
    for (i = 0; i < member_count; i++)
    {
        if (idlist[i] == id)
        {
            current_id = id;
            break;
        }
    }
    if (i == member_count)
    {
        printf("Invalid ID\n");
        return 0;
    }
    char filename[20];
    toString(filename, id);
    strcat(filename, ".txt");
    char location[20] = "data/";
    strcat(location, filename);
    curUser = fopen(location, "r+");
    char password[15];
    fscanf(curUser, "%[^\n]%*c", curMember.password);
    if (strcmp(curMember.password, pass) != 0)
    {
        printf("Invalid password\n");
        fclose(curUser);
        return 0;
    }
    curMember.id = id;
    fscanf(curUser, "%[^\n]%*c", curMember.name);
    fscanf(curUser, "%[^\n]%*c", curMember.phone_number);
    fscanf(curUser, "%[^\n]%*c", curMember.mail);
    fscanf(curUser, "%[^\n]%*c", curMember.join_date);
    fscanf(curUser, "%d", &curMember.age);
    fscanf(curUser, "%d", &curMember.height);
    fscanf(curUser, "%d", &curMember.weight);
    printf("Login successful\n");
    fclose(curUser);
    return 1;
}

int logout()
{
    current_id = -1;
    struct member *x = &curMember;
    free(x);
    return 1;
}

void view_profile()
{
    printf("User Information:\n");
    printf("-----------------\n");
    printf("ID: %d\n", curMember.id);
    printf("Name: %s\n", curMember.name);
    printf("Phone: %s\n", curMember.phone_number);
    printf("Email: %s\n", curMember.mail);
    printf("Join Date: %s\n", curMember.join_date);
    printf("Age: %d\n", curMember.age);
    printf("Height: %d\n", curMember.height);
    printf("Weight: %d\n", curMember.weight);
    printf("BMI: %lf\n", BMI(curMember.height, curMember.weight));
    printf("BMI Category: %s\n", BMI_category(curMember.height, curMember.weight));
    printf("Keep up the good work!\n");
}

int admin_login()
{
    int pass;
    printf("Admin Login:\n");
    printf("\nEnter master password: ");
    scanf("%d", &pass);
    if (pass == master_password)
    {
        current_id = 1500;
        printf("Login successful\n");
        return 1;
    }
    else
    {
        printf("Invalid password\n");
        return 0;
    }
}

void mainUI()
{
    printf("Welcome to your very own Gym Management System!\n");
    printf("1.Admin Login\n");
    printf("2.Member Login\n");
    printf("3.Exit\n");
}

void userUI()
{
    printf("Welcome %s!\n", curMember.name);
    printf("1.View profile\n");
    printf("2.Edit profile\n");
    printf("3.Logout\n");
    printf("4.Exit\n");
}

void adminUI()
{
    printf("Welcome, Admin!\n");
    printf("1.Add member\n");
    printf("2.View all members\n");
    printf("3.Search member\n");
    printf("4.Delete member\n");
    printf("5.Logout\n");
    printf("6.Exit\n");
}

void clearTerminal()
{
#ifdef _WIN32
    system("cls"); // For Windows
#else
    system("clear"); // For Unix-like systems
#endif
}

int main()
{
    char no[10];
    user = fopen("data/user.txt", "r");
    fseek(user, 0, SEEK_SET);
    while (fscanf(user, "%d", &idlist[member_count]) != EOF)
    {
        member_count++;
    }
    fseek(user, 0, SEEK_SET);
    fclose(user);
    int choice;
    
    while (1)
    {
        clearTerminal();
        if (current_id == -1)
        {
            mainUI();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                clearTerminal();
                admin_login();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                clearTerminal();
                login();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                clearTerminal();
                fclose(user);
                if (curUser != NULL)
                {
                    fclose(curUser);
                }
                printf("Thank you for using our system!\n");
                getchar();
                getchar();
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            }
        }
        else if (current_id == 1500)
        {
            adminUI();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                clearTerminal();
                add_member_helper();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                clearTerminal();
                view_all();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                clearTerminal();
                search_member();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 4:
                clearTerminal();
                del_member_helper();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 5:
                clearTerminal();
                current_id = -1;
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 6:
                clearTerminal();
                fclose(user);
                if (curUser != NULL)
                {
                    fclose(curUser);
                }
                printf("Thank you for using our system!\n");
                getchar();
                getchar();
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            }
        }
        else
        {
            userUI();
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
                clearTerminal();
            case 1:
                view_profile();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 2:
                clearTerminal();
                edit_member_helper();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 3:
                clearTerminal();
                logout();
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            case 4:
                clearTerminal();
                fclose(user);
                if (curUser != NULL)
                {
                    fclose(curUser);
                }
                printf("Thank you for using our system!\n");
                getchar();
                getchar();
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                printf("Press enter to continue...\n");
                getchar();
                getchar();
                break;
            }
        }
    }

    return 0;
}

// gcc -o gym gym.c