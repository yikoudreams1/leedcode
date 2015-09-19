/**
 * search a matrix to find the target
 *
 * author: afu
 */

#include <iostream>
#include <vector>

using namespace std;

int findRow(vector<vector<int> >& matrix, int target, int rowTotl);
bool findTarg(vector<int>& targRow, int target, int colmTotl);

// the search function
bool searchMatrix(vector<vector<int> >& matrix, int target) {
    int rowTotl = matrix.size();
    int colmTotl = matrix[0].size();
    int rowTarg = findRow(matrix, target, rowTotl);
    if (rowTarg == -1) {
        return false;
    }
    if (rowTarg == -2) {
        return true;
    }

    return findTarg(matrix[rowTarg], target, colmTotl);
}

// fint the row that the target maybe in
int findRow(vector<vector<int> >& matrix, int target, int rowTotl) {
    int beg = 0;
    int end = rowTotl - 1;
    if (matrix[beg][0] > target) {
        return -1;
    }
    if (matrix[end][0] < target) {
        return rowTotl - 1;
    }
    while ((end - beg) >= 0) {
        if (matrix[end][0] == target || matrix[beg][0] == target) {
            return -2;
        }
        if (matrix[end][0] > target && matrix[beg][0] > target) {
            return beg - 1;
        }
        if (matrix[end][0] < target && matrix[beg][0] < target) {
            return end + 1;
        }
        int mid = (end - beg) / 2;
        if (matrix[mid][0] >= target) {
            end = mid - 1;
        }
        if (matrix[mid][0] < target) {
            beg = mid + 1;
        }
    }
}

// find the target in the row
bool findTarg ( vector<int>& targRow, int target, int colmTotl) {
    int beg = 0;
    int end = colmTotl - 1;
    while ( end >= beg ) {
        int mid = ( beg + end ) / 2;
        if ( targRow[mid] == target ) {
            return true;
        }
        if ( targRow[mid] > target ) {
            end = mid - 1;
        }
        if ( targRow[mid] < target ) {
            beg = mid + 1;
        }
    }
    return false;
}

// other method
bool searchMatrix1(vector<vector<int> >& matrix, int target) {
    if(matrix.size() == 0)
            return false;
    if(matrix[0].size() == 0)
            return false;
    int rowNumber = 0;
    int colNumber = matrix[0].size()-1;
    while(rowNumber < matrix.size() && colNumber >= 0)
        {
            if(target < matrix[rowNumber][colNumber])
                --colNumber;
            else if(target > matrix[rowNumber][colNumber])
                ++rowNumber;
            else
            return true;
        }
    return false;
}

// print out the result of test
void test( bool expected, bool actual ) {
    if ( expected == actual ) {
        cout << "success !!!" << endl;
    }
    if ( expected != actual ) {
        cout << "failed !!!" << endl;
        cout << "expected : " << expected << endl;
        cout << "actual : " << actual << endl;
    }
}

// test1 
void test1 () {
    vector<vector<int> > a;
    vector<int> a0;
    a0.push_back(1);
    a0.push_back(3);
    a0.push_back(5);
    a0.push_back(7);
    vector<int> a1;
    a1.push_back(10);
    a1.push_back(11);
    a1.push_back(16);
    a1.push_back(20);
    vector<int> a2;
    a2.push_back(23);
    a2.push_back(30);
    a2.push_back(34);
    a2.push_back(50);
    a.push_back( a0 );
    a.push_back( a1 );
    a.push_back( a2 );
    cout << "testing test1 ..." << endl;
    test(true, searchMatrix1(a, 3));
}

// test2 
void test2 () {
    vector<vector<int> > a;
    vector<int> a0;
    a0.push_back(1);
    a0.push_back(3);
    a0.push_back(5);
    a0.push_back(7);
    vector<int> a1;
    a1.push_back(10);
    a1.push_back(11);
    a1.push_back(16);
    a1.push_back(20);
    vector<int> a2;
    a2.push_back(23);
    a2.push_back(30);
    a2.push_back(34);
    a2.push_back(50);
    a.push_back( a0 );
    a.push_back( a1 );
    a.push_back( a2 );
    cout << "testing test2 ..." << endl;
    test(false, searchMatrix1(a, 14));
}

// main function
int main( ) {
    test1();
    test2();
}
