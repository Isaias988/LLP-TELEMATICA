#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Inicialização da Pilha
struct Node* topo = NULL;

// Verifica o Topo da Pilha
int verificar_topo() {
    if (topo != NULL) {
        return topo->data;
    } else {
        return -1; // Valor de sentinela para indicar pilha vazia
    }
}

// Implementação do Push (Inserção na Pilha)
void push(int data) {
    struct Node* novo_no = (struct Node*)malloc(sizeof(struct Node));
    novo_no->data = data;
    novo_no->next = topo;
    topo = novo_no;
}

// Implementação do Pop (Remoção da Pilha)
int pop() {
    if (topo == NULL) {
        return -1; // Valor de sentinela para indicar pilha vazia
    } else {
        int valor = topo->data;
        struct Node* temp = topo;
        topo = topo->next;
        free(temp);
        return valor;
    }
}

// Evidência da execução das operações
void imprimir_pilha() {
    struct Node* atual = topo;
    printf("Conteúdo da Pilha a partir do Topo: ");
    while (atual != NULL) {
        printf("%d ", atual->data);
        atual = atual->next;
    }
    printf("\n");
}

// Função principal (main)
int main() {
    printf("Verificando o Topo da Pilha: %d\n", verificar_topo());

    push(1);
    push(2);
    push(3);
    printf("Conteúdo da Pilha após inserção (do topo para base):\n");
    imprimir_pilha();

    printf("Verificando o Topo da Pilha após inserções: %d\n", verificar_topo());

    int removido = pop();
    printf("Elemento removido da Pilha: %d\n", removido);
    printf("Conteúdo da Pilha após remoção (do topo para base):\n");
    imprimir_pilha();

    printf("Verificando o Topo da Pilha após remoção: %d\n", verificar_topo());

    return 0;
}
