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
        
    fclose(tasks);
    fclose(output);
    fclose(input);
}


