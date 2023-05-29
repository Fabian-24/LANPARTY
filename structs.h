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

typedef struct Queue {  //structura pentru coada
    Node* front;
    Node* rear;
} Queue;

typedef struct Stack {  //structura pentru stiva
    Node* top;
} Stack;

/*Functie care adauga un nod la inceputul unei liste*/
void addAtBeginning ( Node ** head, int nr, char* name);

/*Functie care adauga un nod la inceputul unei liste*/
void addAtBeginningMod(Node **head, Node * vec);

/*Functie prin care afisam o lista*/
void printList(Node *head);

/*Functie prin care eliminam un nod in functie de scorul unei echipe*/
void delete(Node** head, int v);

/*Functie prin care initiazima o coada*/
void initializeQueue(Queue* queue);

/*Functie prin care verificam daca o coada este goala*/
int isEmptyQueue(Queue* queue);

/*Functie prin care adaugam un nod intr-o coada*/
void enqueue(Queue* queue, Node* element);

/*Functie prin care scoatem un nod in coada (returneaza nodul pe care il scoatem)*/
Node* dequeue(Queue* queue);

/*Functie prin care convertim o lista la o coada*/
void convertListToQueue(Node* head, Queue* queue);

/*Functie ptrin care initializam o stiva*/
void initializeStack(Stack* stack);

/*Functie prin care verificam daca o stiva este goala*/
int isEmptyStack(Stack* stack);

/*Funcite prin care adaugam un nod intr-o stiva*/
void push(Stack* stack, Node* element);

/*Functie prin care scoatem un nod dintr-o stiva (intoarce nodul pe care il scoate)*/
Node* pop(Stack* stack);

/*Functie prin care convertim o coada intr-o stiva*/
void convertQueueToStack(Queue* queue, Stack* stack);

/*Functie care intoarce dimensiunea unei cozi*/
int queueSize(Queue* queue);

/*Functie prin care scriem in fisier task-urile 1 sau 2*/
void print_task_1_2(Node *head,FILE* output);

/*Functie prin care gasim minimul intr-o lista*/
int findMin(Node *head);

/*Functie ptrin care citim tot input-ul din fisierul d.in*/
int read_teams_from_input(FILE* input, struct Elem** teams);

/*Functie prin care rezolvam exercitiile 1 si 2*/
int process_task_1_2_and_a(char* t1, char* t2, struct Elem** teams, int nr, FILE* output);

/*Functie prin care rezolvam exercitiul 3*/
void process_team_pair(Node* team1, Node* team2, FILE* output, Stack* win_stack, Stack* lose_stack);

/*Functie prin care adaugam castigatorii in stiva si ii scriem in fisier*/
void process_winner(Node* node_aux, int a, FILE* output, struct Elem** top9, Queue* queue);

/*Functie prin care procesam rundele*/
void process_round(FILE* output, Queue* queue, Stack* win_stack, Stack* lose_stack, struct Elem** top9, int* a);





