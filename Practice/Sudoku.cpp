#include <cstdio>
#include <vector>
using namespace std;

vector<vector<char>> board;

bool ispossible(vector<vector<char>>& board,int row,int col,char ch){
    for(int i=0;i<9;i++){
        if(board[i][col]==ch) return false; //checking rows
        if(board[row][i]==ch) return false; //checking cols
    }
    // now check the block
    int x = row-row%3, y=col-col%3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[x+i][y+j]==ch) return false;
        }
    }
    return true; //if it is pefectly safe, then return true
}

bool solve(vector<vector<char>>& board,int row,int col)
{
    if(row==board.size()) return true; //the baord has been solved
    if(col==board.size()) return solve(board,row+1,0); //the current row is solved

    if(board[row][col]=='.'){ //if the spot is empty
        for(int i=1;i<10;i++){ //try filling 1 to 9 numbers
            if(ispossible(board,row,col,(char)i+'0')) {
                // if it is possible,  then move to next colom
                board[row][col]=(char)i+'0';
                if(solve(board,row,col+1)) return true;
                //if next colom is not possible, then erase the current solution
                board[row][col]='.';
            }
        }
        //the  program will never come to this, as this means that there is no possible value for this cell, which in this case is not possible

        return false;
    }
    else return solve(board,row,col+1); //if it is already filled, then move on
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board,0,0);
}


int main() {
    solveSudoku(board);
    /*Input: board = [["5","3",".",".","7",".",".",".","."],
                      ["6",".",".","1","9","5",".",".","."],
                      [".","9","8",".",".",".",".","6","."],
                      ["8",".",".",".","6",".",".",".","3"],
                      ["4",".",".","8",".","3",".",".","1"],
                      ["7",".",".",".","2",".",".",".","6"],
                      [".","6",".",".",".",".","2","8","."],
                      [".",".",".","4","1","9",".",".","5"],
                      [".",".",".",".","8",".",".","7","9"]]

    Output: [["5","3","4","6","7","8","9","1","2"],
             ["6","7","2","1","9","5","3","4","8"],
             ["1","9","8","3","4","2","5","6","7"],
             ["8","5","9","7","6","1","4","2","3"],
             ["4","2","6","8","5","3","7","9","1"],
             ["7","1","3","9","2","4","8","5","6"],
             ["9","6","1","5","3","7","2","8","4"],
             ["2","8","7","4","1","9","6","3","5"],
             ["3","4","5","2","8","6","1","7","9"]]
             */
}
