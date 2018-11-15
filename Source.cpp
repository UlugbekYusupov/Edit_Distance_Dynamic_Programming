#include<stdio.h> 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int Edit_Distance(string str1, string str2, int m, int n, int count)
{
	count++;
	if (m == 0) return n;
	if (n == 0) return m;

	if (str1[m - 1] == str2[n - 1])
		return Edit_Distance(str1, str2, m - 1, n - 1, count);

	return 1 + min(Edit_Distance(str1, str2, m, n - 1, count),
		Edit_Distance(str1, str2, m - 1, n, count),
		Edit_Distance(str1, str2, m - 1, n - 1, count)
	);
}	

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	int  count = 0;
	cout << Edit_Distance(str1, str2, str1.length(), str2.length(), count) << endl;
	cout << count;

	_getch()
	return 0;
}
#include<stdio.h> 
#include<iostream>
#include<string>

using namespace std;
int count = 0;
int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int Edit_Distance(string str1, string str2, int m, int n)
{
	int** dp = new int*[m];
	for (int i = 0; i < m; ++i)
		dp[i] = new int[n];

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1],
					dp[i - 1][j],
					dp[i - 1][j - 1]);
		}
	}

	return dp[m][n];
}
int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;

	cout << Edit_Distance(str1, str2, str1.length(), str2.length()) << endl;

	return 0;
}