 // These files should contain your implementation of the binary search tree to store movies information
#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
    Node();
    Node(string moviename, double Rating);
    Node(const Node& node);
    Node* left, *right, *parent;
    void print();
    string name;
    double rating;
    int depth;
};
class BST {
    public:
        BST() {root = nullptr;}
        ~BST();
        //BST(const BST* CopyBST);
        void insert(Node* movie);
        void print_preorder();
        Node* highest_rated(string prefix);
        int getDepth(Node*n) const;
        Node* getRoot() {return root;}
    private:
        vector<Node*> prefix_collect;
        void print_preorder(Node* n);
        Node* highest_rated(string prefix, Node* n);
        int CalcDepth(Node* n);
        bool HelpInsert(Node* movie, Node* startmovie);
        Node* root;
        void destroy(Node* node);
};