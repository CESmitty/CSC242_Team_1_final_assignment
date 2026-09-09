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
