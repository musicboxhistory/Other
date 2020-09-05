#include <stdio.h>

int Masu[11][9] = { {1,1,1,1,1,1,1,1,1},
                    {1,0,0,0,1,0,0,0,1},
                    {1,1,1,0,0,0,1,0,1},
                    {9,0,0,0,1,0,1,0,1},
                    {1,1,1,0,1,0,1,0,1},
                    {1,0,1,1,1,0,1,1,1},
                    {1,0,0,0,1,0,1,0,1},
                    {1,1,1,0,0,0,1,0,9},
                    {1,0,0,0,1,1,1,0,1},
                    {1,0,1,0,0,0,0,0,1},
                    {1,1,1,1,1,1,1,1,1}};

void hyouji()
{
    int x, y;
    for(y=0; y<9; y++)
    {
        for(x=0; x<11; x++)
        {
            if(Masu[x][y] == 1)
            {
                printf("■");
            }
            else
            {
                printf("□");
            }
        }
        printf("\n");
    }
}

int main(void)
{
    int i, j, x, y, di, dj;

    /* 塗る前表示*/
    printf("---------前------------\n");
    hyouji();

    for(y=1; y<8; y++)
    {
        for(x=1; x<10; x++)
        {
            i = x;
            j = y;
            while(Masu[i+1][j] + Masu[i-1][j] + Masu[i][j+1] + Masu[i][j-1] == 3)
            {
                Masu[i][j] = 1;
                di = Masu[i-1][j] - Masu[i+1][j];
                dj = Masu[i][j-1] - Masu[i][j+1];
                i += di;
                j += dj;
            }
        }
    }

    /* 塗り後表示 */
    printf("---------後------------\n");
    hyouji();

    return 0;
}
