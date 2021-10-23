#include <iostream>
#include <algorithm>

using namespace std;

int n, m, height[1000000];
long long sum[1000000];

int search(int value)
{
	int mid, left = 0, right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (height[mid] > value) right = mid - 1;
		else left = mid + 1;
	}
	return left;
}

int cut()
{
	int mid, left = 0, right = height[n - 1], index;
	while (left <= right)
	{
		mid = ((long long)left + right) / 2;
		index = search(mid);
		if (sum[index] - mid * ((long long)n - index) >= m) left = mid + 1;
		else right = mid - 1;
	}

	return right;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> height[i];
	}
	sort(height, height + n);

	sum[n - 1] = height[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		sum[i] = sum[i + 1] + height[i];
	}

	cout << cut();
}