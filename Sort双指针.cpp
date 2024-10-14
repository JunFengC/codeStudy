#include <iostream>
#include <vector>
using namespace std;
// 双指针法   注意移动顺序
void qsort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	int key = nums[left];   //基准在左
	while (i < j) {
		while (nums[j] >= key && i < j)    //先移动右指针
			j--;
		while (nums[i] <= key && i < j)
			i++;
		if (i < j)	swap(nums[i], nums[j]);    //  i=j时不交换
	}
	swap(nums[left], nums[j]);   // 把最左边的基准元素放到i=j处
	qsort(nums, i + 1, right);    // 对剩下的左右部分进行递归
	qsort(nums, left, i - 1);
}

int main()
{
	vector<int> a = { 0,82,9,4,20,56,41,2,12 };
	qsort(a, 0, a.size() - 1);
	for (int i : a) {
		cout << i << endl;
	}
	return 0;
}
