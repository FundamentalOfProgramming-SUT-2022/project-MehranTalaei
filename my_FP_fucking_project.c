#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
char delete_spaces()
{
    char c;
    while((c=getchar())==' ');
    return c;
}
int compare_string(char* str1,char* str2)
{
    while(1)
    {
        if(*str1=='\0')
        {
            if(*str2=='\0')
            return 1;
            else
            return 0;
        }
        if((*str1)!=(*str2))
        {
            return 0;
        }
        str1++;
        str2++;
    }
}
char* give_me_me_the_address_bastard()
{
    char * address=(char *)malloc(sizeof(char)*120);
    for(int i=0;i<120;i++)
    *(address+i)='\0';
    //if((*address=getchar())!='"')
    //{
        char c;
        int i=0;
        while((c=getchar())!='\n')
        {
            if(c!='"');
            {
                *(address+i)=c;
                i++;
            }
        }
        return address;
    //}
}
void make_address_available(char* address)
{
    //printf("im in");
    char* buff=(char*)malloc(sizeof(char)*120);
    //printf("here");
    for(int i=0;i<120;i++)
    *(buff+i)='\0';
    //printf("oooooo");
    for(int i=0;i<120;i++)
    {
        //printf("im in again");
        if(*(address+i)=='/')
        {
            //printf("\n%s",buff);
            mkdir(buff);
        }
        *(buff+i)=*(address+i);
    }
}
void create_the_foooking_file(char *address)//in the memory of arthur fooooking shelby
{
    FILE* recent_file ;
    recent_file=fopen(address,"w");
    fclose(recent_file);
}
int main()
{
    
    //printf("hello");
    char* command=(char*)malloc(sizeof(char)*60);
    //printf("hello");
    while(1)
    {
        //printf("PPPOOOOFFFF");
        scanf("%s",command);
        if(compare_string("createfile",command))
        {
            for(int i=0;i<9;i++)
            getchar();
            char *address=give_me_me_the_address_bastard();
            printf("\n%s\n",address);
            make_address_available(address);
            create_the_foooking_file(address);
        }
    
        else
        return 0;
    }
    return 0;
}