/*
 *----------------------
 *|     Hash-Table     |
 *----------------------
 * Linear Probing HashTable implementation in C
 *
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include "HashTable.h"


void initHashTable(HashTable *HT) {
    HT->M = 37; // 10 is the default initial capacity
    HT->N = 0;
}

int size(HashTable *HT) {
    return HT->N;
}

boolean isEmpty(HashTable *HT) {
    return HT->N == 0;
}

boolean contains(HashTable *HT, char *key) {
    if (key == NULL)
        return false;

    return get(HT, key) != NULL;
}

int hash(HashTable *HT, void *key) {

    /* hash function from: https://gist.github.com/tonious/1377667 */
	unsigned long int hashval;
	int i = 0;
    char *keyToChar = (char *)key;

	/* Convert our string to an integer */
	while( hashval < ULONG_MAX && i < strlen( keyToChar ) ) {
		hashval = hashval << 8;
		hashval += keyToChar[ i ];
		i++;
	}

	return hashval % HT->M;
}

void resize(HashTable *HT, int capacity) {
    // code here
    HashTable *tempHash = malloc( sizeof(HashTable) );

    // free the temporary hash
    free(tempHash);
}

void put(HashTable *HT, char *key, void *value) {
    // code here
    if (key == NULL) {
        printf("key value is NULL\n");
        return;
    }

    if (value == NULL) {
        deleteKey(HT, key);
        return;
    }

    // double table size if 50% full
    if(HT->N >= HT->M/2)
        resize(HT, (2*HT->M));

    // check if the hash value is already represented
    int i;
    for (i = hash(HT, key); HT->keys[i] !=NULL; i = (i + 1) % HT->M) {
        // if we find the key after indexing by the hashed value
        if (strcmp(HT->keys[i], key) == 0) {
            HT->values[i] = value;
            return;
        }
    }

    //int keyValue = hash(HT, key);
    // otherwise, we put it in for the first time
    HT->keys[i] = key;
    HT->values[i] = value;
    HT->N++;

    printf("Hash value, i=%d\n", i);
    printf("HT->values[keyValue] = %d\n", *(int *)HT->values[i] );
    return;

}

void* get(HashTable *HT, char *key) {
    if (NULL == key) {
         printf("key value is null");
         return NULL;
    }

    printf("Inside get\n");
    // index into the hash table via linear probing
    int i;
    for (i=hash(HT, key); HT->keys[i] != NULL; i = (i + 1) % HT->M) {
        if (HT->keys[i] == key) {
            printf("FROM GET:  hash_key, i=%d, >> HT->values[i] = %d\n", i, *(int *)HT->values[i] );
            return HT->values[i];
        }
    }
    printf("didn't find a match\n");

    // if we don't find a match, then return NULL
    return NULL;
}

void deleteKey(HashTable *HT, char* key) {
    // code here
}

int main(int argc, char* argv[]) {
    // test code here
    HashTable *myHT = malloc( sizeof(HashTable) );
    initHashTable(myHT);

    // Test The Hashing Function first
    int myHash;
    void *myVal;
    int testInt = 1337;
    myVal = &testInt;
    myHash = hash(myHT, myVal);
    printf("MyHash=%d\n", myHash);

    int myHashTwo;
    void *myValTwo;
    int testIntTwo = 13378;
    myValTwo = &testIntTwo;
    myHashTwo = hash(myHT, myValTwo);
    printf("MyHash=%d\n", myHashTwo);


    // test put and get
    int putValOne, putValTwo;
    char *putKeyOne, *putKeyTwo;
    void *value_one_ptr;
    void *value_two_ptr;


    putKeyOne = "One";
    putKeyTwo = "Two";

    putValOne = 99;
    putValTwo = 44;

    value_one_ptr = &putValOne;
    value_two_ptr = &putValTwo;

    // PUT
    put(myHT, putKeyOne, value_one_ptr);
    put(myHT, putKeyTwo, value_two_ptr);
    printf("made it past put\n");

    // GET
    void *return_one_ptr = malloc( sizeof(void *) );
    void *return_two_ptr = malloc( sizeof(void *) );
    return_one_ptr = get(myHT, putKeyOne);
    return_two_ptr = get(myHT, putKeyTwo);
    printf("made it past get\n");

    printf("size of int = %d, size of void * = %d\n",(int)sizeof(int), (int)sizeof(void*));

    printf("Return Value One: %d\n", *(int *)return_one_ptr);
    printf("Return Value Two: %d\n", *(int *)return_two_ptr);


}
