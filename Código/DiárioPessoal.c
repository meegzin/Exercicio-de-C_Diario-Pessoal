#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarSenha(char senhaCadastrada[]){  //verifica se a senha tem pelo menos 8 caracteres
    int tam = 0, i = 0;
    while (senhaCadastrada[i] != NULL){
        tam ++;
        i++;
    }
    if (tam <=7){
        char tentarDenovo[50];
        printf("\nSua senha possui menos de 8 digitos. Por favor, tente outra: ");
        printf("\nDigite a senha: ");
        scanf("%s", &tentarDenovo);
        criarSenha(tentarDenovo); //Recursividade
    }else {
        printf("\nSenha cadastrada com sucesso!\n");
    }
}

int validarAcesso(char senhaDeAcesso[], char senhaCadastrada[]){ //faz a comparação das senhas para liberar o acesso
    if(strcmp(senhaCadastrada, senhaDeAcesso) == 0){
        return 1;
    } else {
        return 0;
    }
}

void main(){
    //Criação e Validação da senha
    //Menu de Login
    int escolha;
    char senhaCadastrada[50], senhaDeAcesso[50];
    printf("\nBem vindo do Diario Pessoal Digital");

    menu1: //checkpoint
    do{
    printf("\n Escolha uma das opcoes abaixo: ");
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

            printf("\ncrie a sua senha (A senha deve ter 8 digitos): ");
            scanf("%s", &senhaCadastrada); //Esse modo de ler strings não permite espaços
            criarSenha(senhaCadastrada); //Função recursiva que valida a senha
            //Pode gravar no arquivo a senha
            goto menu1; //voltar de novo para o menu para poder entrar com a senha de acesso
            break;

        case 2:

            printf("\nSem problemas! Crie a sua nova senha: ");
            scanf("%s", &senhaCadastrada);  //Basicamente, vai setar uma nova senha
            criarSenha(senhaCadastrada);
            goto menu1; //voltar de novo para o menu para poder entrar com a senha de acesso
            break;

        case 3:
            verificar: //checkpoint

            printf("\nDigite a sua senha (Para voltar para o menu principal, digite 1): ");
            scanf("%s", &senhaDeAcesso);
            validarAcesso(senhaDeAcesso, senhaCadastrada);
            if (senhaDeAcesso[0] == '1' && senhaDeAcesso[1] == NULL){ //Caso o usuario queira redefinir a senha
                goto menu1;
            }
            if (validarAcesso(senhaDeAcesso, senhaCadastrada) == 0){
                printf("Senha invalida");
                goto verificar;
            } else {
                printf("Acesso Liberado! ");
            }
            break;

        default:
            printf("Ocorreu um erro! Tente novamente mais tarde");
    }

//Implementação da Lista Encadeada

}
