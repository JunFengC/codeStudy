#include <iostream>
#include <vector>
using namespace std;

//�ο���Ƶ https://www.bilibili.com/video/BV1fp4y1D7cj/?spm_id_from=333.337.search-card.all.click&vd_source=1cd7a3903057473f84a5d1e84cea3cb9

// ����ά�������߱�������
/*����һ������Ϊi�����ӵ�������(2i + 1);
���ʶ�������Ϊi�����ӵ�������(2i + 2);
������������Ϊi�ĸ����������� ((i - 1) / 2);*/

// ά����  ʱ�临�Ӷ�O(log n)
/*
@param a ά���ѵ�����
@param i ��ά���ڵ���±�
@param n ���鳤��
*/
void heapify(vector<int>& a, int i, int n) {
	int largest = i;
	int lson = 2 * i + 1;
	int rson = 2 * i + 2;
	if (lson < n && a[largest] < a[lson]) {  // ע��Ҫ�Ƚ���Խ���ж�
		largest = lson;
	}
	if (rson < n && a[largest] < a[rson]) {
		largest = rson;
	}
	// ���ҵ�Ҫά���Ľڵ㼰�����Һ��ӵ����ֵ���±ꡣ
	if (i != largest) {
		swap(a[i], a[largest]); // �����ֵ�ŵ�Ҫά���Ľڵ㴦 �Ӷ�������������
		heapify(a, largest, n); // �������µݹ�
	}
}

void heap_sort(vector<int>& a, int n) {
	// ����   ʱ�临�Ӷ�O(n)
	// ���������һ�����ӽڵ��Ԫ�ؿ�ʼ������   
	// i=((n-1)-1)/2 = n/2 -1; n-1���һ��Ԫ�ص�λ�ã�Ȼ��i�����ĸ��ڵ� 
	for (int i = n / 2 - 1; i >= 0; i--) {   // ע����i>=0
		heapify(a, i, n);
	}
	// ����   ʱ�临�Ӷ�O(n logn)
	/*ÿ�ΰ����һ��Ԫ�ػ���a[0]����Ȼ���0����λ��ִ��һ��heapify
	�����ͽ�����Ԫ�طŵ������,Ȼ��i һֱ-- ֱ��>0
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