#include <iostream>

using namespace std;

#define MAX 10
#define STCK stack, tos
#define STPR int st[], int& tos
#define TRUE return true
#define FALSE return false
#define OP_FAILED return 96

bool push(int x, STPR) {
    if (tos <= MAX) {
        st[tos] = x;
        tos++;
        TRUE;
    } else
        FALSE;
}

bool pop(STPR) {
    if (tos > 0) {
        tos--;
        delete &st[tos];
        TRUE;
    }
    FALSE;
}

int peek(STPR) {
    int x = tos - 1;
    if (x >= 0)
        return st[x];
    OP_FAILED;
}

bool isStackEmpty(STPR) {
    if (tos == 0)
        TRUE;
    FALSE;
}

bool isStackFull(STPR) {
    if (tos == MAX)
        TRUE;
    FALSE;
}

int main() {
    int stack[MAX];
    int tos = 0;
    int x = 0;

    cout << "Stack Empty: " << (isStackEmpty(STCK) ? "true" : "false") << endl;
    cout << "Stack Full: " << (isStackFull(STCK) ? "true" : "false") << endl << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Enter a num: ";
        cin >> x;
        push(x, STCK);
    }

    cout << "\nLatest stack: " << peek(STCK) << endl;

    pop(STCK);

    cout << "After pop: " << peek(STCK) << endl << endl;
}