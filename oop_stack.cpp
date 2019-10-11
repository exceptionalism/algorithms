#include <iostream>

using namespace std;

#define MAX 10

class Stack {
private:
    int stck[MAX];
    int tos;
public:
    Stack(): tos(0) {}

    bool push(int x) {
        if (tos <= MAX) {
            stck[tos] = x;
            tos++;
            return true;
        } else
            return false;
    }
    bool pop() {
        if (tos > 0) {
            tos--;
            delete &stck[tos];
            return true;
        }
        return false;
    }

    int peek() {
        int x = tos - 1;
        if (x >= 0)
            return stck[x];
        cout << "\nCannot peek. Stack may be empty.\n";
        return 96;
    }

    bool isStackEmpty() {
        if (tos == 0)
            return true;
        return false;
    }

    bool isStackFull() {
        if (tos == MAX)
            return true;
        return false;
    }
    ~Stack() {
        delete this;
    }
};


int main() {
    int x = 0;
    Stack *st = new Stack();

    cout << "Stack Empty: " << (st->isStackEmpty() ? "true" : "false") << endl;
    cout << "Stack Full: " << (st->isStackFull() ? "true" : "false") << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Enter a num: ";
        cin >> x;
        st->push(x);
    }

    cout << "\nLatest stack: " << st->peek() << endl;

    st->pop();

    cout << "After pop: " << st->peek() << endl << endl;

    return 0;
}