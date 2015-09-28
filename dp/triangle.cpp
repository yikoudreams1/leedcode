/**
 * Given a triangle, find the minimum path sum from top to bottom. 
 *  Each step you may move to adjacent numbers on the row below.
 *
 *  author: afu
 */

#include <iostream>
#include <vector> 

using namespace std;

int nFactorial(int n);

// handle the triangle;
int minSum(vector<vector<int> >& triangle) {
    int n = triangle.size();
    int length = nFactorial(n);
    int *dp = new int[length];
    dp[0] = triangle[0][0];
    for(int i = 1; i < n; i++) {
        int m = triangle[i].size();
        for(int j = 0; j < m; j++) {
            if(j == 0) {
                dp[nFactorial(i)] = dp[nFactorial(i - 1)] + triangle[i][0];
                continue;
            }
            if(j == m - 1) {
                dp[nFactorial(i) + j] = dp[nFactorial(i)  - 1] + triangle[i][m - 1];
                continue;
            }
            dp[nFactorial(i) + j] = triangle[i][j] + ((dp[nFactorial(i - 1) + j] > dp[nFactorial(i - 1) + j - 1]) ? dp[nFactorial(i - 1) + j - 1] : dp[nFactorial(i - 1) + j]);
        }
    }
    int ret = dp[nFactorial(n - 1)];
    for(int i = 0; i < length; i++) {
        cout << dp[i] << endl;
    }
    for(int i = nFactorial(n - 1) + 1; i < length; i ++) {
        ret = (ret > dp[i]) ? dp[i] : ret;
    }
    
    return ret;
}

// the function to get the n!
int nFactorial(int n) {
    int length = 0;
    for(int i = 1; i <= n; i++) {
        length += i;
    }
    return length;
}
 
// *--------------better method----------------*
int minimumTotal(vector<vector<int> > &triangle) {  
      int row = triangle.size();  
      if(row ==0) return 0;  
     vector<int> minV(triangle[row-1].size());  
     for(int i =row-1; i>=0; i--)  
      {  
       int col = triangle[i].size();  
       for(int j =0; j<col; j++)  
        {  
          if(i == row-1)  
          {  
            minV[j] = triangle[i][j];  
            continue;  
          }  
          minV[j] = min(minV[j], minV[j+1]) + triangle[i][j];  
        }  
      }  
      return minV[0];  
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

// test1
void test1() {
    vector<vector<int> > a;
    vector<int> a0, a1, a2;
    a0.push_back(2);
    a1.push_back(3);
    a1.push_back(4);
    a2.push_back(6);
    a2.push_back(5);
    a2.push_back(7);
    a.push_back(a0);
    a.push_back(a1);
    a.push_back(a2);
    test(10, minSum(a)); 
}

// main function
int main() {
    test1();
}
