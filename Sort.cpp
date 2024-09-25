#include <iostream>
#include <vector>
using namespace std;

//选择排序
void selectSort(vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(nums[i], nums[minIndex]);
        }
    }
}

//冒泡排序，两两比较，逐步后移
void BubbleSort(vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++) {
        bool falg = true; // 优化 如果没有发生交换，提前结束
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                nums[j] = nums[j] ^ nums[j + 1];
                nums[j + 1] = nums[j] ^ nums[j + 1];
                nums[j] = nums[j] ^ nums[j + 1];
                falg = false;
            }
        }
        if (falg) break;
    }
}

//快速排序 分治思想，确定基准PartSort,再对左右两部分进行同样操作
//递归结构，类似于二叉树的前序遍历
int partSort(vector<int>& nums, int left, int right)
{
    // 快慢指针  慢指针指向满足<=基准的元素的末尾，
    //快指针遍历寻找满足条件的数，然后进行交换。
    //ps:当slow+1=fast时，不需要交换；最后需要把基准元素放到中间然后返回
    int keyi = left;
    int slow = left;
    int fast = left + 1;
    while (fast <= right) {
        if (nums[fast] <= nums[keyi] && ++slow != fast) {
            swap(nums[slow], nums[fast]);
        }
        fast++;
    }
    swap(nums[keyi], nums[slow]);
    keyi = slow;
    return keyi;
}
void QuickSort(vector<int>& nums, int begin, int end)
{
    // 递归终止条件
    if (begin >= end)    return;
    int key = partSort(nums, begin, end);
    QuickSort(nums, begin, key - 1);
    QuickSort(nums, key + 1, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    //BubbleSort(nums);
    //selectSort(nums);
    QuickSort(nums, 0, nums.size() - 1);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << endl;
    }
    return 0;
}