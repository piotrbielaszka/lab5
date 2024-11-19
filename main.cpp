#include <iostream>
#include <list>
#include "Human.hpp"

using namespace std;

void add_n_humans(list<Human> &lst, const unsigned int n_hum);
void print_list(list<Human> &lst);
void print_list_reverse(list<Human> &lst);
void create_humans(list<Human> &hum_list);
void help();
void bday(list<Human> &lst);

int main()
{
    // list<int> l1;
    // l1.push_back(2);
    // l1.push_front(1);

    // cout << "Poczatek: " << l1.front() << "\t Adres: " << &l1.front() << "\n";
    // cout << l1.back() << "\t Adres: " << &l1.back() << "\n";

    list<Human> hum_list{};
    create_humans(hum_list);
    string cmd;
    while (cmd != "exit")
    {
        cout << "Wpisz komende: ";
        cin >> cmd;
        if (cmd == "add")
            create_humans(hum_list);
        else if (cmd == "pop")
            hum_list.pop_back();
        else if (cmd == "list")
            print_list(hum_list);
        else if (cmd == "list_rev")
            print_list_reverse(hum_list);
        else if (cmd == "bday")
            bday(hum_list);
    }
    return 0;
}

void create_humans(list<Human> &hum_list)
{
    cout << "Wpisz ilu ludzi chcesz stworzyc: ";
    int n_hum = 0;
    cin >> n_hum;

    add_n_humans(hum_list, n_hum);
    print_list(hum_list);
}

void help()
{
    cout << "Lista komend:\n";
    cout << "help: wypisuje liste komend\n";
    cout << "add: dodaje ludzi\n";
    cout << "pop: usuwa ostsnia osobe\n";
    cout << "list: wypisuje liste ludzi\n";
    cout << "list_rev: wypisuje liste ludzi od konca\n";
    cout << "exit: zatrzymuje program\n";
    cout << "bday: postarza ludzi o rok\n";
}

void add_n_humans(list<Human> &lst, const unsigned int n_hum)
{
    for (unsigned int i = 0; i < n_hum; i++)
    {
        string name;
        cout << "Wpisz imie czlowieka " << i << ": ";
        cin >> name;
        lst.emplace_back(name, 10 + i, i % 2, i % 4 == 0);
    }
}

void print_list(list<Human> &lst)
{
    // list<Human>::const_iterator it = lst.cbegin();
    // while (it != lst.end())
    // {
    //     cout << "Imie: " << it->getName() << "\t Wiek: " << it->getAge() << "\t Jest potworem: " << it->isMonster() << "\n";
    //     it++;
    // }
    for (Human h : lst)
    {
        cout << "Imie: " << h.getName() << "\t Wiek: " << h.getAge() << "\t Jest potworem: " << h.isMonster() << "\n";
    }
}

void print_list_reverse(list<Human> &lst)
{
    list<Human>::const_reverse_iterator it = lst.crbegin();
    while (it != lst.rend())
    {
        cout << "Imie: " << it->getName() << "\t Wiek: " << it->getAge() << "\t Jest potworem: " << it->isMonster() << "\n";
        it++;
    }
}

void bday(list<Human> &lst)
{
    auto it = lst.begin();
    while (it != lst.end())
    {
        it->birthday();
        it++;
    }
}