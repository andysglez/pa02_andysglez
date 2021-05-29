 // These files should contain your implementation of the binary search tree to store movies information
  #include "movies.h"
  #include <string>
  #include <iostream>
  using namespace std;

Node::Node(const Node& n){
    this->name = n.name;
    this->rating = n.rating;
}
Node::Node() {
    name = "";
    rating = 0.0;
    depth = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
};
Node::Node(string moviename, double Rating) {
    name = moviename;
    rating = Rating;
    depth = 0;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

void Node::print() {
    cout << name << ", " << rating << ", "
    << depth << endl;
}
BST::~BST() {
    destroy(root);
}
//Recursive help function for the destructor
void BST::destroy(Node* node) { //similar to clear() intbst.cpp
    if (node) {
        if (node->left) {destroy(node->left);}
        if (node->right) {destroy(node->right);}
        delete node;
    }
}

void BST::insert(Node* movie) {
    if (!root) {
        Node* insertmovie = new Node(movie->name, movie->rating);
        root = insertmovie;
        root->depth = 0;
    }
    else {
        HelpInsert(movie, root);
    }
}

bool BST::HelpInsert(Node* movie, Node* StartMovie) {
    string name = movie->name;
    string nombre = StartMovie->name;
    if (name > nombre) {
        if (StartMovie->right) {
            return HelpInsert(movie, StartMovie->right);
        }
        else {
            Node* insertmovie = new Node(name, movie->rating);
            StartMovie->right = insertmovie;
            insertmovie->parent = StartMovie;
            insertmovie->depth = getDepth(insertmovie);
            return true;
        }
    }
    if (name < nombre) {
        if (StartMovie->left) {
            return HelpInsert(movie, StartMovie->left);
        }
        else {
            Node* insertmovie = new Node(name, movie->rating);
            StartMovie->left = insertmovie;
            insertmovie->parent = StartMovie;
            insertmovie->depth = getDepth(insertmovie);
            return true;
        }
    }
    return false;
}
void BST::print_preorder() {
    print_preorder(root);
}
void BST::print_preorder(Node* n) {
    if (n) {
        n->print();
        print_preorder(n->left);
        print_preorder(n->right);
    }
}
Node* BST::highest_rated(string prefix) {
    return highest_rated(prefix, root);
}

Node* BST::highest_rated(string prefix, Node* n) {
    int len = prefix.length();
    if (n) {
        string SearchFix = n->name.substr(0, len);
        if (prefix > SearchFix) {
            return highest_rated(prefix, n->right);
        }
        else if (prefix < SearchFix) {
            return highest_rated(prefix, n->left);
        }
        else if (n->right && prefix==SearchFix) {
            string RightFix = n->right->name.substr(0,len);
            if (prefix == RightFix) {
                return highest_rated(prefix, n->right);
            }
        }
        else {
            return n;
        }
    }
    return NULL;
}

int BST::getDepth(Node* n) const{
    int count(0);
    while(n->parent) {
        n = n->parent;
        count++;
    }
    return count;
}