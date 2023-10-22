#include <stdio.h>

// Definindo uma estrutura para armazenar informações do produto
struct Produto {
    char nome[50];
    float preco;
    int estoque;
};

int main() {
    struct Produto produto;

    // Passo 1: Recebendo os dados do produto
    printf("Informe o nome do produto: ");
    scanf("%s", produto.nome);

    printf("Informe o preço do produto: ");
    scanf("%f", &produto.preco);

    printf("Informe a quantidade em estoque: ");
    scanf("%d", &produto.estoque);

    // Passo 2: Gravando a estrutura em um arquivo
    FILE *arquivo = fopen("produtos.txt", "a");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(arquivo, "Nome do Produto: %s\n", produto.nome);
    fprintf(arquivo, "Preço: %.2f\n", produto.preco);
    fprintf(arquivo, "Estoque: %d\n", produto.estoque);
    fprintf(arquivo, "\n");  // Adicionar uma linha em branco entre os registros

    fclose(arquivo);
    printf("Dados do produto gravados com sucesso no arquivo 'produtos.txt'.\n");

    return 0;
}