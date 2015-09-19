/**
 * search for a range int a sorted list
 * use half search
 *  
 * author: afu
 */

#include <iostream>
#include <vector>

using namespace std;

int GetFirstK(vector<int>& nums, int length, int target, int start, int end);
int GetLastK(vector<int>& nums,  int length, int target, int start, int end);

vector<int> searchForARange(vector<int>& nums,  int target)
{
    vector<int> ret; 
    int length = nums.size();
    if(length > 0)
    {
        int first = GetFirstK(nums, length, target, 0, length - 1);
        int last = GetLastK(nums, length, target, 0, length - 1);
        ret.push_back(first);    
        ret.push_back(last);    
    }

    return ret; 
}

// 找到数组中第一个target的下标。如果数组中不存在target，返回-1
int GetFirstK(vector<int>& nums, int length, int target, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = nums[middleIndex];

    if(middleData == target)
    {
        if((middleIndex > 0 && nums[middleIndex - 1] != target) 
            || middleIndex == 0)
            return middleIndex;
        else
            end  = middleIndex - 1;
    }
    else if(middleData > target)
        end = middleIndex - 1;
    else
        start = middleIndex + 1;

    return GetFirstK(nums, length, target, start, end);
}

// 找到数组中最后一个target的下标。如果数组中不存在target，返回-1
int GetLastK(vector<int>& nums, int length, int target, int start, int end)
{
    if(start > end)
        return -1;

    int middleIndex = (start + end) / 2;
    int middleData = nums[middleIndex];

    if(middleData == target)
    {
        if((middleIndex < length - 1 && nums[middleIndex + 1] != target) 
            || middleIndex == length - 1)
            return middleIndex;
        else
            start  = middleIndex + 1;
    }
    else if(middleData < target)
        start = middleIndex + 1;
    else
        end = middleIndex - 1;

    return GetLastK(nums, length, target, start, end);
}

// ====================测试代码====================
void Test(char* testName, int nums[],  int target, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = searchForARange(nums, length, target);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int nums[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", nums, sizeof(nums) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int nums[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", nums, sizeof(nums) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int nums[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", nums, sizeof(nums) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int nums[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", nums, sizeof(nums) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int nums[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", nums, sizeof(nums) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int nums[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", nums, sizeof(nums) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int nums[] = {3, 3, 3, 3};
    Test("Test7", nums, sizeof(nums) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int nums[] = {3, 3, 3, 3};
    Test("Test8", nums, sizeof(nums) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int nums[] = {3};
    Test("Test9", nums, sizeof(nums) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int nums[] = {3};
    Test("Test10", nums, sizeof(nums) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
}

int _tmain(int argc, _TCHAR* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();
    Test11();

    return 0;
}

