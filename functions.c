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

void process_team_pair(Node* team1, Node* team2, FILE* output, Stack* win_stack, Stack* lose_stack) {
    char aux1[50]; //in aux 1 si aux 2 vom tine numele echipelor
    char aux2[50];
    strcpy(aux1, team1->team_name);
    strcpy(aux2, team2->team_name);
    aux1[strlen(aux1) - 1] = '\0';
    aux2[strlen(aux2) - 1] = '\0';
    fprintf(output, "%s", aux1); //afisam numele primei echipe
    for (int i = 0; i < (int)(33 - strlen(aux1)); i++) //pentru a avea acelasi output va trebui sa punem mai multe spatii
        fprintf(output, " ");
    fprintf(output, "-"); 
    for (int i = 0; i < (int)(33 - strlen(aux2)); i++)  //pentru a avea acelasi output va trebui sa punem mai multe spatii
        fprintf(output, " ");
    fprintf(output, "%s\n", aux2); //afisam cel de al doilea nume

    if (team1->score > team2->score) { //daca prima echipa castica ii crestem scorul si o adaugam in stiva de castigatori
        team1->score = team1->score + team1->count_players;
        push(win_stack, team1);
        push(lose_stack, team2);
    } else {    //daca a doua echipa castica ii crestem scorul si o adaugam in stiva de castigatori
        team2->score = team2->score + team2->count_players;
        push(win_stack, team2);
        push(lose_stack, team1);
    }
}

void process_winner(Node* node_aux, int a, FILE* output, struct Elem** top9, Queue* queue) {
    char aux[50];
    strcpy(aux, node_aux->team_name);   //adaugam in aux numele echipei
    aux[strlen(aux) - 1] = '\0';

    fprintf(output, "%s", aux);     //adaugam numele echipei in fisier
    for (int i = 0; i < (int)(35 - strlen(node_aux->team_name)); i++)
        fprintf(output, " ");
    fprintf(output, "-  ");
    fprintf(output, "%.2f\n", (float)node_aux->score / (float)node_aux->count_players);     //adaugam scorul in fisier

    if (a == 8) {
        addAtBeginningMod(top9, node_aux);  //daca a este 8 (afica am ajuns in optimi), atunci dorim sa stocam cele 8 echipe intr-o lista
    }
    enqueue(queue, node_aux); //adaugam ecjipele castigatoare in coada
}

void process_round(FILE* output, Queue* queue, Stack* win_stack, Stack* lose_stack, struct Elem** top9, int* a) {
    int i = 1;
    fprintf(output, "\n");
    while (queueSize(queue) != 0) {
        if (*a == 1) { //daca am ajuns la sfarsit, dorim sa iesim din while
            break;
        }
        fprintf(output, "--- ROUND NO:%d\n", i); //adaugam numarul rundei care se joaca
        while (!isEmptyQueue(queue)) {
            Node* team1 = dequeue(queue); //scoatem cate doua echipe
            Node* team2 = dequeue(queue);
            process_team_pair(team1, team2, output, win_stack, lose_stack); // aflam castigatorul
        }
        while (!isEmptyStack(lose_stack)) { //golim lista de invinsi
            pop(lose_stack);
        }
        *a /= 2; // jumatate au castigat, jumatate au pierdut, deci jucatorii s-au injumatatit
        fprintf(output, "\nWINNERS OF ROUND NO:%d\n", i);
        while (!isEmptyStack(win_stack)) { //adaugam echipele castigatoare din runda respectiva in fisier si in coada
            Node* node_aux = pop(win_stack);
            process_winner(node_aux, *a, output, top9, queue);
        }
        i++;
        if (*a != 1) //intre runde, vom avem o spatiu delimitator
            fprintf(output, "\n");
    }
}