/********************************************
 * This file contains the implementation of the 
 * Node class defined in Node.h
 *
 * Author: Cabri Chamberlin
 * Version: June 25, 2024
 *********************************************/

#include <iostream> 
  using std::cout; 
  using std::endl; 
#include <ostream> 
#include "Node.h"

std::ostream& operator << (std::ostream& output, Node& myNode) {
  output << myNode.getNumber(); 
  return output; 
}

Node::Node(int value) {
  number = value; 
  next = nullptr; 
  previous = nullptr; 
}

Node::Node(int value, Node* prior, Node* following) {
  number = value; 
  next = following; 
  previous = prior; 
}

int Node::getNumber() {
  return this->number; 
}
void Node::setNumber(int newNumber) {
  number = newNumber; 
}

Node* Node::getNextNode() {
  return this->next; 
}
Node* Node::getPreviousNode() {
  return this->previous; 
}

void Node::setNextNode(Node* newLocation) {
  next = newLocation; 
}
void Node::setPreviousNode(Node* newLocation) {
  previous = newLocation; 
}
