#include "frequency.h"
int main()
{
    int numOfWord = 0;
    int length = 0;
    char *input = read(&numOfWord, &length); //*Should be freed.
    if (numOfWord == 0)
    {
        free(input);
        return 0;
    }
    char target = input[0];
    input += 2;
    char *arrayOfStrings = addEachWordDollarAtTheEnd(input, length, numOfWord); //*Should be freed.
    node *root = createRootNode();                                              //*Should be freed.
    putInTrie(arrayOfStrings, length, root);
    if (target == 'r')
    {
        printLex(p);
        freeAll(input, arrayOfStrings, root);
        return 0;
    }
    printLexRP(p);
    freeAll(input, arrayOfStrings, root);
    return 0;
}

char *read(int *numOfWord, int *i)
{
    char *returned = (char *)malloc(sizeof(char));
    numOfWord[0] = 0;
    boolean status = FALSE;

    char c ='';
    while (scanf("%c", &c) > 0)
    {
        returned = (char *)realloc(returned, sizeof(char) * (*i + 2));
        if (retuned == 0)
        {
            printf("No more free memory !\n");
            free(returned);
            exit(-1);
        }
        if (c != ' ')
        {
            status = TRUE;
        }
        else if (status)
        {
            numOfWord[0]++;
            status = FALSE;
        }
        if (c > 96 && c < 123)
        {
            returned[*i] = c;
        }
        else
        {
            returned[*i] = (char)c + 32; //*Changig to lower case in case the char is in upper case.
        }
        *i++;
    }
    returned[*i] = '\0';
    if (*i == 0)
    {
        free(returned);
        exit(-1);
    }
    return returned;
}

char *addEachWordDollarAtTheEnd(char *input, int length, int numOfWord)
{
    char *arr = (char *)malloc((sizeof(char) * length) + (sizeof(char) * numOfWord));
    for (int i = 0; i < length; i++)
    {
       if(input[i]!=' ' && (input[i]!='\n'){
            arr[k] = input[i];
       }
       else {
            arr[k] = '$';
       }
       k++;
    }
    return arr;
}

node *createRootNode()
{
    node *p = (node *)malloc(sizeof(node));
    if (p == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
    p->letter = '$';
    p->children = (node **)calloc(sizeof(node *), NUM_LETTERS);
    if (p->children == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
    p->count = 0;
    return p;
}

void putInTrie(char *arrayOfStrings, int length, node *root)
{
    node *curr = root;
    for (int i = 0; i < length; i++)
    {
        if (arrayOfStrings[i] == ' ')
        {
            continue;
        }
        if (arrayOfStrings[i] == '$')
        {
            curr = root;
            continue;
        }
        if (curr->children[arrayOfStrings[i] - 96] == NULL)
        {
            createNode(curr->children[arrayOfStrings[i] - 96], arrayOfStrings[i]);
            curr = curr->children[arrayOfStrings[i] - 96];
        }
        else
        {
            upgradeNode(curr->children[arrayOfStrings[i] - 96]);
            curr = curr->children[arrayOfStrings[i] - 96];
        }
    }
}
void createNode(node *curr, char c)
{
    curr = (node *)malloc(sizeof(node));
    if (curr->children[arrayOfStrings[i] - 96] == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
    curr->letter = c;
    curr->count = 0;
    curr->children = (node **)calloc(sizeof(node *), NUM_LETTERS);
    if (curr->children == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
}
void upgradeNode(node *curr, char c)
{
    curr->count += 1;
}



