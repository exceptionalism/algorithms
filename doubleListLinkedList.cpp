#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node():data(0), next(NULL) {}
    Node(int x): data(x), next(NULL) {}
};

class LinkedList {
    Node* head;
    Node* freeNodes;


    void dispList(Node* p) {
        if (p == NULL)
            return;
        dispList(p->next);
        cout << p->data << "\t";
    }
public:
    /*
     * Creates 100 nodes as default
     */ 
    LinkedList() {
        head = NULL;
        freeNodes = new Node();
        Node* p = freeNodes;
        for (int i = 0; i < 100; i++) {
            p->next = new Node();
            p = p->next;
        }
    }
    /*
     * Creates nodes as specified
     */ 
    LinkedList(int requiredSpaces) {
        head = NULL;
        freeNodes = new Node();
        Node* p = freeNodes;
        for (int i = 0; i < (requiredSpaces - 1); i++) {
            p->next = new Node();
            p = p->next;
        }
    }

    /*
    * Adds new element to the list
    * 
    */
    bool addElem(int data) {
        if (!freeNodes)
            return false;
        else { 
            if (!head) {
                freeNodes->data = data;
                head = freeNodes;
                freeNodes = freeNodes->next;
                head->next = NULL;
                return true;
            }
            Node* p = head;
            while (p->next)
                p = p->next;
            freeNodes->data = data;
            p->next = freeNodes;
            freeNodes = freeNodes->next;
            p->next->next = NULL;
            return true;
        }
    }
    void dispList() {
        dispList(head);
        cout << endl;
    }
};

int main() {
    LinkedList* l = new LinkedList(10);
    l->addElem(20);
    l->addElem(10);
    l->addElem(30);
    l->addElem(50);
    l->addElem(40);
    l->addElem(90);
    l->addElem(80);
    l->addElem(60);
    l->addElem(70);
    l->addElem(15); // size caps off here
    l->addElem(25);
    l->addElem(30);
    
    l->dispList();
}