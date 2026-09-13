/* ---------------------------------------------------------------------------
 I attest that this following code represents my own work and is subject to
 the plagiarism policy found in the course syllabus.

 Class:     CSC 242
 Assignment:     Lesson #4
 File:     Cipherproj.cpp
 Description: This program will Encrypt and Decrypt files, choose a keyword of your choice and follow the instructions.
 I suggest using input.txt as a test file as it is already in the directory ready to encypt
 Author:      Clayton Smith, Christiaan Blondeeltimmerman, David Garcia
 Date:     9/9/2026
 ** -------------------------------------------------------------------------*/   
#include <iostream> // for cout and cin
#include <fstream> // allows us to open, read and write files
#include <string> // allows us to use string variables
#include <cctype> //allows to check and change letters.

using namespace std;


string make_cipher(string keyword);
void crypt_file(
    ifstream& in,
    ofstream& out,
    string cipher,
    bool decrypt
);

int main()
{      // starts the program in encryption mode
    bool decrypt = false;
    // holds the users choice
    char choice;
    //holds the keyword and file names
    string keyword;
    string input_name;
    string output_name;
    // ask user which operation they want to use
    cout << "Enter E to encrypt or D to decrypt: ";
    cin >> choice;
    // change to decrypt is D is entered
    if (choice == 'D' || choice == 'd')
    {
        decrypt = true;
    }    // stay in encryption mode if E is entered
    else if (choice == 'E' || choice == 'e')
    {
        decrypt = false;
    }
    else    // stop if neither E or D is entered
    {  
        cout << "Invalid selection." << endl;
        return 1;
    }
    //Ask for the keyword
    cout << "Enter the keyword: ";
    cin >> keyword;

    if (keyword.empty())
    {    // stop if there is no keyword
        cout << "Keyword required." << endl;
        return 1;
    }
        // get the name of the files from user
    cout << "Enter the input filename: ";
    cin >> input_name;
    // open original file
    cout << "Enter the output filename: ";
    cin >> output_name;

    ifstream in_file(input_name);
    // stop if file could not be opened
    if (in_file.fail())
    {
        cout << "Could not open input file "
            << input_name << endl;
        return 1;
    }
    //open or create the file that will hold the end result
    ofstream out_file(output_name);

    if (out_file.fail())
    {    // stop if output couldnt be created
        cout << "Could not open output file "
            << output_name << endl;
        return 1;
    }
        // send files and cipher to the function that decrypts or encrypts
    string cipher = make_cipher(keyword);

    crypt_file(
        in_file,
        out_file,
        cipher,
        decrypt
    );

    // Close the files after encryption or decryption
    in_file.close();
    out_file.close();

    cout << "Operation successful." << endl;

   
    return 0;
}

void crypt_file(ifstream& in, ofstream& out, string cipher, bool decrypt )
    { 
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Reads the file character by character
    char ch; // variable to hold each character as they're being read

    // Reads one character from the input file and stores it in ch
    while (in.get(ch)) // keeps looping until there are no more characters left to read
    {
        if (isalpha(ch)) // Checks if a character is a letter
        {
            // Converts to upper case for lookup
            char upperCh = toupper(ch);

            char newCh; // Will hold the encrypted/decrypted character

            if (decrypt)
            {
                // Decrypt: finds letter in the cipher alphabet and replaces it with the normal alphabet 
                int pos = cipher.find(upperCh); // Finds the letter in the cipher alphabet and gets its position
                newCh = alphabet[pos]; // Finds the corresponding position and letter in the normal alphabet
            }
            else
            {
                // Encrypt: finds position of letter in normal alphabet and replaces it with cypher alphabet
                int pos = alphabet.find(upperCh); // Finds letter in the normal alphabet and gets its position
                newCh = cipher[pos]; // Finds corresponding position and letter in the cipher alphabet
            }

            if (islower(ch)) // Checks if the og character was lowercase
            {
                newCh = tolower(newCh); //converts the new character to lowercase
            }

            out << newCh; // Writes the new character to the output file
        }
        else
        {
            out << ch; // Writes the original character unchanged (for spaces,  numbers, punctuation)
        }
    }
}


string make_cipher(string keyword)
{ 
    string cipher = ""; // Creates an empty string that will hold the final cipher alphabet

    // Adds unique letters from keywords
    for (int i = 0; i < keyword.length(); i++) //Loops through each character in the keyword
    {
        char ch = toupper(keyword[i]); // Converts current character to uppercase
        if (cipher.find(ch) == string::npos) // Searches cipher string for the character ch, returns the position if found or string::npos if not found
        {
            cipher = cipher + ch; // Adds the character to cipher string
        }
    }

    // Will add the rest of the alphabet in reverse order
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Creates a string with all letters of the alphabet
    for (int i = 25; i >= 0; i--) // Loops backwards from 25 (Z) to 0 (A)
    {
        char ch = alphabet[i]; // Gets character at position i in the alphabet
        if (cipher.find(ch) == string::npos) // Checks if the character is not already in the cipher
        {
            cipher = cipher + ch; // Adds the character to the cipher string
        }
    }

    //Return statement
    return cipher;
}
