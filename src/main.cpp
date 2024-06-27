/********************************************
 * This file contains only the main function of the program. 
 * the main function makes calls to functions in the LinkedList
 * and Node classes in order to test them. 
 *
 * Author: Cabri Chamberlin
 * Version: June 25, 2024
 *********************************************/

#include <iostream> 
    using std::cout; 
    using std::endl; 
#include "Node.h"
#include "LinkedList.h"

int main() {

//create an instance of LinkedList 
LinkedList myList = LinkedList(); 

//test isEmpty function on empty list 
cout << myList.isEmpty() << endl; 

//test printList function on empty list 
myList.printList(); 

//test creation of new nodes and cout for nodes 
Node* testPtr = nullptr; 
testPtr = new Node(3); 
cout << *testPtr << endl; 

//add new nodes to myList
myList.addNode(1); 
myList.addNode(5); 
myList.addNode(9);
myList.addNode(7); 
myList.addNode(16); 
myList.addNode(19); 
myList.addNode(25); 
myList.addNode(2); 

//add 10 to the list using the addNode function 
myList.addNode(10); 

//test printList function on populated list 
myList.printList(); 

//test isEmpty function on populated list 
cout << myList.isEmpty() << endl; 

//test getCurrentSize function on populated list 
cout << "Currently there are: " << myList.getCurrentSize() << " items in the list" << endl; 


return 0; 

}