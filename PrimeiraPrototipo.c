#include <stdio.h>

// =================================
// PROJETO: SISTEMA LOJA DE ROUPAS
// Integrantes:
// Murilo
// Vinicius
// Felipe
// =================================

// Struct da roupa
struct Roupa {
    char nome[50];
    char cor[20];
    char tamanho[10];
    int quantidade;
};

// Struct do estoque
struct Estoque {
    struct Roupa roupas[10];
};

// Struct do cliente
struct Cliente {
    char nome[50];
    char telefone[20];
};

// Struct do pedido
struct Pedido {
    int idPedido;
    struct Cliente cliente;
    struct Roupa roupa;
};

// Struct principal do sistema
struct Sistema {
    struct Estoque estoque;
    struct Cliente clientes[10];
    struct Pedido pedidos[10];
};

int main() {

    // Criando o sistema
    struct Sistema loja;

    return 0;
}
