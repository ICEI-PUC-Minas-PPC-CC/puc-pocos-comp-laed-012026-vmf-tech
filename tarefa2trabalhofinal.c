#include <stdio.h>

#define MAX_ROUPAS 100

struct Roupa {
    int codigo;
    char categoria[20];
    char modelo[30];
    char tamanho[5];
    char genero[15];
    char cor[20];
    float preco;
    int ativo; };
struct Roupa estoque[MAX_ROUPAS];
int quantidade = 0;

void inserirRoupa() {

    if (quantidade >= MAX_ROUPAS) {
        printf("\nEstoque cheio! Nao e possivel cadastrar mais roupas.\n");
        return;
    }

    printf("\nCadastro de Roupa:\n");

    printf("Codigo: ");
    scanf("%d", &estoque[quantidade].codigo);

    if (estoque[quantidade].codigo <= 0) {
        printf("\nCodigo invalido!\n");
        return;
    }

    printf("Categoria (Camisa/Blusa/Bermuda/Calca): ");
    scanf("%s", estoque[quantidade].categoria);

    printf("Modelo: ");
    scanf("%s", estoque[quantidade].modelo);

    printf("Tamanho (PP/P/M/G/GG): ");
    scanf("%s", estoque[quantidade].tamanho);

    printf("Genero (Masculino/Feminino): ");
    scanf("%s", estoque[quantidade].genero);

    printf("Cor: ");
    scanf("%s", estoque[quantidade].cor);

    printf("Preco: ");
    scanf("%f", &estoque[quantidade].preco);

    if (estoque[quantidade].preco < 0) {
        printf("\nPreco invalido!\n");
        return;
    }

    estoque[quantidade].ativo = 1;

    quantidade++;

    printf("\nRoupa cadastrada.\n");
}

void listarRoupas() {

    int encontrou = 0;

    printf("\nRoupas Cadastradas\n");

    for (int i = 0; i < quantidade; i++) {
        if (estoque[i].ativo == 1) {
            encontrou = 1;

            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Categoria: %s\n", estoque[i].categoria);
            printf("Modelo: %s\n", estoque[i].modelo);
            printf("Tamanho: %s\n", estoque[i].tamanho);
            printf("Genero: %s\n", estoque[i].genero);
            printf("Cor: %s\n", estoque[i].cor);
            printf("Preco: R$ %.2f\n", estoque[i].preco);
        }
    }

    if (!encontrou) {
        printf("\nNenhuma roupa cadastrada.\n");
    }
}

int main() {

    int opcao;

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
                inserirRoupa();
                break;

            case 2:
                listarRoupas();
                break;

            case 3:
                printf("\n[ainda vamos fazer]\n");
                break;

            case 4:
                printf("\n[ainda vamos fazer]\n");
                break;

            case 5:
                printf("\n[ainda vamos fazer]\n");
                break;

            case 6:
                printf("\n[ainda vamos fazer]\n");
                break;

            case 7:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 7);

    return 0;
}
