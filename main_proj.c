#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <io.h>
#include<dirent.h>
#include<windows.h>
#define MAX_OCCUR 10000
int number_of_digits(int n)
{
    if(n==0)
    return 1;
    int ans=0;
    while(n>0){
        ans++;
        n/=10;
    }
    return ans;
}
char* starter(int n)
{
    char* a=(char*)malloc(sizeof(char)*n);
    for(int i=0;i<n;i++)
    *(a+i)='\0';
    return a;
}
int go_to_starter(char* s,int n)
{
    for(int i=0;i<n;i++)
    *(s+i)='\0';
}
char sgetchar(char**s)
{
    char c=**s;
    (*s)++;
    return c;
}
char* sgetword(char**s)
{
    char* ans=starter(500);
    int i=0;
    while(**s!=' '&&**s!='\n'&&**s!='\0')
    {
        ans[i]=**s;
        (*s)++;
        i++;
    }
    //(*s)++;
    return ans;
}
void copy_to_clipboard(char *s)
{
    OpenClipboard(0);
    EmptyClipboard();
    const char* op=s;
    const size_t ln = strlen(op)+1;
    HGLOBAL h= GlobalAlloc(GMEM_MOVEABLE, ln);
    memcpy(GlobalLock(h),op,ln);
    GlobalUnlock(h);
    SetClipboardData(CF_TEXT,h);
    CloseClipboard();
    return;
}
void paste_from_clipboard(char* s)
{
    OpenClipboard(0);
    HANDLE in= GetClipboardData(CF_TEXT);
    strcpy(s,in);
    CloseClipboard();
}
struct file_history{
    int existed;
    char* file_address;
    char* last_content;
};
struct file_history all_history[1000];
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
int shit_counter=0;
int check_input(char*s,int n,char** r)
{
    char c;
    int flag=0;
    for(int i=0;(i<n && (**r)!='\0');i++)
    {
        //printf("$$  %c  $$",**r);
        c=sgetchar(r);
        if(c!=(*(s+i)))
        {
            printf("dorotst voroodi bede\n");
            return 0;
        }
    }
    return 1;
}
char* give_me_me_the_address_bastard(char** s)
{
    char * address=starter(120);
    for(int i=0;i<120;i++)
    *(address+i)='\0';
    //if((*address=getchar())!='"')
    //{
        char c;
        int i=0;
        while((c=sgetchar(s))!='\n' && c!='-' && c!='\0')
        {
            if(c!='"');
            {
                *(address+i)=c;
                i++;
            }
        }
        int n=strlen(address);
        if(c!='\n')
        address[n]='\0';
        return address;
    //}
}
char* give_me_me_the_address_bastard2(char** s)
{
    char * address=starter(120);
    for(int i=0;i<120;i++)
    *(address+i)='\0';
    //if((*address=getchar())!='"')
    //{
        char c;
        int i=0;
        while((c=sgetchar(s))!='\n' && c!=' ' && c!='\0')
        {
            if(c!='"');
            {
                *(address+i)=c;
                i++;
            }
        }
        int n=strlen(address);
        if(c!='\n')
        address[n]='\0';
        return address;
    //}
}
char* read_content(char** s,int type)
{
    char* ans=(char*)malloc(sizeof(char)*4000);
    for(int i=0;i<4000;i++)
    *(ans+i)='\0';
    char d='\0';
    int i=0;
    char c=sgetchar(s);
    if(c=='"')
    {
        while((c=sgetchar(s))!='"'&&c!='\0')
        {
            if(type==1 && c=='*')
            {
                *(ans+i)=1;
                i++;
            }
            else if(c=='\\')
            {
                d=sgetchar(s);
                if(d=='\\')
                {
                    *(ans+i)='\\';
                    i++;
                    *(ans+i)=sgetchar(s);
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
                if(type==1 && d=='*')
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
        sgetchar(s);
    }
    else
    {
        if(type==0 || c!='*')
        *(ans+i)=c;
        else
        *(ans+i)=1;
        i++;
        while((c=sgetchar(s))!=' '&&c!='\0')
        {
            if(type==1&&c=='*') {*(ans+i)=1;i++;}
            else if(c=='\\')
            {
                d=sgetchar(s);
                if(d=='\\')
                {
                    *(ans+i)='\\';
                    i++;
                    *(ans+i)=sgetchar(s);
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
                if(type==1&&d=='*')
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
void create_the_foooking_file(char *address)
{
    FILE* recent_file ;
    recent_file=fopen(address,"w");
    fclose(recent_file);
}
void create_file(char * address)
{
    make_address_available(address);
    if(exists(address))
    {
        printf("its already existed\n");
    }
    else{
        create_the_foooking_file(address);
        all_history[shit_counter].existed=0;
        all_history[shit_counter].file_address=address;
        shit_counter++;
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
            /////
            while(main_string[i]!='\n')
            i++;
            continue;
        }

        i++;
    }
}
char * khat_k_chap_kon(char* chert,int k)
{
    char* output=starter(100000);
    char* temp=starter(1000);
    int line_num=1;
    int i=0;
    while(chert[i]!='\0')
    {
        if(line_num==k)
        {
            while(chert[i]!='\n'&&chert[i]!='\0')
            {
                sprintf(temp,"%c",chert[i]);
                strcat(output,temp);
                i++;
            }
            break;
        }
        if(chert[i]=='\n')
        line_num++;
        i++;
    }
    return output;
}
void occurence_starter(int occurence[],int n)
{
    for(int i=0;i<n;i++)
    occurence[i]=-1;
}
char* save_file(char *address)
{
    char* saver=starter(10000);
    FILE* file;
    //file=fopen(address,"w");
    //fputs("hohohoho Salam Salam",file);
    //fclose(file);
    file=fopen(address,"r");
    int v=0;
    char u;
    while((u=fgetc(file))!=EOF)
    {
        saver[v]=u;
        v++;
    }
    fclose(file);
    return saver;
}
void save_in_history(char* address,char * content_to_save)
{
    int andis=-1;
    for(int i=0;i<shit_counter;i++)
    {
        if(!strcmp(all_history[i].file_address,address))
        andis=i;
    }
    if(andis>=0)
    all_history[andis].last_content=content_to_save;
    else{
        all_history[shit_counter].file_address=address;
        all_history[shit_counter].last_content=content_to_save;
        shit_counter++;
    }
    return;
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
    int size=strlen(target_string);
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
            if(line_number==current_line+1 && start_position==0)
            before[i]='\n';
            else
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
        return 0;
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
int remove_from_file(int line_number,int start_position,char* address,int size,char direction)
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
        return 0 ;
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
            return 0 ;
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
            return 0;
        }
        for(int i=0;i<size_of_before-size;i++)
        {
            fputc(*(before+i),mainfile);
        }
        fputs(after,mainfile);
        fclose(mainfile);
        return 1;
    }
    else
    {
        printf("\nvoorodi eshtebah\n");
        return 0;
    }
}
int copy_from_file(int line_number,int start_position,char* address,int size,char direction,char* clipboard)
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
                return 0;
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
                    return 0;
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
                    return 0;
                }
                for(int i=size_of_before-size;i<size_of_before;i++)
                {
                    clipboard[i-size_of_before+size]=*(before+i);
                }
            }
            else
            {
                printf("\nvoorodi eshtebah\n");
                return 0;
            }
            //printf("\n");
            printf("\n%s\n",clipboard);
            copy_to_clipboard(clipboard);
            return 1;
}
int cut_from_file(int line_number,int start_position,char* address,int size,char direction,char* clipboard)
{
    int a=copy_from_file(line_number,start_position,address,size,direction,clipboard);
    int b=remove_from_file(line_number,start_position,address,size,direction);
    if(a&&b)
    return 1;
    else
    return 0;
}
int paste_to_file(int line_number,int start_position,char* address,char* clipboard)
{
    paste_from_clipboard(clipboard);
    int a=insert_in_file(line_number,start_position,address,clipboard);
    if(a)
    return 1;
    else
    return 0;
}
char* find(char *target,char*address,int type,int number_wanted)
{
    char* output=starter(100000);
    char* temp=starter(1000);
    printf("its in find2\n");
    char* in_the_file=save_file(address);
    struct apperence all_of_wanted[MAX_OCCUR];
    struct_starter(all_of_wanted,MAX_OCCUR);
    find_all_occurence_Namooos(in_the_file,target,all_of_wanted);
    if(type==0){//nothing
        printf("no switch\n");
        sprintf(temp,"%d\n",all_of_wanted[0].char_number);
        strcat(output,temp);return output;
    }
    if(type==1){//just count
        int counter=0;
        for(int i=0;i<MAX_OCCUR;i++)
        {
            if(all_of_wanted[i].char_number!=-1)
            counter++;
            else
            break;
        }
        sprintf(output,"%d\n",counter);return output;
    }
    if(type==2){//just at
        sprintf(temp,"%d\n",all_of_wanted[number_wanted-1].char_number);
        strcat(output,temp); return output;
    }
    if(type==4){//just by word
        sprintf(output,"%d\n",all_of_wanted[0].word_number);return output;
    }
    if(type==8){//just all
        int j=0;
        while(all_of_wanted[j].char_number!=-1)
        {
            sprintf(temp,"%d ",all_of_wanted[j].char_number);
            strcat(output,temp);
            j++;
        }
        strcat(output,"\n");return output;
    }
    if(type==6){//at and byword
        sprintf(output,"%d\n",all_of_wanted[number_wanted-1].word_number);return output ;
    }
    if(type==12){//all and byword
        int j=0;
        while(all_of_wanted[j].char_number!=-1)
        {
            sprintf(temp,"%d ",all_of_wanted[j].word_number);
            strcat(output,temp);
            j++;
        }
        strcat(output,"\n");return output;
    }
}
int replace(char *target,char*address,int type,int num_wanted,char *second_string)
{
    //printf("int the function\n");
    char* in_the_file=save_file(address);
    struct apperence all_of_wanted[MAX_OCCUR];
    struct_starter(all_of_wanted,MAX_OCCUR);
    find_all_occurence_Namooos(in_the_file,target,all_of_wanted);
    //printf(">>>> %d\n",all_of_wanted[0].line_number);
    if(type==0||type==2){
        if(all_of_wanted[num_wanted-1].line_number==-1)return 0;
        remove_from_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,all_of_wanted[num_wanted-1].size,'f');
        insert_in_file(all_of_wanted[num_wanted-1].line_number,all_of_wanted[num_wanted-1].pos_in_string,address,second_string);
        return 1;
    }
    if(type==8){
        if(all_of_wanted[num_wanted-1].line_number==-1)return 0;
        int l=0;
        while(all_of_wanted[l].char_number!=-1)
        {
            remove_from_file(all_of_wanted[l].line_number,all_of_wanted[l].pos_in_string,address,all_of_wanted[l].size,'f');
            insert_in_file(all_of_wanted[l].line_number,all_of_wanted[l].pos_in_string,address,second_string);
            in_the_file=save_file(address);
            struct_starter(all_of_wanted,MAX_OCCUR);
            find_all_occurence_Namooos(in_the_file,target,all_of_wanted);
        }
        return 1;
    }
}
char* grep(char *target,char* addresses[],int type,int number_of_files)
{
    char* output=starter(100000);
    char* temp=starter(1000);
    int files_occurence[100]={0};
    int lines_occurences[100];
    char* content_of_file[number_of_files];
    for(int i=0;i<number_of_files;i++)
        content_of_file[i]=save_file(addresses[i]);
    if(type==0)
    {
        for(int i=0;i<number_of_files;i++){
            occurence_starter(lines_occurences,100);
            find_lines_of_occurence(content_of_file[i],target,lines_occurences);
            if(lines_occurences[0]!=-1)
            files_occurence[i]=1;

            int s=0;
            while(lines_occurences[s]!=-1)
            {
                sprintf(temp,"%s:",addresses[i]);
                strcat(output,temp);
                char* khat=khat_k_chap_kon(content_of_file[i],lines_occurences[s]);
                strcat(output,khat);
                sprintf(temp,"\n");
                strcat(output,temp);
                s++;
            }
        }
        return output;
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
        sprintf(output,"%d\n",ans);
        return output;
    }
    if(type==2)
    {
        for(int i=0;i<number_of_files;i++)
        {
            if(files_occurence[i]!=-1)
            {
                sprintf(temp,"%s ",addresses[i]);
                strcat(output,temp);
            }
        }
        sprintf(temp,"\n");
        strcat(output,temp);
        return output;
    }

}
char* compare(char* first_address,char* second_address)
{
    char* output=starter(100000);
    char* temp=starter(1000);
    char* first_content=save_file(first_address);
	char* second_content=save_file((second_address));
    //printf("%s\n===================\n%s\n",first_content,second_content);
    int pos_in_first=0;
    int pos_in_second=0;
    char* line_saver1=starter(10000);
    char* line_saver2=starter(10000);
    int line_number=1;
    int flag1=0;
    int flag2=0;
    while(1)
    {
        int counter1=0;
        int counter2=0;
        while(first_content[pos_in_first]!='\n')
        {
            if(first_content[pos_in_first]=='\0')
            {
                flag1=1;
                break;
            }
            line_saver1[counter1]=first_content[pos_in_first];
            pos_in_first++;
            counter1++;
        }
        line_saver1[counter1]='\n';
        pos_in_first++;
        counter1++;

        while(second_content[pos_in_second]!='\n')
        {
            if(second_content[pos_in_second]=='\0')
            {
                flag2=1;
                break;
            }
            line_saver2[counter2]=second_content[pos_in_second];
            pos_in_second++;
            counter2++;
        }
        line_saver2[counter2]='\n';
        pos_in_second++;
        counter2++;

        if(strcmp(line_saver1,line_saver2))
        {
            sprintf(temp,"============ #%d# ============\n",line_number);strcat(output,temp);
            sprintf(temp,"%s",line_saver1);strcat(output,temp);
            sprintf(temp,"%s",(line_saver2));strcat(output,temp);
        }
        go_to_starter(line_saver1,10000);
        go_to_starter(line_saver2,10000);
        line_number++;
        if(flag1!=0&&flag2==0)
        {
            counter2=0;
            int adding_line=0;
            while(second_content[pos_in_second]!='\0')
            {
                if(second_content[pos_in_second]=='\n')
                adding_line++;
                line_saver2[counter2]=second_content[pos_in_second];
                pos_in_second++;
                counter2++;
            }
            sprintf(temp,">>>>>>>>>>>> #%d - #%d >>>>>>>>>>>>\n",line_number,line_number+adding_line);strcat(output,temp);
            sprintf(temp,"%s\n",line_saver2);strcat(output,temp);
            break;
        }

        else if(flag2!=0&&flag1==0)
        {
            counter1=0;
            int adding_line=0;
            while(first_content[pos_in_first]!='\0')
            {
                if(first_content[pos_in_first]=='\n')
                adding_line++;
                line_saver1[counter1]=first_content[pos_in_first];
                pos_in_first++;
                counter1++;
            }
            sprintf(temp,"<<<<<<<<<<<< #%d - #%d <<<<<<<<<<<<\n",line_number,line_number+adding_line);strcat(output,temp);
            sprintf(temp,"%s\n",line_saver1);strcat(output,temp);
            break;
        }

        else if(flag1==1&&flag2==1)
        break;
    }
    return output;
}
char* tree(char *address, int current_root,int depth,char *output)
{
    char* temp=starter(1000);
    if(depth<=0)return output;
    int i;
    char next_address[1000];
    struct dirent* current_file;

    DIR* dir= opendir(address);
    if (!dir)return output;
    while ((current_file = readdir(dir)) != NULL){
        if (strcmp(current_file->d_name,".") != 0 && strcmp(current_file->d_name,"..") != 0){
            for (i=0; i<current_root; i++) {
                if (i%2 == 0 || i == 0){
                    sprintf(temp,"%c", 179);// >> | <<
                    strcat(output,temp);
                }
                else{
                    sprintf(temp," ");
                    strcat(output,temp);
                }
            }
            sprintf(temp,"%c%c%s\n",195,196,current_file->d_name); // 195: >> ??? <<    //196: >> ??? <<
            strcat(output,temp);
            strcpy(next_address,address);
            strcat(next_address,"/");
            strcat(next_address,current_file->d_name);
            tree(next_address,current_root + 2,depth-1,output);
        }
    }
    closedir(dir);
}
char* input_cat(char**command)
{
    if(!(check_input(" --file /",9,command)))return 0;
    char *address=give_me_me_the_address_bastard(command);
    if(!(exists(address)))  {printf("\naddress kharab\n");return 0;}
    char* ans=save_file(address);
    return ans;
}
char* input_find(char** command)
{
    int num_wanted=0;
    if(!(check_input(" --str ",7,command))) return 0;
    char* target=read_content(command,1);
    //printf("its target : %s\n",target);
    if(!(check_input("--file /",8,command)))return 0;
    int type=0;
    char *address=give_me_me_the_address_bastard(command);
    if(!(exists(address)))  {printf("\naddress kharab\n");  return 0;}
    //printf("%s\n",address);
    char* first_switch=sgetword(command);
    if(first_switch[0]!='\0'){
        if(!strcmp(first_switch,"count")) type+=1;
        else if(!strcmp(first_switch,"at")){
            type+=2;
            if(!(check_input(" ",1,command))) return 0 ;
            sscanf(*command,"%d",&num_wanted);
            *command+=number_of_digits(num_wanted);
        }
        else if(!strcmp(first_switch,"byword"))type+=4;
        else if(!strcmp(first_switch,"all"))type+=8;
        else { printf("switch kharab\n"); return 0; }
        if(!(check_input(" ",1,command))) return 0;
        char* second_switch=sgetword(command);
        if(second_switch[0]!='\0'){
            if(!strcmp(second_switch,"-at")){
            type+=2;
            if(!(check_input(" ",1,command))) return 0;
            sscanf(*command,"%d",&num_wanted);
            *command+=number_of_digits(num_wanted);
            if(!(check_input(" ",1,command))) return 0;
            }
            else if(!strcmp(second_switch,"-byword"))type+=4;
            else if(!strcmp(second_switch,"-all"))type+=8;
            else { printf("switch kharab\n"); return 0; }
        }
        //printf("%s\n",second_switch);
        (*command)++;
        if(sgetchar(command)!='\0') { printf("switch kharabz\n"); return 0; }
    }
    char *ans=find(target,address,type,num_wanted);
    return ans;
}
char* input_replace(char** command)
{
    //printf("in the main\n");
    if(!(check_input(" --str1 ",8,command))) return 0;
    char *first_string=read_content(command,1);
    if(!(check_input("--str2 ",7,command))) return 0;
    char* second_string=read_content(command,1);
    if(!(check_input("--file /",8,command))) return 0;
    char* address=give_me_me_the_address_bastard(command);
    if(!exists(address))  {printf("\naddress kharab\n");return 0;}
    int type=0,num_wanted=1;
    char* saver=save_file(address);
    char* first_switch=sgetword(command);
    if(first_switch[0]!='\0'){
    if(!strcmp(first_switch,"at")){
        type+=2;
        if(!(check_input(" ",1,command))) return 0;
        sscanf(*command,"%d",num_wanted);
        (*command)+=number_of_digits(num_wanted);
    }
    else if(!strcmp(first_switch,"all"))type+=8;
    else { printf("switch kharab\n"); return 0; }
    }
    //printf("before func\n");
    int a=replace(first_string,address,type,num_wanted,second_string);
    if(a){
        printf("its done !\n");
        save_in_history(address,saver);
        return 0;
    }
    else{
        //printf("there is no occurence");
        return 0;
    }
}
char* input_grep(char** command)
{
    int type=0;
            int flag=0;
            if(!(check_input(" ",1,command))) return 0;
            if(**command=='-'&&*(*command+1)=='c'){ type=1;(*command)+=3;}
            else if(**command=='-'&&*((*command)+1)=='l') {type=2;(*command)+=3;}
            else if(**command=='-'&&*((*command+1))=='-') {type=0;}
            else {printf("wrong input\n"); return 0;}
            //printf("yyyyy");
            if(!(check_input("--str ",6,command)))  return 0;
            char* target=read_content(command,0);
            //printf(".... %s\n",target);
            if(!(check_input("--files ",8,command)))return 0;
            char* addresses[100];
            int number_of_files=0;
            while((**command)!='\0')
            {
                addresses[number_of_files]=give_me_me_the_address_bastard2(command);
                number_of_files++;
                if(*((*command)+1)==' '||*((*command)+1)=='\n'){
                    printf("voroodi eshtebah\n");
                    flag=1;break;
                }
            }
            if(flag) return 0;
            char * ans=grep(target,addresses,type,number_of_files);
            return ans;
}
char* input_compare(char** command)
{
    if(!(check_input(" ",1,command))) return 0;
    char *first_address=give_me_me_the_address_bastard2(command);
    if(!exists(first_address)){printf("\naddress kharab\n");return 0;}
    //if(!(check_input("",1,command))) return 0;
    char *second_address=give_me_me_the_address_bastard(command);
    if(!exists(second_address)){printf("\naddress kharab\n");return 0;}
    char* ans=compare(first_address,second_address);
    return ans;
}
char* input_tree(char**command)
{
    //printf("here  $%s$\n",*command);
    if(!(check_input(" ",1,command)))return 0;
    //printf("here\n");
    int depth;
    sscanf(*command,"%d",&depth);
    (*command)+=number_of_digits(depth);
    if((**command)!='\0'){printf("voroodi bad\n");return 0;}
    char *ans=starter(100000);
    tree("root",0,depth,ans);
    return ans;
}
int main()
{
    char* clipboard=starter(8000);
    char* command=(char*)malloc(sizeof(char)*500);
    char* backup_command=(char*)malloc(sizeof(char)*500);
    while(1)
    {
        gets(command);
        strcpy(backup_command,command);
        if(strstr(command," =D ")!=NULL)
        {
            int t=strlen(command);
            char* first_command=starter(500);
            char* second_command=starter(500);
            second_command=strstr(command," =D ");
            int u=strlen(second_command);
            second_command+=4;
            strcpy(first_command,command);
            int i=0;
            //printf("%d %d\n",t,u);
            while(first_command[i]!='\0')
            {
                if(i>=t-u)
                first_command[i]='\0';
                i++;
            }
            //printf("%s\n%s\n",first_command,second_command);
            char* type1=sgetword(&first_command);
            //printf("type1: %s\n",type1);
            char* output;
            if(0==strcmp(type1,"cat")){output=input_cat(&first_command);}
            else if(0==strcmp(type1,"find")){output=input_find(&first_command);}
            else if(0==strcmp(type1,"grep")){output=input_grep(&first_command);}
            else if(0==strcmp(type1,"compare")){output=input_compare(&first_command);}
            else if(0==strcmp(type1,"tree")){output=input_tree(&first_command);}
            else{printf("invalid command of arman type\n");continue;}
            //printf("%s",output);
            char*type2=sgetword(&second_command);
            strcpy(command,second_command);
            if(0==strcmp(type2,"insertstr"))
            {
                if(!(check_input(" --file /",9,&command))) continue;
                char* address=give_me_me_the_address_bastard(&command);
                //printf("%s\n",address);
                if(!exists(address)) {printf("\naddress kharab\n");  continue;}
                char* saver=save_file(address);
                if(!(check_input("-pos ",5,&command)))continue;
                int line_number,start_position;
                sscanf(command,"%d",&line_number);
                command+=number_of_digits(line_number);
                if(!(check_input(":",1,&command)))continue;

                sscanf(command,"%d",&start_position);
                command+=number_of_digits(start_position);
                int a=insert_in_file(line_number,start_position,address,output);
                if(a)
                save_in_history(address,saver);
                continue;
                }
            else if(0==strcmp(type2,"find"))
            {
                int num_wanted=0;
            if(!(check_input(" --file /",9,&command)))continue;
            int type=0;
            char *address=give_me_me_the_address_bastard(&command);
            if(!(exists(address)))  {printf("\naddress kharab\n");  continue;}
            //printf("%s\n",address);
            char* first_switch=sgetword(&command);
            if(first_switch[0]!='\0'){
                if(!strcmp(first_switch,"count")) type+=1;
                else if(!strcmp(first_switch,"at")){
                    type+=2;
                    if(!(check_input(" ",1,&command))) continue;
                    sscanf(command,"%d",&num_wanted);
                    command+=number_of_digits(num_wanted);
                }
                else if(!strcmp(first_switch,"byword"))type+=4;
                else if(!strcmp(first_switch,"all"))type+=8;
                else { printf("switch kharab\n"); continue; }
                if(!(check_input(" ",1,&command))) continue;
                char* second_switch=sgetword(&command);
                if(second_switch[0]!='\0'){
                    if(!strcmp(second_switch,"-at")){
                    type+=2;
                    if(!(check_input(" ",1,&command))) continue;
                    sscanf(command,"%d",&num_wanted);
                    command+=number_of_digits(num_wanted);
                    if(!(check_input(" ",1,&command))) continue;
                    }
                    else if(!strcmp(second_switch,"-byword"))type+=4;
                    else if(!strcmp(second_switch,"-all"))type+=8;
                    else { printf("switch kharab\n"); continue; }
                }
                //printf("%s\n",second_switch);
                command++;
                if(sgetchar(&command)!='\0') { printf("switch kharabz\n"); continue; }
            }
            char *ans=find(output,address,type,num_wanted);
            printf("%s",ans);
            continue;
            } 
            else if(0==strcmp(type2,"replace"))
            {
                if(!(check_input(" --str1 ",8,&command))) continue;
                char *first_string=read_content(&command,1);

                if(!(check_input("--file /",8,&command))) continue;
                char* address=give_me_me_the_address_bastard(&command);
                if(!exists(address))  {printf("\naddress kharab\n");continue;}
                int type=0,num_wanted=1;
                char* saver=save_file(address);
                char* first_switch=sgetword(&command);
                if(first_switch[0]!='\0'){
                if(!strcmp(first_switch,"at")){
                    type+=2;
                    if(!(check_input(" ",1,&command))) continue;
                    sscanf(command,"%d",&num_wanted);
                    command+=number_of_digits(num_wanted);
                }
                else if(!strcmp(first_switch,"all"))type+=8;
                else { printf("switch kharab\n"); continue; }
                }
                //printf("before func\n");
                int a=replace(first_string,address,type,num_wanted,output);
                if(a){
                    printf("its done !\n");
                    save_in_history(address,saver);
                    continue;
                }
                else{
                    printf("there is no occurence");
                    continue;
                }
            }
            else if(0==strcmp(type2,"grep"))
            {
                int type=0;
                int flag=0;
                if(!(check_input(" ",1,&command))) continue;
                if(*command=='-'&&*(command+1)=='c'){ type=1;command+=3;}
                else if(*command=='-'&&*(command+1)=='l') {type=2;command+=3;}
                else if(*command=='-'&&*(command+1)=='-') {type=0;}
                else {printf("wrong input\n"); continue;}
                //printf("yyyyy");
                //printf(".... %s\n",target);
                if(!(check_input("--files ",8,&command)))continue;
                char* addresses[100];
                int number_of_files=0;
                while((*command)!='\0')
                {
                    addresses[number_of_files]=give_me_me_the_address_bastard2(&command);
                    number_of_files++;
                    if(*(command+1)==' '||*(command+1)=='\n'){
                        printf("voroodi eshtebah\n");
                        flag=1;break;
                    }
                }
                if(flag)continue;
                //printf("before\n");
                char * ans=grep(output,addresses,type,number_of_files);
                printf("%s",ans);
                continue;
            }
            else{printf("invalide command of second part of arman\n");continue;}
            continue;
        }
        char* type_command=sgetword(&command);
        //printf("%s\n%s",command,type_command);
        if(0==strcmp(type_command,"createfile"))
        {
            //printf("salam");
            if(!(check_input(" --file /",9,&command))) continue;
            //printf("=============%s\n",command);
            char *address=give_me_me_the_address_bastard(&command);
            //printf("%s\n",address);
            create_file(address);
            continue;
        }
        else if(0==strcmp(type_command,"insertstr"))
        {
            if(!(check_input(" --file /",9,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            //printf("%s\n",address);
            if(!exists(address)) {printf("\naddress kharab\n");  continue;}
            char* saver=save_file(address);
            if(!(check_input("-str ",5,&command)))continue;
            char* content=read_content(&command,0);
            //printf("%s\n",content);
            if(!(check_input("--pos ",6,&command)))continue;
            int line_number,start_position;
            sscanf(command,"%d",&line_number);
            command+=number_of_digits(line_number);
            if(!(check_input(":",1,&command)))continue;

            sscanf(command,"%d",&start_position);
            command+=number_of_digits(start_position);
            int a=insert_in_file(line_number,start_position,address,content);
            if(a)
            save_in_history(address,saver);
            continue;
        }
        else if(0==strcmp(type_command,"cat"))
        {
            if(!(check_input(" --file /",9,&command)))continue;
            char *address=give_me_me_the_address_bastard(&command);
            if(!(exists(address)))  {printf("\naddress kharab\n");continue;}
            char* ans=save_file(address);
            printf("%s\n",ans);continue;
        }
        else if(0==strcmp(type_command,"removestr"))
        {
            if(!(check_input(" --file /",9,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            //printf("%s\n",address);
            if(!exists(address)) {printf("\naddress kharab\n");  continue;}
            char* saver=save_file(address);
            if(!(check_input("-pos ",5,&command)))continue;
            int line_number,start_position,size;
            sscanf(command,"%d",&line_number);
            command+=number_of_digits(line_number);
            //printf("[[[size]]]");
            if(!(check_input(":",1,&command)))continue;
            sscanf(command,"%d",&start_position);
            //printf("[[[size]]]");
            command+=number_of_digits(start_position);
            if(!(check_input(" -size ",7,&command)))continue;
            sscanf(command,"%d",&size);
            //printf("[[[size]]]");
            command+=number_of_digits(size);
            if(!(check_input(" -",2,&command)))continue;
            char direction=sgetchar(&command);

            int a=remove_from_file(line_number,start_position,address,size,direction);
            if(a)
            save_in_history(address,saver);
            continue;
        }
        else if(0==strcmp(type_command,"copystr"))
        {
            if(!(check_input(" --file /",9,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            //printf("%s\n",address);
            if(!exists(address)) {printf("\naddress kharab\n");  continue;}
            char* saver=save_file(address);
            if(!(check_input("-pos ",5,&command)))continue;
            int line_number,start_position,size;
            sscanf(command,"%d",&line_number);
            command+=number_of_digits(line_number);
            //printf("[[[size]]]");
            if(!(check_input(":",1,&command)))continue;
            sscanf(command,"%d",&start_position);
            //printf("[[[size]]]");
            command+=number_of_digits(start_position);
            if(!(check_input(" -size ",7,&command)))continue;
            sscanf(command,"%d",&size);
            //printf("[[[size]]]");
            command+=number_of_digits(size);
            if(!(check_input(" -",2,&command)))continue;
            char direction=sgetchar(&command);
            int a=copy_from_file(line_number,start_position,address,size,direction,clipboard);
            continue;
        }
        else if(0==strcmp(type_command,"cutstr"))
        {
            if(!(check_input(" --file /",9,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            //printf("%s\n",address);
            if(!exists(address)) {printf("\naddress kharab\n");  continue;}
            char* saver=save_file(address);
            if(!(check_input("-pos ",5,&command)))continue;
            int line_number,start_position,size;
            sscanf(command,"%d",&line_number);
            command+=number_of_digits(line_number);
            //printf("[[[size]]]");
            if(!(check_input(":",1,&command)))continue;
            sscanf(command,"%d",&start_position);
            //printf("[[[size]]]");
            command+=number_of_digits(start_position);
            if(!(check_input(" -size ",7,&command)))continue;
            sscanf(command,"%d",&size);
            //printf("[[[size]]]");
            command+=number_of_digits(size);
            if(!(check_input(" -",2,&command)))continue;
            char direction=sgetchar(&command);
            int a=cut_from_file(line_number,start_position,address,size,direction,clipboard);
            if(a)
            save_in_history(address,saver);
            continue;
        }
        else if(0==strcmp(type_command,"pastestr"))
        {
            if(!(check_input(" --file /",9,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            printf("%s\n",address);
            if(!exists(address)) {printf("\naddress kharab\n");  continue;}
            char* saver=save_file(address);
             if(!(check_input("-pos ",5,&command)))continue;

            int line_number,start_position;
            sscanf(command,"%d",&line_number);
            command+=number_of_digits(line_number);

            if(!(check_input(":",1,&command)))continue;

            sscanf(command,"%d",&start_position);
            command+=number_of_digits(start_position);
            int a=paste_to_file(line_number,start_position,address,clipboard);
            if(a)
            save_in_history(address,saver);
            continue;
        }
        else if(0==strcmp(type_command,"find"))
        {
            //printf("its in find\n");
            int num_wanted=0;
            if(!(check_input(" --str ",7,&command))) continue;
            char* target=read_content(&command,1);
            //printf("its target : %s\n",target);
            if(!(check_input("--file /",8,&command)))continue;
            int type=0;
            char *address=give_me_me_the_address_bastard(&command);
            if(!(exists(address)))  {printf("\naddress kharab\n");  continue;}
            //printf("%s\n",address);
            char* first_switch=sgetword(&command);
            if(first_switch[0]!='\0'){
                if(!strcmp(first_switch,"count")) type+=1;
                else if(!strcmp(first_switch,"at")){
                    type+=2;
                    if(!(check_input(" ",1,&command))) continue;
                    sscanf(command,"%d",&num_wanted);
                    command+=number_of_digits(num_wanted);
                }
                else if(!strcmp(first_switch,"byword"))type+=4;
                else if(!strcmp(first_switch,"all"))type+=8;
                else { printf("switch kharab\n"); continue; }
                if(!(check_input(" ",1,&command))) continue;
                char* second_switch=sgetword(&command);
                if(second_switch[0]!='\0'){
                    if(!strcmp(second_switch,"-at")){
                    type+=2;
                    if(!(check_input(" ",1,&command))) continue;
                    sscanf(command,"%d",&num_wanted);
                    command+=number_of_digits(num_wanted);
                    if(!(check_input(" ",1,&command))) continue;
                    }
                    else if(!strcmp(second_switch,"-byword"))type+=4;
                    else if(!strcmp(second_switch,"-all"))type+=8;
                    else { printf("switch kharab\n"); continue; }
                }
                //printf("%s\n",second_switch);
                command++;
                if(sgetchar(&command)!='\0') { printf("switch kharabz\n"); continue; }
            }
            char *ans=find(target,address,type,num_wanted);
            printf("%s",ans);
            continue;
        }
        else if(0==strcmp(type_command,"replace"))
        {
            //printf("in the main\n");
            if(!(check_input(" --str1 ",8,&command))) continue;
            char *first_string=read_content(&command,1);
            if(!(check_input("--str2 ",7,&command))) continue;
            char* second_string=read_content(&command,1);
            if(!(check_input("--file /",8,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            if(!exists(address))  {printf("\naddress kharab\n");continue;}
            int type=0,num_wanted=1;
            char* saver=save_file(address);
            char* first_switch=sgetword(&command);
            if(first_switch[0]!='\0'){
            if(!strcmp(first_switch,"at")){
                type+=2;
                if(!(check_input(" ",1,&command))) continue;
                sscanf(command,"%d",&num_wanted);
                command+=number_of_digits(num_wanted);
            }
            else if(!strcmp(first_switch,"all"))type+=8;
            else { printf("switch kharab\n"); continue; }
            }
            //printf("before func\n");
            int a=replace(first_string,address,type,num_wanted,second_string);
            if(a){
                printf("its done !\n");
                save_in_history(address,saver);
                continue;
            }
            else{
                printf("there is no occurence");
                continue;
            }
        }
        else if(0==strcmp(type_command,"grep"))
        {
            int type=0;
            int flag=0;
            if(!(check_input(" ",1,&command))) continue;
            if(*command=='-'&&*(command+1)=='c'){ type=1;command+=3;}
            else if(*command=='-'&&*(command+1)=='l') {type=2;command+=3;}
            else if(*command=='-'&&*(command+1)=='-') {type=0;}
            else {printf("wrong input\n"); continue;}
            //printf("yyyyy");
            if(!(check_input("--str ",6,&command)))  continue;
            char* target=read_content(&command,0);
            //printf(".... %s\n",target);
            if(!(check_input("--files ",8,&command)))continue;
            char* addresses[100];
            int number_of_files=0;
            while((*command)!='\0')
            {
                addresses[number_of_files]=give_me_me_the_address_bastard2(&command);
                number_of_files++;
                if(*(command+1)==' '||*(command+1)=='\n'){
                    printf("voroodi eshtebah\n");
                    flag=1;break;
                }
            }
            if(flag)continue;
            //printf("before\n");
            char * ans=grep(target,addresses,type,number_of_files);
            printf("%s",ans);
            continue;
        }
        else if(0==strcmp(type_command,"undo"))
        {
            if(!(check_input(" --file /",9,&command)))continue;
            char *address=give_me_me_the_address_bastard(&command);
            if(!(exists(address))) {printf("\naddress kharab\n");continue;}
            char* saver=save_file(address);

            FILE* file;
            int andis=-1;
            for(int i=0;i<shit_counter;i++)
            {
                if(!strcmp(all_history[i].file_address,address))
                andis=i;
            }
            if(andis==-1){
                printf("no changes yet\n");continue;
                //save_in_history(address,saver);
            }
            //printf(">>>> %s\n",all_history[andis].file_address);
            //printf(">>>> %s\n",all_history[andis].last_content);
            file=fopen(address,"w");
            fputs(all_history[andis].last_content,file);
            fclose(file);
            //////////////////////////////////////////////////////////////////////////////////////////////////
                all_history[andis].last_content=saver;
            //////////////////////////////////////////////////////////////////////////////////////////////////
            continue;
        }
        else if(0==strcmp(type_command,"auto_indent"))
        {
            if(!(check_input(" /",2,&command))) continue;
            char* address=give_me_me_the_address_bastard(&command);
            if(!exists(address)){printf("\naddress kharab\n");continue;}
            ///////////////////////////////////////////////////////////////
            char* saver=save_file(address);
            //printf("%s\n",saver);
            int pos_in_saver=0;
            int pos_in_result=0;
            int indent=0;
            char last_char=0;
            char* result=starter(10000);
            while(saver[pos_in_saver]!='\0')
            {
				//printf(" %c(result:%d) ",saver[pos_in_saver],pos_in_result);
                if(saver[pos_in_saver]=='{')
                {
					if(pos_in_result==0)
					{
						result[pos_in_result]='{';
						pos_in_result++;
					}
					else{
						pos_in_result--;
						while(pos_in_result>0&&(result[pos_in_result]==' '||result[pos_in_result]=='\t'))
                    	{
                        	result[pos_in_result]='\0';///can make some problems in  case of pos==0;
                        	pos_in_result--;
                    	}
						if(pos_in_result==0||result[pos_in_result]=='\n')
                    	{
							pos_in_result++;
							for(int i=0;i<indent;i++)
                    		{
                        		result[pos_in_result]='\t';
                        		pos_in_result++;
                    		}
							result[pos_in_result]='{';
							pos_in_result++;
						}
						else
						{
							pos_in_result++;
							for(int i=0;i<indent;i++)
                    		{
                        		result[pos_in_result]='\t';
                        		pos_in_result++;
                    		}
							result[pos_in_result]=' ';
							pos_in_result++;
							result[pos_in_result]='{';
							pos_in_result++;
						}
					}
					indent++;
                    pos_in_saver++;
					int buff_counter=0;
					while(saver[pos_in_saver]==' '||saver[pos_in_saver]=='\t')
					{
						pos_in_saver++;
					}
                    if(saver[pos_in_saver]!='\n')
                    {
                        result[pos_in_result]='\n';
                        pos_in_result++;
                    }
                    else
                    {
                        //pos_in_saver++;
                        while(saver[pos_in_saver]=='\n')
                        {
                            result[pos_in_result]='\n';
                            pos_in_result++;
                            pos_in_saver++;
                        }
                    }
                    while(saver[pos_in_saver]==' '||saver[pos_in_saver]=='\t')
                    pos_in_saver++;
                    for(int i=0;i<indent;i++)
                    {
                        result[pos_in_result]='\t';
                        pos_in_result++;
                    }
                }
                else if(saver[pos_in_saver]=='}')
                {
                    indent--;
                    pos_in_saver++;
                    pos_in_result--;
                    while(pos_in_result>0&&(result[pos_in_result]==' '||result[pos_in_result]=='\t'))
                    {
                        result[pos_in_result]='\0';///can make some problems in  case of pos==0;
                        pos_in_result--;
                    }
                    if(result[pos_in_result]!='\n')
                    {
                        pos_in_result++;
                        result[pos_in_result]='\n';
                    }
					pos_in_result++;
                    for(int i=0;i<indent;i++)
                    {
                        result[pos_in_result]='\t';
                        pos_in_result++;
                    }
                    result[pos_in_result]='}';
					pos_in_result++;
                    if(saver[pos_in_saver]!='\n')
                    {
						result[pos_in_result]='\n';
						pos_in_result++;
					}
					else
					{
                    	while(saver[pos_in_saver]=='\n')
                    	{
                        	result[pos_in_result]='\n';
							pos_in_result++;
                        	pos_in_saver++;
                    	}
					}
                    while(saver[pos_in_saver]==' '||saver[pos_in_saver]=='\t')
                    pos_in_saver++;
                    for(int i=0;i<indent;i++)
                    {
                        result[pos_in_result]='\t';
                        pos_in_result++;
                    }
                }
                else if(saver[pos_in_saver]=='\n')
                {
                    while(saver[pos_in_saver]=='\n')
                    {
                        result[pos_in_result]='\n';
						//printf("\nits me saving %c(%d)\n",result[pos_in_result],pos_in_result);
						pos_in_result++;
                        pos_in_saver++;
                    }
                    while(saver[pos_in_saver]==' '||saver[pos_in_saver]=='\t')
                    pos_in_saver++;
                    for(int i=0;i<indent;i++)
                    {
                        result[pos_in_result]='\t';
						//printf("\nits me saving %c(%d)\n",result[pos_in_result],pos_in_result);
                        pos_in_result++;
                    }
					continue;
                }
                else
                {
                    result[pos_in_result]=saver[pos_in_saver];
					//printf("\nits me saving %c(%d)\n",result[pos_in_result],pos_in_result);
                    pos_in_saver++;
                    pos_in_result++;
                }
				//////////////////////////////////////////////////////////////////////////////////////////////////
                save_in_history(address,saver);
                //////////////////////////////////////////////////////////////////////////////////////////////////
				FILE* file;
                file=fopen(address,"w");
				fputs(result,file);
				fclose(file);
				continue;

            }
            printf("\n==============\n%s\n",result);
            continue;
        }
        else if(0==strcmp(type_command,"compare"))
        {
            if(!(check_input(" ",1,&command))) continue;
            char *first_address=give_me_me_the_address_bastard2(&command);
            if(!exists(first_address)){printf("\naddress kharab\n");continue;}
            //if(!(check_input("/",1,&command))) continue;
			char *second_address=give_me_me_the_address_bastard(&command);
            if(!exists(second_address)){printf("\naddress kharab\n");continue;}
            char* ans=compare(first_address,second_address);
            printf("%s",ans);
        }
        else if(0==strcmp(type_command,"tree"))
        {
            if(!(check_input(" ",1,&command)))continue;
            int depth;
            sscanf(command,"%d",&depth);
            command+=number_of_digits(depth);
            if(*command!='\0'){printf("voroodi bad\n");continue;}
            char *ans=starter(100000);
            tree(".",0,depth,ans);
            printf("%s",ans);
            continue;
        }
        else if(0==strcmp(type_command,"end"))
        {
            printf("finished\n");
            break;
        }
        else{
            printf("invalid input\n");
        }
        // if(0==strcmp(type_command,"find2"))
        // {
        //     char*a=input_find(&command);
        //     printf("%s",a);
        // }
        // if(0==strcmp(type_command,"grep2"))
        // {
        //     char* a=input_grep(&command);
        //     printf("%s",a);
        // }
        // if(0==strcmp(type_command,"compare2"))
        // {
        //     char* ans=input_compare(&command);
        //     printf("%s",ans);
        // }
        // if(0==strcmp(type_command,"tree2"))
        // {
        //     char *ans=input_tree(&command);
        //     printf("%s",ans);
        // }
    }
}