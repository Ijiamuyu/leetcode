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
        int ret = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < 32; j++)
            {
                if(nums[i] & (1 << j))
                {
                    array[j]++;
                }
            }
        }
        for(int i = 0; i < 32; i++)
        {
            if(array[i] % 3)
            {
                ret += ((array[i] % 3) << i);
            }
        }
        return ret;
    }
}; 
