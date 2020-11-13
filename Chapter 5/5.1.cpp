#include <iostream>

using namespace std;

static int chessboard[5][9];
static int count = 0;
/*
马走日的方向，(dx, dy)，dx表示5行中的第几行的竖直方向，dy表示9列中第几列的横方向。
上：(2, 1)
上右：(1, 2)
下右：(-1, 2)
下： (-2, 1)
*/
const int dx[4] = {2, 1, -1, -2};
const int dy[4] = {1, 2, 2, 1};

void horse_count(int srcx, int srcy, int destx, int desty)
{
    if (srcx >= 0 && srcx < 5 && srcy >= 0 && srcy < 9 && chessboard[srcx][srcy] == 0)
    {
        if (srcx == destx - 1 && srcy == desty - 1)
        {
            count++;
            return;
        }
        //标记为已经走过
        chessboard[srcx][srcy] = 1;
        int i;
        for (i = 0; i < 4; ++i)
        {
            horse_count(srcx + dx[i], srcy + dy[i], destx, desty);
        }
        //当走完四个方向后，回溯到之前走过的一步，标记为未走过。
        chessboard[srcx][srcy] = 0;
    }
}

int main()
{

    int m, n;
    cin >> m >> n;
    horse_count(0, 0, m, n);
    cout << count;
    return 0;
}