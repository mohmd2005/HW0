// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define Max 1000

void func(char* str){
	int arr [10] = {0};
	int len = strlen(str);
	for(int i =0; i < len;i++){
		if(str[i] >= '0' && str[i] <= '9')
			arr[str[i]-'0']++;
	}
	for(int i =0; i < 10;i++){
		printf("%d \n",arr[i]);
	}
}

int main() {
    char str[Max];
    scanf("%s",str);
    func(str);
    return 0;
}
