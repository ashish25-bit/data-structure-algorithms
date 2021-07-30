// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1

#include <bits/stdc++.h>
using namespace std;

vector<int> inputArray(int n)
{
	int temp;
	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}
	return arr;
}

int main()
{
	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<int> arr = inputArray(n);

		int in = arr[0];
		int out = 0;

		for (int i = 1; i < n; i++)
		{
			int temp = in;
			in = max(out + arr[i], in);
			out = temp;
		}
		cout << in << endl;
	}
	return 0;
}