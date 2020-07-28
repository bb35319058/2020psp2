#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data{
    int ID;
    double height;
    int gender;
};

int n = 1;
int list = 0;

int main(void){
    int i;
    int val_1;
    int val_2;
    double val_3;
    int search_data;
    char fname_1[FILENAME_MAX];
    char fname_2[FILENAME_MAX];
    char buf_1[256];
    char buf_2[256];
    FILE* fp_1;
    FILE* fp_2;
    
    struct data heights_data[100];

printf("input the filename of sample_ID:");
fgets(fname_1, sizeof(fname_1), stdin);
fname_1[strlen(fname_1)-1]='\0';
printf("the filename of sample: %s\n", fname_1);

fp_1 = fopen(fname_1, "r");
if(fp_1==NULL){
    fputs("File open error\n", stderr);
    exit(EXIT_FAILURE);
}

while(fgets(buf_1, sizeof(buf_1), fp_1) != NULL){
    sscanf(buf_1, "%d", &val_1);
    heights_data[n].ID = val_1;
    n = n + 1;
}

n = 0;

printf("input the filename of sample_heights:");
fgets(fname_2, sizeof(fname_2), stdin);
fname_2[strlen(fname_2)-1]='\0';
printf("the filename of sample: %s\n", fname_2);

fp_2 = fopen(fname_2, "r");
if(fp_2==NULL){
    fputs("File open error\n", stderr);
    exit(EXIT_FAILURE);
}

while(fgets(buf_2, sizeof(buf_2), fp_2) != NULL){
    sscanf(buf_2, "%d, %lf", &val_2, &val_3);
    heights_data[n].gender = val_2;
    heights_data[n].height = val_3;
    n = n + 1;
}

printf("Which ID's data do you want?:");
scanf("%d", &search_data);

for(i=1; i<=n; i++){
    if(search_data == heights_data[i].ID){
        printf("ID:%d\n", heights_data[i].ID);
    

    printf("height:%.2f\n", heights_data[i].height);

    if(heights_data[i].gender ==1){
        printf("gender:male\n");
    }

    else if(heights_data[i].gender == 2){
        printf("gender:female\n");
    }

    list =1;
    }
}

if(list == 0){
    printf("no data\n");
}

return 0;
}