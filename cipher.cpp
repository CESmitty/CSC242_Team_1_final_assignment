#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;


// Function declarations
// The full functions are written after main
string make_cipher(string keyword);

void crypt_file(
    ifstream& in,
    ofstream& out,
    string cipher,
    bool decrypt
);


int main(int argc, char* argv[])
{
    // The program encrypts by default.
    // This changes to true if the user enters -d
    bool decrypt = false;

    // Stores the keyword entered after -k
    string keyword = "";

    // Counts how many filenames the user enters
    int file_count = 0;

    // Create streams for the input and output files
    ifstream in_file;
    ofstream out_file;


    // Check each command-line argument.
    // Start at 1 because argv[0] is the program name
    for (int i = 1; i < argc; i++)
    {
        // Store the current argument in a string
        string arg = argv[i];

        // Check if the user wants to decrypt the file
        if (arg == "-d")
        {
            decrypt = true;
        }

        // Check if the argument starts with -k
        else if (arg.length() > 2
            && arg.substr(0, 2) == "-k")
        {
            // Remove -k and store the remaining keyword
            // Example: -kFEATHER becomes FEATHER
            keyword = arg.substr(2);
        }

        // Anything else is treated as a filename
        else
        {
            file_count++;

            // The first filename is the input file
            if (file_count == 1)
            {
                in_file.open(arg);

                // Stop the program if the input file
                // could not be opened
                if (in_file.fail())
                {
                    cout << "could not open input file "
                        << arg << endl;

                    return 1;
                }
            }

            // The second filename is the output file
            else if (file_count == 2)
            {
                out_file.open(arg);

                // Stop the program if the output file
                // could not be opened or created
                if (out_file.fail())
                {
                    cout << "Could not open output file "
                        << arg << endl;

                    return 1;
                }
            }
        }
    }


    // Require the user to provide a keyword
    if (keyword.empty())
    {
        cout << "Keyword required" << endl;
        cout << "Use -k followed by the keyword." << endl;

        return 1;
    }


    // The program needs two file names
    // the input filename and the output filename
    if (file_count != 2)
    {
        cout << "Usage: " << argv[0]
            << " [-d] -kKEYWORD infile outfile"
            << endl;

        return 1;
    }


    // Create the cipher alphabet using the keyword
    string cipher = make_cipher(keyword);


    // Send the opened files, cipher alphabet
    // and selected mode to the file-processing function
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

    // Return 0 because the program finished normally
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
