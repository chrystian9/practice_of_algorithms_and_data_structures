#include <iostream>
#include <vector>

using namespace std;

vector<int> quickSort(vector<int> values){
    if(values.size() < 2){
        return values;
    } else {
        vector<int> sortArray;
        
        int pivotIndex = (values.size()/2)-1;
        int pivot = values[pivotIndex];
        
        vector<int> leftArray;
        vector<int> rightArray;
        
        for (int x=0; x<pivotIndex; x++) {
            if(values[x] <= pivot){
                leftArray.push_back(values[x]);
            }else{
                rightArray.push_back(values[x]);
            }
        }
        
        for (int x=pivotIndex+1; x<values.size(); x++) {
            if(values[x] <= pivot){
                leftArray.push_back(values[x]);
            }else{
                rightArray.push_back(values[x]);
            }
        }
        
        vector<int> leftSortArray = quickSort(leftArray);
        vector<int> rightSortArray = quickSort(rightArray);
    
        for (int value : leftSortArray) {
            sortArray.push_back(value);
        }
        
        sortArray.push_back(pivot);
        
        for (int value : rightSortArray) {
            sortArray.push_back(value);
        }
    
        return sortArray;
    }
}

int main()
{
    vector<int> values = {20, 3, 6, 4, 8, 15};
    
    values = quickSort(values);
    
    for (int value : values) {
        cout << value << " ";
    }
    
    return 0;
}