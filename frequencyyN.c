#include "frequency.h"
//* To understand not to commit :
//* (1) Read through CONSTANT REALLOC for EACH readed value .
//* (2) Add '$' at the end of each char sequence .
//* (3) Put all the char sequnces to the trie such as there will be only cycles that start and end with the root node which letter '$' .
//* (4) In each node make an array of all the unvisited connected child nodes that are not '$'.
//* (5) Print type by first char of input and free all the allocated memory by bruteforcing aloocatoed pointers global array. 
//* TODO : 5 .
int main()
{
    int numOfWord = 0;
    int length = 0;
    char *input = read(&numOfWord, &length); //*Remember to free.
    if (numOfWord == 0)
    {
        free(input);
        return 0;
    }
    char target = input[0];
    input += 2;
    char *arrayOfStrings = addEachWordDollarAtTheEnd(input, length, numOfWord); //*Remember to free.
    node *root = createRootNode();                                              //*Remember to free.
    putInTrie(arrayOfStrings, length, root);
    determineNumOfPathsFromEachNode(root);
    if (target == 'r')
    {
        printLexRP(root);
        freeAll(input, arrayOfStrings, root);
        return 0;
    }
    printLex(root);
    freeAll(input, arrayOfStrings, root);
    return 0;
}

char *read(int *numOfWord, int *i)
{
    char *returned = (char *)malloc(sizeof(char)); //*Remember to free.
    numOfWord[0] = 0;
    boolean status = FALSE;

    char c ='';
    while (scanf("%c", &c) > 0)
    {
        returned = (char *)realloc(returned, sizeof(char) * (*i + 2)); //*Remember to free.
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
    char *arr = (char *)malloc((sizeof(char) * length) + (sizeof(char) * numOfWord)); //*Remember to free.
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
    node *p = (node *)malloc(sizeof(node)); //*Remember to free.
    if (p == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
    p->letter = '$';
    p->children = (node **)calloc(sizeof(node *), NUM_LETTERS); //*Remember to free.
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
    curr = (node *)malloc(sizeof(node)); //*Remember to free.
    if (curr->children[arrayOfStrings[i] - 96] == 0)
    {
        printf("No more free memory !\n");
        exit(-1);
    }
    curr->letter = c;
    curr->count = 0;
    curr->children = (node **)calloc(sizeof(node *), NUM_LETTERS); //*Remember to free.
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

void printLexRP(node *root)
{
    //*TODO: Right to left pass on the tree .
}
void printLex(node *root)
{
    //*TODO: Left to right pass on the tree .
}
void determineNumOfPathsFromEachNode(node *root)
{
    //*TODO : Pass on each node and set unvisitedNodesAtPrintLoopRunTime parameter to the relevant value .
}
void freeALL(char *input, char *arrayOfStrings, node *root)
{
    //*TODO: Pass on each pointer was created and contained in pointers array and free this little fucker.
}
