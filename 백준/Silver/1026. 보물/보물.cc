#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> a;
    vector<int> b;

	cin >> N;
    int num;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		a.push_back(num);
	}

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		b.push_back(num);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<>());
	int res = 0;
	for (int i = 0; i < N; i++) {
		res += a[i] * b[i];
	}
	cout << res;
}