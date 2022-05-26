#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarSenha(char senhaCadastrada[]){

    int tam = 0, i = 0;
    while (senhaCadastrada[i] != NULL){
        tam ++;
        i++;
    }
    printf("\nSua senhaCadastrada tem %d caracteres ",tam);
    if (tam <7){
        printf("\nSua senhaCadastrada possui menos de 8 dígitos. Por favor, tente outra: ");
        printf("\nDigite a senhaCadastrada: ");
        scanf("%s", senhaCadastrada);
        criarSenha(senhaCadastrada); //Recursividade
    }else {
        printf("\nSenha cadastrada com sucesso!");
    }

}

void main(){

    //Menu de Login
    int escolha;
    char senhaCadastrada[50];

    do{
    printf("Bem vindo do Diario Pessoal Digital");
    printf("\n Antes de iniciarmos, escolha uma das opcoes abaixo: ");
    printf("\n Para criar uma senhaCadastrada, digite 1 |");
    printf("\n Caso tenha esquecido a senhaCadastrada, digite 2 | ");
    printf("\n Para entrar com uma Senha, digite 3 | ");
    printf("\n Sua escolha: ");
    scanf("%d", &escolha);
    if (escolha <= 0 || escolha >3)
        printf("\nVoce digitou alguma opcao invalida. Por favor, tente novamente\n\n");    
    }while(escolha <= 0 || escolha >3);

    switch (escolha) {
        case 1:

            printf("\ncrie a sua senha: ");
            scanf("%s", senhaCadastrada); //Esse modo de ler strings não permite espaços
            criarSenha(senhaCadastrada); //Função recursiva que valida a senha
            
            break;
        case 2:

            break;

        case 3:
            break;
        default:
            printf("Ocorreu um erro! Tente novamente mais tarde");
    }

}
