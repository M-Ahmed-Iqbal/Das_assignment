#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include<fstream>
using namespace std;

struct HuffNode {
    char character;
    int frequency;
    HuffNode* left, * right;
    HuffNode(char character, int frequency) {
        this->character = character;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    }
};

void generateHuffman(HuffNode* root, vector<string>& codes, string temp) {
    if (!root)
        return;
    if (!root->left && !root->right) {
        codes[root->character] = temp;
        return;
    }
    generateHuffman(root->left, codes, temp + '0');
    generateHuffman(root->right, codes, temp + '1');
}

struct CompareHuffNodes : public binary_function<HuffNode*, HuffNode*, bool> {
    bool operator()(const HuffNode* lhs, const HuffNode* rhs) const {
        return lhs->frequency > rhs->frequency;
    }
};

string encodeHuffman(string input) {
    vector<int> freq(128);
    for (char ch : input) {
        freq[ch]++;
    }

    priority_queue<HuffNode*, vector<HuffNode*>, CompareHuffNodes> pq;
    for (int i = 0; i < 128; ++i) {
        if (freq[i] > 0) {
            HuffNode* newNode = new HuffNode(i, freq[i]);
            pq.push(newNode);
        }
    }

    HuffNode* left, * right, * root;
    while (pq.size() > 1) {
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        root = new HuffNode('$', left->frequency + right->frequency);
        root->left = left;
        root->right = right;
        pq.push(root);
    }

    vector<string> huffCodes(128);
    generateHuffman(pq.top(), huffCodes, "");

    string encodedString = "";
    for (char ch : input) {
        encodedString += huffCodes[ch];
    }

    return encodedString;
}

int main()
{//testing on string
    string txt = "abc";
    cout << encodeHuffman(txt) << endl;
    //testing on files
    string text = "";
    fstream inFile("input.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file!";
        return 1;
    }


    string line;
    while (getline(inFile, line)) {
        text += line;
    }
    inFile.close();

    string codedData = encodeHuffman(text);


    ofstream outFile("Output.txt");
    if (outFile.is_open())
    {
        outFile << codedData;
        outFile.close();
    }
    else
        cout << "File is not open" << endl;
    
}