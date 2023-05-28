#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structura pentru noduri
struct Elem {
    int count_players;  //numarul de jucatori
    char* team_name;    //numele echipei
    int score;  //scorul
    struct Player* players; //jucatorii
    struct Elem * next ; // adresa elementului urmator
};
typedef struct Elem Node ;

struct Player
{
    char* firstName;    //primul nume al jucatorului
    char* secondName;   //al doilea nume al jucatorului
    int points;         //numarul de puncte al jucatorului
};

/*Functie care adauga un nod la inceputul unei liste*/
void addAtBeginning ( Node ** head, int nr, char* name);

/*Functie care adauga un nod la inceputul unei liste*/
void addAtBeginningMod(Node **head, Node * vec);

/*Functie prin care afisam o lista*/
void printList(Node *head);

/*Functie prin care eliminam un nod in functie de scorul unei echipe*/
void delete(Node** head, int v);

/*Functie prin care scriem in fisier task-urile 1 sau 2*/
void print_task_1_2(Node *head,FILE* output);

/*Functie prin care gasim minimul intr-o lista*/
int findMin(Node *head);

/*Functie ptrin care citim tot input-ul din fisierul d.in*/
int read_teams_from_input(FILE* input, struct Elem** teams);

/*Functie prin care rezolvam exercitiile 1 si 2*/
int process_task_1_2_and_a(char* t1, char* t2, struct Elem** teams, int nr, FILE* output);




