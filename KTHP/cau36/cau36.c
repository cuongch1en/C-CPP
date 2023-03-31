#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Lập trình tìm kiếm xâu S1 trong xâu S2 theo thuật toán Boyer-Moore, in giá trị của bảng.
// Trong trường hợp nào thì thuật toán Boyer-Moore được xem là cải tiến hơn thuật toán tìm kiếm vét cạn.
// test case: 1
//           a pattern matching algorithm
//           rithm

char P[1000], T[1000], L[100];
int l[100];
int m, n, u = 0;
int count = 1, cnt = 0;

int min(int a, int b)
{
    if (a == b)
        return a;
    else if (a < b)
        return a;
    else
        return b;
}

void outPut(int t, int I)
{
    printf("#Case%d:\n", t);
    if (I == -1)
    {
        printf("Mau P khong xuat hien o mau T \n");
    }
    else
    {
        printf("Mau T: %s\n", T);
        printf("Mau P: %s\n", P);
        printf("Mau P xuat hien o vi tri %d\n", I++);
        printf("So lan lap tinh toan la: %d\n", count);
        printf("So phep tinh la: %d\n", cnt);
    }
    printf("\n");
}

void inPut()
{
    gets(T);
    gets(P);
    n = strlen(T);
    m = strlen(P);
}

void preprecessor()
{
    int str[128] = {0}; // liet ke tan suat cac ki tu
    int i, j;
    for (i = 0; i < n; i++)
    {
        str[T[i]]++;
    }
    for (i = 32; i < 128; i++) // lay cac ki tu cho L[]
    {
        if (str[i] != 0)
        {
            L[u] = i;
            u++;
        }
    }

    for (i = 0; i < u; i++) // set delta tat ca ki tu thanh -1
    {
        l[i] = -1;
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < u; j++)
        {
            if (P[i] == L[j])
            {
                l[j] = i; // lay delta max cho cac ki tu
            }
        }
    }
    // for (i = 0; i < u; i++)
    // {
    //     printf("%4c ", L[i]);
    // }
    // printf("\n");
    // for (i = 0; i < u; i++)
    // {
    //     printf("%4d ", l[i]);
    // }
    // printf("\n");
}

int checkKiTu(int I)
{
    for (int i = 0; i < u; i++)
    {
        if (L[i] == T[I])
        {
            return l[i];
        }
    }
}

void boyerMoore(int I, int J, int t)
{
    cnt++;
    int l = checkKiTu(I);    // lay chi so delta
    int Min = min(J, 1 + l); // lay ki tu min
    int i = 1;
    if (I > n)
    {
        outPut(t, -1); // truong hop mau P khong xuat hien
        return;
    }
    if (J == 0)
    {

        outPut(t, I); // truong hop mau P xuat hien
        return;
    }
    else
    {
        if (T[I] == P[J])
        {
            I--;
            J--;
            boyerMoore(I, J, t);
            count++;
        }
        else // thuc hien buoc nhay
        {
            I = I + m - Min;
            J = m - 1;
            count++;
            boyerMoore(I, J, t);
        }
    }
}
void reset()
{
    u = 0;
    count = 1;
    cnt = 0;
}
int main()
{
    freopen("E:\\C\\Input\\input2.txt", "r", stdin);

    int c, C; // so luong testcase
    scanf("%d\n", &C);
    for (c = 1; c <= C; c++)
    {
        inPut();
        preprecessor();
        boyerMoore(m, m, c);
        reset();
    }
    return 0;
}