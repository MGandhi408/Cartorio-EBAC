#include <stdio.h> // Biblioteca para fun��es de entrada e sa�da
#include <stdlib.h> // Biblioteca para fun��es de aloca��o de mem�ria e manipula��o de processos
#include <locale.h> // Biblioteca para configurar a linguagem
#include <string.h> // Biblioteca para manipula��o de strings

int registrar() // Fun��o para registrar um novo usu�rio
{
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
    
    // Solicita e l� o CPF
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf); // Usa o CPF como nome do arquivo
    FILE *file = fopen(arquivo, "w"); // Cria o arquivo e escreve o CPF
    fprintf(file, cpf);
    fclose(file);

    // Solicita e adiciona nome, sobrenome e cargo ao arquivo
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a"); // Abre o arquivo para adicionar dados
    fprintf(file, ", %s", nome);
    fclose(file);

    printf("Digite o sobrenome: ");
    scanf("%s", sobrenome);
    file = fopen(arquivo, "a");
    fprintf(file, ", %s", sobrenome);
    fclose(file);

    printf("Digite o cargo: ");
    scanf("%s", cargo);
    file = fopen(arquivo, "a");
    fprintf(file, ", %s.", cargo); // Finaliza com ponto
    fclose(file);

    system("pause");
}

int consultar() // Fun��o para consultar informa��es de um usu�rio
{
    setlocale(LC_ALL, "portuguese"); // Define a linguagem para portugu�s

    char cpf[14], conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo correspondente ao CPF
    
    if (file == NULL) { // Se o arquivo n�o for encontrado
        system("cls");
        printf("Arquivo n�o localizado.\n");
        system("pause");
        return 1;
    }

    // Exibe as informa��es do usu�rio
    while (fgets(conteudo, 200, file)) {
        printf("\nEssas s�o as informa��es do usu�rio:\n%s\n\n", conteudo);
        system("pause");
    }
    fclose(file);
}

int deletar() // Fun��o para deletar um usu�rio
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    // Tenta remover o arquivo e exibe o resultado
    if (remove(cpf) == 0) 
        printf("Usu�rio deletado com sucesso!\n\n");
    else
        printf("Usu�rio n�o encontrado.\n");
    
    system("pause");
    return 0;
}

int main() // Fun��o principal com o menu
{
    int opcao = 0; 
    
    for (;;) { // Loop infinito
        system("cls");
        setlocale(LC_ALL, "portuguese");
        
        // Exibe o menu com as op��es
        printf("\t\t ***Cart�rio da EBAC*** \n\n");
        printf("\t Boas Vindas! \n\n");
        printf("\t Selecione a op��o desejada:\n\n");
        printf("\t 1 Registar nomes:\n");
        printf("\t 2 Consultar nomes:\n");
        printf("\t 3 Deletar nomes:\n");
        printf("\t 4 Sair:\n\n");
        printf("op��o:");
        
        scanf("%d", &opcao); // L� a op��o do usu�rio
        system("pause");
        system("cls");

        switch(opcao) { // Verifica a op��o escolhida
            case 1: registrar(); break; // Chama a fun��o registrar
            case 2: consultar(); break; // Chama a fun��o consultar
            case 3: deletar(); break; // Chama a fun��o deletar
            case 4: 
                printf("Saindo...\n");
                return 0; // Encerra o programa
            default:
                printf("Op��o inv�lida. Selecione uma op��o entre 1 e 4.\n\n");
                system("pause");
                break;
        }
    }
}

