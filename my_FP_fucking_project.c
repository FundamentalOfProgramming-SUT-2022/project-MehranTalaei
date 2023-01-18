#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
#define MAX_OCCUR 10000
int size_of_array(char* string)
{
    int ans=0;
    for(int i=0;*(string+i)!='\0';i++)
    ans++;
    return ans;
}
int go_to_starter(char* s,int n)
{
    for(int i=0;i<n;i++)
    *(s+i)='\0';
}
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
void occurence_starter(int occurence[],int n)
{
    for(int i=0;i<n;i++)
    occurence[i]=-1;
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

char* give_me_me_the_address_bastard2(int *flag)
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
        if(c=='\n')
        *flag=0;
        if(c=='-')
        *flag=1;
        return address;
    //}
}

char* give_me_me_the_address_bastard3(int *flag)
{
    char * address=(char *)malloc(sizeof(char)*120);
    for(int i=0;i<120;i++)
    *(address+i)='\0';
    //if((*address=getchar())!='"')
    //{
        char c;
        int i=0;
        while((c=getchar())!='\n' && c!=' ')
        {
            if(c!='"');
            {
                *(address+i)=c;
                i++;
            }
        }
        if(c=='\n')
        *flag=0;
        if(c==' ')
        *flag=1;
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
char* read_content2()
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
            if(c=='*')
            {
                *(ans+i)=1;
                i++;
            }
            else if(c=='\\')
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
                if(d=='*')
                {
                    *(ans+i)='*';
                    i++;
                }
            }
            else
            {
                *(ans+i)=c;
                i++;
            }
        }
        getchar();
    }
    else
    {
        if(c!='*')
        *(ans+i)=c;
        else
        *(ans+i)=1;
        i++;
        while((c=getchar())!=' ' && c!='\n')
        {
            if(c=='*')
            *(ans+i)=1;
            else if(c=='\\')
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
                if(d=='*')
                {
                    *(ans+i)='*';
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
char* read_content3()
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
        getchar();
    }
    else
    {
        *(ans+i)=c;
        i++;
        while((c=getchar())!=' ' && c!='\n')
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

struct apperence{
    int char_number;
    int word_number;
    int pos_in_string;
    int line_number;
    int size;
};
void struct_starter (struct apperence array[],int n )
{
    for(int i=0;i<n;i++)
    {
        array[i].char_number=-1;
        array[i].pos_in_string=-1;
        array[i].word_number=-1;
        array[i].line_number=-1;
        array[i].size=-1;
    }
}

int search_for_string_at(char * main_string,char* target_string,int i)
{
    for(int j=0;*(target_string+j)!='\0';j++)
    {
        if(*(target_string+j)==*(main_string+j+i))
        continue;
        else
        return 0;
    }
    return 1;
}

void find_lines_of_occurence(char* main_string,char* target_string,int occurences[100])
{
    int i=0;
    int line_number=1;
    int counter=0;
    while(main_string[i]!='\0')
    {
        if(main_string[i]=='\n')
        {
            line_number++;
        }

        if(search_for_string_at(main_string,target_string,i))
        {
            occurences[counter]=line_number;
            counter++;
        }

        i++;
    }
}

void khat_k_chap_kon(char* chert,int k)
{
    int line_num=1;
    int i=0;
    while(chert[i]!='\0')
    {
        if(line_num==k)
        {
            while(chert[i]!='\n'&&chert[i]!='\0')
            {
                printf("%c",chert[i]);
                i++;
            }
            break;
        }
        if(chert[i]=='\n')
        line_num++;
        i++;
    }

}


struct apperence find_the_first_occurence(char* main_string,char* target_string,int after_char,int after_word,char starter_char)//0 base
{
    struct apperence ans;
    int char_buff=after_char;
    int word_buff=after_word;
    char last_char=starter_char;
    int size=size_of_array(target_string);
    for(int i=after_char;*(main_string+i)!='\0';i++)
    {
        if((last_char==' ' || last_char=='\n')&&(*(main_string+i)!=' ' && *(main_string+i)!='\n'))
        {
            word_buff++;
            printf("\nafzayesh dar %c%c \n",last_char,*(main_string+i));
        }
        if(search_for_string_at(main_string,target_string,i))
        {
            //printf("%d\n",search_for_string_at(main_string,target_string,i));
            ans.char_number=i;
            ans.word_number=word_buff;
            return ans;
        }
        last_char=*(main_string+i);
    }
}

void find_all_occurence1(char * main_string,char* target_string,struct apperence array[MAX_OCCUR])
{
    int line_num=1;
    int pos=0;//0 base
    int word_num=0;
    int char_num=0;
    int size=size_of_array(target_string);
    //printf("%d",size);
    char last_char=' ';
    int apperence_num=0;
    if(target_string[0]==1)
    {
        //printf("target of 0 is 1\n");
        struct apperence last_space;
        last_space.line_number=1;
        last_space.char_number=0;
        last_space.word_number=0;
        last_space.pos_in_string=-1;
        for(int i=0;i<size-1;i++)
        target_string[i]=target_string[i+1];
        target_string[size-1]='\0';
        size--;
        /////////////////////////////////////////////////////
        int i=0;
        while(main_string[i]!='\0')
        {
            if(last_char==' '||last_char=='\n')
            {
                if(main_string[i+1]!=' '&&main_string[i+1]!='\n')
                word_num++;
            }

            if(main_string[i]=='\n')
            {
                line_num++;
                pos=0;
            }

            if(main_string[i]!=' '&&main_string[i]!='\n')
            char_num++;
            else
            {
                last_space.char_number=char_num;
                last_space.word_number=word_num;
                last_space.pos_in_string=pos;
                last_space.line_number=line_num;
            }

            if(search_for_string_at(main_string,target_string,i))
            {
                if(main_string[i+size]=='\0'||main_string[i+size]=='\n'||main_string[i+size]==' ')
                    {
                        array[apperence_num].char_number=last_space.char_number+1;
                        array[apperence_num].word_number=last_space.word_number+1;
                        array[apperence_num].pos_in_string=last_space.pos_in_string+1;
                        array[apperence_num].line_number=last_space.line_number;
                        //printf("=== %d %d ===",array[apperence_num].char_number,array[apperence_num].word_number);
                        apperence_num++;
                    }
            }

            
            last_char=main_string[i];
            if(main_string[i]!='\n')
            pos++;
            i++;
        }
    }
    /////////////////////////////////////////////////////////////////////////////
    else if(target_string[size-1]==1)
    {
        target_string[size-1]='\0';
        size--;
        int i=0;
        while(main_string[i]!='\0')
        {
            if(last_char==' '||last_char=='\n')
            {
                if(main_string[i+1]!=' '&&main_string[i+1]!='\n')
                word_num++;
            }

            if(main_string[i]=='\n')
            {
                line_num++;
                pos=0;
            }

            if(main_string[i]!=' '&&main_string[i]!='\n')
            char_num++;

            if(search_for_string_at(main_string,target_string,i))
            {
                //printf("   inside    ");
                if(last_char==' '||last_char=='\n')
                {
                        array[apperence_num].char_number=char_num;
                        array[apperence_num].word_number=word_num;
                        array[apperence_num].pos_in_string=pos;
                        array[apperence_num].line_number=line_num;
                        //printf("=== %d %d ===",array[apperence_num].char_number,array[apperence_num].word_number);
                        apperence_num++;
                }
            }

            
            last_char=main_string[i];
            if(main_string[i]!='\n')
            pos++;
            i++;
        }
    }
    ////////////////////////////////////////////////////////////////////////////
    else{
        //printf("\n=========================\n");
        int i=0;
        while(main_string[i]!='\0')
        {
            if(last_char==' '||last_char=='\n')
            {
                if(main_string[i+1]!=' '&&main_string[i+1]!='\n')
                word_num++;
            }

            if(main_string[i]=='\n')
            {
                line_num++;
                pos=0;
            }

            if(main_string[i]!=' '&&main_string[i]!='\n')
            char_num++;

            if(search_for_string_at(main_string,target_string,i))
            {
                //printf("   inside    ");
                if(last_char==' '||last_char=='\n')
                {
                    if(main_string[i+size]=='\0'||main_string[i+size]=='\n'||main_string[i+size]==' ')
                    {
                        array[apperence_num].char_number=char_num;
                        array[apperence_num].word_number=word_num;
                        array[apperence_num].pos_in_string=pos;
                        array[apperence_num].line_number=line_num;
                        //printf("=== %d %d ===",array[apperence_num].char_number,array[apperence_num].word_number);
                        apperence_num++;
                    }
                }
            }

            
            last_char=main_string[i];
            if(main_string[i]!='\n')
            pos++;
            i++;
        }
    }
}


int Namooos_search_for_string_at(char * main_string,char* target_string,int shift,int* extra_char)
{
    (*extra_char)=0;
    int j=0;
    int loc_of_main=j+shift;
    if(shift>0 && main_string[shift-1]!=' ' && main_string[shift-1]!='\n')
    return 0;
    while(*(target_string+j)!='\0')
    {
        //printf("i am in while");
        //printf("\n j is %d",j);
        char last_char=' ';
        if(target_string[j]==1)
        {

            //printf(" whith star \n");
            //printf("its target:%c  its main:%c \n ",*(target_string+j),main_string[loc_of_main]);


            if( j==0|| target_string[j-1]=='\n' ||target_string[j-1]==' ')//??
            {

                int size=0;
                for(int s=j+1;target_string[s]!=' '&&target_string[s]!='\n'&&target_string[s]!='\0';s++)
                size++;
                //printf("size: %d    ",size);

                while(main_string[loc_of_main+1]!=' ' && main_string[loc_of_main+1]!='\n' && main_string[loc_of_main+1]!='\0')
                {
                    //printf(" i am adding size         ");
                    loc_of_main++;
                    //shift++;
                    (*extra_char)++;
                }
                //shift-=(size+1);
                //printf(" char - size = %d - %d",*extra_char,size);
                (*extra_char)-=(size);
                j=j+size;
                //printf("\n j is %d",j);

                for(int i=0;i<size;i++)
                {
                    if(main_string[loc_of_main-i]!=target_string[j-i])
                    return 0;
                }

                j++;//??????
                loc_of_main++;
                //*(extra_char)++;///????????????????????????????????????????????
            }
            if(target_string[j+1]==' '|| target_string[j+1]=='\n' || target_string[j+1]=='\0'||target_string[j+1]==EOF)
            {
                //printf("**");
                j++;
                while(main_string[loc_of_main]!=' '&&main_string[loc_of_main]!='\n'&&main_string[loc_of_main]!='\0')   
                {
                    loc_of_main++;
                    (*extra_char)++;
                }
                (*extra_char)--;
            }
        }
        else if(*(target_string+j)==*(main_string+loc_of_main))
        {
            j++;
            loc_of_main++;
            //printf(" whithout star \n");
            //printf("its target:%c  its main:%c \n ",*(target_string+j),main_string[loc_of_main]);
            continue;
        }
        else
        return 0;
    }
    if(main_string[loc_of_main]!=' '&&main_string[loc_of_main]!='\n'&&main_string[loc_of_main]!='\0'&&main_string[loc_of_main]!=EOF)
    return 0;
    else
    return 1;
}



int Namooos_search_for_string_at_bad(char * main_string,char* target_string,int shift,int* extra_char)
{
    int last_mod=0;
    (*extra_char)=0;
    int j=0;
    int loc_of_main=j+shift;
    if(shift>0 && main_string[shift-1]!=' ' && main_string[shift-1]!='\n')
    return 0;
    while(*(target_string+j)!='\0')
    {
        //printf("i am in while");
        //printf("\n j is %d",j);
        char last_char=' ';
        if(target_string[j]==1)
        {
            
            //printf(" whith star \n");
            //printf("its target:%c  its main:%c \n ",*(target_string+j),main_string[loc_of_main]);


            if( j==0|| target_string[j-1]=='\n' ||target_string[j-1]==' ')//??
            {

                int size=0;
                for(int s=j+1;target_string[s]!=' '&&target_string[s]!='\n'&&target_string[s]!='\0';s++)
                size++;
                //printf("size: %d    ",size);

                while(main_string[loc_of_main+1]!=' ' && main_string[loc_of_main+1]!='\n' && main_string[loc_of_main+1]!='\0')
                {
                    //printf(" i am adding size         ");
                    loc_of_main++;
                    //shift++;
                    (*extra_char)++;
                }
                //shift-=(size+1);
                //printf(" char - size = %d - %d",*extra_char,size);
                (*extra_char)-=(size);
                j=j+size;
                //printf("\n j is %d",j);

                for(int i=0;i<size;i++)
                {
                    if(main_string[loc_of_main-i]!=target_string[j-i])
                    return 0;
                }
                //last_mod=1;
                j++;//??????
                loc_of_main++;
                //printf("(%d)",*extra_char);
                //*(extra_char)++;///????????????????????????????????????????????
            }
            else if(target_string[j+1]==' '|| target_string[j+1]=='\n' || target_string[j+1]=='\0'||target_string[j+1]==EOF)
            {
                //last_mod=0;
                //printf("**");
                j++;
                while(main_string[loc_of_main]!=' '&&main_string[loc_of_main]!='\n'&&main_string[loc_of_main]!='\0')   
                {
                    loc_of_main++;
                    (*extra_char)++;
                }
                (*extra_char)--;
            }
        }
        else if(*(target_string+j)==*(main_string+loc_of_main))
        {
            j++;
            loc_of_main++;
            //last_mod=0;
            //printf(" whithout star \n");
            //printf("its target:%c  its main:%c \n ",*(target_string+j),main_string[loc_of_main]);
            continue;
        }
        else
        return 0;
    }
    if(main_string[loc_of_main]!=' '&&main_string[loc_of_main]!='\n'&&main_string[loc_of_main]!='\0'&&main_string[loc_of_main]!=EOF)
    return 0;
    else
    {
        // if(last_mod)
        // (*extra_char)++;
        return 1;
    }
}





void find_all_occurence_Namooos(char * main_string,char* target_string,struct apperence array[])
{
    int pos=0;//0 base
    int line_num=1;
    int word_num=0;
    int char_num=0;
    int extra_num=0;
    int size=size_of_array(target_string);
    char last_char=' ';
    int apperence_num=0;
    int i=0;
    while(main_string[i]!='\0')
    {
            //printf("==(in  for i=%d  its %c)==",i,main_string[i]);
        if(last_char==' '||last_char=='\n')
            {
                if(main_string[i+1]!=' '&&main_string[i+1]!='\n')
                word_num++;
            }

            if(main_string[i]=='\n')
            {
                line_num++;
                pos=0;
            }

            if(main_string[i]!=' '&&main_string[i]!='\n')
            char_num++;

            extra_num=0;
            if(Namooos_search_for_string_at_bad(main_string,target_string,i,&extra_num))
            {
                //printf("   extra>>>>%d  ",extra_num);
                array[apperence_num].char_number=char_num;
                array[apperence_num].word_number=word_num;
                array[apperence_num].pos_in_string=pos;
                array[apperence_num].line_number=line_num;
                array[apperence_num].size=size+extra_num;
                //printf("=== %d %d ===",array[apperence_num].char_number,array[apperence_num].word_number);
                apperence_num++;
            }





        ///////////////////////////////////////
        last_char=main_string[i];
        if(main_string[i]!='\n')
        pos++;
        i++;
    }

}



int remove_from_file(int line_number,int start_position,char* address,int size,char direction)
{
    //printf("i am coming\n");
     FILE* mainfile;
     mainfile=fopen(address,"r");

    int current_line=1;
            int current_position=0;
            char c;
            char* before=starter(2000);
            char* after=starter(2000);
            int i=0;
            int j=0;
            int flag=1;
            int size_of_after=0;
            int size_of_before=0;
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
                *(before+i)=c;
                if(c==EOF)
                {
                    flag=0;
                    return 0;
                }
                else if(c=='\n')
                {
                    current_line++;
                    current_position=0;
                    i++;
                    size_of_before++;
                }
                else 
                {
                    current_position++;
                    i++;
                    size_of_before++;
                }
            }

            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
                size_of_after++;
            }
            fclose(mainfile);
            
            //printf("\n%s\n%s\n",before,after);
            //printf("%d\n",size);
            ///////////////////neveshtan
            mainfile=fopen(address,"w");
            if(direction=='f')
            {
                if(size_of_after<size)
                {
                    return 0;
                }
                fputs(before,mainfile);
                for(int i=size;i<size_of_after;i++)
                {
                    fputc(*(after+i),mainfile);
                }
                fclose(mainfile);
            }
            else if(direction=='b')
            {
                if(size_of_before<size)
                {
                    return 0;
                }
                for(int i=0;i<size_of_before-size;i++)
                {
                    fputc(*(before+i),mainfile);
                }
                fputs(after,mainfile);
                fclose(mainfile);
            }
            return 1;
}
int insert_in_file(int line_number,int start_position,char* address,char* content)
{
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
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
                *(before+i)=c;
                if(c==EOF)
                {
                    flag=0;
                    return 0;
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
            
            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
            }
            fclose(mainfile);

            //printf("\n%s   \n%s\n",before,after);

            mainfile=fopen(address,"w");
            fputs(before,mainfile);
            fputs(content,mainfile);
            fputs(after,mainfile);
            fclose(mainfile);
            return 1;
}



int main()
{
    
    //printf("hello");
    char* command=(char*)malloc(sizeof(char)*60);
    char* clipboard=starter(8000);
    //printf("hello");
    while(1)
    {
        //printf("PPPOOOOFFFF");
        scanf("%s",command);
        //printf("\n=======%s=======\n",command);
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

            //printf("\n%s\n",content);
            //printf("%s\n",address);
            /////////////////////////////////////////////////////////////////////////////////////////
            char check=getchar();
            if(check==' ')
            {
                if(!(check_input("--pos ",6)))
            {
                printf("\ndorost voroodi bede digeb\n");
                continue;
            }
            }
            else if(check=='-')
            {
                if(!(check_input("-pos ",5)))
            {
                printf("\ndorost voroodi bede digeeee\n");
                continue;
            }
            }
            else
            {
                printf("\ndorost voroodi bede diger\n");
                continue;
            }
            /*char*buff2=starter(20);
            int counter=0;
            while((*(buff2+counter)=getchar())!='s');
            {
                counter++;
            }
            if(counter==4 && compare_string(buff2,"--pos"));
            else if(counter==5 && compare_string(buff2," --pos"));
            else
            {
                printf("\nvoroodi eshtebah\n");
                continue;
            }
            if(!(check_input(" ",1)))
            {
                printf("\ndorost voroodi bede dige\n");
                continue;
            }
            */
            //////////////////////////////////////////////////////////////////////////////////////
            int line_number,start_position;
            scanf("%d",&line_number);

            if(!(check_input(":",1)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            scanf("%d",&start_position);

            if(!(check_input(" -size ",7)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            printf("%d  %d",line_number,start_position);

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
            while(current_line!=line_number || current_position!=start_position)
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
        if(compare_string("cat",command))
        {
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige\n");
                continue;
            }
            //char * content=starter(20000);
            char *address=give_me_me_the_address_bastard();
            if(!(exists(address)))
            {
                printf("\naddress kharab\n");
                continue;
            }
            FILE* file_to_read=fopen(address,"r");
            char c;
            while((c=fgetc(file_to_read))!=EOF)
            {
                printf("%c",c);
            }
            printf("\n");
        }       
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("removestr",command))
        {
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige0\n");
                continue;
            }

            char *address=give_me_me_the_address_bastard();
            if(!(exists(address)))
            {
                printf("\naddress kharab\n");
                continue;
            }

            if(!(check_input("-pos ",5)))
            {
                printf("\ndorost voroodi bede dige1\n");
                continue;
            }
            int line_number,start_position;
            scanf("%d",&line_number);

            if(!(check_input(":",1)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            scanf("%d",&start_position);

            if(!(check_input(" -size ",7)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            int size;
            scanf("%d",&size);

            if(!(check_input(" -",2)))
            {
                printf("\ndorost voroodi bede dige3\n");
                continue;
            }
            
            char direction=getchar();

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
            int size_of_after=0;
            int size_of_before=0;
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
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
                    size_of_before++;
                }
                else 
                {
                    current_position++;
                    i++;
                    size_of_before++;
                }
            }
            if(!flag)
            {
                printf("\nmage man ba to shookhi daram. inhame khat ro bokon to halghet\n");
                continue;
            }
            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
                size_of_after++;
            }
            fclose(mainfile);
            
            //printf("\n%s\n%s\n",before,after);
            //printf("%d\n",size);
            ///////////////////neveshtan
            mainfile=fopen(address,"w");
            if(direction=='f')
            {
                if(size_of_after<size)
                {
                    printf("\ninghadr char nadare! az bala kam miare\n");
                    fclose(mainfile);
                    continue;
                }
                fputs(before,mainfile);
                for(int i=size;i<size_of_after;i++)
                {
                    fputc(*(after+i),mainfile);
                }
                fclose(mainfile);
            }
            else if(direction=='b')
            {
                if(size_of_before<size)
                {
                    printf("\ninghadr char nadare! az paeen kam miare\n");
                    fclose(mainfile);
                    continue;
                }
                for(int i=0;i<size_of_before-size;i++)
                {
                    fputc(*(before+i),mainfile);
                }
                fputs(after,mainfile);
                fclose(mainfile);
            }
            else
            {
                printf("\nvoorodi eshtebah\n");
                continue;
            }
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("copystr",command))
        {
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }

            char* address=give_me_me_the_address_bastard();
            if(!exists(address))
            {
                printf("\naddress kharab\n");
                continue;
            }

            if(!(check_input("-pos ",5)))
            {
                printf("\ndorost voroodi bede dige6\n");
                continue;
            }
            /////////////////////////////////////
            int line_number,start_position;
            scanf("%d",&line_number);

            if(!(check_input(":",1)))
            {
                printf("\ndorost voroodi bede dige5\n");
                continue;
            }

            scanf("%d",&start_position);

            if(!(check_input(" -size ",7)))
            {
                printf("\ndorost voroodi bede dige4\n");
                continue;
            }
            ///////////////////////////////////////
            int size;
            scanf("%d",&size);

            if(!(check_input(" -",2)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }
            char direction=getchar();

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
            int size_of_after=0;
            int size_of_before=0;
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
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
                    size_of_before++;
                }
                else 
                {
                    current_position++;
                    i++;
                    size_of_before++;
                }
            }
            if(!flag)
            {
                printf("\nmage man ba to shookhi daram. inhame khat ro bokon to halghet\n");
                continue;
            }
            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
                size_of_after++;
            }
            fclose(mainfile);

            if(direction=='f')
            {
                if(size_of_after<size)
                {
                    printf("\ninghadr char nadare! az bala kam miare\n");
                    continue;
                }

                for(int i=0;i<size;i++)
                {
                    clipboard[i]=*(after+i);
                }
            }
            else if(direction=='b')
            {
                if(size_of_before<size)
                {
                    printf("\ninghadr char nadare! az paeen kam miare\n");
                    continue;
                }
                for(int i=size_of_before-size;i<size_of_before;i++)
                {
                    clipboard[i-size_of_before+size]=*(before+i);
                }
            }
            else
            {
                printf("\nvoorodi eshtebah\n");
                continue;
            }
            //printf("\n");
            printf("\n%s\n",clipboard);
            continue;
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("cutstr",command))
        {
            if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige0\n");
                continue;
            }

            char *address=give_me_me_the_address_bastard();
            if(!(exists(address)))
            {
                printf("\naddress kharab\n");
                continue;
            }

            if(!(check_input("-pos ",5)))
            {
                printf("\ndorost voroodi bede dige1\n");
                continue;
            }
            int line_number,start_position;
            scanf("%d",&line_number);

            if(!(check_input(":",1)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            scanf("%d",&start_position);

            if(!(check_input(" -size ",7)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            int size;
            scanf("%d",&size);

            if(!(check_input(" -",2)))
            {
                printf("\ndorost voroodi bede dige3\n");
                continue;
            }
            
            char direction=getchar();

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
            int size_of_after=0;
            int size_of_before=0;
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
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
                    size_of_before++;
                }
                else 
                {
                    current_position++;
                    i++;
                    size_of_before++;
                }
            }
            if(!flag)
            {
                printf("\nmage man ba to shookhi daram. inhame khat ro bokon to halghet\n");
                continue;
            }
            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
                size_of_after++;
            }
            fclose(mainfile);
            
            //printf("\n%s\n%s\n",before,after);
            //printf("%d\n",size);
            ///////////////////neveshtan
            mainfile=fopen(address,"w");
            go_to_starter(clipboard,8000);
            if(direction=='f')
            {
                if(size_of_after<size)
                {
                    printf("\ninghadr char nadare! az bala kam miare\n");
                    fclose(mainfile);
                    continue;
                }
                fputs(before,mainfile);
                for(int i=size;i<size_of_after;i++)
                {
                    fputc(*(after+i),mainfile);
                }
                fclose(mainfile);

                for(int i=0;i<size;i++)
                {
                    clipboard[i]=*(after+i);
                }

            }
            else if(direction=='b')
            {
                if(size_of_before<size)
                {
                    printf("\ninghadr char nadare! az paeen kam miare\n");
                    fclose(mainfile);
                    continue;
                }
                for(int i=0;i<size_of_before-size;i++)
                {
                    fputc(*(before+i),mainfile);
                }
                fputs(after,mainfile);
                fclose(mainfile);

                for(int i=size_of_before-size;i<size_of_before;i++)
                {
                    clipboard[i-size_of_before+size]=*(before+i);
                }

            }
            else
            {
                printf("\nvoorodi eshtebah\n");
                continue;
            }
            printf("\n%s\n",clipboard);
        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("pastestr",command))
        {
             if(!(check_input(" --file /",9)))
            {
                printf("\ndorost voroodi bede dige0\n");
                continue;
            }

            char *address=give_me_me_the_address_bastard();
            if(!(exists(address)))
            {
                printf("\naddress kharab\n");
                continue;
            }

            if(!(check_input("-pos ",5)))
            {
                printf("\ndorost voroodi bede dige1\n");
                continue;
            }
            int line_number,start_position;
            scanf("%d",&line_number);

            if(!(check_input(":",1)))
            {
                printf("\ndorost voroodi bede dige2\n");
                continue;
            }

            scanf("%d",&start_position);


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
            int size_of_after=0;
            int size_of_before=0;
            while(current_line!=line_number || current_position!=start_position)
            {
                c=fgetc(mainfile);
                //printf("  %c  ",c);
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
                    size_of_before++;
                }
                else 
                {
                    current_position++;
                    i++;
                    size_of_before++;
                }
            }
            if(!flag)
            {
                printf("\nmage man ba to shookhi daram. inhame khat ro bokon to halghet\n");
                continue;
            }
            while(((c=fgetc(mainfile))!=EOF))
            {
                //printf("*%c",c);
                *(after+j)=c;
                j++;
                size_of_after++;
            }
            fclose(mainfile);


            mainfile=fopen(address,"w");
            fputs(before,mainfile);
            fputs(clipboard,mainfile);
            fputs(after,mainfile);
            fclose(mainfile);

        }
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("find",command))
        {
              if(!(check_input(" --str ",7)))
            {
                printf("\ndorost voroodi bede dige0\n");
                continue;
            }
            char* target=read_content2();
            printf("its target : %s\n",target);
              if(!(check_input("--file /",8)))
            {
                printf("\ndorost voroodi bede dige0\n");
                continue;
            }

            int flag=0;
            char *address=give_me_me_the_address_bastard2(&flag);
            if(!(exists(address)))
            {
                printf("\naddress kharab\n");
                continue;
            }
            printf("%s\n",address);
            ////////////////////////////////////////////////////////////////////////

            char* in_the_file=starter(10000);
            FILE* file;
            //file=fopen(address,"w");
            //fputs("hohohoho Salam Salam",file);
            //fclose(file);
            file=fopen(address,"r");
            int i=0;
            char u;
            while((u=fgetc(file))!=EOF)
            {
                in_the_file[i]=u;
                i++;
            }
            struct apperence all_of_wanted[MAX_OCCUR];
            struct_starter(all_of_wanted,MAX_OCCUR);
            find_all_occurence_Namooos(in_the_file,target,all_of_wanted);
            fclose(file);
            printf("content of file: %s\n",in_the_file);
            ////////////////////////////////////////////////////////////////////////
            if(flag)
            {
                char first_switch[100];
                char second_switch[100];
                scanf("%s",first_switch);
                if(compare_string(first_switch,"count"))
                {
                    if(getchar()=='\n')
                    {
                        int counter=0;
                        for(int i=0;i<MAX_OCCUR;i++)
                        {
                            if(all_of_wanted[i].char_number!=-1)
                            counter++;
                            else
                            break;
                        }
                        printf("%d\n",counter);
                        continue;
                    }
                    else
                    {
                        printf("vorooodi bad\n");
                        continue;
                    }
                }
                if(compare_string(first_switch,"at"))
                {
                    char d;
                    getchar();
                    int number_wanted;
                    scanf("%d",&number_wanted);
                    if((d=getchar())=='\n')
                    {
                        printf("%d\n",all_of_wanted[number_wanted-1].char_number);
                        continue;
                    }
                    else if(d!=' ')
                    {
                        printf("vorooodi bad\n");
                        continue;
                    }
                    else
                    {
                        scanf("%s",second_switch);
                        if(compare_string(second_switch,"-byword"))
                        {
                            getchar();//////////////!!!!!!!!!!
                            printf("%d\n",all_of_wanted[number_wanted-1].word_number);
                            continue;
                        }
                        else{
                        printf("vorooodi bad\n");
                        continue;
                        }
                    }
                }
                if(compare_string(first_switch,"byword"))
                {
                    char d;
                    if((d=getchar())=='\n')
                    {
                        printf("%d\n",all_of_wanted[0].word_number);
                        continue;
                    }
                    else if(d!=' ')
                    {
                        printf("vorooodi bad\n");
                        continue;
                    }
                    else
                    {
                        scanf("%s",second_switch);
                        if(compare_string(second_switch,"-all"))
                        {
                            getchar();//////////////!!!!!!!!!!
                            int j=0;
                            while(all_of_wanted[j].char_number!=-1)
                            {
                                printf("%d ",all_of_wanted[j].word_number);
                                j++;
                            }
                            printf("\n");
                            continue;
                        }
                        else if(compare_string(second_switch,"-at"))
                        {
                            getchar();
                            int number_wanted;
                            scanf("%d",&number_wanted);

                            getchar();//////////////!!!!!!!!!!
                            printf("%d\n",all_of_wanted[number_wanted-1].word_number);
                            continue;

                        }
                        else{
                        printf("vorooodi bad\n");
                        continue;
                        }
                    }
                }
                if(compare_string(first_switch,"all"))
                {
                    char d;
                    if((d=getchar())=='\n')
                    {
                        int j=0;
                        while(all_of_wanted[j].char_number!=-1)
                        {
                            printf("%d ",all_of_wanted[j].char_number);
                            j++;
                        }
                        printf("\n");
                        continue;
                    }
                    else if(d!=' ')
                    {
                        printf("vorooodi bad\n");
                        continue;
                    }
                    else
                    {
                        scanf("%s",second_switch);
                        if(compare_string(second_switch,"-byword"))
                        {
                            getchar();//////////////!!!!!!!!!!
                            int j=0;
                            while(all_of_wanted[j].char_number!=-1)
                            {
                                printf("%d ",all_of_wanted[j].word_number);
                                j++;
                            }
                            printf("\n");
                            continue;
                        }
                        else{
                        printf("vorooodi bad\n");
                        continue;
                        }
                    }
                }
            }
            else
            {
                printf("no switch\n");
                printf("%d\n",all_of_wanted[0].char_number);
                continue;
            }

        }
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////
        if(compare_string("replace",command))
        {
            if(!(check_input(" --str1 ",8)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            char *first_string=read_content2();

            if(!(check_input("--str2 ",7)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            char* second_string=read_content3();

            if(!(check_input("--file /",8)))
            {
                printf("dorost voroodi bede dige7\n");
                while(getchar()!='\n');
                continue;
            }

            int flag;
            char* address=give_me_me_the_address_bastard2(&flag);
            if(!exists(address))
            {
                printf("\naddress kharab\n");
                continue;
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////////


            char* in_the_file=starter(10000);
            FILE* file;
            //file=fopen(address,"w");
            //fputs("hohohoho Salam Salam",file);
            //fclose(file);
            file=fopen(address,"r");
            int i=0;
            char u;
            while((u=fgetc(file))!=EOF)
            {
                in_the_file[i]=u;
                i++;
            }
            struct apperence all_of_wanted[MAX_OCCUR];
            struct_starter(all_of_wanted,MAX_OCCUR);
            find_all_occurence_Namooos(in_the_file,first_string,all_of_wanted);
            fclose(file);

            printf("wanted : %s\n",first_string);
            printf("content of file: %s\n",in_the_file);





            //////////////////////////////////////////////////////////////////////////////////////////////////////////////
            if(flag)
            {
                char first_switch[100];
                scanf("%s",first_switch);
                if(compare_string(first_switch,"at"))
                {
                    getchar();
                    int num_wanted;
                    scanf("%d",&num_wanted);
                    if(all_of_wanted[num_wanted-1].char_number==-1)
                    {
                        printf("peida noshod\n");
                        continue;
                    }
                    else
                    {
                        remove_from_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,all_of_wanted[num_wanted-1].size,'f');
                        insert_in_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,second_string);
                        continue;
                    }
                }
                if(compare_string(first_switch,"all"))
                {
                    //getchar();
                    int l=0;
                    while(all_of_wanted[l].char_number!=-1)
                    {
                        //printf("===== %d =====",all_of_wanted[l].size);
                        //printf("khaste nabashid \n");
                        remove_from_file(all_of_wanted[l].line_number,all_of_wanted[l].pos_in_string,address,all_of_wanted[l].size,'f');
                        insert_in_file(all_of_wanted[l].line_number,all_of_wanted[l].pos_in_string,address,second_string);
                        ///////////////////////////////////////////////////////////////////////////////////////////////

                        char* in_the_file=starter(10000);
                        FILE* file;
                        //file=fopen(address,"w");
                        //fputs("hohohoho Salam Salam",file);
                        //fclose(file);
                        file=fopen(address,"r");
                        int i=0;
                        char u;
                        while((u=fgetc(file))!=EOF)
                        {
                            in_the_file[i]=u;
                            i++;
                        }
                        //struct apperence all_of_wanted[MAX_OCCUR];
                        struct_starter(all_of_wanted,MAX_OCCUR);
                        find_all_occurence_Namooos(in_the_file,first_string,all_of_wanted);
                        fclose(file);
                        //printf("content of file: %s\n",in_the_file);



                        ///////////////////////////////////////////////////////////////////////////////////////////////
                        l++;
                    }
                    continue;
                }
                else
                {
                     printf("dorost voroodi bede dige7\n");
                    while(getchar()!='\n');
                    continue;
                }
            }
            else
            {
                //getchar();
                int num_wanted=1;
                remove_from_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,all_of_wanted[num_wanted-1].size,'f');
                insert_in_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,second_string);
                continue;
            }
        }
        if(compare_string("grep",command))
        {
            getchar();
            char a=getchar();
            char b=getchar();
            int type=0;
            if(a!='-')
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }


            else if(b=='c'){
            type=1;
            if(!(check_input(" --str ",7)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            }

            else if(b=='l'){
            type=2;
            if(!(check_input(" --str ",7)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            }

            else if(b=='-'){
            if(!(check_input("str ",4)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            type==0;
            }

            else
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }

            char* target=read_content3();

            if(!(check_input("--files ",8)))
            {
                printf("\ndorost voroodi bede dige7\n");
                continue;
            }
            //printf("%s\n",target);


            int flag=1;
            int files_occurence[100]={0};
            int lines_occurences[100];
            char* addresses[100];
            int number_of_files=0;
            while(flag)
            {
                addresses[number_of_files]=give_me_me_the_address_bastard3(&flag);
                //printf("%s\n",addresses[number_of_files]);
                number_of_files++;
            }


            char* content_of_file[100];
            for(int i=0;i<number_of_files;i++)
            {
                //////////////////////////////////////////////////////
                
                content_of_file[i]=starter(10000);
                FILE* file;
                //file=fopen(address,"w");
                //fputs("hohohoho Salam Salam",file);
                //fclose(file);
                file=fopen(addresses[i],"r");
                int j=0;
                char u;
                while((u=fgetc(file))!=EOF)
                {
                    content_of_file[i][j]=u;
                    j++;
                }
                fclose(file);
                printf("%s\n================================================\n",content_of_file[i]);
                
                //////////////////////////////////////////////////////
            }

        
            if(type==0)
            {
                for(int i=0;i<number_of_files;i++)
                {
                

                occurence_starter(lines_occurences,100);
                find_lines_of_occurence(content_of_file[i],target,lines_occurences);

                if(lines_occurences[0]!=-1)
                files_occurence[i]=1;

                int s=0;
                while(lines_occurences[s]!=-1)
                {
                    printf("%s:",addresses[i]);
                    khat_k_chap_kon(content_of_file[i],lines_occurences[s]);
                    printf("\n");
                    s++;
                }
                }
                continue;
            }

            if(type==1)
            {
                int ans=0;
                for(int i=0;i<number_of_files;i++)
                {
                    occurence_starter(lines_occurences,100);
                    find_lines_of_occurence(content_of_file[i],target,lines_occurences);
                

                    int s=0;
                    while(lines_occurences[s]!=-1)
                    {
                        ans++;
                        s++;
                    }
                }

                printf("%d\n",ans);
                continue;
            }

            if(type==2)
            {
                for(int i=0;i<number_of_files;i++)
                {
                    if(files_occurence[i]!=-1)
                    printf("%s ",addresses[i]);
                }
                printf("\n");
                continue;
            }


        }
        else
        {
            printf("\ntamooom shod. boro birooon\n");
            //break;
        }


    }
    return 0;
}