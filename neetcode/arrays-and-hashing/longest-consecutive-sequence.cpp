#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    if(nums.size() == 1) return 1;

    unordered_set<int> distintNums(nums.begin(), nums.end());

    int result = 0;
    
    for (const int& value : distintNums) {
        if(!distintNums.count(value-1)){
            int interationValue = value+1;
            int countIteration = 1;
            
            while(distintNums.count(interationValue)){
                countIteration++;
                interationValue++;
            }
            
            result = max(countIteration, result);
        }
    }

    if(result == 0) return 1;

    return result;
}

int main()
{
    vector<int> input = {2,20,4,10,3,4,5};
    // vector<int> input = {9,1,4,7,3,-1,0,5,8,-1,6};
    
    cout << longestConsecutive(input);
    
    return 0;
}