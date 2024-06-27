/********************************************
 * This file contains the definition of Node.
 * A node object is capable of representing a single 
 * node in a doubly linked list. A node can store a single
 * integer as a variable, as well as two pointers to 
 * the previous and next item in a the list. 
 *
 * Author: Cabri Chamberlin
 * Version: June 25, 2024
 *********************************************/

#ifndef NODE_H
#define NODE_H

#include <ostream> 


class Node {

friend std::ostream& operator << (std::ostream&, Node&);

public: 
//constructor with only value parameter
Node(int); 
//constructor with value and pointer parameters 
Node(int, Node*, Node*); 

int getNumber();
void setNumber(int); 

Node* getNextNode(); 
Node* getPreviousNode(); 

void setNextNode(Node*); 
void setPreviousNode(Node*); 


private: 
int number; 
Node* next; 
Node* previous; 

};

#endif 