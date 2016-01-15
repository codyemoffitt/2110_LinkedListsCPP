********************************************************************
**************************CACM README*******************************
********************************************************************
***********************AUTHOR: Cody Moffitt ************************      
**************************DATE: 3-7-13 *****************************
********************************************************************

     __.,,------.._
      ,'"   _      _   "`.
     /.__, ._  -=- _"`    Y
    (.____.-.`      ""`   j
     VvvvvvV`.Y,.    _.,-'       ,     ,     ,
        Y    ||,   '"\         ,/    ,/    ./
        |   ,'  ,     `-..,'_,'/___,'/   ,'/   ,
   ..  ,;,,',-'"\,'  ,  .     '     ' ""' '--,/    .. ..
 ,'. `.`---'     `, /  , Y -=-    ,'   ,   ,. .`-..||_|| ..
ff\\`. `._        /f ,'j j , ,' ,   , f ,  \=\ Y   || ||`||_..
l` \` `.`."`-..,-' j  /./ /, , / , / /l \   \=\l   || `' || ||...
 `  `   `-._ `-.,-/ ,' /`"/-/-/-/-"'''"`.`.  `'.\--`'--..`'_`' || ,
            "`-_,',  ,'  f    ,   /      `._    ``._     ,  `-.`'//         ,
          ,-"'' _.,-'    l_,-'_,,'          "`-._ . "`. /|     `.'\ ,       |
        ,',.,-'"          \=) ,`-.         ,    `-'._`.V |       \ // .. . /j
        |f\\               `._ )-."`.     /|         `.| |        `.`-||-\\/
        l` \`                 "`._   "`--' j          j' j          `-`---'
         `  `                     "`,-  ,'/       ,-'"  /
                                 ,'",__,-'       /,, ,-'
                                 Vvv'            VVv'
********************************************************************								 
  Hello! Welcome to my CACM program's README file! Please follow the
instructions below to compile, run, and use my program.
********************************************************************
********************************************************************
COMPILATION INSTRUCTIONS:
********************************************************************
  Compilation of this program is very simple. All of the header
files contain their classes function definitions. Simply make sure
that linkedlist.h, article.h, and cacm.cpp are in the same folder
before compilation.

To compile on Windows, open a Command Prompt, navigate to the folder
holding the source code files listed above and enter:

g++ -o cacm.exe cacm.cpp

Thats it!

  For compilation on other platforms, you don't need to use the .exe
extension in the above example.
********************************************************************
RUNNING THE PROGRAM:
********************************************************************
  To run the program after compilation, open a command prompt, and
navigate to the folder where you created the cacm executable file.
Place your data files (holding the CACM databases) in that same
folder.

  Run the program using:
  cacm "database filename"

  For example, if my data file is named cacmpubs.txt, I would enter:
  cacm cacmpubs.txt
  
  This will load the database in cacmpubs.txt into the program.
********************************************************************
USING THE PROGRAM:
********************************************************************
  The program will load in your specified database, then display a
menu:

What would you like to do?
(F)ind an article
(L)ist all articles
(A)dd a new article
(R)emove an existing article
(E)xit
Your choice>
  
  Make your choice by typing the letter in parantheses and then the 
enter button. You may use upper or lower case letters.


F or f: Finds and displays an article.
L or l: Lists all the articles.
A or a: Adds a new article. Prompts you for the key, name, and author.
R or r: Removes an article. Prompts you for the key of the article to 
        remove.
E or e: Exits.
