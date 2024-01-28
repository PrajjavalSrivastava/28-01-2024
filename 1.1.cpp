#include <iostream>
#include <vector>
using namespace std;

// Function to find the length of the longest LCS
int LCSubStr(string s, string t, int n, int m)
{
	// Create DP table
	vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
	int res = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i - 1] == t[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				if (dp[i][j] > res)
					res = dp[i][j];
			}
			else
				dp[i][j] = 0;
		}
	}
	return res;
}

// Driver Code
int main()
{
	string X = "dddabcaafdgssfdgsdg";
	string Y = "bbbabcdeffffffff";
	int m = X.length();
	int n = Y.length();

	cout << LCSubStr(X, Y, m, n);
	return 0;
}

// Time Complexity: O(n*m)
// Auxiliary Space: O(min(m,n))
