/*Cerinta problemei Circuitul Calului: Se dă o tablă de șah de N x N elemente pe care se află un cal la coordonatele
(i,j). Se cere să se scrie un program care determină mutările calului (respectând săritura calului
din jocul de șah) astfel încât toate pozițiile tablei să fie acoperite.*/

//Plan de rezolvare:

/*
    Voi folosi implementarea algoritmului lui Warnsdorff.
    Folosind acest algoritm voi cere utilizatorului sa introduca de la tastatura numarul de linii si coloane ale tablei de sah, respectiv
    N, din cerinta, iar apoi ii voi da oportunitatea de a alege pozitia de plecare a calului.
    Planul este urmatorul: ma voi folosi de 2 vectori pentru pozitiile/directiile pe care le poate lua calul pe tabla de sah, unul pentru randuri
    si unul pentru coloane.
    Voi implementa o functie de calculare a numarului de miscari posibile pentru cal la fiecare pozitie, iar apoi o functie recursiva
    pentru efectuarea miscarilor.
*/

//Implementarea

#include <iostream>
using namespace std;

//vectori pentru directiile/pozitiile pe care le poate lua calul pe randuri si coloane
const int x[8]={-1,1,2,2,1,-1,-2,-2};
const int y[8]={2,2,1,-1,-2,-2,-1,1};

//declaram global matricea de mutari, dimensiunea matricei si numarul mutarii
int matrice_mutari[50][50],mutari,dimensiune_matrice;

void traversare(int linie, int coloana)
{
    int next_linie, next_coloana, gasit=0, nr_miscari;
    int min = 9;    //ne folosim de un min=9, o valoare cu 1 mai mare decat maximul de miscari valide pe care calul le poate face
    for(int i = 0 ; i <= 7 ; i++)
    {
        if(linie + x[i] >= 1 && linie + x[i] <= dimensiune_matrice && coloana + y[i] >= 1 && coloana + y[i] <= dimensiune_matrice)
        {
            //aici va trebui sa calculez recursiv numarul de miscari valide pe care le va putea face calul
            //dupa ce calculez numarul, compar cu min si pastram mereu numarul minim de miscari, apoi updatez linia curenta si 
            //coloana curenta si gasit in cazul in care gasim miscarea
        }
    }
}

int main()
{
    cout << "Dimensiune matrice N x N:";
    cin >> dimensiune_matrice;
    int poz_rand , poz_coloana;
    cout << "Introduceti pozitia de inceput a calului: ";
    cin >> poz_rand>>poz_coloana;
    matrice_mutari[poz_rand][poz_coloana] = 1;

    //functia recursiva de traversare a miscarilor pe tabla de sah

    for(int i = 1 ; i <= dimensiune_matrice ; i++)
    {
        for(int j = 1 ; j <= dimensiune_matrice ; j++)
        {
            cout << matrice_mutari[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
