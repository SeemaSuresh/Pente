#include <iostream>
using namespace std;

bool player1[15][15];
bool player2[15][15];
char grid[15][15];
int x, y;
int dirX = 1;
int dirY = 0;

private int count(bool player[][], int row, int col, int dirX, int dirY) {
           
          int ct = 1;
          
          int r, c;    
          
          r = row + dirX;  
          c = col + dirY;
          while ( r >= 0 && r < 14 && c >= 0 && c < 14 && player[r][c] == true ) {
                 
             ct++;
             r += dirX; 
             c += dirY;
          }
    
          win_r1 = r - dirX; 
          win_c1 = c - dirY;  
                             
                              
          r = row - dirX; 
          c = col - dirY;
          while ( r >= 0 && r < 14 && c >= 0 && c < 14 && player[r][c] == true ) {
             ct++;
             r -= dirX; 
             c -= dirY;
          }
    
          win_r2 = r + dirX;
          win_c2 = c + dirY;
    
          return ct;
    
       }  
    

bool checkGameWin(bool player[15][15], int row, int col){
     if (count( player[row][col], row, col, 1, 0 ) >= 5)
             return true;
          if (count( player[row][col], row, col, 0, 1 ) >= 5)
             return true;
          if (count( player[row][col], row, col, 1, -1 ) >= 5)
             return true;
          if (count( player[row][col], row, col, 1, 1 ) >= 5)
             return true;
   
   return false; 
}

void player1Turn(char grid[15][15]){
    
    cout << "Player's turn";
    cout << "\n Choose move in grid (x,y). Enter x & y values.";
    for(int i = 0; i<15; i++)
     for(int j=0; j<15; j++)
         cout >> grid[i][j];
       
    cin >> x;
    cin >> y;
    if(grid[x][y] != '-') {
        cout << "That spot is not available. Choose another one";
        cin >> x;
        cin >> y;
    }
    grid[x][y] = 'X';
    player1[x][y] = true;
    bool value = checkGameWin(player1, x, y);
    if(value){ cout << "Player Wins!"; exit();}
    else
    player2Turn(grid);
    
}

void player2Turn(char grid[15][15]){
    if(grid[x+1][y] != '-' && grid[x+1][y] != 'X')
    { grid[x+1][y] = 'O';
       x = x+1;}
       
    else if(grid[x][y+1] != '-' && grid[x][y+1] != 'X' ){
        y = y+1;
    }
    grid[x][y+1] = 'O';
    else
    for(int i = 0; i < 15; i++){
     for(int j = 0; j < 15; j++){
         if(grid[i][j] != 'X' && grid[i][j] != '-')
             {
                 grid[i][j] = 'O';
                 x = i;
                 y = j;
                 break;
             }
     }
    }
    bool value = checkGameWin(player2, x, y);
    if(value){ cout << "Computer Wins!"; exit();}
    else
    player1Turn(grid);
}

int main() {
    for(int i = 0; i<15; i++)
     for(int j=0; j<15; j++)
       grid[i][j] = '-';
       player1Turn(grid);
       return 1;
       
  
}




