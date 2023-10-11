#include "Tape/tape.h"
#include <stdbool.h>

//remover os espaços da string de transição
char * removeSpacesFromStr(char *string)
{
    int count = 0;
    //Traverse a string and if it is non space character then, place it at index non_space_count
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ' ')
        {
            string[count] = string[i];
            count++;
        }    
    }
    
    string[count] = '\0';
    return string;
}

bool turing_machine(char qAccept, char matriz[][16], int numTrans, char* word){
    char currQ = '1';
    Node* header = init_tape(word[0]); 
    for (int i = 1; i < strlen(word); i++) {
        add_node(header, word[i]);
    }

    // add blank space to the end of the tape
    add_node(header, '-');
    bool t = false;
    Node* aux = header;
    while(currQ != qAccept){
        t = false;
        for(int i=0; i<numTrans; i++){
            if(matriz[i][0] == currQ && matriz[i][1] == aux->s){
                aux->s = matriz[i][2];
                if(matriz[i][3] == 'D'){
                    aux = aux->next;
                }
                else if(matriz[i][3] == 'E'){
                    aux = aux->prev;
                }
                else{
                    return false;
                }

                char prevQ = currQ;
                currQ = matriz[i][4];

                t = true;

                printf("Estado:%c Leu:%c Escreveu:%c Direção:%c Estado Seguinte:%c\n", prevQ, matriz[i][1], matriz[i][2], matriz[i][3], currQ);
                break;
            }
        }

        if(currQ == qAccept){
            return true;
        }

        if(!t){
            return false;
        }

    }
    return t;
}
int main(int argc, char* argv[]){
    //file passed as argument when running the program =>  gcc -o main main.c && ./main input.txt
    FILE* file = fopen(argv[1], "r");
    if (!file) {
    printf("Could not open\n");
    return 0;
    }

    char sigma[30];
    fgets(sigma, 30, file);
    printf("Alfabeto de entrada: %s\n", sigma);

    char qAccept = getc(file);
    printf("Estado de aceitação: %c\n", qAccept);


    int numTrans = 0;
    fscanf(file, "%d", &numTrans);
    printf("Número de transições: %d\n", numTrans);

    char matriz[numTrans][16];
    char a[16];
    fgets(a,16,file);
    printf("Matriz de Transições\n");
    for (int i=0; i < numTrans; i++) {
        fgets(matriz[i], 16, file);
        printf("%s", matriz[i]);
    }
    int numPalavras;
    fscanf(file, "%d", &numPalavras);
    printf("Número de palavras a serem testadas: %d\n", numPalavras);
    fgets(a,16,file);


    //remove spaces from string
    for(int i = 0; i < numTrans; i++){
        removeSpacesFromStr(matriz[i]);
    }
    for(int i=0; i<numPalavras; i++){
        char word[100];
        fgets(word, 100, file);
        printf("Palavra %d: %s\n", i+1, word);
        bool test = turing_machine(qAccept, matriz, numTrans, word);
        if(test){
            printf("%s OK\n",word);
        }
        else{
           printf("%s not OK\n",word);
        }
    }

    return 0;
}