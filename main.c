#include "structs.h"

int main(int argc, char** argv){
    /*fisierele prin care aflam task-urile de efectuat, precum si fisierul de output*/
    FILE* input, *tasks ,*output;
    /*Deschidem pe rand fisierele(cele din care citim cu 'r', cele in care scriem cu 'w')*/
    input = fopen(argv[2],"r");
    tasks = fopen(argv[1],"r");
    output = fopen(argv[3],"w");
    /*Initializam structurile necesare*/
    char *t1,*t2,*t3,*t4;
    struct Elem* teams = NULL;
    struct Elem* top9 = NULL;
    char buffer_tasks[20];
    /*citim prima linie a fisierului in care se afla ce task-uri vor trebui prelucrate*/
    fgets(buffer_tasks,20,tasks);
    /*in fiecare t vom pune task-urile de la 1 la 5*/
    t1 = strtok(buffer_tasks," ");
    t2 = strtok(NULL," ");
    t3 = strtok(NULL," ");
    t4 = strtok(NULL," ");

    /*citim echipele din fisier*/
    int nr = read_teams_from_input(input,&teams);
    /*afisam tasks-urile 1 sau 2*/ 
    int remaining_teams = process_task_1_2_and_a(t1, t2, &teams, nr, output);

    /*Ne vom initializa doua stive si o coada pentru realizarea task-ului 3*/
    Queue queue;
    Stack lose_stack,win_stack;
    initializeStack(&lose_stack);
    initializeStack(&win_stack);
    queue.front = NULL;
    queue.rear = NULL;
    /*La inceput. toate echipele (cele de la task-ul 2) se vor afla in coada*/
    convertListToQueue(teams,&queue);

    /*Daca trebuie sa efectuam task-ul 3 atunci il vom prelucra*/
    if(strstr(t3,"1") != NULL)
        process_round(output, &queue, &win_stack, &lose_stack, &top9, &remaining_teams);

    /*Pentru task-ul 4, vom initializa structura unui BST*/
    struct BST bst ;
    bst.root = NULL;

    /*Inseram toate elementele din top8 in BST*/
    insertListIntoBST(&bst,top9);
    /*Daca este nevoite, o vom scrie in fisierul de iesire*/
    if(strstr(t4,"1") != NULL){
        fprintf(output,"\nTOP 8 TEAMS:\n");
        inorderTraversal(bst.root,output);
    }

    /*Inchidem fisierele*/
        
    fclose(tasks);
    fclose(output);
    fclose(input);
}


