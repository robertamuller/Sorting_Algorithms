#include <iostream>
#include <chrono>
#include <random>

using std::cout;
using std::endl;

// Lista duplamente encadeada
typedef struct Node
{
    int iPayload;
    Node* ptrNext;
    Node* ptrPrev;
} Node;

// Protótipos lista duplamente encadeada
Node* createNode(int);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void displayList(Node*);
void displayHeadAndTail(Node*);

// Protótipos algorimos de ordenação
void swap(Node*, Node*);
void bubbleSort(Node*, int);
void optimizedBubbleSort(Node*, int);
void selectionSort(Node*, int);
void optimizedSelectionSort(Node*, int);

int main()
{
    cout << "------------ CRIAÇÃO DE LISTAS DE 12 ELEMENTOS ------------\n" << endl;

    Node* copy1 = nullptr;
    Node* copy2 = nullptr;
    Node* copy3 = nullptr;
    Node* copy4 = nullptr;
    int iListLen = 12;

    for (int i = 0; i < iListLen; i++)
    {
        int iNum = rand() %100 + 1;  // Gera um número entre 1 e 100
        insertEnd(&copy1, iNum);
        insertEnd(&copy2, iNum);
        insertEnd(&copy3, iNum);
        insertEnd(&copy4, iNum);
    }

    displayList(copy1);

    cout << "\n------------ TESTES ALGORITMOS DE ORDENAÇÃO ------------\n" << endl;


    auto timeStart1 = std::chrono::high_resolution_clock::now();
    bubbleSort(copy1, iListLen);
    auto timeStop1 = std::chrono::high_resolution_clock::now();
    auto timeDuration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop1 - timeStart1);
    cout << "Temp bubbleSort: " <<  timeDuration1.count() << " nanoseconds" <<  endl;

    auto timeStart2 = std::chrono::high_resolution_clock::now();
    optimizedBubbleSort(copy2, iListLen);    
    auto timeStop2 = std::chrono::high_resolution_clock::now();
    auto timeDuration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop2 - timeStart2);
    cout << "Temp optimizedBubbleSort: " <<  timeDuration2.count() << " nanoseconds" <<  endl;

    auto timeStart3 = std::chrono::high_resolution_clock::now();
    selectionSort(copy3, iListLen);
    auto timeStop3 = std::chrono::high_resolution_clock::now();
    auto timeDuration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop3 - timeStart3);
    cout << "Temp selectionSort: " <<  timeDuration3.count() << " nanoseconds" <<  endl;

    auto timeStart4 = std::chrono::high_resolution_clock::now();
    optimizedSelectionSort(copy4, iListLen);
    auto timeStop4 = std::chrono::high_resolution_clock::now();
    auto timeDuration4 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop4 - timeStart4);
    cout << "Temp optimizedSelectionSort: " <<  timeDuration4.count() << " nanoseconds" <<  endl;

    cout << "\nOs resultados de cada ordenação foram, respectivamente:\n" << endl;

    displayList(copy1);
    displayList(copy2);
    displayList(copy3);
    displayList(copy4);


    cout << "\n------------ CRIAÇÃO DE LISTAS DE 10000 ELEMENTOS ------------\n" << endl;

    copy1 = nullptr;
    copy2 = nullptr;
    copy3 = nullptr;
    copy4 = nullptr;
    iListLen = 10000;

    for (int i = 0; i < iListLen; i++)
    {
        int iNum = rand() %15000 + 1;  // Gera um número entre 1 e 15000
        insertEnd(&copy1, iNum);
        insertEnd(&copy2, iNum);
        insertEnd(&copy3, iNum);
        insertEnd(&copy4, iNum);
    }

    displayHeadAndTail(copy1);

    cout << "\n------------ TESTES ALGORITMOS DE ORDENAÇÃO ------------\n" << endl;


    timeStart1 = std::chrono::high_resolution_clock::now();
    bubbleSort(copy1, iListLen);
    timeStop1 = std::chrono::high_resolution_clock::now();
    timeDuration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop1 - timeStart1);
    cout << "Temp bubbleSort:             " <<  timeDuration1.count() << " nanoseconds" <<  endl;

    timeStart2 = std::chrono::high_resolution_clock::now();
    optimizedBubbleSort(copy2, iListLen);    
    timeStop2 = std::chrono::high_resolution_clock::now();
    timeDuration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop2 - timeStart2);
    cout << "Temp optimizedBubbleSort:    " <<  timeDuration2.count() << " nanoseconds" <<  endl;

    timeStart3 = std::chrono::high_resolution_clock::now();
    selectionSort(copy3, iListLen);
    timeStop3 = std::chrono::high_resolution_clock::now();
    timeDuration3 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop3 - timeStart3);
    cout << "Temp selectionSort:          " <<  timeDuration3.count() << " nanoseconds" <<  endl;

    timeStart4 = std::chrono::high_resolution_clock::now();
    optimizedSelectionSort(copy4, iListLen);
    timeStop4 = std::chrono::high_resolution_clock::now();
    timeDuration4 = std::chrono::duration_cast<std::chrono::nanoseconds>(timeStop4 - timeStart4);
    cout << "Temp optimizedSelectionSort: " <<  timeDuration4.count() << " nanoseconds" <<  endl;

    cout << "\nOs resultados de cada ordenação foram, respectivamente:\n" << endl;

    displayHeadAndTail(copy1);
    displayHeadAndTail(copy2);
    displayHeadAndTail(copy3);
    displayHeadAndTail(copy4);
}

Node* createNode(int iPayload) 
{
    Node* temp = (Node*) malloc(sizeof(Node));
    temp->iPayload = iPayload;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;

    return temp;
}

void displayList(Node* node) 
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayList" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayList" << endl;
        return;
    }

    Node* temp = node;

    cout << "Payload: ";

    //Percorremos a lista até seu fim (ptrNext do último nó é NULL)
    while (temp != nullptr)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext;
    }
    
    cout << endl;
}

void insertFront(Node** head, int iPayload) 
{
    Node* newNode = createNode(iPayload);
    
    if (*head != nullptr)
    {
        // newNode->ptrPrev = nullptr
        (*head)->ptrPrev = newNode;
        newNode->ptrNext = (*head);
        (*head) = newNode;
        return;
    }
    (*head) = newNode;
}

void insertEnd(Node** head, int iPayload) 
{
    Node* newNode = createNode(iPayload);

    if (*head == nullptr)
    {
        (*head) = newNode; // derreferenciando um ponteiro
        return;
    }

    Node* temp = (*head);

    //Percorre a lista
    while (temp->ptrNext != nullptr) temp = temp->ptrNext;

    newNode->ptrPrev =  temp; //newNode aponta para o fim da lista
    temp->ptrNext = newNode; //Antigo último elemento aponta para o novo nó
}

void displayHeadAndTail(Node* node)
{
    if (node == nullptr)
    {
        cout << "Lista vazia: Não é possível realizar displayHead" << endl;
        return;
    }

    if (node->ptrPrev != nullptr)
    {
        cout << "Meio ou Fim da Lista: Não é possível realizar displayHead" << endl;
        return;
    }

    Node* temp = node;

    cout << "Head ... Tail: ";

    // Printa os 5 primeiros elementos da lista
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << "... ";

    // Percorremos a lista até seu fim para obter o endereço do último elemento (ptrNext do último nó é NULL)
    while (temp->ptrNext != nullptr)
    {
        temp = temp->ptrNext;
    }
    
    // Volta 5 elementos
    for (int i = 0; i < 4; i++)
    {
        temp = temp->ptrPrev; 
    }

    // Printa os 5 últimos elementos da lista
    for (int i = 0; i < 5; i++)
    {
        cout << temp->iPayload << " ";
        temp = temp->ptrNext; 
    }

    cout << endl;
}

// algoritmo que troca os valores de dois nós
void swap(Node* node1, Node* node2) 
{
    // salva o valor do node1
    int temp = node1->iPayload;

    // troca os valores
    node1->iPayload = node2->iPayload;
    node2->iPayload = temp;
}

// Implementação do algoritmo Bubble Sort
void bubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        // Loop interno para comparar pares adjacentes e fazer as trocas necessárias
        for (int j = 0; j < iListLen - i - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o próximo nó na lista
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext); // Troca os nós
            }
            current = current->ptrNext; // Move para o próximo nó
        }
        current = head; // Reinicia a posição atual para o início da lista
    }
}

// Implementação do algoritmo Bubble Sort otimizado
void optimizedBubbleSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual
    bool bSwapped; // Flag para indicar se houve troca durante a iteração

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        bSwapped = false; // Inicializa a flag de troca como falsa

        // Loop interno para comparar pares adjacentes e fazer as trocas necessárias
        for (int j = 0; j < iListLen - i - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o próximo nó na lista
            if (current->iPayload > current->ptrNext->iPayload)
            {
                swap(current, current->ptrNext); // Troca os nós
                bSwapped = true; // Define a flag de troca como verdadeira
            }
            current = current->ptrNext; // Move para o próximo nó
        }
        
        // Se não houve troca durante a iteração, a lista está ordenada e podemos sair do loop
        if (bSwapped == false)
        {
            break;
        }

        current = head; // Reinicia a posição atual para o início da lista
    }
}

// Implementação do algoritmo Selection Sort
void selectionSort(Node* head, int iListLen) 
{
    Node* current = head; // Ponteiro para o nó atual
    Node* temp = head; // Ponteiro temporário para auxiliar nas trocas

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        temp = current; // Inicializa o ponteiro temporário como o nó atual

        // Loop interno para encontrar o menor elemento não ordenado
        for (int j = 0; j < iListLen - i; j++)
        {
            // Verifica se o valor do nó atual é maior que o valor do nó temporário
            if (current->iPayload > temp->iPayload)
            {
                swap(current, temp); // Troca os nós
            }
            temp = temp->ptrNext; // Move para o próximo nó temporário
        }
        current = current->ptrNext; // Move para o próximo nó atual
    }
}

// Implementação do algoritmo Selection Sort otimizado
void optimizedSelectionSort(Node* head, int iListLen)
{
    Node* current = head; // Ponteiro para o nó atual
    Node* temp; // Ponteiro temporário para auxiliar nas trocas
    Node* smallest; // Ponteiro para o menor elemento encontrado

    // Loop externo para percorrer a lista
    for (int i = 0; i < iListLen; i++)
    {
        smallest = current; // Define o menor elemento como o nó atual
        temp = current->ptrNext; // Inicializa o ponteiro temporário como o próximo nó

        // Loop interno para encontrar o menor elemento não ordenado
        for (int j = 0; j < iListLen - i - 1; j++)
        {
            // Verifica se o valor do nó atual é maior que o valor do nó temporário
            if (smallest->iPayload > temp->iPayload)
            {
                smallest = temp; // Atualiza o menor elemento encontrado
            }
            temp = temp->ptrNext; // Move para o próximo nó temporário
        }

        // Se o menor elemento encontrado for menor que o nó atual, realiza a troca
        if (smallest->iPayload < current->iPayload)
        {
            swap(smallest, current); // Troca os nós
        }
        
        current = current->ptrNext; // Move para o próximo nó atual
    }
}
