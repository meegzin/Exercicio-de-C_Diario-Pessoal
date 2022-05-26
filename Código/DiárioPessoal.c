#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarSenha(char senhaCadastrada[]){

    int tam = 0, i = 0;
    while (senhaCadastrada[i] != NULL){
        tam ++;
        i++;
    }
    if (tam <7){
        printf("\nSua senha possui menos de 8 dígitos. Por favor, tente outra: ");
        printf("\nDigite a senha: ");
        scanf("%s", senhaCadastrada);
        criarSenha(senhaCadastrada); //Recursividade
    }else {
        printf("\nSenha cadastrada com sucesso!\n");
    }

}

int validarSenha (char senhaDeAcesso[], char senhaCadastrada[]){

    if(strcomp(senhaDeAcesso,senhaCadastrada)){
        printf("Acesso Liberado! ");
        return 1;
    } else {
        return 0;
    }
}


void main(){

    //Menu de Login
    int escolha;
    char senhaCadastrada[50], senhaDeAcesso[50];

    menu1: //checkpoint
    do{
    printf("Bem vindo do Diario Pessoal Digital");
    printf("\n Antes de iniciarmos, escolha uma das opcoes abaixo: ");
    printf("\n Para criar uma senha, digite 1 |");
    printf("\n Caso tenha esquecido a senha, digite 2 | ");
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
            //Pode gravar no arquivo a senha
            printf("\n\n");
            goto menu1; //voltar de novo para o menu para poder entrar com a senha de acesso
            break;

        case 2:

            printf("\nSem problemas. crie a sua senha: ");
            scanf("%s", senhaCadastrada);  //Basicamente, vai setar uma nova senha
            criarSenha(senhaCadastrada);
            break;

        case 3:
            verificar: //checkpoint

            printf("\nDigite a sua senha: ");
            scanf("%s", senhaDeAcesso);
            validarSenha(senhaDeAcesso, senhaCadastrada);
            printf("O valor retorno: %d",validarSenha(senhaDeAcesso, senhaCadastrada));
            if (validarSenha(senhaDeAcesso, senhaCadastrada) == 0){
                printf("Senha invalida");
                goto verificar;
            }
            break;

        default:
            printf("Ocorreu um erro! Tente novamente mais tarde");
            exit;
    }

}
