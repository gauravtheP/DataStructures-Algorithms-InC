#include<stdio.h>
int movement(int, char, char, char);
void main(){
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    printf("Disks are displayed as alphabets, topmost will be 'a' followed by 'b' and so on.\n");
    printf("\n");
    printf("Total Number of movements = %d",movement(disks, 'x', 'y', 'z'));
}
int movement(int disks, char tower1, char tower2, char tower3){
    static int count = 0;
    if(disks>=1){
        movement(disks-1, tower1, tower3, tower2);
        printf("Disks %c moved from tower%c to tower%c\n", disks+96, tower1-71, tower2-71); 
        ++count;
        movement(disks-1, tower3, tower2, tower1);
    }
    return count;
}