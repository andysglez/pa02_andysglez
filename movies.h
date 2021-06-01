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
        int insertTracker(Node* movie);
        void print_preorder();
        Node* highest_rated(string prefix);
        int getDepth(Node*n);
        Node* getRoot() {return root;}
        void searchforAll();
        Node* search(Node* n);
    private:
        int insertTracker(Node* movie, Node* startmovie);
        vector<Node*> prefix_collect;
        void searchforAll(Node* n);
        void print_preorder(Node* n);
        Node* search(Node* n, Node* sn);
        Node* highest_rated(string prefix, Node* n);
        int CalcDepth(Node* n);
        bool HelpInsert(Node* movie, Node* startmovie);
        Node* root;
        void destroy(Node* node);
};