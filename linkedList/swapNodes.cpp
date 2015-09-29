/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * author: afu
 */

#include <iostream>

using namespace std;

struct listNode {
    int val;
    listNode *next;
    listNode(int x) : val(x), next(NULL) {}
};

// swap the value of two node
void swapValue(listNode *a, listNode *b) {
    int tmp;
    tmp = a -> val;
    a -> val = b -> val;
    b -> val = tmp;
}

// swap all ad nodes in LL
listNode *swapNode(listNode *head) {
    if(!head) {
        return NULL;
    }
    listNode *ptr = head;
    while(ptr) {
        if(ptr -> next) {
            swapValue(ptr, ptr -> next);
            ptr = ptr -> next -> next;
            continue;
        }
        return head;
    }
    return head;
}

// print out result of the test
void test(int expected[], int actual[], int length) {
    for(int i = 0; i < length; i++) {
        if(expected[i] != actual[i]) {
            cout << "failed!!!" << endl;
            cout << "expected: " << expected[i] << endl;
            cout << "actual: " << actual[i] << endl;
            return;
        }
    }
    cout << "successed!!!" << endl;
}

// test1 1 2
void test1() {
    listNode *a1 = new listNode(1);
    listNode *a2 = new listNode(2);
    cout << a1 -> val << endl;
    cout << a2 -> val << endl;
    a1 -> next = a2;
    int a[2] = {2,1};
    a1 = swapNode(a1);
    int b[2] = {0};
    b[0] = a1 -> val;
    b[1] = a1 -> next  -> val;
    test(a, b, 2);
}
// main function 
int main() {
    test1();
}
