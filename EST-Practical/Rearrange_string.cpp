
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s) freq[c - 'a']++;

        int mx = 0, ch = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > mx) {
                mx = freq[i];
                ch = i;
            }
        }

        if (mx > (n + 1) / 2) return "";

        vector<char> ans(n);
        int idx = 0;

        while (freq[ch] > 0) {
            ans[idx] = 'a' + ch;
            idx += 2;
            freq[ch]--;
        }

        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (idx >= n) idx = 1;
                ans[idx] = 'a' + i;
                idx += 2;
                freq[i]--;
            }
        }

        return string(ans.begin(), ans.end());
    }
};
