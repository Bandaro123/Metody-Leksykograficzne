#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>


void wyswietl_kategorie(); // funkcja wyświetlająca opis kategorii
void mal_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik); // funkcja sortująca, pierwszy element jest elementem wokół którego się sortuje
// pozostałe elementy są tylko po to, by podążyć za elementem sortowanym
void ros_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik); // jw. tylko że rosnąco
int zliczanie(float *F1); // funkcja sprawdzająca w ilu przypadkach jest remis
void wybierz(int wybor);
int licznik = 10;

using namespace std;
float F1[10], F2[10], F3[10], F4[10], F5[10], F6[10];
int wybor, wariant[10] = {1,2,3,4,5,6,7,8,9,10};

int main()
{
    srand((unsigned)time(NULL));
    for(int i = 0; i < 10; i++)
        F1[i] = rand() % 10; // losowanie liczby
    for(int i = 0; i < 10; i++)
        F2[i] = rand() % 10;
    for(int i = 0; i < 10; i++)
        F3[i] = rand() % 10;
    for(int i = 0; i < 10; i++)
        F4[i] = rand() % 10;
    for(int i = 0; i < 10; i++)
        F5[i] = rand() % 10;
    for(int i = 0; i < 10; i++)
        F6[i] = rand() % 10;

    for(int i = 0; i < 10; i++)
        cout << "Wariant" << wariant[i] << ": " << F1[i] << setw(4) << F2[i] << setw(4) << F3[i] << setw(4)  << F4[i] << setw(4) << F5[i] << setw(4) << F6[i] << setw(4) << endl;
    cout << endl;
    int b=1;
    do
    {
        cout << "Witaj w programie oceny dystrybucji paliw metod¹ leksykograficzna! Podaj najwa¿niejsza kategorie z podanych:  " << endl;
        wyswietl_kategorie();
        cin >> wybor;
        switch(wybor)
        {
        case 1:
            ros_sortowanie(F1, F2, F3, F4, F5, F6, wariant, licznik);
            break;
        case 2:
            ros_sortowanie(F2, F1, F3, F4, F5, F6, wariant, licznik);
            break;
        case 3:
            ros_sortowanie(F3, F1, F2, F4, F5, F6, wariant, licznik);
            break;
        case 4:
            ros_sortowanie(F4, F1, F3, F2, F5, F6, wariant, licznik);
            break;
        case 5:
            ros_sortowanie(F5, F1, F3, F4, F2, F6, wariant, licznik);
            break;
        case 6:
            ros_sortowanie(F6, F1, F3, F4, F5, F2, wariant, licznik);
            break;
        }
            for(int i = 0; i < 10; i++)
        cout << "Wariant" << wariant[i] << ": " << F1[i] << setw(4) << F2[i] << setw(4) << F3[i] << setw(4)  << F4[i] << setw(4) << F5[i] << setw(4) << F6[i] << setw(4) << endl;

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

void mal_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik)
{
    for(int j = 0; j < licznik; j++)
        for(int i = 0; i < licznik; i++)
        {
            if(F1[i] > F1[i + 1])
            {
                std::swap(F1[i], F1[i + 1]);
                std::swap(wariant[i], wariant[i + 1]);


            }
        }

    for(int i = 0; i < 10; i++)
        cout << "Wariant" << wariant[i] << ": " << F1[i] << setw(4) << F2[i] << setw(4) << F3[i] << setw(4)  << F4[i] << setw(4) << F5[i] << setw(4) << F6[i] << setw(4) << endl;
}

void ros_sortowanie(float *F1, float *F2, float *F3, float *F4, float *F5, float *F6, int *wariant, int licznik)
{
    for(int j = 0; j < licznik; j++)
        for(int i = 0; i < licznik; i++)
        {
            if(F1[i] < F1[i + 1])
            {
                std::swap(F1[i], F1[i + 1]);
                std::swap(wariant[i], wariant[i + 1]);


            }
        }
    licznik=zliczanie(F1);
    if( licznik > 1 )
    {
        cout << "Podaj kolejna kategorie" << endl;
        cin >> wybor;
        cout << endl;
        switch(wybor)
        {
        case 1:
            ros_sortowanie(F1, F2, F3, F4, F5, F6, wariant, licznik);
            break;
        case 2:
            ros_sortowanie(F2, F1, F3, F4, F5, F6, wariant, licznik);
            break;
        case 3:
            ros_sortowanie(F3, F1, F2, F4, F5, F6, wariant, licznik);
            break;
        case 4:
            ros_sortowanie(F4, F1, F3, F2, F5, F6, wariant, licznik);
            break;
        case 5:
            ros_sortowanie(F5, F1, F3, F4, F2, F6, wariant, licznik);
            break;
        case 6:
            ros_sortowanie(F6, F1, F3, F4, F5, F2, wariant, licznik);
            break;
        }


    }
   /* for(int i = 0; i < 10; i++)
        cout << "Wariant" << wariant[i] << ": " << F1[i] << setw(4) << F2[i] << setw(4) << F3[i] << setw(4)  << F4[i] << setw(4) << F5[i] << setw(4) << F6[i] << setw(4) << endl; */
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

void wybierz(int wybor)
{
    switch(wybor)
    {


    case 1:
        mal_sortowanie(F1, F2, F3, F4, F5, F6, wariant, licznik);
        break;
    case 2:
        ros_sortowanie(F2, F1, F3, F4, F5, F6, wariant, licznik);
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    }


}
