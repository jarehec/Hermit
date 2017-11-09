#ifndef TABLE_H
#define TABLE_H
typedef struct H_hashTable_t *H_hashTable;

H_hashTable H_HashTable(int size);
void H_insert(H_hashTable h, char *key, void *data);
void *H_find(H_hashTable h, char *key);
void H_delete(H_hashTable h, char *key);

#endif
