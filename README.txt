Mai intai vom citi din fisier. Pe prima linie avem numarul de echipe, il vom lua
sub forma unui string si il vom trnasforma in integer value (folosind atoi)
dupa care vom iterade la 1 la numarul de echipe pentru a citi fiecare linie
In continuare vom avea numarul de jucatori al fiecarei echipe si numele ei,
pe care le vom citi intr-un buffer, vor fi delimitate si puse in structura de
date pentru echipa. Vom citi dupa numele si prenumele fiecarui jucatori si
scorul pe care il are fiecare pen care il vom incrementa la scorul total al
ehipei. In timp ce citim din fisier toate aceste date sunt bagate in-trun nod 
si adaugate intr-o lista.
Task-ul 1 ne cere doar sa afisam numele echipelor inscrise, pe care le vom scrie
in fisierul r.out iterand prin lista respectiva.
Pentru task-ul 2 mai intai am calculat cate echipe vor trebui sa participe dupa
care am facut diferenta dintre numarul de echipe totale si numarul de echipe participante
Aceasta diferenta reprezinta cate echipe trebuie eliminate. Am facut un for in care
am aflat de fiecare data minimul din lista dupa care am eliminat acel nod.
Pentru task-ul 3 mai intai am adaugat echipele intr-o coada, dupa care am facut
un while in care am scos din cate doua echipe din coada pentru a afla bazat pe scor
cine castiga. Echipa este adaugata intr-o stiva iar echipa pierzatoare este adaugata
in alta stiva (echipele castigatoare vor primi cate un punct). Acest rationament se va
repeta pana cand vom goli coada. Vom elibera stiva cu echipele care au pierdut
iar echipele castigatoare se vor adauga din nou in coada. Acest rationament se
termina dupa ce se va juca finala. Atunci cand ne aflam in optimi, dorim sa stocam
aceste echipe intr-o lista pentru a reusi sa efectuam task-ul 4
La task-ul 4 vom adauga lista pe care am salvat-o la task-ul precedent intr-un
arbore BST dupa care vom afisa acest arbore in postordine pentru a afisa echipele
cu scorul cat mai mare. Fata de un arbore BST normal,, pe langa comparatia scorurilor
am adaugat si comparatia de nume.
Consider ca tema este utila, mai ales pentru faptul ca reprezinta o aprofundare a cunostintelor despre liste, stive, cozi si arbori de cautare.