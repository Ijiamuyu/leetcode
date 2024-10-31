class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1, j = b.size() - 1;
        for (int carry = 0; i >= 0 || j >= 0 || carry; --i, --j) {
            carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry % 2) + '0');
            carry /= 2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = a.size() - 1;
        int j = b.size() - 1;
        for(int carry = 0; i >= 0 || j >= 0 || carry; i--, j--)
        {
            carry += (i > -1 ? (a[i] - '0') : 0) + (j > -1 ? ( b[j] - '0') : 0);
            switch(carry)
            {
                case 0:
                    ans.push_back('0');
                    break;
                case 1:
                    ans.push_back('1');
                    carry = 0;
                    break;
                case 2:
                    ans.push_back('0');
                    carry = 1;
                    break;
                case 3:
                    ans.push_back('1');
                    carry = 1;
                    break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution solution;

    string a = "11";
    string b = "10";
    string result = solution.addBinary(a, b);
    cout << "The sum of " << a << " and " << b << " is: " << result << endl;
    return 0;
}
