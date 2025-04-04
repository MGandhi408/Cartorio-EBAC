#include <stdio.h> // Biblioteca para funções de entrada e saída
#include <stdlib.h> // Biblioteca para funções de alocação de memória e manipulação de processos
#include <locale.h> // Biblioteca para configurar a linguagem
#include <string.h> // Biblioteca para manipulação de strings

int registrar() // Função para registrar um novo usuário
{
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
    
    // Solicita e lê o CPF
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

int consultar() // Função para consultar informações de um usuário
{
    setlocale(LC_ALL, "portuguese"); // Define a linguagem para português

    char cpf[14], conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file = fopen(cpf, "r"); // Abre o arquivo correspondente ao CPF
    
    if (file == NULL) { // Se o arquivo não for encontrado
        system("cls");
        printf("Arquivo não localizado.\n");
        system("pause");
        return 1;
    }

    // Exibe as informações do usuário
    while (fgets(conteudo, 200, file)) {
        printf("\nEssas são as informações do usuário:\n%s\n\n", conteudo);
        system("pause");
    }
    fclose(file);
}

int deletar() // Função para deletar um usuário
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    // Tenta remover o arquivo e exibe o resultado
    if (remove(cpf) == 0) 
        printf("Usuário deletado com sucesso!\n\n");
    else
        printf("Usuário não encontrado.\n");
    
    system("pause");
    return 0;
}

int main() // Função principal com o menu
{
    int opcao = 0; 
    
    for (;;) { // Loop infinito
        system("cls");
        setlocale(LC_ALL, "portuguese");
        
        // Exibe o menu com as opções
        printf("\t\t ***Cartório da EBAC*** \n\n");
        printf("\t Boas Vindas! \n\n");
        printf("\t Selecione a opção desejada:\n\n");
        printf("\t 1 Registar nomes:\n");
        printf("\t 2 Consultar nomes:\n");
        printf("\t 3 Deletar nomes:\n");
        printf("\t 4 Sair:\n\n");
        printf("opção:");
        
        scanf("%d", &opcao); // Lê a opção do usuário
        system("pause");
        system("cls");

        switch(opcao) { // Verifica a opção escolhida
            case 1: registrar(); break; // Chama a função registrar
            case 2: consultar(); break; // Chama a função consultar
            case 3: deletar(); break; // Chama a função deletar
            case 4: 
                printf("Saindo...\n");
                return 0; // Encerra o programa
            default:
                printf("Opção inválida. Selecione uma opção entre 1 e 4.\n\n");
                system("pause");
                break;
        }
    }
}

