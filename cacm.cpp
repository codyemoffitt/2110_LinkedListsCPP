//Program 2 cacm.cpp
//Author:  Cody Moffitt
//Date:    3-7-13
//Purpose: This program loads articles from the CACM database files into a sorted linked list.
//         It opens the CACM database file given in the command line arguments.
//         If the filename and file are valid, it loads articles into a sorted linked list.
//         It then displays a menu and lets you make several choices to manipulate or show that list.
//         You can find an article, list all articles, add a new article, remove an article, or exit.
//         The program loops until the user chooses to exit.   

#include <iostream>
#include <string>
#include <fstream>
#include "linkedlist.h"
#include "article.h"

using namespace std;

char displayMenu() //Function to display the user menu and get user input.
{
   cout << endl << endl << "What would you like to do?" << endl;
   cout << "(F)ind an article" << endl;
   cout << "(L)ist all articles" << endl;
   cout << "(A)dd a new article" << endl;
   cout << "(R)emove an existing article" << endl;
   cout << "(E)xit" << endl;
   cout << "Your choice>";
   return cin.get();
}


int main(int argc, char *argv[])
{
    ifstream inFile;              //The stream for the file we will open, it will hold the database.
    string inFileName;            //The name of the file to open.
	Article temp;                 //The article object we will temporarily use to load our database full of articles.
    string nKey, nAuthor, nTitle; //Temporarily used strings to load the article temp object's data members.
    LinkedList<Article> list;     //The linked list we will load our database of articles into.
	char menuChoice;              //The char variable which will hold the user's menu choice.
	bool found = false;           //A bool to determine if an article was found or not.
	bool exit = false;            //If the user wants to quit, this gets turned to true and breaks the program's main loop.
    

   
    if ( argc != 2 ) // We need atleast two arguments, the program name and the filename.
	{
       cout << endl << "Please enter a file name after the program. Example: "<< argv[0] <<" filename" << endl;
	   cout << "Exiting..." << endl;
	   return(0);
	}   
    else
	   inFileName = argv[1]; //If we have enough arguments, assign the 2nd argument to the file name.
	   
   inFile.open(inFileName.c_str()); //Open the file with the database in it.
   if (!inFile)                     //Check to make sure our file is valid.
   {
      cout << "File not found. Exiting..." << endl;
      return(0);
   }
   
   cout << endl << "Loading library, please wait..." << endl; //Tell the user we are loading the database. If it was huge it could take a while.
   
   while(!inFile.eof()) //Load the linked list with the articles in the database. We use the temp article and strings to do it.
   {
      getline(inFile, nKey,'\n');
	  getline(inFile, nAuthor,'\n');
	  getline(inFile, nTitle,'\n');
	  temp.Init(nKey, nAuthor, nTitle);
	  list.PutItem(temp);
   }
   
   inFile.close(); //Close the file. Please be kind, rewind.
   
   cout << endl << "Welcome to the CACM library!" << endl;
   
   //Display the menu, gather user input.
   while(!exit) //Keep running until user specifies to end it.
   {
	   menuChoice = displayMenu(); //Display menu returns the user's input.
	   
	   switch(menuChoice)
	   {
		  case 'F':case 'f':         //Find an article based on its key and display it.
			 cin.ignore(10000,'\n'); //Ignores any weird extra input from cin, so we get good strings below.
			 
			 //We get the key, load it into a string, load that into our temp article. 
			 cout << endl << "Please enter a search key: ";
			 getline(cin, nKey,'\n');
			 temp.setKey(nKey);
			 temp = list.GetItem(temp, found);
			 
			 if(found)
			 {
				cout << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << "- Record FOUND:" << endl;
				cout << "-" << endl;
				cout << "- Key: "    << temp.getKey() << endl;
				cout << "- Author: " << temp.getAuthor() << endl;
				cout << "- Title: "  << temp.getTitle() << endl;
				cout << "------------------------------------------------------------" << endl;
			 }
			 else
			 {
				cout << endl;
				cout << "-----------------------------------------------------------" << endl;
				cout << "-   Sorry, but there are no records matching your query   -" << endl;   
				cout << "-----------------------------------------------------------" << endl;      
			 }
			 
			 found = false; //Reset found, as it is used elsewhere.
			 break; //End the find case.
			 
		  case 'L': case 'l':        //Display all articles in the database.
		     cin.ignore(10000,'\n'); //Ignores any weird extra input from cin.
			 list.DisplayList();
			 cout << list.GetSize() << " records shown." << endl; //Display number of records shown.
			 break; //End the display list case.
			 
		  case 'A': case 'a': //Add an article
		     cin.ignore(10000,'\n'); //Ignores any weird extra input from cin, so we get good strings below.
			 //Load in temp variables, and temp article, so it can be inserted in the list. 
			 cout << endl;
			 cout << "Please enter the key for your new article: ";
			 getline(cin, nKey,'\n');
			 temp.setKey(nKey); //Put that key in our temp object.
			 list.GetItem(temp, found); //Search for the key in the list.
			 if(found) //Check and make sure the key is not already in use.
			 {
				 cout << endl << "This key already exists!" << endl;  
				 break; //End this case prematurely.
			 }
			 else //If it isn't in use, continue and add the object to the list.
			 {
				cout << "Enter the author's name: ";
				getline(cin, nAuthor,'\n');
				cout << "Enter the title of the article: ";
				getline(cin, nTitle,'\n');
				temp.Init(nKey, nAuthor, nTitle); //Load the user's data into the temp object.
				list.PutItem(temp); //Put the new article in the list.
				cout << endl;
				cout << "------------------------------------------------------------" << endl;
				cout << "- The following record has been added: " << endl;
				cout << "-" << endl;
			    cout << "- Key: "    << temp.getKey() << endl;
				cout << "- Author: " << temp.getAuthor() << endl;
				cout << "- Title: "  << temp.getTitle() << endl;
				cout << "------------------------------------------------------------" << endl;
			 }
			 found = false; //Reset our found variable as it is used elsewhere.
			 break; //End the add an article case.	
			 
		  case 'R': case 'r':        //Remove an article from the list.
		     cin.ignore(10000,'\n'); //Ignores any weird extra input from cin, so we get good strings below.
			 
			 //Load the key into the temp object, then search and destroy.
			 cout << endl;
			 cout << "Please enter the key of the item you wish to remove: ";
			 getline(cin, nKey,'\n');
			 temp.setKey(nKey); //Put that key in our temp object.
			 list.GetItem(temp, found); //Search for the key in the list.
			 
			 if(found) //Delete the item from the list if it is in there.
			 {
				list.DeleteItem(temp);
				cout << "------------------------------------------------------------" << endl;
				cout << "- The following record has been REMOVED: " << endl;
				cout << "-" << endl;
				cout << "- Key: " << temp.getKey() << endl;
				cout << "------------------------------------------------------------";
				break; //End this case.
			 }
			 else //If it isn't in the list, tell the user.
			 {
				cout << endl << "Article with key " << temp.getKey() << " not found." << endl;
			 }
			 found = false; //Reset our found variable as it is used elsewhere.	
             break; //End the remove an article case.	
			 
          case 'E': case 'e': //Exit the program, but display a nice message first to help the user's self esteem.
             exit = true;
			 cout << endl << "Thank you for using the CACM Library!" << endl;
             break;	//End the exit case.
		  
          default:
		     cin.ignore(10000,'\n'); //Ignores any weird extra input from cin.
             cout << endl << "Please make a valid menu choice." << endl;		  
			 
	   } //End switch statement
   } // End while statement
   
   
   return 0; //End program
}
