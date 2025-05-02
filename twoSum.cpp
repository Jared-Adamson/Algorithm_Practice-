class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int length = nums.size();
        std::vector<int> sumArr;
        bool stop = false;

        for (int i=0; i < length  && !stop; i++){
            for(int k=i+1; k < length; k++){
                if(nums[i]+nums[k] == target){
                    sumArr.push_back(i);
                    sumArr.push_back(k);
                    stop = true;
                    break;
                }
            }
        }
       

        return sumArr;
    }
};
