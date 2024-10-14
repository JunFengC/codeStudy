#include <iostream>
#include <vector>
using namespace std;
// ˫ָ�뷨   ע���ƶ�˳��
void qsort(vector<int>& nums, int left, int right) {
	if (left >= right) return;
	int i = left, j = right;
	int key = nums[left];   //��׼����
	while (i < j) {
		while (nums[j] >= key && i < j)    //���ƶ���ָ��
			j--;
		while (nums[i] <= key && i < j)
			i++;
		if (i < j)	swap(nums[i], nums[j]);    //  i=jʱ������
	}
	swap(nums[left], nums[j]);   // ������ߵĻ�׼Ԫ�طŵ�i=j��
	qsort(nums, i + 1, right);    // ��ʣ�µ����Ҳ��ֽ��еݹ�
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
