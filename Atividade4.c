#include <stdio.h>


struct Roupa {
    int codigo;
    char categoria[20];
    char modelo[30];
    char tamanho[5];
    char genero[15];
    char cor[20];
    float preco;
    int ativo; };
struct Roupa estoque[100];
int quantidade = 0;

void inserirRoupa() {

    if (quantidade >= 100) {
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
void pesquisarRoupa() {

    int codigo;
    int encontrou = 0;

    printf("\nDigite o codigo da roupa que deseja pesquisar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < quantidade; i++) {

        if (estoque[i].codigo == codigo && estoque[i].ativo == 1) {

            encontrou = 1;

            printf("\n=== ROUPA ENCONTRADA ===\n");
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Categoria: %s\n", estoque[i].categoria);
            printf("Modelo: %s\n", estoque[i].modelo);
            printf("Tamanho: %s\n", estoque[i].tamanho);
            printf("Genero: %s\n", estoque[i].genero);
            printf("Cor: %s\n", estoque[i].cor);
            printf("Preco: R$ %.2f\n", estoque[i].preco);

            break;
        }
    }

    if (encontrou == 0) {
        printf("\nRoupa nao encontrada.\n");
    }
}
void editarRoupa() {

    int codigo;
    int encontrou = 0;

    printf("\nDigite o codigo da roupa que deseja editar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < quantidade; i++) {

        if (estoque[i].codigo == codigo && estoque[i].ativo == 1) {

            encontrou = 1;

            printf("\n=== EDITANDO ROUPA ===\n");

            printf("Nova categoria: ");
            scanf("%s", estoque[i].categoria);

            printf("Novo modelo: ");
            scanf("%s", estoque[i].modelo);

            printf("Novo tamanho: ");
            scanf("%s", estoque[i].tamanho);

            printf("Novo genero: ");
            scanf("%s", estoque[i].genero);

            printf("Nova cor: ");
            scanf("%s", estoque[i].cor);

            printf("Novo preco: ");
            scanf("%f", &estoque[i].preco);

            printf("\nRoupa editada com sucesso!\n");

            break;
        }
    }

    if (encontrou == 0) {
        printf("\nRoupa nao encontrada ou excluida.\n");
    }
}
void excluirRoupa() {

    int codigo;
    int encontrou = 0;

    printf("\nDigite o codigo da roupa que deseja excluir: ");
    scanf("%d", &codigo);

    for (int i = 0; i < quantidade; i++) {

        if (estoque[i].codigo == codigo && estoque[i].ativo == 1) {

            estoque[i].ativo = 0;

            encontrou = 1;

            printf("\nRoupa excluida com sucesso!\n");

            break;
        }
    }

    if (encontrou == 0) {
        printf("\nRoupa nao encontrada.\n");
    }
}
void resumoEstatisticas() {

    int totalAtivas = 0;

    float somaPrecos = 0;
    float maiorPreco = 0;
    float menorPreco = 0;

    int codigoMaior = 0;
    int codigoMenor = 0;

    for (int i = 0; i < quantidade; i++) {

        if (estoque[i].ativo == 1) {

            totalAtivas++;

            somaPrecos += estoque[i].preco;

            if (totalAtivas == 1) {

                maiorPreco = estoque[i].preco;
                menorPreco = estoque[i].preco;

                codigoMaior = estoque[i].codigo;
                codigoMenor = estoque[i].codigo;
            }

            if (estoque[i].preco > maiorPreco) {

                maiorPreco = estoque[i].preco;
                codigoMaior = estoque[i].codigo;
            }

            if (estoque[i].preco < menorPreco) {

                menorPreco = estoque[i].preco;
                codigoMenor = estoque[i].codigo;
            }
        }
    }

    printf("\n===== RESUMO DO ESTOQUE =====\n");

    printf("Roupas ativas: %d\n", totalAtivas);

    if (totalAtivas > 0) {

        printf("Valor total do estoque: R$ %.2f\n", somaPrecos);

        printf("Preco medio: R$ %.2f\n",
               somaPrecos / totalAtivas);

        printf("Roupa mais cara:\n");
        printf("Codigo %d - R$ %.2f\n",
               codigoMaior,
               maiorPreco);

        printf("Roupa mais barata:\n");
        printf("Codigo %d - R$ %.2f\n",
               codigoMenor,
               menorPreco);
    }
    else {

        printf("Nenhuma roupa cadastrada.\n");
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
                pesquisarRoupa();
                break;

            case 4:
               editarRoupa();
                break;

            case 5:
                excluirRoupa();
                break;

            case 6:
               resumoEstatisticas();
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
