#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

void panduan(char b[heng][shu])
{
    int i, j;//记录每个方块的循环
    int x, y;//记录当前方块的数字
    int c = 0;//记录（雷周围的）数字大小
    for (i = 1; i < heng - 1; i++)
        for (j = 1; j < shu - 1; j++)
            if (b[i][j] != '*')
            {
                c = 0;
                for (x = i - 1; x < i + 2; x++)
                    for (y = j - 1; y < j + 2; y++)
                        if (b[x][y] == '*')
                            c++, b[i][j] = c + 48;
            }
}

void chushihua(char a[heng][shu])
{
    int r = lei;
    int i, j;
    srand((unsigned int)time(NULL));//保证每次产生的雷都不一样
    while (r)
    {
        i = rand() % (heng - 2) + 1;
        j = rand() % (shu - 2) + 1;
        if (a[i][j] != '*')//雷可不能放重
        {
            a[i][j] = '*';
            r--;
        }
    }
    panduan(a);
}
void dayin(char a[heng][shu])
{
    int i, j;
    printf("\n \t ");
    for (i = 1; i < shu - 1; i++)
        printf(" %2d ", i);//这个2d是左对齐还是右对齐来着，忘了
    for (i = 1; i < heng - 1; i++)//这几步主要是为了好看
    {
        printf("\n     %2d", i);
        for (j = 1; j < shu - 1; j++)
            if (j == 1)
                printf(" | %c |", a[i][j]);
            else
                printf(" %c |", a[i][j]);
        if (i < heng - 2)
        {
            printf("\n\t|");
            for (j = 1; j < shu - 1; j++)
                printf("---|");
        }
    }
}

void xunzhao(char a[heng][shu], char b[heng][shu], char c[heng][shu], int i, int j)
{
    int x, y;
    if (i == 0 || j == 0 || i == heng - 1 || j == shu - 1);//把最边上的都给屏蔽掉
    else
        for (x = i - 1; x < i + 2; x++)
            for (y = j - 1; y < j + 2; y++)
                if (c[x][y] == 0)  //每个寻找过得位置都置‘1’，防止浪费栈的空间
                {
                    c[x][y] = '1';
                    if (b[x][y] == 0)//空白块直接展开，并且寻找下一个
                    {
                        a[x][y] = '0';
                        xunzhao(a, b, c, x, y);
                    }
                    else if (b[x][y] > '0' && b[x][y] < '9')//数字块记录但是不再展开
                        a[x][y] = b[x][y];
                }
}

int dianji(char a[heng][shu], char b[heng][shu], char c[heng][shu], int i, int j)
{
    if (b[i][j] == '*')
        return 0;
    else
    {
        xunzhao(a, b, c, i, j);
        return 1;
    }
}

void baozha(char a[heng][shu], char b[heng][shu])
{
    int i, j;
    for (i = 0; i < heng; i++)
        for (j = 0; j < shu; j++)
            if (b[i][j] == '*')
                a[i][j] = b[i][j];
    system("cls");
    dayin(a);//这一步是为了展现炸弹爆炸，看起来比较厉害
}

int shengli(char a[heng][shu], char b[heng][shu], int m)
{
    int i, j;
    int s = 0;
    if (m = 10)//这个指的是标记的部位等于10个的时候进行胜利判定
        for (i = 0; i < heng; i++)
            for (j = 0; j < shu; j++)
                if (b[i][j] == '*' && a[i][j] == 5)//雷的位置和标记位置一样
                    s++;
    if (s == 10)
    {
        printf("\n\n\t\t胜利！");
        return 1;
    }
    else
        return 0;
}