#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool hasDuplicate(vector<int>& nums){
    set<int> setWithNums(nums.begin(), nums.end());

    return nums.size() != setWithNums.size();
}

int main()
{
    vector<int> values = {5, 4, 3, 2, 10};
    
    cout << hasDuplicate(values);
    
    return 0;
}