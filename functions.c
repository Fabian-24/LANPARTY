#include"structs.h"

void print_task_1_2(Node *head,FILE* output){
    //iteram prin lista
    while(head != NULL){
        //ne luam un auxiliar deoarece unele teste au un ' ' la sfarsitul numelui de echipa si il eliminam 
        char aux[100];
        strcpy(aux,head->team_name);
        if(aux[strlen(aux) - 2] == ' '){
            aux[strlen(aux) - 1] = '\0';
            strcpy(head->team_name,aux);
        }
        fprintf(output,"%s\n",head->team_name);
        head = head->next;
    }
}

int findMin(Node *head){
    //cautam scorul cel mai mic dintr-o lista iterand prin ea
    int min = 9999;
    while(head != NULL){
        if(min > head->score)
            min = head->score;
        head = head->next;
    }
    return min;
}

int read_teams_from_input(FILE* input, struct Elem** teams) {
    char buffer[100];
    fgets(buffer, 100, input);
    int nr = atoi(buffer);
    for (int i = 1; i <= nr; i++) {     //vom face un loop de la 1 la nr de echipe
        char name_team[100];
        memset(name_team, 0, 100);
        memset(buffer, 0, 100);   
        fgets(buffer, 100, input);  //citim numele echipei si numarul de coechipieri
        char* tkn = strtok(buffer, " ");    //delimitam numarul de jucatori de numele echipei
        int players = atoi(tkn);

        tkn = strtok(NULL," ");
        while (tkn != NULL) {
            strcat(name_team, tkn);
            strcat(name_team, " ");
            tkn = strtok(NULL, " ");
        }
        name_team[strlen(name_team) - 2] = '\0';

        addAtBeginning(teams, players, name_team);  //adaugam echipa intr-o lista

        (*teams)->score = 0;

        for (int j = 0; j < players; j++) {     //adaugam si jucatorii direct in nodul noul creat pentru echipa
            fgets(buffer, 100, input);  //citim pe rand jucatorii
            tkn = strtok(buffer, " ");
            (*teams)->players[j].firstName = (char*)malloc(strlen(buffer) + 1);
            strcpy((*teams)->players[j].firstName, tkn);
            tkn = strtok(NULL, " ");
            (*teams)->players[j].secondName = (char*)malloc(strlen(buffer) + 1);
            strcpy((*teams)->players[j].secondName, tkn);
            tkn = strtok(NULL, " ");
            (*teams)->players[j].points = atoi(tkn);
            (*teams)->score += atoi(tkn);   //incrementam scorul
        }
        fgets(buffer, 100, input);
    }
    return nr; //intoarcem numarul de echipe
}

int process_task_1_2_and_a(char* t1, char* t2, struct Elem** teams, int nr, FILE* output) {
    if (strstr(t1, "1") != NULL && strstr(t2, "0") != NULL) {   //daca t1 este 1 si t2 este 0 atunci afisam toate echipele din fisier
        print_task_1_2(*teams, output);
    }

    int numer_teams_fight = 2; // calculam numaru de echipe care se vor califica
    while (numer_teams_fight <= nr) {
        numer_teams_fight = numer_teams_fight * 2;
    }
    numer_teams_fight /= 2;

    int dif = nr - numer_teams_fight; //diferenta reprezinta numarul de echipe care trebuie eliminate

    for (int i = 0; i < dif; i++) {
        int min = findMin(*teams);
        delete(teams, min); //eliminam echipa cu cel mai mic scor
    }

    if (strstr(t1, "1") != NULL && strstr(t2, "1") != NULL) { //daca t1 si t2 sunt 1 atunci afisam doar echipele care nu au fost eliminate
        print_task_1_2(*teams, output);
    }

    return numer_teams_fight;
}