// 1209 移除元素：
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 快慢指针
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(nums[fastIndex] != val){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};