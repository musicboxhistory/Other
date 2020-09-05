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
    int nutta;
    int x, y, s;

    /* 塗る前表示*/
    printf("---------前------------\n");
    hyouji();

    do
    {
        nutta = 0;
        for(y=1; y<8; y++)
        {
            for(x=1; x<10; x++)
            {
                s = Masu[x-1][y] + Masu[x+1][y] + Masu[x][y-1] + Masu[x][y+1];
                if(Masu[x][y] == 0 && s == 3)
                {
                    Masu[x][y] = 1;
                    nutta = 1;
                }
            }
        }
    } while(nutta != 0);

    /* 塗り後表示 */
    printf("---------後------------\n");
    hyouji();

    return 0;
}
