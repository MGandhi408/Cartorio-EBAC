#include <stdio.h>  // Entrada e saída
#include <stdlib.h> // Funções do sistema
#include <locale.h> // Suporte a acentuação
#include <string.h> // Manipulação de strings

int registrar() {
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);
    FILE *file = fopen(arquivo, "w");
    fprintf(file, cpf);
    fclose(file);

    printf("Digite o nome a ser cadastrado: ");
    scanf("%s", nome);
    file = fopen(arquivo, "a");
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
    fprintf(file, ", %s.", cargo);
    fclose(file);

    system("pause");
    return 0;
}

int consultar() {
    setlocale(LC_ALL, "Portuguese");

    char cpf[14], conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        system("cls");
        printf("Arquivo não localizado.\n");
        system("pause");
        return 1;
    }

    while (fgets(conteudo, 200, file)) {
        printf("\nEssas são as informações do usuário:\n%s\n\n", conteudo);
        system("pause");
    }

    fclose(file);
    return 0;
}

int deletar() {
    char cpf[40];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    if (remove(cpf) == 0)
        printf("Usuário deletado com sucesso!\n\n");
    else
        printf("Usuário não encontrado.\n");

    system("pause");
    return 0;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    char senhadigitada[10];
    int tentativas = 0;
    const int max_tentativas = 3;

    while (tentativas < max_tentativas) {
        system("cls");
        printf("\t\t ***Cartório da EBAC*** \n\n");
        printf("Login de Administrador.\n\nDigite a senha para acessar: ");
        scanf("%s", senhadigitada);

        if (strcmp(senhadigitada, "admin") == 0) {
            while (1) {
                system("cls");
                printf("\t\t ***Cartório da EBAC*** \n\n");
                printf("\t Boas Vindas! \n\n");
                printf("\t Selecione a opção desejada:\n\n");
                printf("\t 1 Registrar nomes\n");
                printf("\t 2 Consultar nomes\n");
                printf("\t 3 Deletar nomes\n");
                printf("\t 4 Sair\n\n");
                printf("Opção: ");
                scanf("%d", &opcao);
                system("cls");

                switch (opcao) {
                    case 1: registrar(); break;
                    case 2: consultar(); break;
                    case 3: deletar(); break;
                    case 4:
                        printf("Saindo...\n");
                        return 0;
                    default:
                        printf("Opção inválida. Selecione entre 1 e 4.\n");
                        system("pause");
                        break;
                }
            }
        } else {
            tentativas++;
            system("cls");
            printf("Senha incorreta. Você tem %d tentativa(s) restante(s).\n\n", max_tentativas - tentativas);
            system("pause");

            if (tentativas >= max_tentativas) {
            	system ("cls");
                printf("Número máximo de tentativas atingido. Saindo...\n\n");
                system("pause");
                return 0;
            }
        }
    }

    return 0;
}
