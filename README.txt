Mai întâi vom citi din fișier. Pe prima linie avem numărul de echipe, pe care îl vom lua sub formă de string și îl vom transforma într-un număr întreg folosind funcția "atoi". Apoi, vom itera de la 1 la numărul de echipe pentru a citi fiecare linie.

În continuare, vom avea numărul de jucători al fiecărei echipe și numele ei, pe care le vom citi într-un buffer. Acestea vor fi delimitate și puse într-o structură de date pentru echipă. Vom citi apoi numele și prenumele fiecărui jucător și scorul pe care îl are fiecare, pe care îl vom adăuga la scorul total al echipei. Pe măsură ce citim din fișier, toate aceste date sunt introduse într-un nod și adăugate într-o listă.

Task-ul 1 ne cere doar să afișăm numele echipelor înscrise, pe care le vom scrie în fișierul "r.out" iterând prin respectiva listă.

Pentru task-ul 2, mai întâi am calculat câte echipe vor trebui să participe, după care am făcut diferența dintre numărul total de echipe și numărul de echipe participante. Această diferență reprezintă numărul de echipe care trebuie eliminate. Am utilizat un for în care am aflat de fiecare dată minimul din listă, după care am eliminat acel nod.

Pentru task-ul 3, mai întâi am adăugat echipele într-o coadă, după care am utilizat un while în care am scos câte două echipe din coadă pentru a afla, bazat pe scor, cine câștigă. Echipa câștigătoare este adăugată într-o stivă, iar echipa învinsă este adăugată într-o altă stivă (echipele câștigătoare vor primi câte un punct). Acest proces se va repeta până când coada va fi goală. Vom elibera stiva cu echipele care au pierdut, iar echipele câștigătoare se vor adăuga din nou în coadă. Acest proces se termină după ce se va juca finala. 

Atunci când ne aflăm în optimi, dorim să stocăm aceste echipe într-o listă pentru a reuși să efectuăm task-ul 4.

La task-ul 4, vom adăuga lista pe care am salvat-o în task-ul precedent într-un arbore BST, după care vom afișa acest arbore în postordine pentru a afișa echipele cu scorul cel mai mare. În comparație cu un arbore BST normal, pe lângă comparația scorurilor, am adăugat și comparația numelor.

Consider că tema este utilă, mai ales pentru faptul că reprezintă o aprofundare a cunoștințelor despre liste, stive, cozi și arbori de căutare.