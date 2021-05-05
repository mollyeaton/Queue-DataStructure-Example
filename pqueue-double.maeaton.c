#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue-double.maeaton.h"

int enqueue(PQueueNode **pqueue, int priority, void *data) {
    //create a temporary node to hold all of the info
    PQueueNode *newTemp = (PQueueNode*)malloc(sizeof(PQueueNode));
    //create a temporary node to hold the new next node
    PQueueNode *tempNext;
    //create a temporary node to use for counting and looping
    PQueueNode *counter = *pqueue;

    //if the pqueue is empty then set both next and prev to NULL
    if (*pqueue == NULL) {
        //assign parameters to the temp node
        newTemp -> priority = priority;
        newTemp -> data = data;
        newTemp -> next = NULL;
        newTemp -> prev = NULL;

        *pqueue = newTemp;
        return 0; //exit the function
    }

    //if there is one node
    if ((*pqueue) -> next == NULL) {
        //check if the priority puts the new node before or after
        //if the priority puts it before the current
        if (priority < (*pqueue) -> priority) {
            //save the current pqueue
            tempNext = *pqueue;
            //assign the parameters to the temp node
            newTemp -> priority = priority;
            newTemp -> data = data;
            newTemp -> next = tempNext;
            newTemp -> prev = NULL;
            //set the prev to the new node
            (*pqueue) -> prev = newTemp;
            *pqueue = newTemp; //transfer over to pqueue
            return 0; //leave the function
        }
        else {
            //assign the parameters to the temp node
            newTemp -> priority = priority;
            newTemp -> data = data;
            newTemp -> next = NULL;
            newTemp -> prev = *pqueue; //set previous to original node

            (*pqueue) -> next = newTemp;//set the current pqueue node's next to the new node
            return 0; //leave the function
        }
    }
    //the node will be inserted at the beginning
    if (priority < (*pqueue) -> priority) {
        //assign the parameters to the temp node
        newTemp->priority = priority;
        newTemp->data = data;
        newTemp->next = *pqueue;
        newTemp->prev = NULL;
        //have the original head point backwards to the new node
        (*pqueue) -> prev = newTemp;
        *pqueue = newTemp;
        return 0; //leave the function
    }
    //loop through the pqueue until the next node's priority is greater than the new node
    while (priority >=  (counter) -> next -> priority ) {
        counter = (counter)->next;
        //if the next is null then you have reached the end of the pqueue
        if (counter -> next == NULL) {
            break;
        }
    }
    //if the next is NULL then the node is being inserted at the end of the pqueue
    if ((counter) -> next  == NULL ) {
        //assign the parameters to the temp node
        newTemp->priority = priority;
        newTemp->data = data;
        newTemp->next = NULL; //have the inserted node point to the right node
        newTemp->prev = counter;
        //have the left node point to the inserted node
        (counter) -> next = newTemp;
    }
    //otherwise it is being inserted into the middle
    else {
        //save the next node for the pointer
        tempNext = (counter) -> next;
        //assign the parameters to the temp node
        newTemp->priority = priority;
        newTemp->data = data;
        newTemp->next = tempNext; //have the inserted node point to the right node
        newTemp->prev = counter; //have the prev point to left node
        (counter) -> next = newTemp; //have the original node point to the new node
        //set the next node to point back to new node
        newTemp->next->prev = newTemp;
    }

    return 0;
}

void *dequeue(PQueueNode **pqueue) {
    //if the pqueue is empty just return NULL
    if (*pqueue == NULL) {
        return NULL;
    }
    //create a void pointer to the data held within the front node
    void *returnData;
    //have the pointer point to the data held
    returnData = (*pqueue) -> data;

    //create a temp holder for the original pqueue and move the pqueue down one
    PQueueNode *temp = *pqueue;
    (*pqueue) -> prev = NULL; //set the new top's prev to be null
    *pqueue = (*pqueue) -> next;

    //free the original queue front node
    free(temp);

    //return the data
    return returnData;
}

void *peek(PQueueNode *pqueue){
    //if the pqueue is empty just return NULL
    if(pqueue == NULL) {
        return NULL;
    }
    //otherwise the pqueue is not empty
    //return the data from the top node
    return pqueue -> data;

}

void printQueue(PQueueNode *pqueue, void (printFunction)(void*)) {
    //loop through the pqueue until the node is null
    //call the print function on every node and then move down the list
    while (pqueue != NULL) {
        printf("priority = %d data = ", pqueue -> priority);
        printFunction(pqueue -> data);
        pqueue = pqueue -> next;
    }
}

void printSong(void *data) {
    //cast data as a song struct
    Song song = *((Song *) data);
    //display the info
    printf("\"%s\" (%s)\n", song.title, song.artist);
}

int getMinPriority(PQueueNode *pqueue) {
    //return the first node's priority
    return pqueue -> priority;
}

int queueLength(PQueueNode *pqueue) {
    //if the queue is empty return 0
    if (pqueue == NULL) {
        return 0;
    }
    //declare variable to hold the count
    int counter = 0;
    //find the length of the queue by looping through
    while (pqueue != NULL) {
        counter ++;
        pqueue = pqueue -> next;
    }
    //return the end count
    return counter;
}

printReverse(PQueueNode *pqueue, void (printFunction) (void*)){
    PQueueNode *counter = pqueue;
    //loop through the pqueue until the last node
    while (counter -> next != NULL) {
        counter = counter -> next;
    }

    //loop through the pqueue until the node is null using prev pointers
    //call the print function on every node and then move up the list
    while (counter != NULL) {
        printf("priority = %d data = ", counter -> priority);
        printFunction(counter -> data);
        counter = counter -> prev;
    }
}