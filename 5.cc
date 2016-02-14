#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool d[1001][1001];
void solve(string s)
{
	int len = s.size();
	int i, ans;
	for(int i = 0; i < 1001; i++)
		d[0][i] = true;
	for(i = 1; i < len; i++){
		for(int j = 0; j + i < len; j++){
			if(s[j] == s[i + j]){
				if(i == 1){
					ans = j;
					d[i][j] = true;
				}else if(d[i - 2][j + 1]){
					ans = j;
					d[i][j] = true;
				}
			}
		}
	}	
	
	for(int i = len - 1; i >= 0; i--){
		for(int j = 0; j < len; j++)
		if(d[i][j] == true){
			cout << s.substr(j, i + 1) << endl;
			return ;
		}
	}
}
int main()
{
	string s;
	cin >> s;
	solve(s);
	return 0;
}
