#include <iostream>
using namespace std;

// List data structure
struct Node {
    Node* prev;
    int value;
    Node* link;
};

// HEAD of the list
Node* HEAD = new Node();

// Insert a data set into the list
int insert(int val = 0, Node* s = HEAD, Node* m = HEAD->link) {
    if (s->value == -1) {
        s->prev = m;
        s->value = val;
        s->link = new Node();
        (s->link)->value = -1;
        return 1;
    } else {
        insert(val, s->link, s);
    }
}

// Displays all the data in the list (latest first)
void getAll(Node* s = HEAD) {
    if (s->value != -1) {
        getAll(s->link);
        cout << s->value << "\t";
    }
}

// Deletes an specific item from the list
bool dltItem(int x, Node* s = HEAD) {
    if (s->value != -1) {
        if (s->value == x) {
            (s->prev)->link = s->link;
            (s->link)->prev = s->prev;
            delete s;
            return true;
        } else {
            dltItem(x, s->link);
        }
    } else
        return false;
}

// Main program for the implementation of list
int main() {
    // init list properly
    HEAD->value = -1;
    HEAD->prev = 0;

    // get data and enrich list
    int j = 0;
    for (int i = 0; i < 5; i++) {
        cout << "Enter Number: ";
        cin >> j;
        insert(j);
    }

    // display list
    getAll();
    cout << endl;

    // attempt to delete latest addition from list
    bool deleted = dltItem(j);
    if(deleted)
        cout << "Deleted from list." << endl;
    else
        cout << "Data not in list." << endl;
    
    // show list after deletion
    getAll();
    
    return 0;
}