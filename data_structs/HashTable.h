#ifndef HASHTABLE_H_   /* Include guard */
#define HASHTABLE_H_

// Define booleans
typedef enum { false, true } boolean;


/* Linear Probing Hash Table */
typedef struct HashTable HashTable;
struct HashTable {
    int N; // Number of pairs in Table
    int M; // Size of the table
    char *keys[37];  // Array of keys, each a String
    void *values[37]; // Array of values, all void pointers
};


void initHashTable(HashTable *HT);
int size(HashTable *HT);
boolean isEmpty(HashTable *HT);
boolean contains(HashTable *HT, char *key);
int hash(HashTable *HT, void *key);
void resize(HashTable *HT, int capacity);
void put(HashTable *HT, char *key, void *value);
void* get(HashTable *HT, char *key);
void deleteKey(HashTable *HT, char* key);




#endif // HASHTABLE_H_
