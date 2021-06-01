// These files should contain test code for all the classes and methods for your implementation
#include "tests.h"
#include <string>
#include <iostream>
using namespace std;

int main() {
    test_all();
    return 0;
}

void test_nodeconstructor() {
    Node movie;
    bool passed = false;
    if (movie.name == "" && movie.depth == 0 && movie.rating == 0.0) {
        passed = true;
    }
    testOut("test_nodeconstructor", passed);
}
void test_nodeconstructor2() {
    Node movie("Toy Story", 5.0);
    bool passed = false;
    if (movie.name == "Toy Story" && movie.rating == 5.0 && movie.depth == 0.0) {
        passed = true;
    }
    testOut("test_nodeconstructor2", passed);
}
void test_constructor() {
    BST mybst;
    Node* node = nullptr;
    AssertEquals(mybst.getRoot(), node);
}
void test_getDepth() {
    BST mybst;
    Node* node = new Node("Toy Story", 5.5);
    Node* node2 = new Node("Pulp Fiction", 8.0);
    Node* node3 = new Node("Avengers: Endgame", 7.9);
    mybst.insert(node);
    mybst.insert(node2);
    mybst.insert(node3);
    AssertEquals(mybst.getRoot()->left->depth, 1);
    AssertEquals(mybst.getRoot()->left->left->depth, 2);
    delete node; delete node2; delete node3;
    
}
void test_insert() {
    BST mybst;
    Node* node = new Node("Toy Story", 5.5);
    Node* node2 = new Node("Pulp Fiction", 8.0);
    Node* node3 = new Node("Avengers: Endgame", 7.9);
    mybst.insert(node);
    mybst.insert(node2);
    mybst.insert(node3);
    delete node; delete node2; delete node3;
    testOut("test_insert", true);
}

void test_highestrated() {
    
}