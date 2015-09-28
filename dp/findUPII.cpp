/**
 * How many possible unique paths in the M * N grid
 *
 * author: afu
 */

#include <iostream>
#include <vector>

using namespace std;

int findUPII(vector<vector<int> > inVct) {
    int m = inVct.size();
    int n = inVct.back().size();
    int *dp = new int[n];
    int flag = 1;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                dp[j] = flag && !inVct[i][j] && 1;
                if(dp[j] == 0) {
                    flag = 0;
                }
                continue;
            }
            if(j == 0) {
                dp[j] = !inVct[i][j] && dp[j];
                continue;
            }
            if(!inVct[i][j]) {
                dp[j] = (dp[j] + dp[j - 1]);
                continue;
            }
            dp[j] = 0;
        }
        for(int i = 0; i < n; i++) {
            cout << dp[i] << endl;
        }
    }
    return dp[n - 1];
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
    vector<vector<int> > inVct;
    vector<int> a;
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    inVct.push_back(a);
    a.clear();
    a.push_back(0);
    a.push_back(1);
    a.push_back(0);
    inVct.push_back(a);
    a.clear();
    a.push_back(0);
    a.push_back(0);
    a.push_back(0);
    inVct.push_back(a);
    a.clear();

    test(2, findUPII(inVct));
}


int main() {
   test1();
}
