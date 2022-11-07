#include "ArgumentManager.h"
#include <fstream>
#include <vector>

using namespace std;



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