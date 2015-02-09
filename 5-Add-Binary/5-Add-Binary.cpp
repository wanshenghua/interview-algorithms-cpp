#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(const string &a, const string &b) {
		int m = a.length();
		int n = b.length();
		int carry = 0;
		string res("");
		int max_len = max(m, n);
		for(int i = 0; i < max_len; i++){
			int p = (i < m) ? a.c_str()[m - i - 1] - '0' : 0;
			int q = (i < n) ? b.c_str()[n - i - 1] - '0' : 0;
			int tmp = p + q + carry;
			carry = tmp / 2;
			string prefix = (tmp % 2) ? string("1") : string("0");
			res  = prefix + res;
		}
		return (carry) ? string("1") + res : res;
	}

};

int main()
{
	Solution sol;
	string a("11");
	string b("1");
	cout << sol.addBinary(a, b) << endl;
	return 0;
}