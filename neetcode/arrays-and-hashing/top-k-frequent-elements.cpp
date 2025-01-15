#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) { // O(N)
    unordered_map<int, int> quantByValue;
    vector<vector<int>> valuesByQuant(nums.size());
    vector<int> result;

    for(const int& value : nums){ // O (n)
        quantByValue[value]++;
    }

    for(const auto& pair : quantByValue){ // O (n)
        valuesByQuant[pair.second-1].push_back(pair.first);
    }
    
    for(int i=nums.size()-1; i>=0; i--){ // O (n)
        if(valuesByQuant[i].size() > 0 and result.size() < k){
            for(const int& value : valuesByQuant[i]){
                if(result.size() < k){
                    result.push_back(value);
                }
            }
        }
    }

    return result;
}

int main()
{
    vector<int> input = {1,2,2,3,3,3};
    int k = 2;
    
    // vector<int> input = {7,7};
    // int k = 1;
    
    vector<int> result = topKFrequent(input, k);
    
    for(const int& value : result){
        cout << value << " ";
    }
    
    return 0;
}