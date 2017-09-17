#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int max(int, int);
void LongestCommonSubSequence(char *, char *, int, int);

int max(int a, int b)
{
	return a > b? a: b;
}
  
void LongestCommonSubSequence(char str1[], char str2[], int len1, int len2){
    int lcs[len1+1][len2+1], i, j;
    for (i = 0; i <= len1; i++){
        for (j = 0; j <= len2; j++){
            if (i == 0 || j == 0){
                lcs[i][j] = 0;
            }
            else if(str1[i-1] == str2[j-1]){
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
            else{
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
    	}
    }
    int a = len1, b = len2;
    char *lcsString = malloc(0);
    int k = 0;
    
    while(a!=0){
        if(str1[a-1]!=str2[b-1]){
            int max = lcs[a-1][b];
            a--;
            if(max < lcs[a+1][b-1]){
                b--;
                a++;
            }
        }
        else{
            k++;
            char c = str1[a-1];
            lcsString = realloc(lcsString, k);
            lcsString[k-1] = c;
            lcsString[k] = '\0';
            a--;
            b--;
        }
    }
    printf("Longest Common Subsequence: ");
    for(i = 0; lcsString[i]!='\0'; i++);
    for(j = i; j>=0; j--){
       printf("%c", lcsString[j]); 
    }
    printf("\nLength of Longest Common Sub sequence = %d\n", lcs[len1][len2]);
}

void main()
{
  char str1[] = "ACBDEA";
  char str2[] = "ABCDA";
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  LongestCommonSubSequence(str1, str2, len1, len2);
}