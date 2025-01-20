#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// bool isValidSudoku(vector<vector<char>>& board) { // time: O(n^2) space: O(n^2)
//     unordered_map<int, unordered_map<char, int>> map;
    
//     for(int i=0; i<9; i++){
//         for(int j=0; j<9; j++){
//             char value = board[i][j];

//             if(value != '.'){
//                 if(map[i].find(value) != map[i].end()){
//                     map[i][value]++;
//                 } else {
//                     map[i][value] = 1;
//                 }
//             }
            
//             if(map[i][value] > 1){
//                 return false;
//             }
//         }
//     }
    
//     map.clear();

//     for(int i=0; i<9; i++){
//         for(int j=0; j<9; j++){
//             char value = board[j][i];

//             if(value != '.'){
//                 if(map[i].find(value) != map[i].end()){
//                     map[i][value]++;
//                 } else {
//                     map[i][value] = 1;
//                 }
//             }
            
//             if(map[i][value] > 1){
//                 return false;
//             }
//         }
//     }

//     map.clear();
    
//     int subRow = 0;
//     int subColumn = 0;
//     int subBoxeIndex = 0;
//     for(int i=subRow; i<subRow+3; i++){
//         for(int j=subColumn; j<subColumn+3; j++){
//             char value = board[i][j];
                
//             if(value != '.'){
//                 if(map[subBoxeIndex].find(value) != map[subBoxeIndex].end()){
//                     map[subBoxeIndex][value]++;
//                 } else {
//                     map[subBoxeIndex][value] = 1;
//                 }
//             }
            
//             if(map[subBoxeIndex][value] > 1){
//                 return false;
//             }    
//         }
        
//         if(i == subRow+2){
//             if(subRow+3 < 9){
//                 subRow += 3;
//                 subBoxeIndex++;
//             } else if(subColumn+3 < 9) {
//                 i = 0;
//                 subRow = 0;
//                 subColumn += 3;
//                 subBoxeIndex++;
//             }
//         }
//     }
    
//     return true;
// }

bool isValidSudoku(vector<vector<char>>& board) { // time: O(n^2) space: O(n^2)
    unordered_map<int, unordered_set<char>> rows, columns;
    map<pair<int, int>, unordered_set<char>> subBoxes;
    
    for(int i=0; i<9; i++){ // O(n^2)
        for(int j=0; j<9; j++){
            char value = board[i][j];

            if(value == '.') continue;

            pair<int, int> squareKey = {i / 3, j / 3};

            if(rows[i].count(value) || columns[j].count(value) || subBoxes[squareKey].count(value)){
                return false;    
            }
            
            rows[i].insert(value);
            columns[j].insert(value);
            subBoxes[squareKey].insert(value);
        }
    }
    
    return true;
}

int main()
{
    
    // vector<vector<char>> board = {
    //     {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
    //     {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
    //     {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
    //     {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
    //     {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
    //     {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    //     {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
    //     {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
    //     {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    // };
    
    vector<vector<char>> board = {
        {'1', '2', '.', '.', '3', '.', '.', '.', '.'},
        {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
        {'.', '9', '1', '.', '.', '.', '.', '.', '3'},
        {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
        {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    
    cout << isValidSudoku(board);
    
    return 0;
}