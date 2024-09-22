#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 判断单词是否包含子串"PDD"
bool containsPDD(const string& word)
{
    return word.find("PDD") != string::npos;
}

// 自定义排序规则
bool customSort(const string& a, const string& b)
{
    bool a_contains = containsPDD(a);
    bool b_contains = containsPDD(b);

    // 如果一个单词包含"PDD"而另一个不包含，则优先排序包含的
    if (a_contains && !b_contains) return true;
    if (!a_contains && b_contains) return false;

    // 否则按照字典序排序
    return a < b;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<string> words(N);

    // 输入单词
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    // 使用自定义规则进行排序
    sort(words.begin(), words.end(), customSort);

    // 输出前M个单词
    for (int i = 0; i < M; ++i) {
        cout << words[i] << endl;
    }

    return 0;
}
