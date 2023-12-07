#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char* T;

typedef struct Node
{
    T value;
    int repeat;
    struct Node *next;
} Node;




void push(Node **head, T data)
{
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->repeat = 1;
    tmp->next = *head;
    *head = tmp;
}

int find(Node **head, T data)
{
    Node *tmp = *head;
    while (tmp)
    {
        if (strcmp(data, tmp->value) == 0)
        {
            tmp->repeat++;
            return 1;
        }
        tmp = tmp->next;
    }
    push(head, data);

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

T removeNonGraphChars(T word)
{
    int i, j;
    for (i = 0, j = 0; word[i]; i++)
    {
        if (isgraph(word[i]))
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
        removeNonGraphChars(word);
        if (word[0] != '\0')
        {
            T newWord = (T)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(newWord, word);
            find(stack, newWord);
        }
    }
}

void printLinkedList(const Node *head, FILE *file) {
	while (head) {
		fprintf(file, "%s, %d\n", head->value, head->repeat);
		head = head->next;
	}
	fprintf(file, "\n");
}

void deleteList(Node **head) {
    while ((*head)->next) {
        pop(head);
        *head = (*head)->next;
    }
    free(*head);
}

int main(int argc, char *argv[])
{
    if (argc<2)
    {
        return 1;
    }
    FILE *file = fopen(argv[1], "w");
    if (file == NULL)
    {
        return 1;
    }
    Node *head = NULL;
    processInput(&head);
    printLinkedList(head, file);
    deleteList(&head);
    fclose(file);
    return 0;
}