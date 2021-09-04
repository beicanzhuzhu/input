/*模仿python中的input函数，返回一个指向动态内存的指针*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char * input();

int main(void)
{
    const char * str = input();
    puts(str);
    getchar();
    return 0;
}

char * input()
{
    char *p1 = NULL;    //指向第一个内存
    char *p2 = NULL;    //指向第二个内存    
    char a[2];          //临时用于获取输入，用数组是因为懒得在最后加'\0'
    int i = 1;          //计数
    while((a[0] = getchar()) != '\n')       //丢弃换行符
    {

        if((i % 2) == 1)                //当第奇数次时，申请第一个内存
        {
            p1 = (char *)malloc((i+1) * sizeof(char));
            if(p1 == NULL)
                printf("warning!");
            if(p2 != NULL)              //防止第一次运行时加入奇怪的东西
            {
                strcpy(p1, p2);         //将p2拷贝至p1
                free(p2);               //释放p2的内存
            }
            strcat(p1, a);              //将这次的输入拼接至p1的结尾
        }
        else                            //第偶数次时，申请第二个内存
        {
            p2 = (char *)malloc((i+1) * sizeof(char));
            if(p2 == NULL)
                printf("warning!");
            strcpy(p2, p1);             //将p1拷贝至p2
            free(p1);                   //释放p1的内存
            strcat(p2, a);              //将这次的输入拼接至p2的结尾
        }
        i++;        //递增计数器
    }
    if((i-1) % 2 == 1)      //返回指针
    {
        return p1;
    }
    else
    {
        return p2;
    }
        
}