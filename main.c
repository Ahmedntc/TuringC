#include "tape.h"
#include <stdbool.h>

// Função para remover os espaços de uma string
char * removeSpacesFromStr(char *string)
{
    int count = 0;
    // Percorre a string e, se o caractere não for um espaço, coloca-o no índice count
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

//Função principal da máquina de Turing que processa a palavra de entrada
bool turing_machine(char qAccept, char matriz[][16], int numTrans, char* word){
    char currQ = '1';
    // Inicializa a fita da máquina de Turing
    Node* header = init_tape(word[0]); 
    for (int i = 1; i < strlen(word); i++) {
        add_node(header, word[i]);
    }
    // Adiciona espaço em branco ao final da fita
    add_node(header, '-');

  
    while(currQ != qAccept){
        //variavel usada para checar se uma transição foi encontrada
        bool t = false;
        for(int i=0; i<numTrans; i++){
            /*
            matriz[i][0] = estado
            matriz[i][1] = símbolo a ser lido
            matriz[i][2] = símbolo  ser escrito
            matriz[i][3] = movimento da cabeça
            matriz[i][4] = próximo estado
            */
            if(matriz[i][0] == currQ && matriz[i][1] == header->s){
                header->s = matriz[i][2];
                if(matriz[i][3] == 'D'){
                    header = header->next;
                }
                else if(matriz[i][3] == 'E'){
                    header = header->prev;
                }
                else{
                    return false;
                }

                char prevQ = currQ;
                currQ = matriz[i][4];
                //se uma transição foi encontrada, nossa variavel t é true
                t = true;
                printf("%s",matriz[i]);
                break;
            }
        }
        if(currQ == qAccept){
            return true;
        }
        //se t permanecer false, significa que não foi encontrada nenhuma transição
        if(!t){
            return false;
        }
    }
    return false;
}

// Função principal
int main(int argc, char* argv[]){
    // Abre o arquivo passado como argumento na execução do programa
    FILE* file = fopen(argv[1], "r");
    if (!file) {
        printf("Não foi possível abrir o arquivo\n");
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
    // Remove o \n da leitura do número de transições
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
    // Remove o \n da leitura do número de palavras
    fgets(a,16,file);

    // Remover espacos da string de transicoes para facilitar uso dela
    for(int i = 0; i < numTrans; i++){
        removeSpacesFromStr(matriz[i]);
    }

    // Processa e testa cada palavra usando a máquina de Turing
    for(int i=0; i<numPalavras; i++){
        char word[100];
        fgets(word, 100, file);
        printf("\nPalavra %d: %s\n", i+1, word);
        printf("\nTransicoes feitas\n");
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