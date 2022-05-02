/*
STUDENTS DATABASE
Author: Kamil Koltowski
Date: 2018
Description: Simple tool made for managing database of students
*/


#include <cstdlib>
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

struct student
{
    string imie, nazwisko, plec;
    long int pesel, indeks;
};
student s[100];
int i;

void add_student()
{
    char choice;
    system("cls");
    cout << "WPROWADZANIE STUDENTA DO BAZY DANYCH" << endl;
    cout << endl;
    do
    {
        cout << "Student ID " << i + 1 << endl;
        cout << "Podaj imie: ";
        cin >> s[i].imie;
        cout << "Podaj nazwisko: ";
        cin >> s[i].nazwisko;
        cout << "Podaj plec: ";
        cin >> s[i].plec;
        cout << "Podaj pesel: ";
        cin >> s[i].pesel;
        cout << "Podaj nr. indeksu: ";
        cin >> s[i].indeks;
        i++;
        cout << endl;
        cout << "Czy chcesz dodac kolejnego studenta? wpisz t/n ";
        cin >> choice;
        cout << endl;
    } while (choice != 'n');
    cout << "Nacisnij dowolny klawisz aby powrocic do menu" << endl;
    _getch();
    system("cls");
}

void display_all_student()
{
    system("cls");
    cout << "LICZBA STUDENTOW W BAZIE: " << i << endl;
    cout << endl;
    for (int j = 0; j < i; j++)
    {
        cout << "Student ID " << j + 1 << endl;
        cout << "Imie: " << s[j].imie << endl;
        cout << "Nazwisko: " << s[j].nazwisko << endl;
        cout << "Plec: " << s[j].plec << endl;
        cout << "Pesel: " << s[j].pesel << endl;
        cout << "Nr. indeksu: " << s[j].indeks << endl;
        cout << endl;
    }
    cout << "Nacisnij dowolny klawisz aby powrocic do menu" << endl;
    _getch();
    system("cls");
}

void display_student()
{
    system("cls");
    int d;
    cout << "LICZBA STUDENTOW W BAZIE: " << i << endl;
    cout << endl;
    cout << "Wpisz numer ID studenta aby zobaczyc jego dane ";
    cin >> d;
    while (d > i)
    {
        cout << "Nie ma takiego ID, sprobuj ponownie: ";
        cin >> d;
    }
    for (int c = d; c <= d; c++)
    {
        cout << "Student ID " << d << endl;
        cout << "Imie: " << s[c - 1].imie << endl;
        cout << "Nazwisko: " << s[c - 1].nazwisko << endl;
        cout << "Plec: " << s[c - 1].plec << endl;
        cout << "Pesel: " << s[c - 1].pesel << endl;
        cout << "Nr. indeksu: " << s[c - 1].indeks << endl;
        cout << endl;
    }
    cout << "Nacisnij dowolny klawisz aby powrocic do menu" << endl;
    _getch();
    system("cls");
}

void remove_student()
{
    system("cls");
    int kto;
    cout << "LICZBA STUDENTOW W BAZIE: " << i << endl;
    cout << endl;
    cout << "Podaj numer ID studenta aby usunac go z bazy danych ";
    cin >> kto;
    while (kto > i)
    {
        cout << "Nie ma takiego ID, sprobuj ponownie: ";
        cin >> kto;
    }
    for (int a = kto; a < i; a++)
    {
        s[a - 1].imie = s[a].imie;
        s[a - 1].nazwisko = s[a].nazwisko;
        s[a - 1].plec = s[a].plec;
        s[a - 1].pesel = s[a].pesel;
        s[a - 1].indeks = s[a].indeks;
    }
    i--;
    cout << endl;
    cout << "Pomyslnie usunieto studenta z bazy danych, nacisnij dowolny klawisz aby powrocic do menu" << endl;
    _getch();
    system("cls");
}

void find_student()
{
    system("cls");
    long int szukana;
    cout << "LICZBA STUDENTOW W BAZIE: " << i << endl;
    cout << endl;
    cout << "Wpisz numer indeksu studenta aby pokazac jego informacje ";
    cin >> szukana;
    cout << endl;

    for (int i = 0; i < szukana; i++)
    {
        if (szukana == s[i].indeks)
        {
            cout << "Student ID " << i + 1 << " [Numer studenta w tablicy to " << i << "]" << endl;
            cout << "Imie: " << s[i].imie << endl;
            cout << "Nazwisko: " << s[i].nazwisko << endl;
            cout << "Plec: " << s[i].plec << endl;
            cout << "Pesel: " << s[i].pesel << endl;
            cout << "Nr. indeksu: " << s[i].indeks << endl;
            break;
        }
    }
    cout << endl;
    cout << "Nacisnij dowolny klawisz aby powrocic do menu" << endl;
    _getch();
    system("cls");
}

void save_student()
{
    ofstream plik("student.txt", ios::out | ios::trunc);
    plik << "LICZBA STUDENTOW W BAZIE: " << i << endl;
    plik << endl;
    for (int j = 0; j < i; j++)
    {
        plik << "Imie: " << s[j].imie << endl;
        plik << "Nazwisko: " << s[j].nazwisko << endl;
        plik << "Plec: " << s[j].plec << endl;
        plik << "Pesel: " << s[j].pesel << endl;
        plik << "Nr. indeksu: " << s[j].indeks << endl;
        plik << endl;
    }

    cout << "Dane zostaly zapisane, nacisnij dowolny klawisz aby powrocic do menu";
    _getch();
    system("cls");
}

void load_student()
{
    ifstream plik("student.txt", ios::in);
    plik >> i;
    int j = 0;
    do
    {
        plik >> s[j].imie;
        plik >> s[j].nazwisko;
        plik >> s[j].plec;
        plik >> s[j].pesel;
        plik >> s[j].indeks;
        j++;
    } while (!plik.eof());
    cout << "Dane zostaly wczytane, nacisnij dowolny przycisk aby kontyunowac" << endl;
    _getch();
    system("cls");
}

int main()
{
    int wybor;

    while (true)
    {
        cout << "ZADANIE ZALICZENIOWE                         [Kamil Koltowski, Indeks: 240631]" << endl;
        cout << "===================================" << endl;
        cout << "[1].Dodaj studenta do bazy danych." << endl;
        cout << "[2].Wyswietl wszystkich studentow." << endl;
        cout << "[3].Wyswietl pojedynczego studenta po ID." << endl;
        cout << "[4].Usun studenta z bazy danych." << endl;
        cout << "[5].Znajdz studenta w bazie po numerze indeksu." << endl;
        cout << "[6].Zapisz dane studentow w pliku." << endl;
        cout << "[7].Wczytanie studentow z pliku." << endl;
        cout << "[8].Wyjscie z programu." << endl;
        cout << "===================================" << endl;
        cout << "Wybieram opcje nr: ";
        cin >> wybor;
        cout << endl;
        switch (wybor)
        {
        case 1:
        {
            add_student();
            break;
        }
        case 2:
        {
            display_all_student();
            break;
        }
        case 3:
        {
            display_student();
            break;
        }
        case 4:
        {
            remove_student();
            break;
        }
        case 5:
        {
            find_student();
            break;
        }
        case 6:
        {
            save_student();
            break;
        }
        case 7:
        {
            load_student();
            break;
        }
        case 8:
        {
            exit(0);
        }
        }
    }
    return 0;
}
