#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
// Câu 9.  Viết chương trình đếm số số nguyên tố nhỏ hơn hoặc bằng N với N được nhập vào từ bàn phím.
// Câu 10. Viết chương trình đếm số ước và số ước nguyên tố của một số N nhập vào từ bàn phím.
// Câu 11. Viết chương trình tính tổng của các số nguyên tố nhỏ hơn hoặc bằng N với N được nhập từ bàn phím.
// Câu 12. Viết chương trình tìm bốn số nguyên tố liên tiếp, sao cho tổng của chúng là số nguyên tố nhỏ hơn hoặc bằng N (với N được nhập vào từ bàn phím).
// Câu 13. Viết chương trình tìm hai số nguyên tố nhỏ hơn hoặc bằng N với N nhập vào từ bàn phím, sao cho tổng và hiệu của chúng đều là số nguyên tố.

// testcase:
int N;
int p[1000];
int q[1000];
int checkNT(int x)
{
    if (x < 2)
    {
        return 0;
    }
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    // freopen("E:\\C\\Input\\INPUT3.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    switch (T)
    {
    case 9: // dem so nguyen to <=N
    {
        scanf("%d", &N);
        int cnt = 0;
        for (int i = 2; i <= N; i++)
        {
            if (checkNT(i))
            {
                printf("%d \n",i);
                cnt++;
            }
        }
        printf("So cac so nguyen to <= N la: %d\n", cnt);
        break;
    }
    case 10: // dem so uoc va so uocNT cua N
    {
        scanf("%d", &N);
        int soUoc = 0;
        int soUocNT = 0;
        for (int i = 1; i <= N; i++)
        {
            if (N % i == 0)
            {
                soUoc++;
                if (checkNT(i))
                {
                    soUocNT++;
                }
            }
        }
        printf("So uoc cua N la: %d\n", soUoc);
        printf("So uoc nguyen to cua N la: %d\n", soUocNT);
        break;
    }
    case 11: // tinh tong cac so nguyen to <= N
    {
        scanf("%d", &N);
        int cnt = 0;
        for (int i = 2; i <= N; i++)
        {
            if (checkNT(i))
            {
                // printf("%d \n",i);
                cnt += i;
            }
        }
        printf("Tong cac so nguyen to <= N la: %d\n", cnt);
        break;
    }
    case 12: // tim 4 so NT lien tiep tong cua chung <= N
    {
        scanf("%d", &N);
        int count = 0;
        for (int i = 2; i <= N; i++)
        {
            if (checkNT(i))
            {
                // printf("%d \n",i);
                p[count] = i; // mang cac so NT
                count++;
            }
        }
        if (count <= 4)
        {
            printf("Khong co 4 so nguyen to hop le\n");
        }
        else
        {
            for (int i = 0; i <= count--; i++)
            {
                // && (p[i] != 0 && p[i + 1] != 0 && p[i + 2] != 0 && p[i + 3] != 0)
                int sum = (p[i] + p[i + 1] + p[i + 2] + p[i + 3]);
                if (sum <= N)
                {
                    printf("4 so NT lien tiep co tong <= N la: %d %d %d %d\n", p[i], p[i + 1], p[i + 2], p[i + 3]);
                    printf("tong la: %d\n", sum);
                    // break;
                }
            }
        }
        break;
    }
    case 13: // tim 2 so NT  <= N de tong vs hieu cua chung la so NT
    {
        int u = 0;
        scanf("%d", &N);
        for (int i = 2; i <= N; i++)
        { // lay mang cac so nguyen to <= N
            if (checkNT(i))
            {
                q[u] = i;
                u++;
            }
        }
        for (int i = 0; i <= u - 1; i++)
        {
            for (int j = i + 1; j <= u - 1; j++)
            {
                if ((checkNT(q[i] + q[j])) && (checkNT(q[j] - q[i])))
                {
                    printf("Hai so thoa man la: %d %d\n", q[i], q[j]);
                    printf("Hieu hai so la: %d\n", q[j] - q[i]);
                    printf("Tong hai so la: %d\n", q[j] + q[i]);
                }
            }
        }
        break;
    }
    }
    return 0;
}