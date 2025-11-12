
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        vector<vector<int>> ans;
        for (auto& entry : freq) {
            ans.push_back({entry.first, entry.second});
        }

        return ans;
    }
};

int main() {
    Solution s;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> result = s.countFreq(arr);

    cout << "\nElement - Frequency\n";
    for (auto& pair : result) {
        cout << pair[0] << " - " << pair[1] << endl;
    }

    return 0;
}
