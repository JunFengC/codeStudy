#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// �жϵ����Ƿ�����Ӵ�"PDD"
bool containsPDD(const string& word)
{
    return word.find("PDD") != string::npos;
}

// �Զ����������
bool customSort(const string& a, const string& b)
{
    bool a_contains = containsPDD(a);
    bool b_contains = containsPDD(b);

    // ���һ�����ʰ���"PDD"����һ�������������������������
    if (a_contains && !b_contains) return true;
    if (!a_contains && b_contains) return false;

    // �������ֵ�������
    return a < b;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> words(N);

    // ���뵥��
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // ʹ���Զ�������������
    sort(words.begin(), words.end(), customSort);

    // ���ǰM������
    for (int i = 0; i < M; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}
