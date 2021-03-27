Major Program 2: Interactive Storybook

tl;dr Students work together to create an interactive book using what they’ve learned of strings, classes, and stacks.

 

Students will create a program which takes the user through an interactive “book”. It should print the text of the pages to the screen using cout and also provide the user with some choices of what to do. The program will obtain the user’s choice through cin. The story should contain a happy ending that the user wishes to find, as well as a bad ending (such as “you died!”) that the user wishes to avoid. The user should be able to return to the previous page at any time.

 

The “book” is an array of objects of type Page. The Page type consists of a text body and an array of Choice objects. The Choice type consists of a text body and an index for the page it leads to. The reader’s active progress (what pages they have visited) should be stored in a stack so they can return to previous pages. Pages should not contain a reference to the previous page, as some pages will have multiple paths to reach them. (For instance, a “you’ve died” page)

 

The “book” needs to contain at least: a starting page, a good ending, a bad ending, 1 path to the good ending, 2 paths to the bad ending. (For a total of 6 pages) Pages should be 2-6 sentence paragraphs.

 

In addition to the above requirements, I expect students to include their own unique and interesting ideas into the program. Students should include at least one additional feature of their choice to make their book more interesting.

 

If you are having trouble coming up with something, my recommendation is some sort of persistent variable that is used throughout the book. For instance, before starting into the book you could prompt the user for their favorite color. Then, using a string variable, the book could later describe something as being their favorite color. (Ex. “The flower was a beautiful shade of [user’s favorite color]”)

 

Students cannot use the exact feature (favorite color) I described as their unique idea. It was just an example. Students are welcome to include it in their book if they really want to, but I’d like for students to come up with their own as well.

 

Students will be working in groups of two for this assignment. In industry and in other classes, students may find themselves working on very large projects in fairly large groups. Working in pairs, students will start to learn how to work collaboratively in a programming context. However, each student is ultimately responsible for the outcome of their own grade. If there are issues with group assignments, let me know early. Students may be allowed to work on their own after talking to me.

 

Topics Required

To complete this assignment, students will need to understand C++ strings, C++ classes, and stack data structures.

 

Purpose

Students completing this assignment will have demonstrated their knowledge of required topics and gained insight into collaborative programming.