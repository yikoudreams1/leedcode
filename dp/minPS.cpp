/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 *
 * author: afu
 */

#include <iostream>
#include <vector>

using namespace std;

int minPS(vector<vector<int> >& grid) {
    int m = grid.size();
    int n = grid.back().size();
    int *dp = new int[n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(i == 0) {
                if(j == 0) {
                    dp[j] = grid[i][j];
                    continue;
                }
                dp[j] = dp[j - 1] + grid[i][j];
                continue;
            }
            if(j == 0) {
                dp[j] = dp[j] + grid[i][j];
                continue;
            }
            dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n-1]; 
}

// print out the result
void test(int expected, int actual) {
    if(expected == actual) {
        cout << "success!!!" << endl;
    }
    if(expected != actual) {
        cout << "failed!!" << endl;
        cout << "expected: "  << expected << endl;
        cout << "actual: " << actual << endl;
    
    }
}

// test1 
// 1  2  3
// 1  2  3
// 1  2  3
void test1() {
    vector<vector<int> > a;
    vector<int> b;
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(b);
    b.clear();
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(b);
    b.clear();
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    a.push_back(b);
    b.clear();
    test(8, minPS(a));
}

int main() {
    test1();
}
