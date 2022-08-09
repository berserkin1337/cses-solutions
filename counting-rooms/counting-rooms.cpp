#include <bits/stdc++.h>
// https://cses.fi/problemset/task/1192
using namespace std;
vector<int> dx = {1,0,-1,0};
vector<int> dy = {0,1,0,-1};

bool isSafe(int i,int j , vector<vector<char>> &grid) {
    
    return i < grid.size() && i >=0 && j < grid[0].size() && j >=0 && grid[i][j] == '.' ;
}

void dfs(int i , int j , vector<vector<char>> &grid,vector<vector<bool>> &visited) {
    if(visited[i][j]) return;
    visited[i][j] = true;
    for(int idx = 0;idx<4;++idx){
        int ix = i + dx[idx];
        int iy = j + dy[idx];
        if(isSafe(ix,iy,grid)) dfs(ix,iy,grid,visited);
    }

}

int countRooms(vector<vector<char>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    long long res = 0;
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(grid[i][j] == '.' && visited[i][j] == false) {
                dfs(i,j,grid,visited);
                res += 1;
            }
        }
    }

    return (int)res;
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char> (m));
    for(int i=0;i < n;++i) {
        for(int j=0;j<m;++j) {
            cin >> grid[i][j];
        }
    }
    cout << countRooms(grid);

    return 0;
}