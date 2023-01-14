#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>

int check_input(char*s,int n)
{
    char c;
    for(int i=0;i<n;i++)
    {
        c=getchar();
        if(c!=(*(s+i)))
        {
            return 0;
        }
    }
    return 1;
}
char* starter(int n)
{
    char* a=(char*)malloc(sizeof(char)*n);
    for(int i=0;i<n;i++)
    *(a+i)='\0';
    return a;
}
int exists(char *file_name)
{
    FILE *file;
    if ((file = fopen(file_name, "r")))
    {
        fclose(file);
        return 1;
    }
    return 0;
}
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
        while((c=getchar())!='\n' && c!='-')
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
char* read_content()
{
    char* ans=(char*)malloc(sizeof(char)*4000);
    for(int i=0;i<4000;i++)
    *(ans+i)='\0';
    char d='\0';
    int i=0;
    char c=getchar();
    if(c=='"')
    {
        while((c=getchar())!='"')
        {
            if(c=='\\')
            {
                d=getchar();
                if(d=='\\')
                {
                    *(ans+i)='\\';
                    i++;
                    *(ans+i)=getchar();
                    i++;
                }
                if(d=='n')
                {
                    *(ans+i)='\n';
                    i++;
                }
                if(d=='"')
                {
                    *(ans+i)='"';
                    i++;
                }
            }
            else
            {
                *(ans+i)=c;
                i++;
            }
        }
    }
    else
    {
        *(ans+i)=c;
        i++;
        while((c=getchar())!=' ')
        {
            if(c=='\\')
            {
                d=getchar();
                if(d=='\\')
                {
                    *(ans+i)='\\';
                    i++;
                    *(ans+i)=getchar();
                    i++;
                }
                if(d=='n')
                {
                    *(ans+i)='\n';
                    i++;
                }
                if(d=='"')
                {
                    *(ans+i)='"';
                    i++;
                }
            }
            else
            {
                *(ans+i)=c;
                i++;
            }
        }
    }
    return ans;
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
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige\n");
                continue;
            }

            char *address=give_me_me_the_address_bastard();

            //printf("\n%s\n",address);

            make_address_available(address);

            if(exists(address))
            printf("its already existed");
            else
            create_the_foooking_file(address);

        }
        if(compare_string("insertstr",command))
        {
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige\n");
                continue;
            }

            char* address=give_me_me_the_address_bastard();
            if(!exists(address))
            {
                printf("\naddress kharab\n");
                continue;
            }

            if(!(check_input("-str ",5)))
            {
                printf("\ndorost voroodi bede dige\n");
                continue;
            }
            char* content=read_content();

            printf("\n%s\n",content);
            printf("%s\n",address);
            ////////////////////////////////////////////////////////////////////////////////////////
            char*buff2=starter(20);
            int counter=0;
            while((*(buff2+counter)=getchar())!='s');
            {
                counter++;
            }
            if(counter==6 && compare_string(buff2,"--pos "));
            else if(counter==7 && compare_string(buff2," --pos "));
            else
            {
                printf("\nvoroodi eshtebah\n");
                continue;
            }
            //////////////////////////////////////////////////////////////////////////////////////
            int line,position;
            scanf("%d:%d",&line,&position);

            printf("%d  %d",line,position);

            FILE* mainfile;
            mainfile=fopen(address,"r");
            //FILE* result=fopen(address,"w");
            int current_line=1;
            int current_position=0;
            char c;
            char* before=starter(2000);
            char* after=starter(2000);
            int i=0;
            int j=0;
            int flag=1;
            while(current_line!=line || current_position!=position)
            {
                c=fgetc(mainfile);
                printf("  %c  ",c);
                *(before+i)=c;
                if(c==EOF)
                {
                    flag=0;
                    break;
                }
                else if(c=='\n')
                {
                    current_line++;
                    current_position=0;
                    i++;
                }
                else 
                {
                    current_position++;
                    i++;
                }
            }
            if(!flag)
            {
                printf("\nmage man ba to shookhi daram. inhame khat ro bokon to halghet\n");
                continue;
            }
            while(((c=fgetc(mainfile))!=EOF))
            {
                printf("*%c",c);
                *(after+j)=c;
                j++;
            }
            fclose(mainfile);

            printf("\n%s   \n%s\n",before,after);

            mainfile=fopen(address,"w");
            fputs(before,mainfile);
            fputs(content,mainfile);
            fputs(after,mainfile);
            fclose(mainfile);
        }
        else
        return 0;
    }
    return 0;
}