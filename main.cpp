#include "ArgumentManager.h"
#include <fstream>
#include "Command.h"
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

PriorityQueue parseData(vector<string> lines) {
    PriorityQueue q;
    for (int i = 0; i < lines.size(); i++) {
        string line = lines.at(i);
        int cmdIndex = line.find(":");
        string cmd = line.substr(0, cmdIndex);
        int dataIndex = line.find("[");
        int endDataIndex = line.find("]");
        string data = line.substr(dataIndex+1, endDataIndex-dataIndex-1);
        int numIndex = line.find("(");
        int endNumIndex = line.find(")");
        int num = stoi(line.substr(numIndex+1, endNumIndex-numIndex-1));
        q.push(cmd, data, num);
    }
    return q;
}

int main(int argc, char* argv[]) {

    ArgumentManager am(argc, argv);
    string input = am.get("input");
    string output = am.get("output");

    ifstream ifs(input);
    ofstream ofs(output);

    string line;
    vector<string> lines;   
    string traversal;
    while(getline(ifs, line)) {
        if (line.find(':') == string::npos) {
            traversal = line; // should always be last line so it's safe to break
            break;
        }
        lines.push_back(line);
    }

    BST tree;
    tree.insertNode("HELLO WORLD");
    tree.insertNode("TESTING");
    tree.insertNode("sdjkhfajkfhjkfhjksadfhjiwdfhkjlfds");
    std::cout << tree.getRoot()->data;
    std::cout << tree.getRoot()->left->data;
    tree.inOrderTraversal(tree.getRoot());

    // PriorityQueue q = parseData(lines); // Gets correct data to push into priority queue
    // // cout << endl;
    // // // Testing priority queue
    // // while (!q.isEmpty()) {
    // //     node* temp = q.pop();
    // //     std::cout << temp->command << " " <<  temp->priority << std::endl;
    // // }

    // commands(q);

    return 1;
}