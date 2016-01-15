//Program 2 listTestDriver.cpp
//Author: Cody Moffitt
//Date: 2-27-13
//Purpose: This driver tests the linkedlist.h implementation.

#include <iostream>
#include <string>
#include "linkedlist.h"

using namespace std;

int main()
{
//Variable and linked list declarations
bool found;
LinkedList<int> intList;
LinkedList<double> doubleList;
LinkedList<string> stringList;

cout << "intList operations:" << endl;
intList.PutItem(5);
intList.PutItem(6);
intList.PutItem(4);
intList.PutItem(4);
intList.PutItem(4);
intList.DisplayList();
intList.DeleteItem(4);
intList.DisplayList();
intList.DeleteItem(5);
intList.DisplayList();
intList.PutItem(4);
intList.PutItem(5);
intList.DisplayList();
cout << "Looking for 7: " << endl;
intList.GetItem(7, found);
if(found)
   cout << intList.GetItem(7, found) << " is in list" << endl;
else
   cout << "7 is not in list" << endl;   
   
cout << "Looking for 5: " << endl;
intList.GetItem(5, found);
if(found)
   cout << intList.GetItem(5, found) << " is in list" << endl;
else
   cout << "5 is not in list" << endl;     
intList.DeleteItem(5);
intList.DeleteItem(7);
intList.DisplayList();
intList.DeleteItem(6);
intList.DisplayList();
intList.DeleteItem(4);
intList.DisplayList();

cout << "doubleList operations:" << endl;
doubleList.PutItem(3.44);
doubleList.PutItem(1.11);
doubleList.PutItem(6.77);
doubleList.DisplayList();
doubleList.DeleteItem(1.11);
doubleList.DisplayList();
   
cout << "Looking for 8.11: " << endl;
doubleList.GetItem(8.11, found);
if(found)
   cout << doubleList.GetItem(8.11, found) << " is in list" << endl;
else
   cout << "8.11 is not in list" << endl;     
 
cout << "stringList operations:" << endl;
stringList.PutItem("cat");
stringList.PutItem("Cat");
stringList.PutItem("Dog");
stringList.DisplayList();
stringList.DeleteItem("Dog");
stringList.DisplayList();
   
cout << "Looking for cat: " << endl;
stringList.GetItem("cat", found);
if(found)
   cout << stringList.GetItem("cat", found) << " is in list" << endl;
else
   cout << "cat is not in list" << endl;   
stringList.PutItem("Aardvark"); 
stringList.PutItem("aardvark");
stringList.PutItem("Beer");
stringList.PutItem("beer");
stringList.DisplayList();
return 0;
}
