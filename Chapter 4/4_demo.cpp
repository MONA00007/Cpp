#include <iostream>
#include <queue>
#include <string>
using namespace std;
char maze[10][10];
int mark[10][10][10][10];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int M, N;
struct node
{
    int hr, hc, br, bc, depth;
    node(int hr, int hc, int br, int bc, int depth) : hr(hr), hc(hc), br(br), bc(bc), depth(depth) {}
};
int bfs(node &start);
int main()
{
    while (cin >> M >> N)
    {
        node start(0, 0, 0, 0, 0);
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
            {
                char c;
                cin >> c;
                maze[i][j] = c;
                if (c == 'X')
                {
                    start.hr = i;
                    start.hc = j;
                }
                if (c == '*')
                {
                    start.br = i;
                    start.bc = j;
                }
            }
        cout << bfs(start) << endl;
    }
    return 0;
}
int bfs(node &start)
{
    queue<node> q;
    q.push(start);
    mark[start.hr][start.hc][start.br][start.bc] = 1;
    while ((!q.empty()))
    {
        node head = q.front();
        q.pop();
        if (maze[head.br][head.bc] == '@')
            return head.depth;
        for (int i = 0; i < 4; i++)
        {
            int hnr = head.hr + dir[i][0];
            int hnc = head.hc + dir[i][1];
            int bnr = head.br;
            int bnc = head.bc;
            if (hnr < 0 || hnr >= M || hnc < 0 || hnc >= N) //人越界
                continue;
            if (maze[hnr][hnc] == '#') //人碰到障碍物
                continue;
            if (hnr == head.br && hnc == head.bc)
            {
                bnr = bnr + dir[i][0];
                bnc = bnc + dir[i][1];
                if (bnr < 0 || bnr >= M || bnc < 0 || bnc >= N) //箱子越界
                    continue;
                if (maze[bnr][bnc] == '#') //箱子碰到障碍物
                    continue;
            }
            if (mark[hnr][hnc][bnr][bnc] == 1) //状态已被访问过
                continue;
            q.push(node(hnr, hnc, bnr, bnc, head.depth + 1));
            mark[hnr][hnc][bnr][bnc] = 1;
        }
    }
    return -1;
}