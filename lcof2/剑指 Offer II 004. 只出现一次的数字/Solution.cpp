#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int cnt = 0;
            for (int x : nums) {
                cnt += (x >> i) & 1;
            }
            cnt %= 3;
            ans |= cnt << i;
        }
        return ans;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> array(32);
        array.assign(array.size(), 0);
        int ret = 0;
        for(int i = 0; i < 32; i++)
        {
            for(int j = 0; j < nums.size(); j++)
            {
                array[i] += (nums[j] >> i) & 1;
            }
            array[i] %= 3;
            ret |= array[i] << i;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    int a[4] = {2,2,3,2};
    vector<int> b;
    b.insert(b.begin(),a,a+4);
    int result = solution.singleNumber(b);
    cout << "Result of  Solution  is: " << result << endl;

    return 0;
}

