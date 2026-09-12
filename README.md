# CSC242_Team_1_final_assignment
# Instructions

## Background
This is a group project. Teamwork and collaboration will be essential in completing this assignment. All team members must actively participate in the group meetings, remain in communication with other team members, and contribute to the design and implementation of the solution. 

* **Group Size:** Each group must consist of no more than three members. You may contact other classmates and form your own three-member group. Otherwise, your instructor will assign students to groups.
* **Group Lead:** One team member should act as a lead and inform the instructor of the formation of your group.
* **Course Objective:** In this Signature Assignment, you will demonstrate your mastery of C++ concepts covered in the course (*150 points for the programming*).
* **Peer Evaluation:** Please note that each member will be peer evaluated by the other team members according to the teambuilding criteria. The average peer evaluation scores from the other team members will be used as your grade (*100 points for peer evaluation*).

---

## Problem Set
Complete the following programming projects under **Chapter 8. Streams – End-of-Chapter Exercises - Programming Projects - P8.2, P8.7** from the textbook *Big C++: Late Objects, Enhanced*.

### Problem 1: P8.2 (Spell Checker)
Write a program that checks the spelling of all words in a file. It should read each word of a file and check whether it is contained in a word list. 

A word list is available on most UNIX systems (including Linux and macOS) in the file `/usr/share/dict/words`. (If you don’t have access to a UNIX system, you can find a copy of the file on the Internet by searching for `/usr/share/dict/words`.) The program should print out all words that it cannot find in the word list. 

Follow this pseudocode:
1. Open the dictionary file.
2. Define a `vector` of strings called `words`.
3. For each word in the dictionary file:
   * Append the word to the `words` vector.
4. Open the file to be checked.
5. For each word in that file:
   * If the word is not contained in the `words` vector:
     * Print the word.

### Problem 2: P8.7 (Random Monoalphabet Cipher)
The Caesar cipher, which shifts all letters by a fixed amount, is far too easy to crack. Here is a better idea. As the key, don’t use numbers but words. Suppose the key word is **FEATHER**. Then first remove duplicate letters, yielding **FEATHR**, and append the other letters of the alphabet in reverse order.

Write a program that encrypts or decrypts a file using this cipher. For example:
`crypt -d -kFEATHER encrypt.txt output.txt`

This decrypts a file using the keyword `FEATHER`. It is an error not to supply a keyword.

---

## Implementation Guidelines
1. **Task Delegation:** After analyzing the problem and specifications described in the problem, the team must break down the problem into smaller tasks and write a function to implement each task. Be sure each member is responsible for the implementation of at least one function.
2. **Project Setup:** Create C++ projects in Visual Studio for each problem and translate your solution to a working program.
3. **Documentation:**
   * Ensure that a comment header (based on the template provided under Learning Resources) is included at the top of your `.cpp` file.
   * Use descriptive in-line comments that follow conventions described in the reading throughout your code.
   * Each code segment in the program must clearly indicate the name of the team member who authored that segment.

---

## Submission Requirements
* **Individual Submission:** Each team member must submit the group project separately and list the names of other team members in the submission file.
* **Archive Format:** Create a single `.zip` file containing your Visual Studio project folder and pseudocode document.
* **Naming Convention:** Name the `.zip` file using the following format: `FirstNameAssignmentNumber` (e.g., `SmithJohnAssignment5`).
* **Peer Evaluation:** Each team member must submit the completed peer evaluation form separately.
