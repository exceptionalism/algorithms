#include <iostream>
using namespace std;





/* 
 * LinkedList data structure
 * 
 * @members {int} value
 * @members {Node*} next
 */
struct Node {
    int value;
    Node* next;
};





/*
 * Class representing a linked-list
 * 
 * Null
 */
class LinkedList {
    /*
     * Head of the list
    */
    Node* Head;
public:
    /*
    * Empty constructor - sets Head to NULL
    * 
    * Null
    */
    LinkedList() {
        Head = NULL;
    }
    /*
    * Initialize a list with first node in the list
    * 
    * @param {int} data - Value of first node
    */
    LinkedList(int data) {
        Head = new Node;
        Head->value = data;
        Head->next = NULL;
    }

    /*
    * Insert a new node in the list
    * 
    * @param {int} data - Value to be added in the list
    */
    Node* insertNode(int data) {
        if (Head == NULL) {
            Head = new Node();
            Head->value = data;
            Head->next = NULL;
            return Head;
        } else {
            Node* node = new Node;
            node->value = data;
            node->next = NULL;
            Node* curr;
            curr = Head;
            while(curr->next) curr = curr->next;
            curr->next = node;
            return node;
        }
    }

    /*
    * Remove a node with specific data in the list
    * 
    * @param {Node*} index - Position from where the node should be removed in the list
    */
    bool removeAt(Node* index) {
        if (Head == index) {
            Head = Head->next;
            return 1;
        }
        Node* curr = Head;
        while (curr) {
            cout << curr << endl;
            if (curr->next == index) {
                curr->next = curr->next->next;
                return 1;
            }
            curr=curr->next;
        }
        return 0;
    }

    /*
    * Remove a node at specific position in the list
    * 
    * @param {int} value - Position from where the node should be removed in the list
    */
    bool removeAt(int value) {
        if (Head->value == value) {
            Head = Head->next;
            return 1;
        }
        Node* curr = Head;
        while (curr->next) {
            if (curr->next->value == value) {
                curr->next = curr->next->next;
                return 1;
            }
            curr = curr->next;
        }
        return 0;
    }


    /*
    * Search for specific element in the list
    * 
    * @param {int} searchItem - Item to be searched for in the list
    */
    Node* searchFor(int searchItem) {
        if (Head->value == searchItem) return Head;
        Node* curr = Head->next;
        while (curr) {
            if (curr->value == searchItem) return curr;
            curr = curr->next;
        }
        return NULL;
    }

    /*
    * Print data in every node in the list
    * 
    * Null
    */
    void printList() {
        Node* curr = Head;
        while (curr) {
            cout << curr->value << "\t";
            curr = curr->next;
        }
        cout << endl;
    }

    /*
    * Clear the whole list
    * 
    * Null
    */
    bool clearList() {
        Node* curr = Head;
        Node* next;
        Head = NULL;
        while (curr) {
            next = curr->next;
            delete curr;
            curr = next;
        }
        return 1;
    }
    
};

int main() {
    LinkedList* l = new LinkedList;
    l->insertNode(200);
    l->insertNode(300);
    l->insertNode(400);
    cout << "Address at: " << l->searchFor(200) << endl;
    cout << "Address at: " << l->searchFor(300) << endl;
    cout << "Address at: " << l->searchFor(400) << endl;
    l->removeAt(l->searchFor(400));
    // l->clearList();
    l->removeAt(400);
    l->printList();

    return 0;
}