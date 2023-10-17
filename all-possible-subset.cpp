#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1e18

const ll P = 29, N = 2e5 + 50, mod = 1e9 + 7;

int main() {
	//https://www.hackerrank.com/contests/srbd-code-contest-2023-round-1/challenges
	//freopen("input.txt", "r", stdin);
  //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  ll t = 1;
  cin >> t;
  for (ll T = 1; T <= t; T++) {
    string s;
    cin >> s;
    vector<string> color = {"blue", "green", "yellow", "red", "purple", "orange", "pink", 
    	"grey", "cyan", "brown", "ash", "silver", "gold", "white", "black"
	  };
	  ll siz = s.size();
	  vector<ll> temp(35, 0);
	  for (ll i = 0; i < siz; i++) {
	  	ll id = s[i] - 'a' + 1;
	  	temp[id]++;
	  }
	  ll len = color.size(), res = 0;
	  for (ll i = 1; i < (1 << len); i++) {
	  	ll curr = 0;
	  	vector<ll> cnt = temp;
	  	for (ll j = 0; j < len; j++) {
	  		if (i & (1 << j)) {
	  			bool ok = 1;
	  			for (auto k : color[j]) {
	  				ll id = k - 'a' + 1;
	  				if (cnt[id] <= 0) {ok = 0;}
	  				cnt[id]--;
	  			}
	  			if (ok == 0) {
	  				for (auto k : color[j]) {
		  				ll id = k - 'a' + 1;
		  				cnt[id]++;
		  			}
		  			continue;
	  			}
	  			curr++;
	  		}
	  	}
	  	res = max(res, curr);
	  }
	  cout << res << "\n";
  }
  return 0;
}



