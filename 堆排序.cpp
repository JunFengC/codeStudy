#include <iostream>
#include <vector>
using namespace std;

//参考视频 https://www.bilibili.com/video/BV1fp4y1D7cj/?spm_id_from=333.337.search-card.all.click&vd_source=1cd7a3903057473f84a5d1e84cea3cb9

// 数组维护堆所具备的性质
/*性质一：索引为i的左孩子的索引是(2i + 1);
性质二：索引为i的左孩子的索引是(2i + 2);
性质三：索引为i的父结点的索引是 ((i - 1) / 2);*/

// 维护堆  时间复杂度O(log n)
/*
@param a 维护堆的数组
@param i 待维护节点的下标
@param n 数组长度
*/
void heapify(vector<int>& a, int i, int n) {
	int largest = i;
	int lson = 2 * i + 1;
	int rson = 2 * i + 2;
	if (lson < n && a[largest] < a[lson]) {  // 注意要先进行越界判断
		largest = lson;
	}
	if (rson < n && a[largest] < a[rson]) {
		largest = rson;
	}
	// 先找到要维护的节点及其左右孩子的最大值的下标。
	if (i != largest) {
		swap(a[i], a[largest]); // 把最大值放到要维护的节点处 从而满足大根堆性质
		heapify(a, largest, n); // 继续向下递归
	}
}

void heap_sort(vector<int>& a, int n) {
	// 建堆   时间复杂度O(n)
	// 从最下面第一个有子节点的元素开始，遍历   
	// i=((n-1)-1)/2 = n/2 -1; n-1最后一个元素的位置，然后i是它的父节点 
	for (int i = n / 2 - 1; i >= 0; i--) {   // 注意是i>=0
		heapify(a, i, n);
	}
	// 排序   时间复杂度O(n logn)
	/*每次把最后一个元素换到a[0]处，然后对0索引位置执行一次heapify
	这样就将最大的元素放到了最后,然后i 一直-- 直到>0
	*/
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		heapify(a, 0, i);
	}
}

int main() {
	vector<int> a = { 0,22,4,52,0,15,9,36,-5 };
	heap_sort(a, a.size());
	for (int i : a) {
		cout << i << endl;
	}
	return 0;
}