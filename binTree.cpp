#include <iostream>
#include <vector>
using namespace std;

/* 
 * Binary Tree data structure
 * 
 * @members {int} value
 * @members {Node*} left
 * @members {Node*} right
 */
struct Node {
    int value;
    Node* left;
    Node* right;
};


class BinaryTree {
private:
    Node* root;

    /*
     * Print the entire the tree
     * 
     * @param {Node *} t - Pointer from where the tree should be printed
     * @param {bool} printAsc - Flag whether to print the tree in ascending or descending order
    */
    void printTree(Node* t, bool printAsc) {
        if (t) {
            if (printAsc) {
                printTree(t->left, printAsc);
                cout << t->value << "\t";
                printTree(t->right, printAsc);
            } else {
                printTree(t->right, printAsc);
                cout << t->value << "\t";
                printTree(t->left, printAsc);
            }
        }
    }

    /*
     * Delete the whole tree
     * 
     * Null 
    */
    void deleteTree(Node* t) {
        while (t) {
            deleteTree(t->left);
            deleteTree(t->right);
            t = NULL;
        }
        delete t;
    }

    /*
     * Compute the height of the tree
    */
    int height(Node* t) {
        if (t)
            return 1 + (max(height(t->left), height(t->right)));
        return 0;
    }

    /*
    * Get the greater number between two integers
    */
    int max(int a, int b) {
        return a > b ? a : b;
    }

    /*
     * Computes the number of nodes on the tree
    */
    int size(Node* t) {
        if (t)
            return (1 + size(t->left) + size(t->right));
        return 0;
    }


    /*
     * Build a sorted dynamic array with all the nodes on the tree
     * 
     * @param {Node*} t - Node on the tree
     * @param {vector<Node*>} nodes - Vector array(passed by reference) to be build
    */
    void getNodes(Node* t, vector<Node*> &nodes) {
        if (!t) return;
        getNodes(t->left, nodes);
        nodes.push_back(t);
        getNodes(t->right, nodes);
    }


    /*
     * Build a tree from a sorted dynamic array
     * 
     * @param {vector<Node*>} nds - Vector array(passed by reference) to be build
     * @param {int} st - Starting index of the vector
     * @param {int} end - Ending index of the vector
     * 
     * @return {Node*} - pointer to the root node of the new tree
    */
    Node* buildTree(vector<Node*> nds, int st, int end) {
        if (st > end) return NULL;
        int mid = (st + end) / 2;
        Node* rt = nds[mid];

        rt->left = buildTree(nds, st, mid-1);
        rt->right = buildTree(nds, mid+1, end);
        return rt;
    }

    /*
     * Traverse through the tree to check if the value exists
     * 
     * @param {Node*} t - Node from where the tree need to be traversed
     * @param {int} sFor - Value to be searched for
    */
    void searchFor(Node* t, int sFor) {
        if (!t) return;
        if (t->value == sFor)
            cout << sFor << " exists." << endl;
        else {
            if (sFor < t->value)
                searchFor(t->left, sFor);
            else
                searchFor(t->right, sFor);
        }
    }



    
public:
    BinaryTree() {
        root = NULL;
    }


    /*
     * Initiate a binary tree with root
     * 
     * @param {int} data - Root of the first elem on the tree.
    */
    BinaryTree(int data) {
        root = new Node();
        root->value = data;
        root->left = root->right = NULL;
    }


    /*
     * Add an element as a child to the tree
     * 
     * @param {int} data - Elem to be added on the tree.
    */
    void addChild(int data) {
        // check if the root exists
        // if root does not exist, create one and exit
        if(!root) {
            root = new Node();
            root->left = root->right = NULL;
            root->value = data;
            return;
        }
        // if root already exists, prep for tree traversal
        Node* curr = root;
        Node* prev = NULL;
        // traverse through the tree to reach required position
        while (curr) {
            prev = curr;
            if(data < curr->value)
                curr = curr->left;
            else
                curr = curr->right;
        }
        // define new node for the tree
        curr = new Node;
        curr->value = data;
        curr->left = curr->right = NULL;
        // attach the new node to the tree
        if (data < prev->value)
            prev->left = curr;
        else
            prev->right = curr;
        return;
    }


    /*
     * Delete the whole tree
     * 
     * Null 
    */
    void deleteTree() {
        deleteTree(root);
        root = NULL;
    }

    
    /*
     * Print the entire tree in ascending order 
     * 
     * Null
    */
    void printTree() {
        if (root)
            printTree(root, true);
        else
            cout << "Tree is empty.";
        cout << endl;
    }


    /*
     * Print the entire tree 
     * 
     * @param {bool} printAsc - Flag whether to print the tree in ascending order, or in descending order
    */
    void printTree(bool printAsc) {
        if (root)
            printTree(root, printAsc);
        else
            cout << "Tree is empty.";
        cout << endl;
    }


    /*
     * Get the height of the tree
     * 
     * Null 
    */
    int height() {
        if (!root)
            return 0;
        return height(root);
    }


    /*
     * Get the number of nodes on the tree
     * 
     * Null 
    */
    int size() {
            if (!root)
                return 0;
            return size(root);
    }


    /*
    * Computes the size of root's each subtree 
    * 
    * Null
    */
    void compSize() {       
        if (root) {
            cout << " Left sub-tree's height: " << height(root->left) << endl;
            cout << "Right sub-tree's height: " << height(root->right) << endl;
        }
    }


    /*
     * Checks whether the tree is height-balanced
     * 
     * Null 
    */
    bool isBalanced() {
        return (height(root->left) - height(root->right) == 1 || height(root->left) == height(root->right) || height(root->left) - height(root->right) == -1);
    }


    /*
     * Checks whether the sub-tree is height-balanced
     * 
     * @param {Node*} t - Node in the tree from where the sub-tree starts
    */
    bool isBalanced(Node* t) {
        return (height(t->left) - height(t->right) == 1 || height(t->left) == height(t->right) || height(t->left) - height(t->right) == -1);
    }


    /*
    * Balances the tree on the basis of height
    * 
    * Null
    */
    void balanceTree() {
        vector<Node*> nodes;
        getNodes(root, nodes);
        Node* newRoot = buildTree(nodes, 0, nodes.size() - 1);
        deleteTree();
        this->root = newRoot;
    }

    /*
     * Search for a value in the tree
     * 
     * @param {int} sFor - Value to be searched for
    */
    void searchFor(int sFor) {
        if (!root) return;
        searchFor(root, sFor);
    }
};


int main() {
    BinaryTree* bt = new BinaryTree(7);

    bt->addChild(4);
    bt->addChild(9);
    bt->addChild(2);
    bt->addChild(6);
    bt->addChild(5);
    bt->addChild(3);
    bt->addChild(8);
    bt->addChild(1);
    bt->addChild(10);
    bt->addChild(20);
    bt->addChild(19);
    bt->addChild(14);
    bt->addChild(18);
    bt->addChild(15);
    bt->addChild(17);
    bt->addChild(12);
    bt->addChild(11);
    bt->addChild(13);
    bt->addChild(16);

    cout << " BEFORE:" << endl;
    cout << "     Height of the tree: " << bt->height() << endl;
    bt->compSize();
    bt->printTree();
    cout << endl;

    bt->balanceTree();

    cout << " AFTER:" << endl;
    cout << "     Height of the tree: " << bt->height() << endl;
    bt->compSize();
    bt->printTree();

    cout << endl << "No. of nodes on the tree: " << bt->size() << endl;

    bt->searchFor(212);

    return 0;
}