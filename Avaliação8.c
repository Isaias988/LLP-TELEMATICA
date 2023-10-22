#include <stdio.h>
#include <stdlib.h>
//Isaias Fabricio da Costa - LLP 2023.2

// Definindo a estrutura de um nó da fila
struct Node {
    int data;
    struct Node *next;
};

// Definindo a estrutura da fila
struct Queue {
    struct Node *front;  // Ponteiro para o primeiro elemento da fila
    struct Node *rear;   // Ponteiro para o último elemento da fila
};

// Função para criar uma fila vazia
struct Queue* createQueue() {
    struct Queue *queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Função para inserir um elemento na fila
void enqueue(struct Queue *queue, int item) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (queue->rear == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("Inserido: %d\n", item);
}

// Função para retirar o primeiro elemento da fila
int dequeue(struct Queue *queue) {
    if (queue->front == NULL) {
        printf("A fila está vazia.\n");
        return -1;
    } else {
        int item = queue->front->data;
        struct Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);
        return item;
    }
}

// Função para percorrer e mostrar os elementos da fila
void displayQueue(struct Queue *queue) {
    struct Node *current = queue->front;
    if (current == NULL) {
        printf("A fila está vazia.\n");
    } else {
        printf("Elementos na fila: ");
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue *fila = createQueue();

    enqueue(fila, 10);
    enqueue(fila, 20);
    enqueue(fila, 30);

    displayQueue(fila);

    int elementoRetirado = dequeue(fila);
    if (elementoRetirado != -1) {
        printf("Elemento retirado: %d\n", elementoRetirado);
    }

    displayQueue(fila);

    return 0;
}