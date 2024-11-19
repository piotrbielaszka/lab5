#include <iostream>
#include <vector>
#include "Human.hpp"

using namespace std;

void add_n_humans(vector<Human> &vect, const unsigned int n_hum);
void print_vector(vector<Human> &vect);
void create_humans(vector<Human> &hum_vect);
void help();

int main()
{
    // zad 1,2
    //  vector<int> v1;

    // cout << "Rozmiar wektora to: " << v1.size();
    // cout << "\t a jego pojemnosc to: " << v1.capacity() << ".\n";

    // for (int i = 0; i < 100; i++)
    // {
    //     v1.emplace_back(i);

    //     cout << "Rozmiar wektora to: " << v1.size();
    //     cout << "\t a jego pojemnosc to: " << v1.capacity() << ".\t";
    //     cout << "Adres pierwszego elementu: " << &v1[0] << ".\n";
    // }

    // zad3
    //  vector<int> v2(100, 42);
    //  cout << "Rozmiar wektora to: " << v2.size();
    //  cout << "\t a jego pojemnosc to: " << v2.capacity() << ".\n";

    // vector<int> v3{100, 42};
    // cout << "Rozmiar wektora to: " << v3.size();
    // cout << "\t a jego pojemnosc to: " << v3.capacity() << ".\n";

    // zad 4
    vector<Human> hum_vect{};
    create_humans(hum_vect);
    string cmd;
    while (cmd != "exit")
    {
        cout << "Wpisz komende: ";
        cin >> cmd;
        if (cmd == "add")
            create_humans(hum_vect);
        else if (cmd == "pop")
            hum_vect.pop_back();
        else if (cmd == "list")
            print_vector(hum_vect);
    }
    return 0;
}

void create_humans(vector<Human> &hum_vect)
{
    cout << "Wpisz ilu ludzi chcesz stworzyc: ";
    int n_hum = 0;
    cin >> n_hum;

    add_n_humans(hum_vect, n_hum);
    print_vector(hum_vect);
}

void help()
{
    cout << "Lista komend:\n";
    cout << "help: wypisuje liste komend\n";
    cout << "add: dodaje ludzi";
    cout << "pop: usuwa ostsnia osobe";
}

void add_n_humans(vector<Human> &vect, const unsigned int n_hum)
{
    for (int i = 0; i < n_hum; i++)
    {
        string name;
        cout << "Wpisz imie czlowieka " << i << ": ";
        cin >> name;
        vect.emplace_back(name, 10 + i, i % 2, i % 4 == 0);
    }
}

void print_vector(vector<Human> &vect)
{
    int s = vect.size();
    for (int i = 0; i < s; i++)
    {
        cout << i << ":\tImie: " << vect[i].getName() << "\t Wiek: " << vect[i].getAge() << "\t Jest potworem: " << vect[i].isMonster() << "\n";
    }
}