/**
 * find the largest rectangle form the historam
 *
 * author: afu
 */

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int findRight(vector<int>& height, int i);
int findLeft(vector<int>& height, int i);

// find the value
int largestRectangleArea(vector<int>& height) {
    int length = height.size();
    int ret = 0;
    for (int i = 0; i < length; i++) {
        int right = findRight(height, i);
        int left = findLeft(height, i);
        int tmp = height[i] * (right + left + 1);
        ret = (ret > tmp) ? ret : tmp;
    }
    return ret;
}

// find the distance from i to the most right one who is small than height[i]
int findRight(vector<int>& height, int i) {
    int length = height.size();
    int ret = 0;
    for (int j = i + 1; j < length; j ++) {
        if (height[j] >= height[i]) {
            ret ++;
            continue;
        }
        break;
    }
    return ret;
}

// find the distance from i to the most left one who is small than height[i]
int findLeft(vector<int>& height, int i) {
    int res = 0;
    for (int j = i - 1; j >= 0; j --) {
        if (height[j] >= height[i]) {
            res ++;
            continue;
        }
        break;
    }
    return res;
}

// another more effient method th solve this problem with stack
int largestRectangleArea1(vector<int>& height) {
   height.push_back(0);
   stack<int> retStack;
   int retMaxArea = 0;
   int hLength = height.size();
   for (int i = 0; i < hLength; i ++) {
       while (!retStack.empty() && height[retStack.top()] > height[i]) {
           int h = retStack.top();
           retStack.pop();
           int tmpArea = height[h] * (retStack.empty() ? i : (i - retStack.top() - 1));
           retMaxArea = (retMaxArea > tmpArea) ? retMaxArea : tmpArea;
       }
       if (retStack.empty() || height[i] >= height[retStack.top()]) {
           retStack.push(i);
           continue;
       }
   }
   return retMaxArea;
}
// print out the result of the test
void test(int expected, int actual) {
    if(expected == actual) {
        cout << "success!!!" << endl;
    }
    if(expected != actual) {
        cout << "failed!!!" << endl;
        cout << "ecpected :  " << expected << endl;
        cout << "actual :  " << actual << endl;
    }
}

// test1 2, 1, 5, 6, 2, 3
void test1() {
    cout << "testing test1 ..." << endl;
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    a.push_back(3);
    test(10, largestRectangleArea1(a));
}

// main function
int main() {
    test1();
}
