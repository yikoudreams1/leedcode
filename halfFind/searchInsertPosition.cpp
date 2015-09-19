/**
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 *
 * author: afu
 */

#include <iostream>
#include <vector>

using namespace std;

// search funtion 
int searchInseartPosition(vector<int>& nums, int target) {
    int beg = 0;
    int end = nums.size() - 1;
    while(end >= beg) {
            int mid = (beg + end) / 2;
            int midValue = nums[mid];
            if(midValue == target) {
                    return mid;
            }
            if(midValue > target) {
                    end = mid - 1;
            }
            if(midValue < target) {
                    beg = mid + 1;
            }
     }
// 是个好思路，就算2这样的无法除尽的也可以通过下面的来整，帅
     return (beg + end + 1) / 2;
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

// test1 测试略
void test1() {
    vector<......
    test(4,searchInseartPosition(16));
}

// main function
int main() {
    test1();
}
