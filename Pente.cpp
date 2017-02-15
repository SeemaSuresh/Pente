
#include <iostream>

using namespace std;

bool player1[15][15];
bool player2[15][15];
char grid[15][15];
int x, y, win_r1, win_c1, win_r2, win_c2;

void player2Turn(int a, int b);
int count(bool player[15][15], int row, int col, int dirX, int dirY);

//Function to decide the winner
bool checkGameWin(bool player[15][15], int row, int col) {
  if (count(player, row, col, 1, 0) >= 5)
    return true;
  if (count(player, row, col, 0, 1) >= 5)
    return true;
  if (count(player, row, col, 1, -1) >= 5)
    return true;
  if (count(player, row, col, 1, 1) >= 5)
    return true;

  return false;
}

//function to get the consecutive row count
int count(bool player[15][15], int row, int col, int dirX, int dirY) {

  int ct = 1;

  int r, c;

  r = row + dirX;
  c = col + dirY;
  while (r >= 0 && r < 14 && c >= 0 && c < 14 && player[r][c] == true) 
  {
    ct++;
    r += dirX;
    c += dirY;
  }

  win_r1 = r - dirX;
  win_c1 = c - dirY;


  r = row - dirX;
  c = col - dirY;
  while (r >= 0 && r < 14 && c >= 0 && c < 14 && player[r][c] == true) 
  {
    ct++;
    r -= dirX;
    c -= dirY;
  }

  win_r2 = r + dirX;
  win_c2 = c + dirY;

  return ct;
}

//Player's Turn Function
void player1Turn() {

  cout << "Player's turn";
  cout << "\n Choose move in grid (x,y). Enter x & y values.";
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }

  cin >> x;
  cin >> y;
  if (grid[x][y] != '-') 
  {
    cout << "That spot is not available. Choose another one";
    cin >> x;
    cin >> y;
  }
  grid[x][y] = 'X';
  player1[x][y] = true;

  bool value = checkGameWin(player1, x, y);
  if (value)
  { 
    cout << "Player Wins!"; 
    return; 
  }
  else
    player2Turn(x, y);
}


//Computer's Turn Function
void player2Turn(int a, int b) {
  cout << "Computer's turn!"; 

  if (grid[a + 1][b] != 'X' && player2[a+1][b] == false)
  {
    grid[a + 1][b] = 'O';
    player2[a + 1][b] = true;
    x = a + 1;
    goto endloop;
  }

  else if (grid[a][b + 1] != 'X' && player2[a][b + 1] == false)
  {
    y = b + 1;
    grid[a][b + 1] = 'O';
    player2[a][b+1] = true;
    goto endloop;
  }
  else 
  {
    for (int i = 0; i < 15; i++) {
      for (int j = 0; j < 15; j++) {
        if (grid[i][j] != 'X' && !player2[i][j])
        {
          grid[i][j] = 'O';
          x = i;
          y = j;
          player2[i][j] = true;
          goto endloop;
        }
      }
    }
  }

endloop:
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }
  bool value = checkGameWin(player2, a, b);

  if (value)
  { 
    cout << "Computer Wins!"; 
    return; 
  }
  else
    player1Turn();
}

int main() {
  for (int i = 0; i < 15; i++)
  {
    for (int j = 0; j < 15; j++)
    {
      grid[i][j] = '-';
      player1[i][j] = false;
      player2[i][j] = false;
    }
  }
  player1Turn();
  return 1;
}
