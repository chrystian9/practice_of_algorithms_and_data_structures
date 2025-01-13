#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) { // O(n) 
    unordered_map<int, int> indexToNum;
    
    for(int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        
        if(indexToNum.find(complement) != indexToNum.end()) 
            return {indexToNum[complement], i};
        
        indexToNum[nums[i]] = i;
    }

    return {};
}

int main()
{
    vector<int> input = {3,4,5,6};
    
    vector<int> result = twoSum(input, 7);
    
    for(const int& v : result){
        cout << v << " ";
    }
    
    return 0;
}