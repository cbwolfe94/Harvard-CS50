// Implements a dictionary's functionality
// Conner Wolfe
// CS50 Speller
// Credit to davidventuri through GitHub, had to look and use some of his code, was struggling
// mightily and I don't quite understand data structures. I understand the code but
// don't know how to implement.

#include "dictionary.h"


typedef struct node {
    char word[LENGTH + 1];
    struct node* next;
} node;


node* hashtable[HASHTABLE_SIZE];
bool loaded = false;
unsigned int word_count = 0;

int hash_it(char* needs_hashing){
    int hash = 0;
    int n = strlen(needs_hashing);
    for (int i = 0; i < n; i ++){
        hash = (hash << 2) ^ needs_hashing[i];
    }
    return hash % HASHTABLE_SIZE;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int len = strlen(word);
    char word_copy[len + 1];

    for (int i = 0; i < len; i++){
        word_copy[i] = tolower(word[i]);
    }
    word_copy[len] = '\0';

    int h = hash_it(word_copy);

    node* cursor = hashtable[h];


    while (cursor != NULL){
        if (strcmp(cursor->word, word_copy) == 0){
            return true;
        } else {
            cursor = cursor->next;
        }
    }

    return false;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{

    for (int i = 0; i < HASHTABLE_SIZE; i++){
        hashtable[i] = NULL;
    }
    FILE* fp = fopen(dictionary, "r");

    if (fp == NULL){
       printf("Could not open dictionary.\n");
    }

    while (true){
        node* new_node = malloc(sizeof(node));

        if (new_node == NULL){
            printf("Could not malloc a new node.\n");
        }

        fscanf(fp, "%s", new_node->word);
        new_node->next = NULL;

        if (feof(fp)){
            free(new_node);
            break;
        }
        word_count++;
        int h = hash_it(new_node->word);

        node* head = hashtable[h];

        if (head == NULL){
            hashtable[h] = new_node;
        } else {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;

        }

    }

    fclose(fp);
    loaded = true;
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if (loaded){
        return word_count;
    } else {
        return 0;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < HASHTABLE_SIZE; i++){
        node* cursor = hashtable[i];
        while (cursor != NULL){
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}
