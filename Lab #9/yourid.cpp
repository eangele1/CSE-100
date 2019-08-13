#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node {
    
    char value;
    int frequency;
    Node* left;
    Node* right;
    
    Node(char v, int num) {
        left = NULL;
        right = NULL;
        value = v;
        frequency = num;
    }
    
    ~Node() {}
    
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return (left->frequency > right->frequency);
    }
};

void print(Node* T, string s, char chars[], int size, string binary[]) {
    
    if (T == NULL){}
    
    else if (T->value == '\n') {
        print(T->left, s + "0", chars, size, binary);
        print(T->right, s + "1", chars, size, binary);
    }
    
    else {
        int i = 0;
        while(i < size) {
            if (T->value == chars[i]) {
                binary[i] = s;
            }
            i++;
        }
    }
    
}

void Huffman(int num[], char chars[], int size, string binary[]) {
    
    Node* x;
    Node* y;
    Node* z;
    
    priority_queue <Node*, vector <Node*>, compare> queue;
    
    int i = 0;
    
    while (i < size) {
        Node * temp = new Node(chars[i], num[i]);
        queue.push(temp);
        i++;
    }
    
    do {
        x = queue.top();
        queue.pop();
        
        y = queue.top();
        queue.pop();
        
        z = new Node('\n', x->frequency + y->frequency);
        z ->left = x;
        z ->right = y;
        
        queue.push(z);
    } while (queue.size() != 1);
    
    string s = "";
    print(queue.top(), s, chars, size, binary);
    
}

int main() {
    
    int arr[6];
    string binary[6];
    char chars[6];
    
    int i = 0;
    
    while (i < 6) {
        cin >> arr[i];
        i++;
    }
    
    i = 0;
    
    for(int a = 65; a < 72; a++){
        char b = (char) a;
        chars[i] = b;
        i++;
    }
    
    Huffman(arr, chars, 6, binary);
    
    i = 0;
    
    while (i < 6) {
        cout << chars[i] << ":" << binary[i] << endl;
        i++;
    }
    
    return 0;
}
