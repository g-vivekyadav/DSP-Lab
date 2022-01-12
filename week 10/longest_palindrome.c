#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isPalindrome(char *s, char *t){
    while(s < t){
        if(*s != *t)
            return 0;
        s++;
        t--;
    }
    return 1;
}
char * longestPalindrome(char * s){
    int i, j, max = 0, l = strlen(s);
    char *ans = (char*)calloc(l+1,sizeof(char));
    if(l == 1)  
		return s;
	else{
    for(i = 0; i < l; i++){
        for(j = l - 1; j > i + max; j--){
            if(s[j] == s[i]){
                if(isPalindrome(s + i, s + j)==1){
                    // Here, j - i must be greater than max (because j > i + max)
                    max = j - i;
                    strncpy(ans, s + i, max + 1);
                }
            }
        }
    }
    if(max == 0){
        strncpy(ans, s, max + 1);
    }
    return ans;
}
}
void main(){
	int choice=0,size;
	while(choice!=2){
		printf("\nEnter the choice 1.Input String 2.Exit\n");
		scanf("%d",&choice);
		if(choice==1){
			printf("Enter the size of the string\n");
			if(scanf("%d",&size)==1){
				char *str=(char*)malloc(sizeof(char)*size);
				printf("Enter the String:\n");
				fflush(stdin);
				gets(str);
				printf("\nThe longest palindromic substring is\n");
				puts(longestPalindrome(str));
			}
			else{
				printf("Invalid size\n");
				exit(0);
			}
		}
		else if(choice==2)
			exit(0);
		else
			printf("Enter the valid choice\n");
	}
}
