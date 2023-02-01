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
    int andis=0;
    for(int i=0;i<shit_counter;i++)
    {
        if(!strcmp(all_history[i].file_address,address))
        andis=i;
    }
    all_history[andis].last_content=content_to_save;
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
                printf("%s:",addresses[i]);
                khat_k_chap_kon(content_of_file[i],lines_occurences[s]);
                printf("\n");
                s++;
            }
        }
        return;
    }
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
        if(0==strcmp(type_command,"insertstr"))
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
        if(0==strcmp(type_command,"cat"))
        {
            if(!(check_input(" --file /",9,&command)))continue;
            char *address=give_me_me_the_address_bastard(&command);
            if(!(exists(address)))  {printf("\naddress kharab\n");continue;}
            char* ans=save_file(address);
            printf("%s\n",ans);continue;
        }
        if(0==strcmp(type_command,"removestr"))
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
        if(0==strcmp(type_command,"copystr"))
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
        if(0==strcmp(type_command,"cutstr"))
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
        if(0==strcmp(type_command,"pastestr"))
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
        if(0==strcmp(type_command,"find"))
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
        if(0==strcmp(type_command,"replace"))
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
                //printf("there is no occurence");
                continue;
            }
        }
        if(0==strcmp(type_command,"grep"))
        {
            
        }
    }
}