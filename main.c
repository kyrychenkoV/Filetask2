#include <stdio.h>
FILE * inputData(char *name,char *mode);
FILE * addNewFile(char *name,char *mode);
void addIntegersAndRealnumbersTofiles(FILE *myfile,FILE*integer,FILE*floatnumber);
void sumIntegerNumbers(FILE *integer);
void sumFloatNumbers(FILE*floatnumber);
void allFunkc();
int main()
{
    allFunkc();
    return 0;
}
void allFunkc(){
    FILE * myfile ,*integer,*floatnumber;
    myfile=inputData("text.txt","w+");
    floatnumber=addNewFile("floatnumber.txt","w");
    integer=addNewFile("integer.txt","w");
    addIntegersAndRealnumbersTofiles(myfile,integer,floatnumber);
    sumIntegerNumbers(integer);;
    sumFloatNumbers(floatnumber);
}
FILE * inputData(char *name,char *mode){
    FILE *file=fopen(name,mode);
    char *inputdata="25.4 25.4 25.6 23 28 45 1.2 23.3 58 94 25 45 1.2";
    fprintf(file,"%s",inputdata);
    fclose(file);
    return file;
}
FILE * addNewFile(char *name,char *mode){
    FILE *file=fopen(name,mode);
    fclose(file);
    return file;
}
void addIntegersAndRealnumbersTofiles(FILE *myfile,FILE*integer,FILE*floatnumber){
    myfile=fopen("text.txt","r");
    integer=fopen("integer.txt","r+");
    floatnumber=fopen("floatnumber.txt","r+");
    char allwords[20];
    int countallwords=0;
    while(fscanf(myfile,"%s",allwords)!=EOF){
        countallwords++;
        int flag=0;
        int i=0;
        while (allwords[i]!='\0') {
            if ((allwords[i]=='.')){
                flag=1;
            }
            i++;
        }
        if (flag==1){
            fprintf(floatnumber,"%s\n",allwords);
        }
        else{
            fprintf(integer,"%s\n",allwords);
        }
    }
    fclose(integer);
    fclose(floatnumber);
    fclose(myfile);
}
void sumIntegerNumbers(FILE *integer){
    int summ=0,i=0;
    int arrforinteger[10]={0};
    static int count=0;
    integer=fopen("integer.txt","r+");
    i=0;
    while((fscanf(integer, "%d", &arrforinteger[i]))!=EOF){
        i++;
        count++;
    }
    for (i=0;i<count;i++){
        summ+=arrforinteger[i];
    }

    fflush(integer);
    fclose(integer);
}
void sumFloatNumbers(FILE*floatnumber){
    int arrinteger[10]={0};
    int arrafterpoint[10]={0};
    floatnumber=fopen("floatnumber.txt","r+");

    long int pointpozition=ftell(floatnumber);
    printf("Curren position pointer=%ld(byte)\n",pointpozition);

    int i=0;int count1=0;
    while((fscanf(floatnumber, "%d.%d", &arrinteger[i],&arrafterpoint[i]))!=EOF){
        i++;
        count1++;
    }

    pointpozition=ftell(floatnumber);
    printf("Curren position pointer after funkc fscanf=%ld(byte)",pointpozition);

    char *message="integer part=";
    fprintf(floatnumber,"%s",message);
    int summbefor=0;
    int summafter=0;
    for (i=0;i<count1;i++){
        summbefor+=arrinteger[i];
        summafter+=arrafterpoint[i];
        fprintf(floatnumber, "%d ",arrinteger[i]);
    }
    fprintf(floatnumber, "\nSumm befor.=%d,Summ after.=%d", summbefor,summafter);
    fclose(floatnumber);
}