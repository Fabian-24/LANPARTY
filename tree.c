#include "structs.h"

BSTNode* createBSTNode(Node* data) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*Fata de ce era in plus la BST, am luat si cazul in care
doua echipe au acelasi scor, caz in care au fost comparate
dupa nume*/
BSTNode* insertBSTNode(BSTNode* root, Node* data) {
    if (root == NULL) {
        return createBSTNode(data);
    }

    if (data->score < root->data->score ) {
        root->left = insertBSTNode(root->left, data);
    } else if (data->score > root->data->score ) {
        root->right = insertBSTNode(root->right, data);
    }
    else if(strcmp(root->data->team_name,data->team_name) < 0){
        root->right = insertBSTNode(root->right, data);
    }
    else{
        root->left = insertBSTNode(root->left, data);
    }

    return root;
}

void insertBST(struct BST* bst, Node* data) {
    bst->root = insertBSTNode(bst->root, data);
}

/*Traversare prin care adaugam in fisierul de output*/
void inorderTraversal(struct BSTNode* root,FILE* output) {
    if (root == NULL) {
        return;
    }

    // Subarborele drept
    inorderTraversal(root->right,output);
    char ceva[50];
    strcpy(ceva,root->data->team_name);
    ceva[strlen(ceva) - 1]  ='\0';
    
    fprintf(output,"%s", ceva);
    for(int i = 0 ; i < (int)(34 - strlen(ceva)) ; i++)
        fprintf(output," ");
    fprintf(output,"-  ");
    fprintf(output,"%.2f\n",(float)((float)root->data->score / (float)root->data->count_players));

    /*Subarborele stang*/
    inorderTraversal(root->left,output);
}

void printBSTReverseOrder(struct BST* bst,FILE* output) {
    inorderTraversal(bst->root,output);
}

void insertListIntoBST(struct BST* bst, Node* list) {
    Node* current = list;
    while (current != NULL) {
        insertBST(bst, current);
        current = current->next;
    }
}

