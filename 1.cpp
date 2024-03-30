//
// Created by ogier on 2024/3/30.
//
#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int> &nums, int target){
        unordered_map<int,int>map;
        for(int i = 0; i < nums.size(); ++i){
            if(map.find(target - nums[i]) != map.end()){
                return {i,map.find(target-nums[i])->second};
            }
            map[nums[i]] = i;
        }
        return {};  
    }    
};
