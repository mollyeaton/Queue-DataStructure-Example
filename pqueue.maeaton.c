#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pqueue.maeaton.h"


int enqueue(PQueueNode **pqueue, int priority, void *data){
    //create a temporary node to hold all of the info
    PQueueNode *newTemp = (PQueueNode*)malloc(sizeof(PQueueNode));
    //create a temporary node to hold the new next node
    PQueueNode *tempNext;
    //create a temporary node to use for counting and looping
    PQueueNode *counter = *pqueue;
    //if the pqueue is empty then set the next pointer to NULL
    if (*pqueue == NULL) {
        //assign the parameters to the temp node
        newTemp -> priority = priority;
        newTemp -> data = data;
        newTemp -> next = NULL;
        //assign the pqueue to the temp node
        *pqueue = newTemp;
    }
    //if the pqueue is not empty then you must find where to place the new node
    else {
        //if there is only one node in the p queue no need to loop through
        if ((*pqueue)->next == NULL) {
            //if the original pqueue node has a lower digit priority then it stays at the front
            //and will point TO the new node
            if ((*pqueue)->priority < priority) {
                //assign the parameters to the temp node
                newTemp->priority = priority;
                newTemp->data = data;
                newTemp->next = NULL;

                (*pqueue)->next = newTemp;
            }
                //if the original node has a higher digit priority the new node will be in the front
                //the new node will point TO the original node
            else {
                //assign the parameters to the temp node
                newTemp->priority = priority;
                newTemp->data = data;
                newTemp->next = *pqueue;
            }
        }
        //there are more than 2 nodes in the pqueue and will need to loop to find the right spot for insertion
        else {
            //the node will be inserted at the beginning
            if (priority < (*pqueue) -> priority) {
                //assign the parameters to the temp node
                newTemp->priority = priority;
                newTemp->data = data;
                newTemp->next = *pqueue;

                *pqueue = newTemp;
                return 0; //leave the function
            }
            //loop through the pqueue until the next node's priority is greater than the new node
            while (priority >=  (counter) -> next ->priority ) {
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
                //have the left node point to the inserted node
                (counter) -> next = newTemp;

            }
        }
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

