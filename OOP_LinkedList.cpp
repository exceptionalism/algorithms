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
    bool insertNode(int data) {
        if (Head == NULL) {
            Head = new Node();
            Head->value = data;
            Head->next = NULL;
        } else {
            Node* node = new Node;
            node->value = data;
            node->next = NULL;
            Node* curr;
            curr = Head;
            while(curr->next) {
                curr = curr->next;
            }
            curr->next = node;
        }
        return 1;
    }

    /*
    * Remove a node at specific position in the list
    * 
    * @param {int} index - Position from where the node should be removed in the list
    */
    bool removeAt(int index) {
        Node* curr = Head;
        int count = -1;
        while (curr) {
            curr = curr->next;
            count++;
        }
        cout << "Count: " << count << endl;
        curr = Head;
        if (index > 0 && index > count) {
            return 0;
        } else if (index == 0) {
            Head = Head->next;
            delete curr;
        } else {
            Node* prev;
            count = 0;
            while (count < index) {
                count++;
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        return 1;
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
    // l->clearList();
    l->removeAt(1);
    l->printList();

    return 0;
}