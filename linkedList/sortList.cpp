/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 *
 * author: afu
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// merge two sorted list
ListNode *merge(ListNode *l, ListNode *r) {
    if(!l) {
        return r;
    }
    if(!r) {
        return l;
    }
    if(l -> val < r -> val) {
        l -> next = merge(l -> next, r);
        return l;
    }
    r -> next = merge(l, r -> next);
    return r;
}

// sort list
ListNode *sortList(ListNode *head) {
    if(!head) {
        return NULL;
    }
    if(!head -> next) {
        return head;
    }
    ListNode *ptr1 = head;
    ListNode *ptr2 = head;
    while(ptr2) {
        if(!ptr2 -> next) {
            break;
        }
        ptr2 = ptr2 -> next -> next;
        ptr1 = ptr1 -> next;
    }
    ListNode *ptr = head;
    while(ptr -> next != ptr1) {
        ptr = ptr -> next;
    }
    ptr -> next = NULL;
    return merge(sortList(head), sortList(ptr1));
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
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
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
