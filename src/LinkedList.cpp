/********************************************
 * This file contains the implementation of the LinkedList 
 * class defined in LinkedList.h 
 *
 * Author: Cabri Chamberlin
 * Version: June 25, 2024
 *********************************************/

#include <iostream> 
  using std::cout; 
  using std::endl; 
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {
  totalNodes = 0; 
  Node* headPtr = nullptr; 
}

int LinkedList::getCurrentSize() {
  return this->totalNodes; 
}

bool LinkedList::isEmpty() {
  if (totalNodes == 0) {
    return true; 
  }
  else {
    return false; 
  }
}

void LinkedList::addNode(int newValue) {
  cout << "Attempting to add value: " << newValue << " to Linked list" << endl; 
  //case of first node being added to list 
  if (totalNodes == 0) {
    cout << "Inside if totalNodes==0 statement" << endl; 
    headPtr = new Node(newValue); 
    totalNodes++; 
  }
  //case where the node must be added to the beginning of list of existing values
  else if (headPtr->getNumber() > newValue) {
    Node* currentHeadPtr = headPtr; 
    //create new node, set headptr to location of new node 
    //set 'next' value of new node to value of old headptr (which
    //is now the second item on the list)
    headPtr = new Node(newValue, nullptr, currentHeadPtr); 
    totalNodes++; 
  }
  //case where node must be added to middle or end of list of existing values
  else if (totalNodes != 0) {
    cout << "Inside else if totalNodes != 0 statement" << endl; 
    //grab value of first node in list 
    int value = headPtr->getNumber(); 
    cout << "value is " << value << endl; 
    //grab address of next node after first node 
    Node* nextNodePtr = headPtr->getNextNode(); 
    cout << "nextNodePtr address is: " << nextNodePtr << endl; 
    while (newValue > value && nextNodePtr != nullptr) {
      cout << "inside while loop" << endl; 
      value = nextNodePtr->getNumber(); 
      cout << "the new value is: " << value << endl; 
      nextNodePtr = nextNodePtr->getNextNode(); 
    }
    //case where we have reached the end of the list and need to insert item at end
    //need to add additional statement here that causes the item to get added to list in the 
    //second to last position 
    if (nextNodePtr == nullptr) {
      cout << "inside if nextNodePtr == nullptr statement" << endl; 
      //case of insertion at end of list 
      Node* lastNodeAddress = findByValue(value); 
      Node* additionalNode = new Node(newValue, lastNodeAddress, nullptr); 
      lastNodeAddress->setNextNode(additionalNode); 
      totalNodes++; 
    }
    //case where we are in the middle of the list and need to insert new node between 
    //two existing nodes 
    else {
      //points to the node that should be on the 'right' side of the new node that
      //will be inserted if you imagine the list visually
      Node* rightSideNodePtr = nextNodePtr->getPreviousNode(); 
      //points to the node that should be on the 'left' side of the new node that 
      //will be inserted if you imagine the list visually 
      Node* leftSideNodePtr = rightSideNodePtr->getPreviousNode(); 
      //create a new Node, with value of newValue, and with pointers to the correct
      //previous and following values based on the numberical value of newValue
      Node* addedNode = new Node(newValue, leftSideNodePtr, rightSideNodePtr); 
      //update the pointers in the nodes to the left and right of the new node to point at the new node 
      //rather than each other 
      rightSideNodePtr->setPreviousNode(addedNode); 
      leftSideNodePtr->setNextNode(addedNode); 
      //increment total number of nodes
      totalNodes++; 

    }


  }
}

void LinkedList::printList() {
  //case of empty list 
  if (totalNodes == 0) {
    cout << "The list is empty" << endl; 
    return; 
  }
  //case of list that contains nodes 
  int nodeIndex = 1; 
  Node* currentNodePtr = headPtr; 
  while(currentNodePtr != nullptr) { 
    cout << "Item Number: " << nodeIndex << endl; 
    cout << "Data Value: " << *currentNodePtr << endl; 
    cout << "*****" << endl; 
    currentNodePtr = currentNodePtr->getNextNode();
    nodeIndex++; 


  }
}

Node* LinkedList::findByValue(int number) {
  cout << "Inside Find By Value Function" << endl; 
  Node* currentNodePtr = headPtr; 
  cout << "currentNodePtr value is: " << currentNodePtr << endl; 
  int value = currentNodePtr->getNumber(); 
  cout << "Value held at that node is: " << value << endl; 
  cout << "Current value to search is: " << number << endl; 
  while(currentNodePtr != nullptr) {
    cout << "inside while loop" << endl; 
    if (value == number) {
      cout << "Value and number were equal. Node located" << endl; 
      return currentNodePtr; 
    }
    currentNodePtr = currentNodePtr->getNextNode(); 
    cout << "CurrentNodePtr now has value: " << endl; 
    value = currentNodePtr->getNumber(); 

  }
  return nullptr; 
}
