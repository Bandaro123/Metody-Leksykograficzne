#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>


void wyswietl_kategorie(); // funkcja wyświetlająca opis kategorii
void mal_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik, int pozycja); // funkcja sortująca, pierwszy element jest elementem wokół którego się sortuje
// pozostałe elementy są tylko po to, by podążyć za elementem sortowanym
int ros_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik, int pozycja); // jw. tylko że rosnąco
int zliczanie(float *F1); // funkcja sprawdzająca w ilu przypadkach jest remis
void wybierz(int wybor);
void wyswietl_tabele(); // wyswietla tabele na ekranie
int licznik = 11, pozycja = 0;

using namespace std;
float F1[10] = {1, 3, 2, 5, 6, 3, 1, 2, 3, 6};
float F2[10] = {9, 9, 9, 9, 9, 3, 4, 1, 2, 1};
float F3[10] = {4, 4, 4, 3, 3, 9, 9, 9, 2, 2};
float F4[10] = {7, 2, 3, 6, 8, 4, 4, 6, 1, 2};
float F5[10] = {6, 2, 3, 4, 2, 3, 8, 9, 9, 3};
float F6[10] = {7, 4, 3, 5, 5, 3, 2, 8, 8, 8};
int wybor, wariant[10] = {1,2,3,4,5,6,7,8,9,10};

int main()
{

    cout << "Witaj w programie oceny dystrybucji paliw metod¹ leksykograficzna! Podaj najwa¿niejsza kategorie z podanych:  " << endl;
    cout << endl;
    int b=1;
    do
    {
        wyswietl_kategorie();
        wyswietl_tabele();

        do
        {
            cout << "Podaj kategorie: ";
            cin >> wybor;
            switch(wybor)
            {
            case 1:
                ros_sortowanie(F1, F2, F3, F4, F5, F6, wariant, licznik, pozycja);
                licznik=zliczanie(F1);
                break;

            case 2:
                ros_sortowanie(F2, F1, F3, F4, F5, F6, wariant, licznik, pozycja);
                licznik=zliczanie(F2);
                break;

            case 3:
                ros_sortowanie(F3, F1, F2, F4, F5, F6, wariant, licznik, pozycja);
                licznik=zliczanie(F3);
                break;

            case 4:
                ros_sortowanie(F4, F1, F3, F2, F5, F6, wariant, licznik, pozycja);
                licznik=zliczanie(F4);
                break;

            case 5:
                ros_sortowanie(F5, F1, F3, F4, F2, F6, wariant, licznik, pozycja);
                licznik=zliczanie(F5);
                break;

            case 6:
                ros_sortowanie(F6, F1, F3, F4, F5, F2, wariant, licznik, pozycja);
                licznik=zliczanie(F6);
                break;
            }
            wyswietl_tabele();
        }
        while(licznik>1);
        cout << endl << "Zakonczyles sortowanie!" << endl << endl;
        licznik = 11, pozycja = 0;


    }
    while(b);
    return 0;
}

void wyswietl_kategorie()
{
    cout << "1 - œredni czas potrzebny na pokonanie drogi od magazynu do odbiorcy paliwa [h]" << endl;
    cout << "2 - wspó³czynnik gotowoœci technicznej pojazdu [-]" << endl;
    cout << "3 - liczba osób zatrudnionych [-]" << endl;
    cout << "4 - koszty inwestycji obejmuj¹ce wymianê czêœci taboru i wybudowanie nowych magazynów [z³]" << endl;
    cout << "5 - koszty deinwestycji zwi¹zany ze sprzeda¿¹ grupy œrodków transportu [z³]" << endl;
    cout << "6 - ³¹czne koszty dystrybucji [z³]" << endl;
}

int ros_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik, int pozycja)
{
    for(int j = 0; j < licznik-1; j++)
        for(int i = 0; i < licznik-1; i++)
        {
            if(F1[i] < F1[i + 1])
            {
                std::swap(F1[i], F1[i + 1]);
                std::swap(F2[i], F2[i + 1]);
                std::swap(F3[i], F3[i + 1]);
                std::swap(F4[i], F4[i + 1]);
                std::swap(F5[i], F5[i + 1]);
                std::swap(F6[i], F6[i + 1]);
                std::swap(wariant[i], wariant[i + 1]);
            }
        }
    return pozycja;
}

int zliczanie(float *F1)
{
    int licznik=1;
    for(int i=0; i<10; i++)
    {
        cout << "F1[" << i << "] wynosi " << F1[i] << endl;
        if( F1[i] == F1[i+1])
        {
            licznik++;
            cout << "Licznik wynosi " << licznik << endl;
        }
        else
            break;
    }
    return licznik;
}

void wyswietl_tabele()
{
    for(int i = 0; i < 10; i++)
        cout << "Wariant" << wariant[i] << ": " << F1[i] << setw(4) << F2[i] << setw(4) << F3[i] << setw(4)  << F4[i] << setw(4) << F5[i] << setw(4) << F6[i] << setw(4) << endl;
}
