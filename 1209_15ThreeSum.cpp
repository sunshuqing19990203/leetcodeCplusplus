class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 两个指针，头尾指针 i, left, right
        //1. 首先对数组进行排序
        sort(nums.begin(),nums.end());
        vector<vector<int>> results;
        // a = nums[i], b = nums[left], c = nums[right], a < b < c
        // 对i进行从0到nums.size()的循环，
        // 固定i，初始值left=i+1，right=nums.size()-1,
        // 若a+b+c<0，则left++;
        // 若a+b+c==0，则将a,b,cpush进results;left++,right--;
        // 若a+b+c>0,则right--
        // 循环条件是left<right

        // 考虑去重复当数组已经排序后，如果出现重复则一定是在相邻数据间
        // i可能引起重复，譬如nums[i]==nums[i-1]
        // left可能引起重复

        int size = nums.size();
        for (int i = 0; i < size; i++){            
            int left = i + 1;
            int right = size - 1;
            // int a = nums[i];
            // int b = nums[left];
            // int c = nums[right];
            // 特殊情况的判断非常重要，可以减少时间消耗
            if(nums[i] > 0)
                continue;
            else if(nums[right] < 0)
                return results;
    
            // 去重复
            else if(i > 0 && nums[i] == nums[ i - 1])
                continue;
            // 普遍情况
            while(left < right){
                if(nums[i] + nums[left] + nums[right] < 0) 
                    left++;
                else if(nums[i] + nums[left] + nums[right] > 0)
                    right--;
                else{
                    results.push_back(vector<int>{nums[i],nums[left],nums[right]});
            
                    // 考虑去重复
                    while(left < right && nums[left] == nums[left + 1]) 
                        left++;
                    while(left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                    
                    
                    
                }
            }
        }

        return results;
    }
};



