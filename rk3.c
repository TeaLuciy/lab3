#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef char* T;

typedef struct Node
{
    T value;
    struct Node* next;
} Node;


void push(Node **head, T data)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
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

void processInput(struct Node** LowerStack, struct Node** HigherStack, FILE *file) {
    char word[100];
    while (fscanf(file, "%s", word) != EOF)
    {
        int j;
        removeNonGraphChars(word);
        if (word[0] != '\0')
        {
            T newWord = (T)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(newWord, word);
            if (islower(newWord[0]))
            {
                push(LowerStack, newWord);
            }
            else
            {
                push(HigherStack, newWord);
            }
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

void printLinkedListFile(const Node *head, FILE *file) {
	while (head) {
		fprintf(file, "%s\n", head->value);
		head = head->next;
	}
	fprintf(file, "\n");
}

void deleteList(Node **head) {
	Node* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}

int main(int argc, char *argv[])
{
    if (argc<3)
    {
        return 1;
    }
    FILE *filein = fopen(argv[1], "r");
    if (filein == NULL)
    {
        return 1;
    }
    FILE *fileout = fopen(argv[2], "w");
    if (fileout == NULL)
    {
        return 1;
    }



    Node *hs = NULL;
    Node *ls = NULL;
    processInput(&ls, &hs, filein);
    printf("\n");
    printLinkedList(ls);
    printf("\n");
    printLinkedListFile(hs, fileout);
    deleteList(&hs);
    deleteList(&ls);
    fclose(filein);
    fclose(fileout);
}