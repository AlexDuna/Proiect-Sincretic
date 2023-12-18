/*Cerinta problemei Circuitul Calului: Se dă o tablă de șah de N x N elemente pe care se află un cal la coordonatele
(i,j). Se cere să se scrie un program care determină mutările calului (respectând săritura calului
din jocul de șah) astfel încât toate pozițiile tablei să fie acoperite.*/

#include <iostream>
using namespace std;

//vectori pentru directiile/pozitiile pe care le poate lua calul pe randuri si coloane
const int x[8]={-1,1,2,2,1,-1,-2,-2};
const int y[8]={2,2,1,-1,-2,-2,-1,1};

//declaram global matricea de mutari, dimensiunea matricei si numarul mutarii
int matrice_mutari[50][50] = {},mutari,dimensiune_matrice=8, poz_rand=3,poz_coloana=6;

//functie ca sa calculam nr de mutari valide de la o anumita pozitie data de linie si coloana
int numar_mutari(int linie, int coloana)
{
    int nr=0;
    for(int i=0;i<=7;i++)
    {
        if(linie+x[i]>=1 && linie+x[i]<=dimensiune_matrice && coloana+y[i]>=1 && coloana+y[i]<=dimensiune_matrice && matrice_mutari[linie+x[i]][coloana+y[i]]==0)
            nr++;
    }
    return nr;
}

//functie de traversare a tablei de sah folosindu-ne de mutarile valide only
void traversare(int linie, int coloana)
{
    int next_linie, next_coloana, gasit, nr, min;
    matrice_mutari[linie][coloana] = mutari + 1;
    gasit = 0;
    min = 9;//ne folosim de un min=9, o valoare cu 1 mai mare decat maximul de miscari valide pe care calul le poate face
 
    for(int i = 0 ; i <= 7 ; i++)
    {
        if(linie+x[i]>=1 && linie+x[i]<=dimensiune_matrice && coloana+y[i]>=1 && coloana+y[i]<=dimensiune_matrice && matrice_mutari[linie+x[i]][coloana+y[i]] == 0)
        {
            nr = numar_mutari(linie + x[i],coloana + y[i]);
            if(nr < min)
            {
                min = nr;
                next_linie = linie + x[i];
                next_coloana = coloana + y[i];
                gasit = 1;
            }
        }
    }
        if(gasit)
        {
            mutari++;
            traversare(next_linie,next_coloana);
        }
}

int main()
{
    //cout << "Dimensiune matrice N x N:";
    //cin >> dimensiune_matrice;
    //int poz_rand , poz_coloana;
    //cout << "Introduceti pozitia de inceput a calului: ";
    //cin >> poz_rand>>poz_coloana;
    matrice_mutari[poz_rand][poz_coloana] = 1;

    traversare(poz_rand, poz_coloana);

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
