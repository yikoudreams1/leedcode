/**
 * Given two string, find the longest common substring of the two string.
 *
 * author: afu
 */

#include <iostream>
#include <algorithm>

using namespace std;

int findLCS(string &a, string &b) {
    int m = a.size();
    int n = b.size();
    if(!m || !n) {
        return 0;
    }

    int **LCS_length = (int **)(new long int[m]);
    for(int i = 0; i < m; i++) {
        LCS_length[i] = (int *)new int[n];
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            LCS_length[i][j] = 0;
        }
    }

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                if(j == 0) {
                    LCS_length[i][j] = (a[i] == b[j]) ? 1 : 0; 
                    continue;
                }
                LCS_length[i][j] = (a[i] == b[j]) ? 1 : LCS_length[i][j - 1];
                continue;
            }
            if(j == 0) {
                LCS_length[i][j] = (a[i] == b[j]) ? 1 : LCS_length[i - 1][j];
                continue;
            }
            LCS_length[i][j] = (a[i] == b[j]) ? (1 + LCS_length[i - 1][j - 1]) : max(LCS_length[i - 1][j], LCS_length[i][j - 1]);
        }
    }
    return LCS_length[m - 1][n - 1];
}

// print out the result of the test
void test(int expected, int actual) {
    if(expected == actual) {
        cout << "success!!!" << endl;
    }
    if(expected != actual) {
        cout << "failed!" << endl;
        cout << "expected: " << expected << endl;
        cout << "actual: " << actual << endl;
    }
}

// test 1 
// a,b,c,b,d,a,b
// b,d,c,a,b,a
void test1() {
    string a = "abcbdab";
    string b = "bdcaba";
    test(4, findLCS(a, b));
}

int main() {
    test1();
}
