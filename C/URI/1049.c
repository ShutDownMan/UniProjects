#include <stdio.h>
#include <string.h>

int main(){
    char se1[12], se2[12], se3[12];

    scanf("%s", se1);
    scanf("%s", se2);
    scanf("%s", se3);

    if(strcmp(se1, "vertebrado") == 0){
        if(strcmp(se2, "ave") == 0){
            if(strcmp(se3, "carnivoro") == 0){
                printf("aguia\n");
            } else {
                printf("pomba\n");
            }
        } else {
            if(strcmp(se3, "onivoro") == 0){
                printf("homem\n");
            } else {
                printf("vaca\n");
            }
        }
    } else {
        if(strcmp(se2, "inseto") == 0){
            if(strcmp(se3, "hematofago") == 0){
                printf("pulga\n");
            } else {
                printf("lagarta\n");
            }
        } else {
            if(strcmp(se3, "hematofago") == 0){
                printf("sanguessuga\n");
            } else {
                printf("minhoca\n");
            }
        }
    }

    return 0;
}