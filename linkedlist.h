//Program 2 linkedlist.h
//Author:  Cody Moffitt
//Date:    3-7-13
//Purpose: This is the header file for the templated LinkedList class. Its for sorted singly-linked lists.
//         It includes the function definitions, so no .cpp file is needed.

#include <iostream>

using namespace std;

template<class T>
class LinkedList
{
 public:
   //------ LinkedList OPERATIONS
   LinkedList();                   //Default Constructor
   ~LinkedList();                  //Default Destructor
   void PutItem(T item);           //Puts an item of type T in the list
   void DeleteItem(T item);        //Deletes an item that matches item of type T from the list
   void DisplayList();             //Displays the sorted list
   T GetItem(T item, bool& found); //Returns an item of type T from the list if it is found, changes value of found accordingly
   int GetSize();                  //Returns the size of the list
   
private:
   class Node //Node class. The list is composed of nodes. Fully defined below.
   {
       public:
          //DATA MEMBERS OF Node
	      T data;           //Data the node holds
	      Node *next;       //Pointer to the next node
          //Node OPERATIONS
         /* --- The Node class constructor initializes a Node's data members.

           Precondition:  None
           Receive:       dataValue, a value of type T;
           Postcondition: The data and next members have been set to
                          dataValue and 0, respectively.
         -------------------------------------------------------------------*/
         Node(T dataValue)
	     {
	        data = dataValue; 
		    next = NULL;
	     };
   }; //--- end of Node class

   //DATA MEMBERS OF LinkedList

   Node *first;
   int mySize; //Size of the linked list, incremented every time a node is added.

}; //--- end of LinkedList class


//Function definitions

// Descr: Default constructor
// Pre:	  None
// Post:  New LinkedList instance is created. mySize is set to zero, and the "first" pointer is set to null
template<class T>
LinkedList<T>::LinkedList()
{
   mySize = 0;
   first = NULL;
}

// Descr: Default destructor
// Pre:	  LinkedList has been initialized
// Post:  All nodes in list are deallocated, "first" pointer is set to null, mySize is set to 0.
template<class T>
LinkedList<T>::~LinkedList()
{
   Node *currPtr = first;
   Node *nextPtr = NULL;
   while(currPtr!= NULL)     //Delete all list elements
   {
      nextPtr = currPtr->next;
	  if(currPtr != NULL)
	     delete currPtr;
	  currPtr = nextPtr;
   }
   currPtr = NULL; //Set everything to NULL
   nextPtr = NULL;
   first = NULL;
   mySize = 0;
}


// Descr: Puts an item in the sorted list.
// Pre:	  LinkedList has been initialized.
// Post:  If its the first item added to the list, or it should be the first, it changes the "first" pointer. 
//        Otherwise it simply allocates a new item, adds it to the list in the appropriate location, and increases mySize by one.
template<class T>
void LinkedList<T>::PutItem(T item)
{
   Node* nPtr = new Node(item);
   bool found = false;
   Node* predPtr = NULL;
   Node* currPtr = first;
   while(currPtr != NULL && !found) //Iterate through list to find proper place to put the new item
   {
      if(currPtr->data > nPtr->data) //Compare items in list
	     found = true;
	  else
      {
	     predPtr = currPtr;
		 currPtr = currPtr->next;
      }
   }
      
   if (predPtr == NULL) //If the item fits in the first spot, put it there
   {
      nPtr->next = first;
	  first = nPtr;
   }   	  
   else //Place the item in the correct spot in the list
   {
	  nPtr->next = predPtr->next;
      predPtr->next = nPtr;
   }
   
   mySize++;
}

// Descr: Displays all members of the list.
// Pre:	  LinkedList has been initialized.
// Post:  Nothing is changed. The list is shown.
template<class T>
void LinkedList<T>::DisplayList()
{
   Node* currPtr = first;
   while(currPtr != NULL)
   {
      cout << currPtr->data;
      currPtr = currPtr->next;
   }
   cout << endl;
      
}


// Descr: Deallocates and deletes an item from the list.
// Pre:	  LinkedList has been initialized.
// Post:  If the node matches the item given, it is deallocated and deleted, while mySize is decreased by one. Otherwise, do nothing.
//        The item deletion won't ruin the order of the list.
template<class T>
void LinkedList<T>::DeleteItem(T item)
{

   Node* currPtr = first;
   Node* predPtr = NULL;
   Node* tempPtr = NULL;

   while(currPtr != NULL)
   {
      if(currPtr->data == item) //If we found the item
	  {
	     if(predPtr == NULL)  //If it is the first item
		 {
		    first = currPtr->next;
			delete currPtr;
			currPtr = first;
		 }	
		 else //If it is not the first item
         {
		    predPtr->next = currPtr->next;
			tempPtr = currPtr; //set a pointer to the item to be deleted
	        currPtr = currPtr->next; //increment currPtr, to continue search for next matching item
			delete tempPtr; //delete the matching item
         }	
         mySize--; //Decrement size 
      }	  
	  
	  else //Item not found, iterate through list to next item
	  {
	  predPtr = currPtr;
	  currPtr = currPtr ->next;
	  }
	  

   }
      
}

// Descr: Gets an item from the list.
// Pre:	  LinkedList has been initialized.
// Post:  If the item is found, sets found to true and returns a copy of that item. If not, sets found to false and returns a copy of the original item.
template<class T>
T LinkedList<T>::GetItem(T item, bool& found)
{
   Node *currPtr = first;
   T copyOfItem;
   found = false;
   while(currPtr != NULL && !found) //Iterate through list until item is found
   {
      if(currPtr->data == item)
	  {
	     found = true;
		 copyOfItem = currPtr->data; //Copy the found item
	  }
      
	  currPtr = currPtr->next; //iterate through list
   }
   return copyOfItem;
}

// Descr: Gets the size of the list.
// Pre:	  LinkedList has been initialized, which should initialize mySize as well.
// Post:  Returns mySize. Doesn't change anything.
template<class T>
int LinkedList<T>::GetSize()
{
   return mySize;
}

