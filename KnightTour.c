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