#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    char surname[50];
    int score[3];
};

int main(){

    struct Student s[10];
    FILE *fp;
    int i,j;
    int total;
    float avg;

    fp = fopen("./lab11/no2/std10.dat","wb");

    if(fp == NULL){
        printf("File error\n");
        exit(1);
    }

    for(i=0;i<10;i++){

        printf("Student %d\n",i+1);

        printf("Name: ");
        scanf("%s",s[i].name);

        printf("Surname: ");
        scanf("%s",s[i].surname);

        for(j=0;j<3;j++){
            printf("Score %d: ",j+1);
            scanf("%d",&s[i].score[j]);
        }

        fwrite(&s[i],sizeof(struct Student),1,fp);
    }

    fclose(fp);

    fp = fopen("./lab11/no2/std10.dat","rb");

    printf("\n----- Result -----\n");

    for(i=0;i<10;i++){

        fread(&s[i],sizeof(struct Student),1,fp);

        total = 0;

        for(j=0;j<3;j++){
            total += s[i].score[j];
        }

        avg = total / 3.0;

        printf("\n%s %s\n",s[i].name,s[i].surname);
        printf("Total = %d\n",total);
        printf("Average = %.2f\n",avg);

        for(j=0;j<3;j++){
            if(s[i].score[j] < 10){
                printf("Exam %d less than 10 : %d\n",j+1,s[i].score[j]);
            }
        }
    }

    fclose(fp);

    return 0;
}
