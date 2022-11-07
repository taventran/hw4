#include "ArgumentManager.h"
#include <fstream>
#include <vector>

using namespace std;

// TO DO
// Make Priority Queue that holds everything from .txt file
// Make regular Queue that holds strings that requires decoding
// Make replace function 
// Make add function
// Make remove function
// Make swap function
// Make BST 

int main(int argc, char* argv[]) {

    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    ifstream ifs(input);
    ofstream ofs(output);

    string line;
    vector<string> lines;

    while(getline(ifs, line)) {
        lines.push_back(line);
    }



    return 1;
}