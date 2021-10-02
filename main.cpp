// Group Member: Angel Badillo
#include <iostream>
#include <fstream>
#include <string>
#include "ListStack.h"
#include "Book.h"
using namespace std;

// Reads title text from file
string readTitle(ifstream& infile);
// Reads question text from file
string readQuestion(ifstream& infile);
// Reads page text from file
string readPageText(ifstream& infile);
//Reads choice text from file
string readChoiceText(ifstream& infile);

int main()
{
    ifstream infile("TheWorld.txt");
    Book theWorld(7); // Creates a 7 page book
    
    // These strings will be replaced with the user's answers
    theWorld.setKeyVal(0, "[1]");
    theWorld.setKeyVal(1, "[2]");
    theWorld.setKeyVal(2, "[3]");
    theWorld.setKeyVal(3, "[4]");

    // Reads title text from the file, sets the title text
    theWorld.setTitle(readTitle(infile));
    
    // Reads question text in from the file, sets the question text
    for(int i = 0; i < 4; i++)
    theWorld.setQuestion(i, readQuestion(infile));
    
    // Page 0
    // Reads page text from a file, sets page text
    // Reads choice text from a file, set choice text and page index it leads to
    theWorld.setPageText(0, readPageText(infile));
    theWorld.setChoiceText(0, 0, readChoiceText(infile), 1); // Choice 0
    theWorld.setChoiceText(0, 1, readChoiceText(infile), 4); // Choice 1
    theWorld.setChoiceText(0, 2, readChoiceText(infile), 5); // Choice 2

    // Page 1
    theWorld.setPageText(1, readPageText(infile));
    theWorld.setChoiceText(1, 0, readChoiceText(infile), 5);
    theWorld.setChoiceText(1, 1, readChoiceText(infile), 2);
    theWorld.setChoiceText(1, 2, readChoiceText(infile), 5);
    
    // Page 2
    theWorld.setPageText(2, readPageText(infile));
    theWorld.setChoiceText(2, 0, readChoiceText(infile), 5);
    theWorld.setChoiceText(2, 1, readChoiceText(infile), 5);
    theWorld.setChoiceText(2, 2, readChoiceText(infile), 3);
    
    // Page 3
    theWorld.setPageText(3, readPageText(infile));
    theWorld.setChoiceText(3, 0, readChoiceText(infile), 4);
    theWorld.setChoiceText(3, 1, readChoiceText(infile), 5);
    theWorld.setChoiceText(3, 2, readChoiceText(infile), 5);

    // Page 4
    theWorld.setPageText(4, readPageText(infile));
    theWorld.setChoiceText(4, 0, readChoiceText(infile), 5);
    theWorld.setChoiceText(4, 1, readChoiceText(infile), 0);
    theWorld.setChoiceText(4, 2, readChoiceText(infile), 6);

    // Page 5
    // Reads page text from the file, sets text for bad ending
    theWorld.setBadEnding(readPageText(infile));
    // Page 6
    // Reads page text from the file, sets text for good ending
    theWorld.setGoodEnding(readPageText(infile));
    
    // "Plays" the book
    // A lot happens here, but it basically consists of
    // printing text, prompting the user, executing choices.
    theWorld.playBook();
   
    infile.close();
    return 0;
}

// Reads title text from file
string readTitle(ifstream& infile)
{
    string line = "";
    string title = "";
    while (line != "$END_OF_TITLE")
    {
        // Add each line that is read from the file
        // to the title
        title += line;
        // If the line actually contains text, add a newline
        // to the end
        if (line != "")
            title += '\n';
        // Get the next line from the file
        getline(infile, line);
    }
    return title;
}

// Reads question text from file
string readQuestion(ifstream& infile)
{
    string line = "";
    string question = "";
    while (line != "$END_OF_QUESTION")
    {
        // Add each line that is read from the file
        // to the title
        question += line;
        // If the line actually contains text, add a newline
        // to the end
        if (line != "")
            question += '\n';
        // Get the next line from the file
        getline(infile, line);
    }
    return question;
}

// Reads page text from file
string readPageText(ifstream& infile)
{
    string line = "";
    string text;
    while (line != "$END_OF_PAGE")
    {
        // Add each line that is read from the file
        // to the title
        text += line;
        // If the line actually contains text, add a newline
        // to the end
        if (line != "")
            text += '\n';
        // Get the next line from the file
        getline(infile, line);
    }
    return text;
}

// Reads choice text from file
string readChoiceText(ifstream& infile)
{
    string line = "";
    string text = "";
    while (line != "$END_OF_CHOICE")
    {
        // Add each line that is read from the file
        // to the title
        text += line;
        // If the line actually contains text, add a newline
        // to the end
        if (line != "")
            text += '\n';
        // Get the next line from the file
        getline(infile, line);
    }
    return text;
}