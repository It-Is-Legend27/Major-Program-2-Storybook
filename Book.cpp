#include "Book.h"

// Intializes values
Book::Choice::Choice()
{
    text = "Choice Text\n"; // Placeholder text
    int index = -99; // default value ("closes" book)
}

// Intitializes values
Book::Page::Page()
{
    numChoices = 0;
    text = "Page Text\n"; // Placeholder text
    choices = nullptr;
}

// Creates choice arrays of size nC
void Book::createChoiceArray(int p, int nC)
{
    book[p].numChoices = nC;
    book[p].choices = new Choice[nC];
    
    // Essential menu choices
    book[p].choices[nC - 3].text = to_string(nC - 2) + ". Return to the previous page\n";
    book[p].choices[nC - 3].index = -1;
    book[p].choices[nC - 2].text = to_string(nC - 1) + ". Start from the beginning\n";
    book[p].choices[nC - 2].index = -2;
    book[p].choices[nC - 1].text = to_string(nC) + ". Close the interactive book\n";
    book[p].choices[nC - 1].index = -3;
}

// Constructs book of 6 or more pages
Book::Book(int nP)
{
    // Book must be 6 pages or more
    if (nP < 6)
    {
        nP = 6;
    }
        title = "Title Text\n\n\n"; // Placeholder text

        // 4 questions,  4 answers, and the 4 key values
        numQA = 4;
        question = new string[numQA];
        answer = new string[numQA];
        keyVal = new string[numQA];


        for (int i = 0; i < numQA; i++)
        {
            question[i] = "Question Text\n\n"; // Placeholder text
            answer[i] = "Answer Text"; // Placeholder text
            keyVal[i] = "KeyVal"; // Placeholder text
        }

        numPages = nP;
        book = new Page[nP];
        prevPage = new ListStack;
        
        // Creates choice arrays of 6 choices 
        // (last 3 choices are menu options)
        for(int i = 0; i < (numPages - 2); i++)
        {
            createChoiceArray(i, 6);
        }

        // Creates choice arrays of 3 choices 
        // (endings only allow you to use menu options)
        for (int i = numPages-1; i > (numPages - 3); i--)
        {
            createChoiceArray(i, 3);
        }
}

// Deallocates arrays
Book::~Book()
{
    // Deletes question, answer, key value arrays
    delete[] question;
    delete[] answer;
    delete[] keyVal;

    // Deletes array of choices in every page
    for (int p = 0; p < numPages; p++)
    {
        delete[] book[p].choices;
    }
    
    // deletes the array of pages
    delete[] book;

    // Deletes stack
    delete prevPage;
}

// Sets title text
void Book::setTitle(string t)
{
    title = t;
}

// Sets question text
void Book::setQuestion(int q, string t)
{
    if (!outOfBounds(q, numQA))
    {
        question[q] = t;
    }
    else
    {
        cerr << "\n<Error: Invalid argument.>"
            << "\n<Method: Book::setQuestion>\n\n\a";
    }
}

// Prints title text
void Book::printTitle()
{
    cout << title;
}

// Prints question text
void Book::printQuestion(int q)
{
    if (!outOfBounds(q, numQA))
    {
        cout << question[q];
    }
    else
    {
        cerr << "\n<Error: Invalid argument.>"
            << "\n<Method: Book::printQuestion>\n\n\a";
    }
}

// Sets key value
void Book::setKeyVal(int k, string t)
{
    if (!outOfBounds(k, numQA))
    {
        keyVal[k] = t;
    }
    else
    {
        cerr << "\n<Error: Invalid argument.>"
            << "\n<Method: Book::setQuestion>\n\n\a";
    }
}

// Prompts user for answer to intro questions
string Book::promptAnswer()
{
    string answer;
    cout << "> ";
    getline(cin, answer); // Reads in an entire line
    return answer;
}

// Stores user's answers
void Book::setAnswer(int q, string t)
{
    answer[q] = t;
}

// "Plays" introduction
// Prints title text, question text, prompts for user, stores answer
void Book::playIntro()
{
    printTitle();
    cout << "\n\n";
    for (int q = 0; q < numQA; q++)
    {
        printQuestion(q);
        setAnswer(q, promptAnswer());
    }
    cout << string(300, '\n');
}

// Sets the page text
void Book::setPageText(int p, string t)
{
    if (!outOfBounds(p, numPages))
    {
        book[p].text = t;
    }
    else
    {
        cerr << "\n<Error: Invalid arguments.>"
            << "\n<Method: Book::setPageText>\n\n\a";
    }

}

// p is page number, c is choice number, t is text, i is index
// Sets choice text
void Book::setChoiceText(int p, int c, string t, int i)
{
    // Prevents going out-of-bounds
    if (!(outOfBounds(p, numPages) && outOfBounds(c, book[p].numChoices) && outOfBounds(i, numPages)))
    {
        // Cannot modify last 3 choices as they are essential
        if ((c != book[p].numChoices - 1) && (c!= book[p].numChoices - 2) && (c!= book[p].numChoices - 3))
        {
            book[p].choices[c].text = t;
            book[p].choices[c].index = i;
        }
        else
        {
            cerr << "\n<Error: Cannot modify the last 3 choices.>"
                << "\n<Method: Book::setPageChoice>\n\n\a";
        }
    }
    else
    {
        cerr << "\n<Error: Invalid arguments.>"
            << "\n<Method: Book::setPageChoice>\n\n\a";
    }
}

// Sets text for good ending
void Book::setGoodEnding(string t)
{
    book[numPages - 1].text = t;
}

// Sets text for bad ending
void Book::setBadEnding(string t)
{
    book[numPages - 2].text = t;
}

// Prints page
void Book::printPage(int p)
{
    if (!outOfBounds(p, numPages))
    {
        string temp = book[p].text;
        for (int i = 0; i < numQA; i++)
        {
            temp = replace_all(temp, keyVal[i], answer[i]);
        }
        cout << temp;

        // Prints out every choice in the page
        for (int c = 0; c < book[p].numChoices; c++)
        {
            cout << book[p].choices[c].text;
        }
    }
    else
    {
        cerr << "\n<Error: Invalid argument.>"
            << "\n<Method: Book::printPage>\n\n\a";
    }  
}

// Prompts user for choice
int Book::promptChoice(int p)
{
    cout << "Enter your choice:> ";
    
    int userChoice;
    cin >> userChoice;
    cin.ignore(); // prevents issues from switching to cin to getline

    // Data-validation
    while (userChoice > book[p].numChoices || userChoice < 1)
    {
        cout << string(300, '\n');
        cerr << "Invalid choice.\n";
        Book::printPage(p);
        cout << "Enter your choice:> ";
        cin >> userChoice;
        cin.ignore();
    }
    return userChoice;
}

// Puts user's choice into execution
void Book::executeChoice(int p, int c)
{
    // Returns to previous page
    if (book[p].choices[c - 1].index == -1)
    {
        if (!prevPage->empty())
        {
            cout << string(300, '\n');
            playPage(prevPage->pop());
        }
        // If stack is empty, just start at the first page again
        else
        {
            cout << string(300, '\n');
            playPage(0);
        }
    }
    // Restarts the book
    else if (book[p].choices[c - 1].index == -2)
    {
        delete prevPage;
        prevPage = new ListStack;
        cout << string(300, '\n');
        playBook();
    }
    
    // Closes the book
    else if (book[p].choices[c - 1].index == -3)
    {
        return; // Stops "playing" the book (returns to main function)
    }
    // Progression choices
    else
    {
        prevPage->push(p);
        cout << string(300, '\n');
        playPage(book[p].choices[c - 1].index);
    }
}

// "Plays" a page
void Book::playPage(int p)
{
    printPage(p);
    int c = promptChoice(p);
    executeChoice(p, c);
}

// "Plays" the book
// Essentially, prints text, prompts user, executes choice
void Book::playBook()
{
    playIntro();
    playPage(0);
}

// Checks to see if out-of-bounds
bool Book::outOfBounds(int i, int sz)
{
    return i < 0 || i > sz;
}

// Replaces a key value in a string to a user's answer
string Book::replace_all(string text, string from, string to)
{
    size_t start_pos = 0;
    // While we can find the substring "from"
    // (start position changes each time we make a replacement)
    while ((start_pos = text.find(from, start_pos)) != string::npos)
    {
        // Make the replacement
        text.replace(start_pos, from.length(), to);
        // Move past the string replacement's length, we don't need to
        // check it
        start_pos += to.length();
    }
    return text;
}