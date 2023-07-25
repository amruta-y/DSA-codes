#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CACHE_SIZE 10
#define TABLE_SIZE 20

typedef struct {
    int key;
    int value;
    int is_valid;
} CacheEntry;

CacheEntry cache[CACHE_SIZE];
int hash_table[TABLE_SIZE];

// Hash function to convert the key to an index
int hash(int key) {
    return key % TABLE_SIZE;
}

// Function to initialize the cache
void initializeCache()
{
    for (int i = 0; i < CACHE_SIZE; i++)
    {
        cache[i].is_valid = 0;
    }
}

// Function to check if a cache entry is valid
int isValidCacheEntry(int index)
{
    return cache[index].is_valid;
}

// Function to get the value from the cache
int getFromCache(int key)
{
    int index = hash(key) % CACHE_SIZE;

    for (int i = 0; i < CACHE_SIZE; i++)
    {
        if (isValidCacheEntry(index) && cache[index].key == key)
        {
            return cache[index].value;
        }
        index = (index + 1) % CACHE_SIZE; // Move to the next entry using linear probing
    }

    return -1; // Not found in cache
}

// Function to add an entry to the cache
void addToCache(int key, int value)
{
    int index = hash(key) % CACHE_SIZE;

    // Search for an empty slot or a slot with the same key
    while (isValidCacheEntry(index))
    {
        if (cache[index].key == key)
        {
            // If the key already exists in the cache, update the value and return
            cache[index].value = value;
            return;
        }
        index = (index + 1) % CACHE_SIZE; // Move to the next entry using linear probing
    }

    // If an empty slot is found, add the new entry to the cache
    cache[index].key = key;
    cache[index].value = value;
    cache[index].is_valid = 1;
}

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    if (!inputFile || !outputFile)
    {
        printf("Error opening files.\n");
        return 1;
    }

    initializeCache();

    int key, value;
    char operation;

    // Read operations from the input file and perform cache operations accordingly
    while (fscanf(inputFile, "%c %d %d\n", &operation, &key, &value) == 3)
    {
        if (operation == 'R')
        {
            int result = getFromCache(key);
            fprintf(outputFile, "Read key %d: %d\n", key, result);
        }
        else if (operation == 'W')
        {
            addToCache(key, value);
            fprintf(outputFile, "Write key %d: %d\n", key, value);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
