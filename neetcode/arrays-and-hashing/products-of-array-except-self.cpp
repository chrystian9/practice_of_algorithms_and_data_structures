#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) { // time: O(n) | space: O(1)
    vector<int> result(nums.size(), 0);

    // for(int i=0; i<nums.size(); i++){ // O(n^2)
    //     for(int j=0; j<nums.size(); j++){
    //         if(j != i){
    //             result[i] *= nums[j];
    //         }
    //     }    
    // }

    int prefix = 1;
    for(int i=0; i<nums.size(); i++){ // O(n)
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for(int i=nums.size()-1; i>=0; i--){ // O(n)
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main()
{
    vector<int> input = {1,2,4,6};
    // vector<int> input = {-1,0,1,2,3};
    
    vector<int> result = productExceptSelf(input);
    
    for(const int& value : result){
        cout << value << " ";
    }
    
    return 0;
}