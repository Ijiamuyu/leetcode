class Solution {
public:
    int divide(int a, int b) {
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
};

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    int divide(int a, int b)
    {
        if (a == INT_MIN && b == -1)
            return INT_MAX;
        int negative = 0, ans = 0, flag = 0;
        if (a < 0)
        {
            negative++;
            if (a == INT_MIN)
            {
                a = INT_MAX;
                flag = 1;
            }
            else
            {
                a = -a;
            }
        }
        if (b < 0)
        {
            negative++;
            b = -b;
        }
        while (a >= b)
        {
            int d = b, c = 1;
            while (d < INT_MAX >> 1 && (d + d <= a))
            {
                d += d;
                c += c;
            }
            a -= d;
            ans += c;
            if (flag)
            {
                a += 1;
                flag = 0;
            }
        }
        return negative == 1 ? -ans : ans;
    }
};

int main()
{
    Solution solution;
    int a = INT_MIN;
    int b = 1;
    int result = solution.divide(a, b);
    cout << "Result of " << a << " divided by " << b << " is: " << result << endl;

    return 0;
}
