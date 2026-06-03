#include <stdio.h>

struct Roupa {
    int codigo;
    char categoria[20];
    char modelo[30];
    char tamanho[5];
    char genero[15];
    char cor[20];
    float preco;


    int ativo;
};


struct Roupa estoque[100];

int main() {

    int opcao=0;

    do {

        printf("\n        VMF CLOTHING");
        printf("\n Sistema de Controle de Roupas");
        printf("\n====================================");
        printf("\n1 - Inserir roupa");
        printf("\n2 - Listar roupas");
        printf("\n3 - Pesquisar roupa");
        printf("\n4 - Editar roupa");
        printf("\n5 - Excluir roupa");
        printf("\n6 - Resumo e Estatisticas");
        printf("\n7 - Sair");
        printf("\n====================================");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("\n[Inserir roupa - Em desenvolvimento]\n");
                break;

            case 2:
                printf("\n[Listar roupas - Em desenvolvimento]\n");
                break;

            case 3:
                printf("\n[Pesquisar roupa - Em desenvolvimento]\n");
                break;

            case 4:
                printf("\n[Editar roupa - Em desenvolvimento]\n");
                break;

            case 5:
                printf("\n[Excluir roupa - Em desenvolvimento]\n");
                break;

            case 6:
                printf("\n[Resumo e Estatisticas - Em desenvolvimento]\n");
                break;

            case 7:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 7);

    return 0;
}
