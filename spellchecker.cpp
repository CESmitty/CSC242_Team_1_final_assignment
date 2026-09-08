#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Open words.txt from the local project repository folder
    ifstream dict_file("words.txt");
    if (dict_file.fail()) {
        cout << "Error: Could not open dictionary file words.txt." << endl;
        cout << "Make sure words.txt is present in the working directory." << endl;
        return 1;
    }

    vector<string> words;
    string word;

    while (dict_file >> word) {
        words.push_back(word);
    }
    dict_file.close();

    string filename;
    cout << "Enter the name of the file to check: ";
    cin >> filename;

    ifstream check_file(filename);
    if (check_file.fail()) {
        cout << "Error: Could not open file " << filename << endl;
        return 1;
    }

    cout << "\nWords not found in dictionary:" << endl;

    while (check_file >> word) {
        if (find(words.begin(), words.end(), word) == words.end()) {
            cout << word << endl;
        }
    }

    check_file.close();
    return 0;
}
