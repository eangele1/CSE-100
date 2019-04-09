#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node* parent;
};

void Inorder_Tree_Walk(Node* &T){
    if (T != NULL) {
        Inorder_Tree_Walk(T->left);
        cout << T->data << endl;
        Inorder_Tree_Walk(T->right);
    }
}

void Preorder_Tree_Walk(Node* &T){
    if (T != NULL) {
        cout << T->data << endl;
        Preorder_Tree_Walk(T->left);
        Preorder_Tree_Walk(T->right);
    }
}

void Postorder_Tree_Walk(Node* &T){
    if (T != NULL) {
        Postorder_Tree_Walk(T->left);
        Postorder_Tree_Walk(T->right);
        cout << T->data << endl;
    }
}

Node* Tree_Search(Node* &T, int k){
    if (T == NULL || k == T->data){
        return T;
    }
    if (k < T->data) {
        return Tree_Search(T->left, k);
    }
    else{
        return Tree_Search(T->right, k);
    }
}

void Tree_Insert(Node* &T, int value){
    
    Node* y = NULL;
    Node* x = T;
    Node* z = new Node();
    
    z->data = value;
    
    while (x != NULL) {
        y = x;
        if (z->data < x->data) {
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    
    z->parent = y;
    
    if (y == NULL) {
        T = z;
    }
    else if(z->data < y->data){
        y->left = z;
    }
    else{
        y->right = z;
    }
    
}

void Transplant(Node* &T, Node* &u, Node* &v){
    if (u->parent == NULL) {
        T = v;
    }
    else if (u == u->parent->left){
        u->parent->left = v;
    }
    else{
        u->parent->right = v;
    }
    if(v != NULL){
        v->parent = u->parent;
    }
}

Node* Tree_Minimum(Node* &T){
    while (T->left != NULL) {
        T = T->left;
    }
    return T;
}

void Tree_Delete(Node* &T, int value){
    
    Node* z = Tree_Search(T, value);
    
    if (z->left == NULL) {
        Transplant(T, z, z->right);
    }
    else if (z->right == NULL){
        Transplant(T, z, z->left);
    }
    else{
        Node* y = Tree_Minimum(z->right);
        
        if(y->parent != z){
            Transplant(T, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(T, z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

int main(int argc, const char * argv[]) {
    
    Node* T = NULL;
    
    int value;
    
    string line = "";
    
    while (getline(cin, line)) {
        if (line.size() == 0){
            continue;
        }
        if (line[0] == 'e'){
            return 1;
        }
        if (line[0] == 'o'){
            if (line.substr(0, 3) == "oin"){
                Inorder_Tree_Walk(T);
            }
            else if (line.substr(0, 4) == "opre"){
                Preorder_Tree_Walk(T);
            }
            else if (line.substr(0, 5) == "opost"){
                Postorder_Tree_Walk(T);
            }
        }
        else{
            stringstream convert_stm(line.substr(1, line.size() - 1));
            if (!(convert_stm >> value))
                value = -1;
            if (line.substr(0, 1) == "i"){
                Tree_Insert(T, value);
            }
            else if (line.substr(0, 1) == "d"){
                Tree_Delete(T, value);
            }
        }
    }
    
    return 0;
}
