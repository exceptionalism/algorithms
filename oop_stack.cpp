#include <iostream>

using namespace std;

#define MAX 5

class Stack {
private:
    int stck[MAX];
    int tos;
public:
    Stack(): tos(0) {}

    bool push(int x) {
        if (tos < MAX) {
            stck[tos] = x;
            tos++;
            return true;
        } else
            throw "Cannot push. Stack may be full.";
    }
    bool pop() {
        if (tos > 0) {
            tos--;
            delete &stck[tos];
            return true;
        }
        throw "Cannot pop. Stack may be empty";
    }

    int peek() {
        int x = tos - 1;
        if (x >= 0)
            return stck[x];
        throw "Cannot peek. Stack may be empty.";
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

    for (int i = 0; i < 6; i++) {        
        cout << "Stack Empty: " << (st->isStackEmpty() ? "true" : "false") << endl;
        cout << "Stack Full: " << (st->isStackFull() ? "true" : "false") << endl << endl;
        cout << "Enter a num: ";
        cin >> x;
        try {
            st->push(x);
            cout << endl;
        } catch (const char* s) {
            cout << "Error!\n" << s << endl << endl;
        }
    }

    cout << "\nLatest stack: " << st->peek() << endl;

    st->pop();

    cout << "After pop: " << st->peek() << endl << endl;

    return 0;
}