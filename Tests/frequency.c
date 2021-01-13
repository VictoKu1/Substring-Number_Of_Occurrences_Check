#include "frequency.h"


int main(){
    node root;
    return 0;
}

// read a word from the user and return the word (update the length of the word with the poiner i)

char* get_word(int *i){
    char *word = (char *)malloc(sizeof(char)*51);
    if (word == NULL)
    {
        printf("not enough memory");
        exit(-1);
    }
    char c;
    *i = 0;
    int len = 50;
    scanf('%c',&c);
    while (c != ' ' && c != '\t'&& c != '\n' && c != 13)
    {
        if (*i >= len)
        {
            word = realloc(word,len*2);
        }
        if (word == NULL)
        {
        printf("not enough memory");
        exit(-1);
        }
        word[i] = c;
        scanf('%c',&c);
        ++(*i);
    }
    word[*i] = '\0';
    return word;
}

// given a word build a path for it in the tree ( $ is the end of the word)
void tree_builder(char *c,int len,node* root){
    int index ;
    node n;
    node par = *root;
    for (size_t i = 0; i < len; i++)
    {
        index = hash(c[i]);
        if (index != -1)
        {
           n = *(node_builder(c[i]));
           par.children[index] = &n;
           par = n;
        }
    }
    n = *(node_builder('$'));
    par.children[0] = &n;
}

// build a node that represent the given char
node* node_builder(char c){
    node * n = (node*)malloc(sizeof(node));
    if (n == NULL)
    {
        printf("not enough memory");
        exit(-1);
    }
    n->count = 0 ;
    n->letter = c;
    node** children = (node**)malloc(sizeof(node*)*NUM_LETTERS);
    if (children == NULL)
    {
        printf("not enough memory");
        exit(-1);
    }
    n->children = children;
    return n;
}

// caculate a hash function for the letters
int hash(int i){
    if (i<91 || i >64)
    {
        i = i + 32
    }
    if (i-97 < 0 || i >25)
    {
        return -1;
    }
    return i - 96
}