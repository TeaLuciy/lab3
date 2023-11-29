#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define INIT_SIZE 10
#define MULT 2

typedef char* T;

typedef struct Node
{
    T value;
    struct Node *next;
} Node;




void push(Node **head, T data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = *head;
    *head = tmp;
}

T pop(Node **head)
{   
    T tmpp;
    Node *tmp = NULL;
    if (head == NULL)
    {
        exit(-1);
    }
    tmp = (*head);
    tmpp = tmp->value;
    *head = (*head)->next;
    free(tmp);
    return tmpp;
}

char* removeNonAlphaChars(char* word)
{
    int i, j;
    for (i = 0, j = 0; word[i]; i++)
    {
        if (isalpha(word[i]))
        {
            word[j++] = word[i];
        }
    }
    word[j] = '\0';
    return word;
}

void processInput(struct Node** stack) {
    char word[100];
    while (scanf("%s", word) != EOF)
    {
        int j;
        removeNonAlphaChars(word);
        if (word[0] != '\0')
        {
            char* newWord = (char*)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(newWord, word);
            push(stack, newWord);
        }
    }
}

void printLinkedList(const Node *head) {
	while (head) {
		printf("%s\n", head->value);
		head = head->next;
	}
	printf("\n");
}

void main()
{
    Node *head = NULL;
    processInput(&head);
    printf("\n");
    printLinkedList(head);
}