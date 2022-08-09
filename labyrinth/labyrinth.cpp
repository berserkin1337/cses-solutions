#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1193
#define ll unsigned long long
using namespace std;
// bool ans = false;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string direction = "URDL";
bool isSafe(ll i, ll j, vector<vector<char>> &grid)
{

    return i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0 && grid[i][j] != '#';
}
vector<vector<int>> previousStep;
string ansString = "NOT FOUND";
void dfs(int startX, int startY, vector<vector<char>> &grid, string curString, int targetX, int targetY, vector<vector<bool>> &visited)
{   
    int n = grid.size(),m = grid[0].size();
    previousStep.resize(n,vector<int>(m,0));
    queue<pair<int,int>> q;
    visited[startX][startY] = true;

    q.push({startX,startY});
    while (!q.empty()) {
        pair<int,int> point = q.front();q.pop();
        int x,y;
        tie(x,y) = point;
        for(int i=0;i<4;++i) {
            int ix = x + dx[i];
            int iy = y + dy[i]; 
            if(isSafe(ix,iy,grid) && !visited[ix][iy]) {
                visited[ix][iy] = true;
                previousStep[ix][iy] = i;
                if(ix == targetX && iy == targetY)return;
                q.push({ix,iy});
            } 
        }
    }
}
void labyrinth(int startx, int starty, int endx, int endy, vector<vector<char>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    dfs(startx, starty, grid, "", endx, endy, visited);
    if (visited[endx][endy])
    {
        cout << "YES" << endl;
        int curX = endx,curY = endy;
        string ans = "";
        while (grid[curX][curY] != 'A') {
            int prev = previousStep[curX][curY];
            ans += direction[prev];
            curX -= dx[prev]   ; curY -= dy[prev]; 
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size()<<endl;
        cout << ans << endl;
        // cout << previousStep[endx][endy].size() << endl;
        // cout << previousStep[endx][endy] << endl;
    }
    else
    {
        cout << "NO";
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));

    int startx=-1, starty=-1, endx=-1, endy=-1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                startx = i;
                starty = j;
            }
            else if (grid[i][j] == 'B')
            {
                endx = i;
                endy = j;
            }
        }
    }
    labyrinth(startx, starty, endx, endy, grid);
}