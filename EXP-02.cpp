
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;
        if (exp < 0) {
            x = 1 / x;
            exp = -exp;
        }
        return power(x, exp);
    }

private:
    double power(double base, long exp) {
        if (exp == 0) return 1;

        double half = power(base, exp / 2);

        if (exp % 2 == 0) {
            return half * half;
        } else {
            return half * half * base;
        }
    }
};

int main() {
    Solution s;
    double x;
    int n;

    cout << "Enter base: ";
    cin >> x;
    cout << "Enter exponent: ";
    cin >> n;

    cout << "Result: " << s.myPow(x, n) << endl;
    return 0;
}
