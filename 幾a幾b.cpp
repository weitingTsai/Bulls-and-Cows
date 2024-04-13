#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

int main()
{
    int A=0,B=0,random_a,random_g,i,j,counter=8;
    char digit_g[5],digit_a[5];
    srand(time(NULL));
    random_a=time(NULL)%10000;
    digit_a[0]=(int(random_a/1000)%10)+48;
    digit_a[1]=(int(random_a/100)%10)+48;
    digit_a[2]=(int(random_a/10)%10)+48;
    digit_a[3]=(int(random_a/1)%10)+48;
    if(digit_a[0]==digit_a[1] && digit_a[1]!=48)
        digit_a[1]--;
    else if(digit_a[0]==digit_a[1] && digit_a[1]==48)
        digit_a[1]+=9;
    if(digit_a[0]==digit_a[2] && digit_a[2]!=48)
        digit_a[2]--;
    else if(digit_a[0]==digit_a[2] && digit_a[2]==48)
        digit_a[2]+=9;
    if(digit_a[0]==digit_a[3] && digit_a[3]!=48)
        digit_a[3]--;
    else if(digit_a[0]==digit_a[3] && digit_a[3]==48)
        digit_a[3]+=9;
    if(digit_a[1]==digit_a[2] && digit_a[2]!=48)
        digit_a[2]--;
    else if(digit_a[1]==digit_a[2] && digit_a[2]==48)
        digit_a[2]+=9;
    if(digit_a[1]==digit_a[3] && digit_a[3]!=48)
        digit_a[3]--;
    else if(digit_a[1]==digit_a[3] && digit_a[3]==48)
        digit_a[3]+=9;
    if(digit_a[2]==digit_a[3] && digit_a[3]!=48)
        digit_a[3]--;
    else if(digit_a[2]==digit_a[3] && digit_a[3]==48)
        digit_a[3]+=9;
    while(1)
    {
        cout << "猜個數字吧~(0000~9999)" << endl;
        cin >> random_g;
        digit_g[0]=(int(random_g/1000)%10)+48;
        digit_g[1]=(int(random_g/100)%10)+48;
        digit_g[2]=(int(random_g/10)%10)+48;
        digit_g[3]=(int(random_g/1)%10)+48;
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(digit_g[i]==digit_a[j] && i==j)
                    A++;
                else if(digit_g[i]==digit_a[j] && i!=j)
                    B++;
            }
        }
        cout << A << "A" << B << "B" << endl;
        if(A==4)
        {
            cout << "恭喜答對!" << endl;
            break;
        }
        else if(counter==1)
        {
            cout << "沒有機會可以猜了" << endl;
            cout << "正確答案是:" << digit_a << endl;
            break;
        }
        else
        {
            counter--;
            cout << "答錯了 只剩下" << counter << "次機會可以猜數字了" << endl;
            A=0;
            B=0;
        }

    }
    return 0;
}
