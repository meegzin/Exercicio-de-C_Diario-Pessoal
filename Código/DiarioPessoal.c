#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro {
    char data[10];  // O maior caso é este exemplo -> 20/05/2020 no máximo vou precisar de 10 espaços
    char hora[8]; // O maior caso é esse -> 24:10:50 no máximo, precisarei de 8 espaços
    char titulo[150];
    char local[250];
    int duracao; // Pedir para o usuário só digitar o número
    char observacao[500];
    struct registro *prox;
};
typedef struct registro reg;

void adicionar(char *data, char *hora, char *titulo, char *local, int duracao, char *observacao, reg *p){
    reg *novo;
    novo = (reg *) malloc (sizeof(reg));
    strcmp(novo -> data,data);
    strcmp(novo -> hora,hora);
    strcmp(novo -> titulo,titulo);
    strcmp(novo -> local,local);
    novo -> duracao = duracao;
    strcmp(novo -> observacao,observacao);
    novo -> prox = p -> prox;
    p -> prox = novo;
}


void listar(reg *ini){
    reg *p;
    for (p = ini->prox; p != NULL; p = p->prox) {
      //  printf("Data: ");
        printf ("%s\t", p->data);
      //  printf("Hora: ");
        printf ("%s\t", p->hora);
     //   printf("Titulo: ");
        printf ("%s\t", p->titulo);
      //  printf("Locala: ");
        printf ("%s\t", p->local);
     //   printf("Duracao: ");
        printf ("%d\t", p->duracao);
     //   printf("Observacao: ");
        printf ("%s\t", p->observacao);
    }
}

void procurarEAlterar(char titulo[], reg *lista){
    reg *a, *b;
    a = lista;
    b = lista -> prox;
    while (b != NULL && b -> titulo != titulo){
        a = b;
        b = b -> prox;
    }
 /*   printf("Vamos alterar o conteúdo do diário");
    char data[10]; 
    char hora[8]; 
    char titulo[150];
    char local[250];
    int duracao;
    char observacao[500];
    printf("Data nova: ");
    scanf("%s", &data);
    strcmp(a -> data,data);
    printf("Hora nova: ");
    scanf("%s", &hora);
    strcmp(a -> hora,hora);
    printf("Titulo nova: ");
    scanf("%s", &titulo);
    strcmp(a -> titulo,titulo);
    printf("Local novo: ");
    scanf("%s", &local);
    strcmp(a -> local,local);
    printf("Duracao nova: ");
    scanf("%s", &duracao);
    a -> duracao = duracao;
    printf("Observacao nova: ");
    scanf("%s", &observacao);
    strcmp(a -> observacao,observacao); 
    free(a);
    */

}

void procurarERemover(char titulo[], reg *lista){
    reg *a, *b;
    a = lista;
    b = lista -> prox;
    while (b != NULL && b -> titulo != titulo){
        a = b;
        b = b -> prox;
    }
    if (b != NULL){
        a -> prox = b -> prox;
        free(b);
    }
}



int main () {


    int op = -1;
     char data[10];  
    char hora[8]; 
    char titulo[150];
    char local[250];
    int duracao; 
    char observacao[500];
    
    reg *lista = NULL;
    lista = (reg *) malloc(sizeof(reg));
    menuDaLista:
    while (op != 0) {
        printf("\nOpcoes disponiveis:\n");
        printf("\tecle 1 p/ imprimir lista.\n");
        printf("\tecle 2 p/ inserir novo elemento na lista.\n");
        printf("\tecle 0 p/ encerrar.\n");
        printf("Entre opcao desejada: ");
        scanf("%d", &op);

    switch(op) {
        case 0: 
            printf("\n\nTCHAU!\n"); 
            break;
        case 1: 
            listar(lista);
            goto menuDaLista;
            break;
        case 2:
            printf("Data nova: ");
            scanf("%s", &data);
            printf("Hora nova: ");
            scanf("%s", &hora);
            printf("Titulo nova: ");
            scanf("%s", &titulo);
            printf("Local novo: ");
            scanf("%s", &local);
            printf("Duracao nova: ");
            scanf("%s", &duracao);
            printf("Observacao nova: ");
            scanf("%s", &observacao);
            adicionar(data,hora, titulo, local, duracao, observacao, &lista);
            printf("Adicionado");
            goto menuDaLista;
            break;
        default:
            printf("\n\nOPCAO INVALIDA!\n");
    }

    }






    free(lista);
    return 1;
}