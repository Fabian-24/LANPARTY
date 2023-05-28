#include"structs.h"

void addAtBeginning ( Node ** head, int nr, char* name)
{
    Node * newNode = ( Node *) malloc ( sizeof ( Node ));
    newNode->count_players = nr;
    newNode->team_name =(char *) malloc(strlen(name) + 10);
    strcpy(newNode->team_name, name);
    newNode->players = (struct Player *) malloc(nr * sizeof(struct Player));
    newNode->next = * head ;
    *head = newNode ;
}

void addAtBeginningMod(Node **head, Node * vec) {
    Node* newNode = (Node *) malloc(sizeof (Node));
    newNode->count_players = vec->count_players;
    newNode->team_name = (char*) malloc(strlen(vec->team_name) + 1);
    strcpy(newNode->team_name,vec->team_name);
    newNode->score = vec->score;
    newNode->players = (struct Player*)malloc(sizeof(struct Player)*vec->count_players);
    for(int i = 0 ; i < vec->count_players ; i++){
        vec->players[i].firstName = (char*)malloc(50);
        vec->players[i].secondName = (char*)malloc(50);
    }
    newNode->players = vec->players;
    newNode->next = *head;
    *head = newNode;
}

void printList(Node *head)
{
    while(head != NULL){
        printf("%d ",head->count_players);
        printf("%s\n", head->team_name);
        for(int j = 0 ; j < head->count_players ; j++){
            printf("%s %s %d\n",head->players[j].firstName,head->players[j].secondName,head->players[j].points);
        }
        head = head -> next;
        printf("\n");
    }
}

void delete(Node** head, int v) {
    // 0. Lista goala
    if (*head == NULL) return;

    // 1. Elementul de sters este capul listei
    Node* headcopy = *head;
    if (headcopy->score == v) {
        *head = (*head)->next;
        free(headcopy); // sterge primul element
        return;
    }

    // 2. Elementul de sters are o pozitie oarecare
    Node* prev = *head; // predecesorul elementului cautat
    while (headcopy != NULL) {
        if (headcopy->score == v) {
            prev->next = headcopy->next;
            free(headcopy); // sterge elementul
            return;
        } else {
            prev = headcopy;
            headcopy = headcopy->next;
        }
    }
}