#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;
struct Name
{
    string first;
    string last;
};
struct Bdate
{
    int year;
    int month;
    int day;
};
struct Person
{
    int no;
    string ID;
    Name name;
    string email;
    string gender;
    string phone;
    Bdate bdate;
    string jobtitle;
};

void makePerson(vector<Person> &);
void printPerson(vector<Person>);
void sortPerson(vector<Person> &);

void makePerson(vector<Person> &person)
{
    ifstream file("people-100.csv");
    if (!file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        Person p;
        string token;

        // Read and assign each field of the Person struct
        getline(ss, token, ',');
        p.no = stoi(token);
        getline(ss, p.ID, ',');
        getline(ss, p.name.first, ',');
        getline(ss, p.name.last, ',');
        getline(ss, p.email, ',');
        getline(ss, p.gender, ',');
        getline(ss, p.phone, ',');
        getline(ss, token, '-');
        p.bdate.year = stoi(token);
        getline(ss, token, '-');
        p.bdate.month = stoi(token);
        getline(ss, token, ',');
        p.bdate.day = stoi(token);
        getline(ss, p.jobtitle, ',');

        person.push_back(p);
    }

    file.close();
}

void printPerson(vector<Person> person)
{
    vector<Person>::iterator it;
    printf("NO\tID\t\tName\t\t\tEmail\t\tPhone\t\t\tBirthday\t\t\t\tJobtitle\n");
    for (it = person.begin(); it != person.end(); it++)
    {
        cout << it->no << "\t";
        cout << it->ID << "\t";
        cout << it->name.first << " " << it->name.last << "\t";
        cout << it->email << "\t";
        cout << it->phone << "\t";
        cout << it->bdate.year << "\t"
             << it->bdate.month << "\t"
             << it->bdate.day << "\t";
        cout << it->jobtitle << endl;
    }
    cout << "**************************************************\n";
}

void sortPerson(vector<Person> &person)
{
    for (size_t i = 0; i < person.size() - 1; ++i)
    {
        for (size_t j = 0; j < person.size() - 1 - i; ++j)
        {
            if (person[j].name.last > person[j + 1].name.last)
            {
                swap(person[j], person[j + 1]);
            }
        }
    }
}

/*******************************
 * Code your program here
 *******************************/