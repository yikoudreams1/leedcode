/**
 * judge wheather the given  string is valid parentheses
 *
 * author afu
 */

#include<string>
#include<iostream>
#include<stack>

using namespace std;

// match the two chars
bool isMatch(char a, char b) {
    if(a == '(' && b == ')') {
        return true;
    }
    if(a == '[' && b == ']') {
        return true;
    }
    if(a == '{' && b == '}') {
        return true;
    }
    return false;
}

// judge the string
bool isValid(string s) {
    int sSize = s.size();
    stack<char> retStack;
    for(int i = 0; i <= sSize - 1; i ++) {
        if(retStack.empty() || !(isMatch(retStack.top(), s[i]))) {
            retStack.push(s[i]);
            continue;
        }
        retStack.pop();
    }
    if(retStack.empty()) {
        return true;
    }
    return false;
}

// print out the resault of the test
void test(bool expected, bool actual) {
    if(expected == actual) {
        cout << "seccessed!!" << endl;
    }
    if(expected != actual) {
        cout << "failed!!" << endl;
    }
}

// test1 "(){}[]"
void test1() {
    string a = "(){}[]";
    cout << "testing test1......" << endl;
    test(true, isValid(a));
}

// test2 "(){}["
void test2() {
    string a = "(){}[";
    cout << "testing test2......" << endl;
    test(false, isValid(a));
}

// test3 "({})"
void test3() {
    string a = "({})";
    cout << "testing test3......" << endl;
    test(true, isValid(a));
}

// main function
int main() {
    test1();
    test2();
    test3();
}
