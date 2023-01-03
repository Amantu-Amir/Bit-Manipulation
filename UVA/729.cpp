#include<iostream>
using namespace std;

int main() {
	int t, flag = 0;
	cin >> t;
	while (t--) {
		int n, h;
		cin >> n >> h;
		int num = 0;
		for (int i = 0; i < h; i++) {
			num += (1 << i);
		}
		if (flag) cout << "\n";
		flag = 1;
		while (1) {
			int temp = num, one = 0, cnt = 0;
			char str[n+5];
			for (int i = 0; i <= n; i++) str[i] = '0';
			while (temp) {
				if (temp % 2) {
					one++;
					str[cnt] = '1';
				}
				cnt++;
				temp /= 2;
			}
			if (cnt > n) break;
			if (cnt <= n and one == h) {
				int dif = n - cnt;
				for (int i = 0; i < dif; i++) cout << "0";
				for (int i = cnt - 1; i >= 0; i--) cout << str[i];
				cout << "\n";
			}
			num++;
		}
	}	
}
