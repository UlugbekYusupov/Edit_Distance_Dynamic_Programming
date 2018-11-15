#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}

int Edit_Distance(string str1, string str2, int m, int n)
{

	int dp[300][300];
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

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[m][n];
}
int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;

	cout << Edit_Distance(str1, str2, str1.length(), str2.	length()) << endl;

	return 0;
}
