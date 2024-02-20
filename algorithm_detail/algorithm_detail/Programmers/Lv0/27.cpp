#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> directions = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

int solution(vector<vector<int>> board) {
    int answer = 0;

    int rows = board.size();
    int cols = board[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;

    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            if (board[x][y] == 1)
            {
                q.push({ x,y });
                visited[x][y] = true;
            }
        }
    }

    while (!q.empty())
    {
        pair<int,int> a = q.front();
        int x = a.first;
        int y = a.second;
        q.pop();

        for (pair<int,int> dir : directions)
        {
            int dx = dir.first;
            int dy = dir.second;
            int nx = x + dx;
            int ny = y + dy;

            if (dx > 0 && dx < rows && dy >= 0 && dy < cols)
            {
                visited[nx][ny] = true;
                q.push({ nx,ny });
            }

        }
    }
    int safeArea = 0;
    for (int x = 0; x < rows; ++x) 
    {
        for (int y = 0; y < cols; ++y) 
        {
            if (!visited[x][y])
            {
                safeArea++;
            }
        }
    }
    
    return safeArea;
 }

int main()
{
    solution({ { 0,0,0,0,0 },{0,0,0,0,0},{0,0,0,0,0},{0,0,1,1,0,},{0,0,0,0,0} });
}