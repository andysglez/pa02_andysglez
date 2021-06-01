 // These files should contain your implementation of the binary search tree to store movies information
  #include "movies.h"
  #include <string>
  #include <iostream>
  #include <vector>
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

void BST::searchforAll() {
    searchforAll(root);
}
void BST::searchforAll(Node *n) {
    if (n) {
        search(n);
        searchforAll(n->right); 
        searchforAll(n->left);
    }
}

Node* BST::search(Node*n) {
    return search(n, root);
}
Node* BST::search(Node* n, Node* sn) {
    if (n) {
        if (n->name == sn->name) {
            return sn;
        }
        else if (n->name < sn->name) {
            if (sn->left) {
                return search(n, sn->left);
            }
        }
        else if (n->name > sn->name) {
            if (sn->right) {
                return search(n, sn->right);
            }
        }
    }
    return nullptr;
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
    if (n) {
        if(n->name.length() > prefix.length()) {
            string searchfix = n->name.substr(0,prefix.length());
            if (prefix == searchfix) {
                prefix_collect.push_back(n);
            }  
        }
        if (n->right) {highest_rated(prefix, n->right);}
        if (n->left) {highest_rated(prefix, n->left);}
    }
    Node* hr_Node = nullptr;
    double hr(0);
    for(auto l: prefix_collect) {
        if (l->rating>hr) {
            hr_Node = l;
            hr = l->rating;
        }
    }
    return hr_Node;
}

int BST::getDepth(Node* n){
    Node* n2 = search(n);
    int count(0);
    while(n2->parent) {
        n2 = n2->parent;
        count++;
    }
    return count;
}