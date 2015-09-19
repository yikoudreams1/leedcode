/**
 * Compute and return the square root of x
 *
 * author: afu
 */

#include <iostream>

using namespace std;

// sqrt funtion 
int mySqrt(int x) {
    int beg = 0;
    int end = x/2<std::sqrt(INT_MAX)? x/2+1:std::sqrt(INT_MAX);
    while(end >= beg) {
        int mid = (beg + end) / 2;
        int midValue = mid * mid;
        if(midValue == x) {
            return mid;
        }
        if(midValue > x) {
            end = mid - 1;
        }
        if(midValue < x) {
            beg = mid + 1;
        }
    }
    return (beg + end) / 2;
}

// print out the result of the test
void test(int expected, int actual) {
    if(expected == actual) {
        cout << " success !!!" << endl;
    }
    if(expected != actual) {
        cout << " failed !!!" << endl;
        cout << " expect: " << expected << endl;
        cout << " actual: " << actual << endl;
    }
}

// test1
void test1() {
    test(4,mySqrt(16));
}

// main function
int main() {
    test1();
}
