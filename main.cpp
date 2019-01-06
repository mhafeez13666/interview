//
//  main.cpp
//  learnPrepare
//
//  Created by Mohamed Hafeez on 06/01/19.
//  Copyright © 2019 Mohamed Hafeez. All rights reserved.
//

#include <iostream>

using namespace std;

//Total HashTable size is 20 rows
#define HASH_TABLE_SIZE 20

//Node Struct
typedef struct hashList {
    long hashKey;
    char *strVal;
    struct hashList *next;
} linkedListNode;


//Class to hold the HashTable
class hashTable {
    
private:
    linkedListNode *hashTableRowsHead;
    linkedListNode *hashTableRowsTail;
public:
    hashTable() {
        hashTableRowsHead = NULL;
        hashTableRowsHead = NULL;
    }
    linkedListNode *InsertIntoHashTable(long hashValue, const char *strValue);

};

//Insert the keyvalue into the Table/row
linkedListNode *hashTable::InsertIntoHashTable(long hashValue, const char *strValue){
    
    linkedListNode *node = (linkedListNode *)malloc(sizeof(linkedListNode));
    
    node->hashKey  = hashValue;
    node->strVal   = (char *)strValue;
    node->next     = NULL;


    //Check if it is the first node
    if ( hashTableRowsHead == NULL){
        hashTableRowsHead = node;
        hashTableRowsTail = node;
        hashTableRowsHead->next = NULL;
    }
    else {
        hashTableRowsTail->next = node;
        hashTableRowsTail = node;
    }
    
    return node;
}

//DJB2 Algorithm for Hash calculation
long calculateHash(const char *_str){
    
    const char *str = _str;
    unsigned int hash = 5381;
    char c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


int main(int argc, const char * argv[]) {


    //Main Hash Table
    hashTable hTable[HASH_TABLE_SIZE];

    //Test Data
    const char *keyValuesStr[] = {"Hello world", "joyful", "synaphea", "Robert Lafore","Stroustroup"};
    
    int hashTableRowIndex = 0;
    long hashValue;
    
    //Insert all the Key-Value pairs
    for (int i=0;i<5;i++){
        
        hashValue         = calculateHash(keyValuesStr[i]); //Calculate Hash for the String value
        hashTableRowIndex = hashValue%HASH_TABLE_SIZE;      //Get the row Index
        
        cout << "HashValue is " << hashValue << " and row is " << hashTableRowIndex << endl;
        
        //Insert into the hashTable in the appropriate row
        hTable[hashTableRowIndex].InsertIntoHashTable(hashValue,keyValuesStr[i]);
        
    }
    
    
    return 0;
}
