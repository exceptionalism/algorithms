#include <iostream>
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
     * Print the entirity of the tree
     * 
     * @param {Node *} t - Pointer from where the tree should be printed
     * @param {bool} printAsc - Flag whether to print the tree in ascending or descending order
    */
    void printTree(Node* t, bool printAsc) {
        if (t) {
            if (printAsc) {
                printTree(t->left, printAsc);
                cout << t->value << endl;
                printTree(t->right, printAsc);
            } else {
                printTree(t->right, printAsc);
                cout << t->value << endl;
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
            cout << "deleting..." << endl;
            deleteTree(t->left);
            deleteTree(t->right);
            t = NULL;
        }
        delete t;
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

        // exit
        return;
    }

    /*
     * Delete the whole tree
     * 
     * Null 
    */
    void deleteTree() {
        deleteTree(root);
        cout << "Deletion complete." << endl;
        root = NULL;
    }

    
    /*
     * Print the entirety of the tree in ascending order 
     * 
     * Null
    */
    void printTree() {
        if (root)
            printTree(root, true);
        else
            cout << "Tree is empty." << endl;
    }
    /*
     * Print the entirety of the tree 
     * 
     * @param {bool} printAsc - Flag whether to print the tree in ascending order, or in descending order
    */
    void printTree(bool printAsc) {
        if (root)
            printTree(root, printAsc);
        else
            cout << "Tree is empty." << endl;
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
    bt->addChild(10);
    bt->addChild(8);
    bt->addChild(1);
    bt->addChild(20);
    bt->addChild(19);
    bt->addChild(14);
    bt->addChild(18);
    bt->addChild(17);

    // bt->deleteTree();

    bt->printTree();

    return 0;
}