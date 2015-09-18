/**
 * find the longest valid varentheses
 * for example: the longest avlid varentheses of ")()())" is "()()", we return the length of the result.
 *
 * author: afu
 */

#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

// find the varentheses
int longestVP(string s) {
    stack<int> retStk;
   vector<int> lastVct;
    int tmp = 0;
    int retInt = 0; //返回值
    int popCount = 0; //连续括号周期中弹出次数
    int leftPush = 0; //循环结束后栈中剩余个数
    int flag = 1; //指示剩余的是否为连续括号的开头
    int sSize = s.size();

    for(int i = 0; i < sSize; i++) {
       if(s[i] == ')' && retStk.empty()) {
           tmp = popCount * 2;
           retInt = (retInt > tmp) ? retInt : tmp;
           tmp = popCount = 0;
           continue;
       }
       if(s[i] == ')' && !retStk.empty()) {
           retStk.pop();
           popCount ++ ;
           continue;
        }
        if(s[i] == '(') {
           retStk.push(i);
        }
     }
     if(retStk.empty()) {
        tmp = popCount * 2;
        retInt = (retInt > tmp) ? retInt : tmp;
        return retInt;
     }
     lastVct.push_back(sSize);
     while(!retStk.empty()) {
        if((sSize - (popCount * 2 + leftPush)) == retStk.top()) {
            flag = 0;
        }
        lastVct.push_back(retStk.top());
        leftPush ++;
        retStk.pop();
     }
     lastVct.push_back(sSize - (popCount * 2 + leftPush) - flag);
     for (int i = 0; i < lastVct.size() - 1; i++) {
        retInt = (retInt > (lastVct[i] - lastVct[i + 1] - 1)) ? retInt : (lastVct[i] - lastVct[i + 1] - 1);
     }
     return retInt;
}

// print out the result of testing
void test(int expected, int actual) {
    if(expected == actual) {
        cout << "successed!!!" << endl;
    }
    if(expected != actual) {
        cout << "failed!!!" << endl;
    }
}

// test1 ")()())"
void test1() {
    cout << "testing test1 ......" << endl;
    string a = ")()())";
    test(4, longestVP(a));
}

// test2 "()())"
void test2() {
    cout << "testing test2 ......" << endl;
    string a = "()())";
    test(4, longestVP(a));
}

// test3 "(()())"
void test3() {
    cout << "testing test3 ......" << endl;
    string a = "(()())";
    test(6, longestVP(a));
}

// test4 "()(()"
void test4() {
    cout << "testing test4 ......" << endl;
    string a = "()(()";
    test(2, longestVP(a));
}

// main function
int main() {
    test1();
    test2();
    test3();
    test4();
}
