#ifndef ASSIGNMENT03_PQUEUE_DOUBLE_MAEATON_H
#define ASSIGNMENT03_PQUEUE_DOUBLE_MAEATON_H

//declare the max name length as static constant
#define MAX_NAME_LENGTH 64

//define struct for song data type
typedef struct {
    char title[MAX_NAME_LENGTH];
    char artist[MAX_NAME_LENGTH];
} Song;

//declare struct for double linked list
typedef struct PQueueStruct {
    int priority;
    void *data;
    struct PQueueStruct *prev;
    struct PQueueStruct *next;
} PQueueNode;

//Requires: new PQueue node, priority of node, and the data held in node
//Modifies: the PQueue
//Effects: goes through checks for inserting the new node and loops through to find the correct insertion point
int enqueue(PQueueNode **pqueue, int priority, void *data);

//Requires: the PQueue
//Modifies: the PQueue
//Effects: removes the top node on the PQueue and frees the pointer that referenced it
void *dequeue(PQueueNode **pqueue);

//Requires: the PQueue
//Modifies: nothing
//Effects: returns the information held in the top node
void *peek(PQueueNode *pqueue);

//Requires: the PQueue, function used for printing data held within
//Modifies: nothing
//Effects: loops through the entire PQueue and displays the node's information
void printQueue(PQueueNode *pqueue, void (printFunction)(void*));

//Requires: the PQueue
//Modifies: nothing
//Effects: returns the highest (lowest number) priority held in the PQueue
int getMinPriority(PQueueNode *pqueue);

//Requires: the PQueue
//Modifies: nothing
//Effects: returns the length of the PQueue
int queueLength(PQueueNode *pqueue);

//Requires: void pointer to a song
//Modifies: nothing
//Effects: casts the void pointer to a song struct and displays its information
void printSong(void *data);

//Requires: the PQueue, function used for printing the data
//Modifies: nothing
//Effects: prints the queue in reverse order to test the 'prev' pointer functionality
printReverse(PQueueNode *pqueue, void (printFunction) (void*));

#endif //ASSIGNMENT03_PQUEUE_DOUBLE_MAEATON_H
