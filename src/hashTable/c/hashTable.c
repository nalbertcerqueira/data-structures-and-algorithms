#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashTable.h"

struct HashTable* createHashTable(int size){
    if (size <= 0){
        printf("Key must be greater than 0!\n");
        return NULL;
    }

    struct HashTable *hashTable = malloc(sizeof(struct HashTable));
    hashTable->size = size;
    hashTable->values = malloc(sizeof(struct Registry*) * size);

    return hashTable;
}

int set(int key, char *value, struct HashTable *hashTable){
    if (key <= 0){
        printf("Key must be greater than 0!\n");
        return -1;
    }

    int index = hash(key, hashTable);
    struct Registry *registry = hashTable->values[index];

    //Criando o primeiro registro caso nao exista nenhum
    if (!registry){
        registry = malloc(sizeof(struct Registry));
        registry->data = malloc(sizeof(struct Data));
        registry->data->value = malloc(sizeof(char) * (strlen(value) + 1));

        strncpy(registry->data->value, value, strlen(value) + 1);
        registry->data->key = key;
        registry->next = NULL;
        hashTable->values[index] = registry;
        return 0;
    }

    //Iterando sobre os registros para verificar se já existe um registro com a mesma 'key'
    while (registry->data->key != key){
        //Caso o registro não seja encontrado, um novo é criado
        if (registry->next == NULL){
            struct Registry *newRegistry = malloc(sizeof(struct Registry));
            newRegistry->data = malloc(sizeof(struct Data));
            newRegistry->data->value = malloc(sizeof(char) * (strlen(value) + 1));

            strncpy(newRegistry->data->value, value, strlen(value) + 1);
            newRegistry->data->key = key;
            newRegistry->next = NULL;
            registry->next = newRegistry;

            return 0;
        }
        registry = registry->next;
    }

    //Alterando o valor armazenado no registro caso já exista um registro
    //para a 'key' recebida
    free(registry->data->value);
    registry->data->value = malloc(sizeof(char) * (strlen(value) + 1));
    strncpy(registry->data->value, value, strlen(value) + 1);
    return 0;
}

int delete(int key, struct HashTable *hashTable){
    int index = hash(key, hashTable);
    struct Registry *prevRegistry = NULL;
    struct Registry *currRegistry = hashTable->values[index];

    if (!currRegistry){
        printf("Data with key: '%d' not found\n", key);
        return -1;
    }

    while (currRegistry->data->key != key){
        if (currRegistry->next == NULL){
            printf("Data with key: '%d' not found\n", key);
            return -1;
        }
        prevRegistry = currRegistry;
        currRegistry = currRegistry->next;
    }

    if (prevRegistry){
        prevRegistry->next = currRegistry->next;
    } else{
        hashTable->values[index] = currRegistry->next;
    }

    free(currRegistry->data->value);
    free(currRegistry->data);
    free(currRegistry);

    return 0;
}

char* get(int key, struct HashTable *hashTable){
    int index = hash(key, hashTable);
    struct Registry *registry = hashTable->values[index];

    if (!registry){
        printf("Data with key: '%d' not found\n", key);
        return NULL;
    }

    while (registry->data->key != key){
        if(registry->next == NULL ){
            printf("Data with key: '%d' not found\n", key);
            return NULL;
        }
        registry = registry->next;
    }

    return registry->data->value;
}

int print(struct HashTable *hashTable){
    printf("{\n");
    for (int i=0; i<hashTable->size; i++){
        struct Registry *registry = hashTable->values[i];
        if(registry){
            while (registry != NULL){
                printf("  %d: %s\n", registry->data->key, registry->data->value);
                registry = registry->next;
            }
        }
    }
    printf("}\n");

    return 0;
}

static int hash(int key, struct HashTable *hashTable){
    int index = key % hashTable->size;
    return index;
}
