#define _CRT_SECURE_NO_WARNINGS
#include"head.h"

void panduan(char b[heng][shu])
{
    int i, j;//��¼ÿ�������ѭ��
    int x, y;//��¼��ǰ���������
    int c = 0;//��¼������Χ�ģ����ִ�С
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
    srand((unsigned int)time(NULL));//��֤ÿ�β������׶���һ��
    while (r)
    {
        i = rand() % (heng - 2) + 1;
        j = rand() % (shu - 2) + 1;
        if (a[i][j] != '*')//�׿ɲ��ܷ���
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
        printf(" %2d ", i);//���2d������뻹���Ҷ������ţ�����
    for (i = 1; i < heng - 1; i++)//�⼸����Ҫ��Ϊ�˺ÿ�
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
    if (i == 0 || j == 0 || i == heng - 1 || j == shu - 1);//������ϵĶ������ε�
    else
        for (x = i - 1; x < i + 2; x++)
            for (y = j - 1; y < j + 2; y++)
                if (c[x][y] == 0)  //ÿ��Ѱ�ҹ���λ�ö��á�1������ֹ�˷�ջ�Ŀռ�
                {
                    c[x][y] = '1';
                    if (b[x][y] == 0)//�հ׿�ֱ��չ��������Ѱ����һ��
                    {
                        a[x][y] = '0';
                        xunzhao(a, b, c, x, y);
                    }
                    else if (b[x][y] > '0' && b[x][y] < '9')//���ֿ��¼���ǲ���չ��
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
    dayin(a);//��һ����Ϊ��չ��ը����ը���������Ƚ�����
}

int shengli(char a[heng][shu], char b[heng][shu], int m)
{
    int i, j;
    int s = 0;
    if (m = 10)//���ָ���Ǳ�ǵĲ�λ����10����ʱ�����ʤ���ж�
        for (i = 0; i < heng; i++)
            for (j = 0; j < shu; j++)
                if (b[i][j] == '*' && a[i][j] == 5)//�׵�λ�úͱ��λ��һ��
                    s++;
    if (s == 10)
    {
        printf("\n\n\t\tʤ����");
        return 1;
    }
    else
        return 0;
}