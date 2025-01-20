#include <iostream>
#include <vector>
using namespace std;

int min(vector<int> values){
    int minValue = values.front();
    int minIndex = 0;
    int index = 0;
    
    for (int value : values) {
        if (minValue > value) {
            minIndex = index;
        }
        index++;
    }
    
    return minIndex;
}

vector<int> selectionSort(vector<int> values){
    vector<int> orderValues;
    int size = values.size();
    
    for (int x=0; x<size; x++) {
        int minValueIndex = min(values);
        
        orderValues.push_back(values[minValueIndex]);
        
        values.erase(values.begin() + minValueIndex);
    }
    
    return orderValues;
}

int main()
{
    vector<int> values = {5, 4, 3, 2, 10};
    
    values = selectionSort(values);
    
    for (int value : values) {
        cout << value << " ";
    }
    
    return 0;
}