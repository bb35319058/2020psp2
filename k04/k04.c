#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data{
    int ID;
    int height;
    int gender;
};

int N = 1;
int list = 0;

int main(void){
    int i;
    int val_1;
    int val_2;
    int val_3;
    int search_data;
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
    struct data heights_data[100];

printf("input the filename of sample_ID:");
fgets(fname, sizeof(fname), stdin);
fname[strlen(fname)-1]='\0';
fp = fopen(fname, "r");
if(fp==NULL){
    fputs("File open error\n", stderr);
    exit(EXIT_FAILURE);
}

while(fgets(buf, sizeof(buf), fp) != NULL){
    sscanf(buf, "%d", &val_1);
    heights_data[N].ID = val_1;
    N = N + 1;
}

printf("input the filename of sample_heights:");
fgets(fname, sizeof(fname), stdin);
fname[strlen(fname)-1]='\0';
fp = fopen(fname, "r");
if(fp==NULL){
    fputs("File open error\n", stderr);
    exit(EXIT_FAILURE);
}

while(fgets(buf, sizeof(buf), fp) != NULL){
    sscanf(buf, "%d, %d", &val_2, &val_3);
    heights_data[N].height = val_2;
    heights_data[N].gender = val_3;
    N = N + 1;
}

printf("Which ID's data do you want?:");
scanf("%d", &search_data);

for(i=1; i<=N; i++){
    if(search_data == heights_data[i].ID){
        printf("ID:%d\n", heights_data[i].ID);
    }

    printf("height:%d\n", heights_data[i].height);

    if(heights_data[i].gender ==1){
        printf("gender:male\n");
    }

    else if(heights_data[i].gender == 2){
        printf("gender:female\n");
    }

    list =1;
}

if(list == 0){
    printf("no data\n");
}

return 0;
}