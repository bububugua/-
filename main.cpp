#define _CRT_SECURE_NO_WARNINGS
#include"head.h" 

void denglu()
{
    printf("\n\n\t\t欢迎进入扫雷，请选择\n\n");
    printf("\t\t1.开始游戏\n\n");
    printf("\t\t2.退出游戏\n\n\t\t");
}

void game()
{
    char a[heng][shu] = { 0 }, b[heng][shu] = { 0 }, c[heng][shu] = { 0 };
    int i, j, l;
    int s = 1, m = 0;//用于判断操作行为
    int g = -1;
    chushihua(b);
    while (g)
    {
        system("cls"); //每次选择完刷新页面
        dayin(b);
        printf("\n\n\t你可以选择一个坐标：");
        scanf("%d%d", &i, &j);
        printf("\n\t1 点击 \t2 标记\n\t你选择的操作是：");
        while (s)
        {
            scanf("%d", &l);
            switch (l)
            {
            case 1:g = dianji(a, b, c, i, j);
                s = 0;
                break;
            case 2:a[i][j] = 5;//用ascii码里5这个符号主要是因为比较好看，可以换的
                s = 0;
                m++;//标记的数目
                break;
            default:
                printf("\n\t请重新输入操作！");
                break;
            }
        }
        s = 1;
        if (shengli(a, b, m) == 1)
            break;
        if (g == 0)
        {
            baozha(a, b);
            printf("\n\t很不幸，你点到了炸弹\n\n\t游戏结束");
        }
    }
}

int main()
{
    int a = 0, b, c;
    while (1)
    {
        denglu();
        while (a != 2)
        {
            scanf("%d", &a);
            switch (a)
            {
            case 1:  printf("\n\t\t开启你的扫雷生涯吧！");
                printf("\n\n\t本次游戏共有%d个雷，祝你玩得愉快！！", lei);
                Sleep(2000);//等待两秒再刷新
                system("cls");
                game();
                c = 0;
                break;
            case 2:
                break;
            default:printf("\n\t\t输入错误，请重试\n\t\t");
                break;
            }
            if (c == 0)
                break;
        }
        printf("\n\t1 是\t2 否");
        printf("\n\t是否要重新玩一局？");
        scanf("%d", &b);
        system("cls");
        if (b == 2 || a == 2)
            break;
    }

    system("cls");
    printf("\n\n\t\t感谢游玩，我们下次再见！！\n\n");
    return 0;
}