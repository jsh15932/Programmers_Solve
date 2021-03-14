#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int d[27];
map<string, int> mp;
vector<string> dp[27][21];

void Find(string s, int idx, string s2) {
	if(s2.size() > 1) {
		mp[s2]++;
		d[s2.size()] = max(d[s2.size()], mp[s2]);
		dp[s2.size()][mp[s2]].push_back(s2);
	}
	
	for(int i = idx + 1; i < s.size(); i++) {
		s2.push_back(s[i]);
		Find(s, i, s2);
		s2.pop_back();
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> ans;
	
	for(string &s:orders) {
		sort(s.begin(), s.end());
		Find(s, -1, "");
	}
	
	for(int i:course) {
		if(d[i] > 1) {
			for(string s:dp[i][d[i]]) {
				ans.push_back(s);
			}
		}
	}
	
	sort(ans.begin(), ans.end());
	
	return ans;
}
