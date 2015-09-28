/**
 * How many possible unique paths in the M * N grid
 *
 * author: afu
 */

#include <iostream>

using namespace std;

int findUP(int m, int n) {
    int *dp = new int(m * n);
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(i == m - 1) {
                dp[i * n + j] = 1;
                continue;
            }
            if(j == n - 1) {
                dp[i * n + j] = 1;
                continue;
            }
            dp[i * n + j] = dp[(i + 1) * n + j] + dp[i * n + j + 1];
        }
    }
    return dp[0];
}
// *----------------better method----------------------*
int findUP(int m, int n) {
       if(m<1 || n<1) return 0;
               vector<int> dp(n, 1);
                       for(int i=1; i<m; i++) {
                                       for(int j=1; j<n; j++) {
                                                           dp[j] += dp[j-1];
                                                                       }
                                               }
        return dp[n-1];
                                       }
                       }
// print out the result of the test
void test(int expected, int actual) {
    if(expected == actual) {
        cout << "success!!!!" << endl;
    }
    if(expected != actual) {
        cout << "failed" << endl;
        cout << "expect: " << expected << endl;
        cout << "actual: " << actual << endl;
    }
}

// test1  2*2
void test1() {
    test(2, findUP(2, 2));
}

// test2  2*3
void test2() {
    test(3, findUP(2, 3));
}

// test3  1*10
void test3() {
    test(1, findUP(1, 10));
}

int main() {
    test1();
    test2();
    test3();
}
