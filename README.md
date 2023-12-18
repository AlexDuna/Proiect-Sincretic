# Proiect-Sincretic

Pentru proiectul sincretic am folosit Github, Github desktop, Visual Studio Code, Docker hub si Docker Desktop.

#CODUL#
Pentru rezolvarea problemei 25, traseul calului pe tabla de sah, am folosit algoritmul lui Warnsdorff prin care aleg ce dimensiune sa aibe tabla, aleg pozitia de plecare a calului pe tabla de sah, iar folosindu-ma de doua functii, dintre care una recursiva, traversez mutare cu mutare traseul pana nici o pozitie nu mai este libera.
Vectorii x si y reprezinta toate posibilitatile de pozitii pe care le poate lua calul pe matricea de mutari, de la o pozitie anume, x reprezentand pozitii pentru linia din matrice si y reprezentand pozitii pentru coloana.

Variabilele matrice_mutari[50][50], mutari, dimensiune_matrice, poz_linie, poz_coloana reprezinta: matricea pe care vom trece traseul parcurs de cal, numarul curent al fiecarei mutari, dimensiunea tablei de sah, pozitia initiala pe linie si pozitia initiala pe coloana.

Functia numar_mutari este functia care calculeaza cate mutari valide poate sa faca calul de la o anumita pozitie, sau de la pozitia curenta, mutare valida insemnand o mutare care pe o pozitie DIN matricea de mutari si pozitia sa fie 0, adica sa fie libera.

Functia traversare construieste recursiv traseul calului plecand de la o pozitie data si incrementand pozitia de plecare la fiecare autoapel al functiei. La fiecare apel trecem in matricea de mutari mutarea pe care a facut-o calul, verificam ca pozitia la care urmeaza sa sara sa fie valida si calculam numarul minim de mutari valide pe care calul poate sa le faca de la pozitia curenta. Daca s-a gasit o pozitie valida, trecem la urmatoarea pozitie si trecem "gasit" pe 1 pentru ca s-a gasit o pozitie valida, apoi apelam recursiv functia pentru urmatoarea pozitie. Se va autoapela pana cand nu mai exista pozitii valide de mutare a calului, adica toata tabla a fost parcursa.

In main doar apelam functia cu valorile pe care dorim sa le dam dimensiunii tablei de sah si pozitiei de plecare.

#GITHUB si GIT DESKTOP#

Am folosit pentru prima data github si consider ca a fost foarte usor de folosit si extrem de folositor.
In primul rand in github poti sa-ti salvezi progresul unui cod sau a unui proiect, ajutandu-te de commituri, astfel oricand ai dori sa revi la o versiune anterioara a proiectului tau poti sa o faci, deoarece pasii pe care i-ai parcurs prin commituri sunt salvati.
Cum functioneaza github? 
Pe github lucram cu repository-uri, adica pentru fiecare proiect pe care il facem, cream un repository. In acest repository se vor salva tot progresul si toti pasii pe care ii parcurgem de-a lungul proiectului, impreuna cu toate fisierele folosite. De aceea, dupa cum am spus mai sus, se poate reveni la orice versiune anterioara care a fost salvata prin commituri a proiectului, sau a fisierelor din cadrul proiectului.
De asemenea github iti ofera posibilitatea de a lucra pe branch-uri, in cazul dezvoltarii unui proiect in echipa cu mai multi participanti. Proiectul meu nu este dezvoltat pe mai multe branch-uri deoarece am fost doar eu, o singura persoana care a lucrat la el deci nu a necesitat mai multe ramuri pentru proiect, dar totusi acest feature reprezinta un tool extrem de avantajos pentru lucrul in echipa, pentru corectarea de erori intr-un program mare, organizare si multe alte aspecte ale unui proiect.
Ca tot am vorbit de commituri, cum functioneaza commiturile si de ce sunt atat de importante si folositoare?
Odata creat un repository nou pe github, atunci cand deschizi visual studio code ai oportunitatea de a-ti conecta aplicatia cu repository-ul tau, astfel programele pe care le faci, codurile pe care le scrii, fisierele pe care le editezi vor fi conectate cu repository-ul tau, si odata cu fiecare editare a unuia dintre fisiere ai posibilitatea prin Github Desktop sa accesezi commitul. Adica aplicatia va vedea modificarile pe care le-ai facut, iti va spune ca ai facut modificari si iti ofera posibilitatea sa creezi un commit nou cu modificarea respectiva, pastrand si varianta fisierului tau de dinainte de modificare dar si varianta modificata, astfel de aici ni se ofera avantajul de a reveni la versiuni anterioare ale unui fisier de-al nostru salvat intr-un repository din github.

#DOCKER#
Docker, la fel ca si github, este o modalitate de a-ti usura treaba de programator. Cu ajutorul docker-ului si a containerelor din docker orice aplicatie/program/cod care functioneaza pe o masina anume, va functiona si pe alte masini de asemenea, deoarece containerele pot fi rulate pe orice sistem de operare, deci se elimina din start o problema foarte mare. Beneficiile containerelor sunt in principal: faptul ca, containerele se creeaza rapid si usor si le poti trimite mai departe la fel de usor, de asemenea mai multe containere putand fi rulate simultan.
Cum functioneaza Docker?
Principalul aspect al docker-ului este containerul. Exact cum suna, containerul grupeaza toate elementele esentiale ale unei aplicatii/program intr-un singur pachet, pentru a putea fi rulate/livrate deodata si nepierdandu-se nimic esential, in mod normal, vor putea fi folosite pe mai multe masini si sisteme de operare fara probleme.
Pentru problema mea am folosit un dockerfile. 
Dockerfile este un fișier de configurare text care conține instrucțiuni pentru construirea unei imagini Docker. Aceste instrucțiuni includ adăugarea de fișiere, instalarea de pachete, setarea de variabile de mediu și alte acțiuni necesare pentru configurarea mediului de execuție al containerului.
O imagine Docker este un pachet portabil care include codul aplicației, mediul de execuție, bibliotecile, variabilele de mediu și alte dependențe necesare pentru a rula aplicația într-un mediu izolat.

In dockerfile am folosit urmatoarele instructiuni pentru urmatoarele functii:
FROM gcc:latest
FROM - este instructiunea care indica crearea unei noi imagini si specifica imaginea de baza de pe care va fi construit containerul
gcc:latest - indica faptul ca se va incepe construirea containerului pe baza imaginii GCC, de ce gcc? Pentru ca am lucrat in C++

WORKDIR C:\Users\Alex\Desktop\Proiect Sincretic\Proiect-Sincretic 
Aceasta comanda specifica directorul in care lucram, si aici am plasat codul meu cpp

COPY KnightTour.cpp .
Aceasta comanda indică Docker Engine să copieze fișierul KnightTour.cpp (codul meu) din directorul local al sistemului de fișiere (unde se află Dockerfile-ul) în directorul curent al sistemului de fișiere din containerul în curs de construcție.

RUN gcc -o KnightTour KnightTour.cpp -lstdc++
Această comandă are rolul de a compila fișierul KnightTour.cpp folosind compilatorul GCC și de a crea un executabil numit KnightTour.

CMD ["./KnightTour"]
Această comandă indică ce proces sau aplicație ar trebui să fie lansată în interiorul containerului atunci când acesta este pornit.

Dupa ce am introdus toate acestea in Dockerfile, am introdus urmatoarele comenzi intr-un terminal (cmd):
docker build -t alexduna/my-gcc-app .
docker build - Aceasta este comanda principală pentru construirea imaginilor Docker. 
-t este folosit pentru a specifica numele imaginii
alexduna/my-gcc-app este numele imaginii.

docker run -d -p 8080:80 alexduna/my-gcc-app 
Aceasta comanda este folosită pentru a rula un container Docker bazat pe imaginea alexduna/my-gcc-app
-d face ca containerul să ruleze în modul detach, adică în fundal. Acest lucru permite ca terminalul să fie eliberat pentru alte comenzi.
8080:80 este utilizată pentru a publica porturile containerului către porturile gazdei. Astfel, poți accesa aplicația în container la adresa localhost:8080

docker login
Comanda docker login este utilizată pentru a autentifica un utilizator într-un registry Docker, permițându-i să încarce (push) și să descarce (pull) imagini către și de la acel registry.

docker push 
Comanda docker push este folosită pentru a încărca o imagine Docker către un registry Docker.





