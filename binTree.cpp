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
            cout << "deleting..." << endl;
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
    * Computes the size of root's each subtree 
    * 
    * Null
    */
   void compSize() {       
        cout << "Left sub-tree's height: " << height(root->left) << endl;
        cout << "Right sub-tree's height: " << height(root->right) << endl;
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
     * Balances the tree based on its height
     * 
     * Null
     */
    void heightbalance() {
        if (!root)
            return;
        else {
            int lh = 0, rh = 0;
            while (!isBalanced()) {
                lh = height(root->left);
                rh = height(root->right);
                Node* newPtr = NULL;
                if (rh > lh) {
                    newPtr = root->right;
                    root->right = newPtr->left;
                    newPtr->left = root;
                } else {
                    newPtr = root->left;
                    root->left = newPtr->right;
                    newPtr->right = root;
                }
                root = newPtr;
            }
        }
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
    bt->addChild(16);


    // cout << "Height of the tree: " << bt->height() << endl;
    cout << "BEFORE:" << endl;
    bt->compSize();
    bt->printTree();
    cout << endl;

    bt->heightbalance();

    cout << "AFTER:" << endl;
    // cout << "Height of the tree: " << bt->height() << endl;
    bt->compSize();
    bt->printTree();

    return 0;
}