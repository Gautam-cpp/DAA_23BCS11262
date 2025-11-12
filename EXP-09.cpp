
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> search(string pat, string txt) {
        vector<int> res;
        int n = txt.length();
        int m = pat.length();

        for (int i = 0; i <= n - m; i++) {
            if (txt.substr(i, m) == pat)
                res.push_back(i + 1); // 1-based index (same as Java)
        }
        return res;
    }
};

int main() {
    string txt, pat;
    cout << "Enter text: ";
    getline(cin, txt);
    cout << "Enter pattern: ";
    getline(cin, pat);

    Solution s;
    vector<int> result = s.search(pat, txt);

    if (result.empty()) {
        cout << "Pattern not found." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int pos : result)
            cout << pos << " ";
        cout << endl;
    }

    return 0;
}
