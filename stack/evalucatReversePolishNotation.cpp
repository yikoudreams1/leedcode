/**
 * evaluate reverse polish notation
 * assume that the right notation is given
 *
 * author: afu
 */

#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

// evaluate the natation
int evalRPN(vector<string>& tokens) {
    string opera = tokens[tokens.size() - 1];
    tokens.pop_back();
    if(!( "+" == opera || "-" == opera || "*" == opera || "/" == opera )) {
        return atoi(opera.c_str());
    }
    int rightParam = evalRPN(tokens);
    int leftParam = evalRPN(tokens);
    char operater = opera[0];
    switch(operater) {
        case '+': return leftParam + rightParam;
        case '-': return leftParam - rightParam;
        case '*': return leftParam * rightParam;
        case '/': return leftParam / rightParam;
    }
}

// print out the resualt of the test
void test(int expected, int actual, string testnumb) {
    if(expected == actual) {
        cout << " Testinga " << testnumb << " successed! " << endl;
    }
    if(expected != actual) {
        cout << " Testinga " << testnumb << " failed! " << endl;
    }
}

// test1 ["2", "1", "+", "3", "*"]
void test1() {
    vector<string> testStr;
    testStr.push_back("2");
    testStr.push_back("1");
    testStr.push_back("+");
    testStr.push_back("3");
    testStr.push_back("*");
    test(9, evalRPN(testStr), string("test1"));
}

// main function
int main() {
    test1();
}
