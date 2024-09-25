#include <iostream>
#include <vector>
using namespace std;

//ѡ������
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

//ð�����������Ƚϣ��𲽺���
void BubbleSort(vector<int>& nums)
{
    for (int i = 0; i < nums.size() - 1; i++) {
        bool falg = true; // �Ż� ���û�з�����������ǰ����
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

//�������� ����˼�룬ȷ����׼PartSort,�ٶ����������ֽ���ͬ������
//�ݹ�ṹ�������ڶ�������ǰ�����
int partSort(vector<int>& nums, int left, int right)
{
    // ����ָ��  ��ָ��ָ������<=��׼��Ԫ�ص�ĩβ��
    //��ָ�����Ѱ����������������Ȼ����н�����
    //ps:��slow+1=fastʱ������Ҫ�����������Ҫ�ѻ�׼Ԫ�طŵ��м�Ȼ�󷵻�
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
    // �ݹ���ֹ����
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