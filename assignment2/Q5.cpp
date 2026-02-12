#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffmanCodes) {
    if (!root) return;
    
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code.empty() ? "0" : code;
    }
    
    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<char> characters = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> frequencies = {5, 9, 12, 13, 16, 45};
    
    // Create a min heap of nodes
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    
    for(int i = 0; i < characters.size(); i++){
        minHeap.push(new Node(characters[i], frequencies[i]));
    }
    
    // Build Huffman Tree
    while(minHeap.size() > 1){
        Node* left = minHeap.top();
        minHeap.pop();
        
        Node* right = minHeap.top();
        minHeap.pop();
        
        Node* parent = new Node('#', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        
        minHeap.push(parent);
    }
    
    Node* root = minHeap.top();
    
    // Generate Huffman Codes
    map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);
    
    // Print Huffman Codes
    cout << "Character\tFrequency\tHuffman Code" << endl;
    for(int i = 0; i < characters.size(); i++){
        cout << characters[i] << "\t\t" << frequencies[i] << "\t\t" 
             << huffmanCodes[characters[i]] << endl;
    }
    
    return 0;
}
