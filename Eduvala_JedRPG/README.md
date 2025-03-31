[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Jed Eduvala`  
### **Student ID:** `828099214`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

My game gives the user a main option of choosing a smaller boat leading to a foggy island or a larger boat leading to a volcanic island.

Depending on the option you choose you are presented two different pathways but they both lead to the same outcome.

Once you reach the end for either pathway you will be presented with a text saying you have found all the clues to find the desired One Piece treasure located on the final island.

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `loads the story and starts the game prompting the user with the first set of choices.`  
- **`GameDecisionTree.h`** → `controls how the game will interact with the user after they have entered their input`  
- **`Node.h`** → `Generic Node class that stores one story event and has pointers leading to the next portion of the story`  
- **`Story.h`** → `holds the details of each event used in my game`  
- **`story.txt`** → `Contains the two choices a user is presented along with values that determine what will happen next. A value of -1 indicates that the path is over and will you have arrived at the final destination. All nodes are linked and lead to the same outcome which is the clues leading to the One Piece.`  



---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
- How are nodes linked based on left and right event numbers?  
- What happens if an event has `-1` as left or right children?  

Each node contains a different part of my game's story with different options leading to different outcomes. The decision tree found in my story.txt file is split using delimitirs between  the desc and the two different options.

The nodes are linked together using their left and right children which you can also call the 1st and 2nd option you are presented after making your previous choice.

An event ending in -1 ultimately means that the path or choice you decided on brought you to the end of a path with no more additional choices for you to make.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
- What happens when the player reaches a leaf node?  
- Explain the special case where multiple events lead to the same outcome.  

The user's path is determined by their input when presented between 2 options.

When a player reaches a leaf node the game is over and there is no more additional choice for the user to make.

Regardless of the path that the user takes whether they boarded the Going Merry or the Thousand Sunny, they will end up finding the clues that lead to the One Piece treasure. Of course the paths will differ based on the decisions the user makes but they will all circle back to the desired ending.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
- How do you ensure nodes are properly linked?  
- Any challenges faced while handling file input?  

The file is read line by line and each node's ID, text, and options are seperated using a delimiter ( | ), 

By using a Map/Dictionary it is easy to store and keep track of the parent nodes as well as there left and right children.

One challenge I faced while handling the file input was when I tried running the main file to test my code but kept receiving an error since my story.txt file had a missing input preventing my code from running.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

Initially my code would run without fail, but no matter which option I picked I kept getting the same result. I had to go through my code and realized I was missing a few parentheses in key areas of my code which kept making my code go in circles until I fixed it.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)

You wash ashore on the first island, clutching a torn map. Two boats wait.
1. You take the smaller boat called the Going Merry to the misty island.
2. You sail the larger boat called the Thousand Sunny to the volcanic island.
> 1

You take the smaller boat called the Going Merry to the misty island.
1. The mist clears and reveals a hidden path to the secret Amazon Lily island.
2. You row around the island and find a cave entrance.
> 2

You row around the island and find a cave entrance.
1. Inside the cave, you discover symbols matching your map.
2. The cave narrows, revealing a buried shipwreck.
> 1

Inside the cave, you discover symbols matching your map.

All clues point to the final island — the One Piece treasure awaits.


---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(n or 1)`  
- **Game traversal efficiency** → `O(height)`  

Loading the tree from the file has a big O, O(n). Each line is read storing info in a map and then is looped once more linking the child nodes. Ultimately the operations are linear and will be dependent on the number of events contained in the pathway you choose.

When searching for an event in the tree the Big O is either O(1) or O(n). This is based on whether or not you have a map to go off of allowing you to locate the event quickly, but if you don't you will need to iterate through the game n times in order to find the event.

Game traversal efficiency would be O(h) since it is based on the height of the tree.

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

I tested what would happen if I entered a number besides the ones given to me like "3". In my code I added a section that prompted me with a text saying "Invalid, enter choice". This allowed me to give another input without having to restart the program.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)

Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
