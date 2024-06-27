/********************************************
 * This file contains the definition of LinkedList. 
 * A linked list contains a pointer to a Node object which 
 * is its' first item. Linked list tracks the number of nodes it 
 * contains and can report the value. It can add nodes to the list
 * and place them in the correct place based on the numerical value
 * they store. It can print the list to the terminal window. 
 *
 * Author: Cabri Chamberlin
 * Version: June 25, 2024
 *********************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {

public: 

//constructor 
LinkedList(); 

int getCurrentSize(); 

bool isEmpty(); 

void clearAll(); 

bool removeNode(int); 

void addNode(int); 

void printList(); 

Node* findByValue(int); 


private: 

Node* headPtr; 
int totalNodes; 

};

#endif