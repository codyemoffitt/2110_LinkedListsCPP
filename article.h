//Program 2 article.h
//Author:  Cody Moffitt
//Date:    3-7-13
//Purpose: This is the header file for the article class. It will hold each CACM article's information.
//         It includes the function definitions, so no .cpp file is needed.

#include <iostream>
#include <string>

using namespace std;

class Article
{
   public:
      Article();      
      Article(string nKey, string nAuthor, string nTitle);
	  void Init(string nKey, string nAuthor, string nTitle);        //Reassigns all private members of the article class
	  string getKey();                                              //Returns the article's key
	  void setKey(string nKey);                                     //Sets the article's new key
	  string getAuthor();                                           //Returns the article's author as a string
	  void setAuthor(string nAuthor);                               //Sets the article's author
	  string getTitle();                                            //Return's the article's title as a string
	  void setTitle(string nTitle);                                 //Set's the article's new title
      friend bool operator>(const Article& a, const Article& b);    //Overload the > operator so it knows how to compare article objects 
	  friend bool operator==(const Article& a, const Article& b);   //Overload the == operator so it knows how to compare article objects 
	  friend ostream& operator<<(ostream& out, const Article& a);   //Overload the << operator so we can display article objects easily
   private:
      string key;                                                   //The article's unique key
	  string author;                                                //The article's author
	  string title;                                                 //The article's title
};

// Descr: Default constructor
// Pre:	  None
// Post:  New Article instance is created. Nothing is initialized.
Article::Article()
{
}

// Descr: Another constructor
// Pre:	  None
// Post:  New Article instance is created. All private data members are intialized.
Article::Article(string nKey, string nAuthor, string nTitle)
{
   key = nKey;
   author = nAuthor;
   title = nTitle;
}

// Descr: Reassigns the values of all the private data members.
// Pre:	  Article class is initialized.
// Post:  key, author, and title are set to new values.
void Article::Init(string nKey, string nAuthor, string nTitle)
{
   key = nKey;
   author = nAuthor;
   title = nTitle;
}

// Descr: Gets the key of the article.
// Pre:	  Article class is initialized, key is initialized.
// Post:  Returns the key, changes nothing.
string Article::getKey()
{
   return key;
}

// Descr: Gets the author of the article.
// Pre:	  Article class is initialized, author is initialized.
// Post:  Returns the author, changes nothing.
string Article::getAuthor()
{
   return author;
}

// Descr: Gets the title of the article.
// Pre:	  Article class is initialized, title is initialized.
// Post:  Returns the title, changes nothing.
string Article::getTitle()
{
   return title;
}

// Descr: Sets the key of the article.
// Pre:	  Article class is initialized.
// Post:  Sets the key to a new given key.
void Article::setKey(string nKey)
{
   key = nKey;
}

// Descr: Sets the author of the article.
// Pre:	  Article class is initialized.
// Post:  Sets the author to a new given author.
void Article::setAuthor(string nAuthor)
{
   author = nAuthor;
}

// Descr: Sets the title of the article.
// Pre:	  Article class is initialized.
// Post:  Sets the title to a new given title.
void Article::setTitle(string nTitle)
{
   title = nTitle;
}

// Descr: Overload the > operator to compare articles based on their key.
// Pre:	  Both article classes are initialized, as well as their keys.
// Post:  Returns a "more than" comparison of their keys. Allows alphabetization of articles in a LinkedList class.
bool operator>(const Article& a, const Article& b)
{
   return(a.key>b.key);
}

// Descr: Overload the == operator to compare articles based on their key.
// Pre:	  Both article classes are initialized, as well as their keys.
// Post:  Returns true if the keys are the same, false otherwise.
bool operator==(const Article& a, const Article& b)
{
   return(a.key==b.key);
}

// Descr: Overload the << operator to display an article.
// Pre:	  The article and its private data members are initialized.
// Post:  Changes nothing, just displays the article info to whatever ostream is specified.
ostream& operator<<(ostream& out, const Article& a)
{
   out << endl;
   out << "------------------------------------------------------------" << endl;
   out << "- Key: "    << a.key    << endl;
   out << "- Author: " << a.author << endl;
   out << "- Title:  " << a.title  << endl;
   out << "------------------------------------------------------------" << endl;
   return out;
}