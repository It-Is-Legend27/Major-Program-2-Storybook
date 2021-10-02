#pragma once
#include <iostream>
#include <string>
#include "ListStack.h"
using namespace std;

class Book
{
public:
    Book(int sz); // Constructor creates 6 pages or more
    ~Book(); // Deallocates all dynamic arrays and deletes stack
    void setTitle(string t); // Sets title text
    void printTitle(); // Prints title
    void setQuestion(int q, string t); // Sets question text
    void printQuestion(int q); // Prints a question
    void setKeyVal(int k, string t); // Sets key values that will be replaced by user's answers
    void setPageText(int p, string t); // Sets the page text
    void setChoiceText(int p, int c, string t, int i); // page number, choice number, text, index
    void setGoodEnding(string t); // Sets text for good ending (choices are predefined)
    void setBadEnding(string t); // Sets text for bad ending (choices are predefined)
    void printPage(int p); // Prints page contents
    void playBook(); // Plays the book from the beginning
private:
    void playIntro(); // Plays the intro
    string promptAnswer(); // Prompts user to answer intro question
    void playPage(int p); // Plays the book starting at a specific page
    void setAnswer(int a, string t); // Stores an intro answer
    int promptChoice(int p); // Prompts user to enter a choice
    void executeChoice(int p, int c); // Executes the choice
    bool outOfBounds(int i, int sz); // Returns false if in-bounds, true if out-of-bounds
    string replace_all(string text, string from, string to); // Replaces all key values with answers
    void createChoiceArray(int p, int nC); // Creates choice arrays for the pages
    class Choice
    {
    public:
        Choice();
        string text; // Choice text
        int index; //Index choice leads to
    };
    class Page
    {
    public:
        Page();
        string text; // Page text
        Choice* choices; // Array of choices
        int numChoices;
    };
    string title;
    string* question; // Questions that will be asked at the start
    string* answer; // User's answers to the questions
    string* keyVal; // Placeholders that will be replaced with the user's answers
    int numQA; // number of question and answers
    Page* book; //Array of pages
    int numPages; // Number of pages
    ListStack* prevPage; // Stores progress as page indeces
};