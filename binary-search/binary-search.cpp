#include <iostream>

int binarySearch(int list[5], int value){
    int end = 4;
    int initial = 0;
    int mid;
    
    while(initial <= end){
        mid = (end + initial) / 2;
        
        if (list[mid] == value) {
            return mid;   
        } else if (list[mid] > value) {
            end = mid - 1;
        } else {
            initial = mid + 1;
        }
    }
    
    return -1;
}

int main()
{
    int list[5] = {1, 4, 6, 7, 10};
    
    int value = -1;
    
    std::cin >> value;
    
    int result = binarySearch(list, value);
    
    if (result == -1)
        std::cout << "Not found";
    else
        std::cout << "Position " << result;

    return 0;
}