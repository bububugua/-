#define _CRT_SECURE_NO_WARNINGS
#include"head.h" 

void denglu()
{
    printf("\n\n\t\t��ӭ����ɨ�ף���ѡ��\n\n");
    printf("\t\t1.��ʼ��Ϸ\n\n");
    printf("\t\t2.�˳���Ϸ\n\n\t\t");
}

void game()
{
    char a[heng][shu] = { 0 }, b[heng][shu] = { 0 }, c[heng][shu] = { 0 };
    int i, j, l;
    int s = 1, m = 0;//�����жϲ�����Ϊ
    int g = -1;
    chushihua(b);
    while (g)
    {
        system("cls"); //ÿ��ѡ����ˢ��ҳ��
        dayin(b);
        printf("\n\n\t�����ѡ��һ�����꣺");
        scanf("%d%d", &i, &j);
        printf("\n\t1 ��� \t2 ���\n\t��ѡ��Ĳ����ǣ�");
        while (s)
        {
            scanf("%d", &l);
            switch (l)
            {
            case 1:g = dianji(a, b, c, i, j);
                s = 0;
                break;
            case 2:a[i][j] = 5;//��ascii����5���������Ҫ����Ϊ�ȽϺÿ������Ի���
                s = 0;
                m++;//��ǵ���Ŀ
                break;
            default:
                printf("\n\t���������������");
                break;
            }
        }
        s = 1;
        if (shengli(a, b, m) == 1)
            break;
        if (g == 0)
        {
            baozha(a, b);
            printf("\n\t�ܲ��ң���㵽��ը��\n\n\t��Ϸ����");
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
            case 1:  printf("\n\t\t�������ɨ�����İɣ�");
                printf("\n\n\t������Ϸ����%d���ף�ף�������죡��", lei);
                Sleep(2000);//�ȴ�������ˢ��
                system("cls");
                game();
                c = 0;
                break;
            case 2:
                break;
            default:printf("\n\t\t�������������\n\t\t");
                break;
            }
            if (c == 0)
                break;
        }
        printf("\n\t1 ��\t2 ��");
        printf("\n\t�Ƿ�Ҫ������һ�֣�");
        scanf("%d", &b);
        system("cls");
        if (b == 2 || a == 2)
            break;
    }

    system("cls");
    printf("\n\n\t\t��л���棬�����´��ټ�����\n\n");
    return 0;
}