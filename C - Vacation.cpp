#include <iostream>

using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	cin >> n;

	int ar[n][3];

	for(int i =0; i < n; i++) 
		for(int j = 0; j < 3; j++) 
			cin >> ar[i][j];
		

	int dp[n][3];

	for(int j = 0; j < 3; j++) {
		dp[0][j] = ar[0][j];
	}

	for(int i = 1; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			int mini =0; 
			for(int k = 0; k < 3; k++) {
				if(k != j) {
					dp[i][j] = max(mini, dp[i-1][k] + ar[i][j]);
					mini = dp[i-1][k] + ar[i][j];
				}
			}
		}
	}

	cout << dp[n-1][2] << '\n';
	
		

	return 0;
}
