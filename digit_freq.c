// 123456789
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LEN 1000

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str [MAX_LEN];
    int len = strlen(str);
    int hist [10]={0};
    int num = 0;
    for (int i = 0; i < len; ++i) {
        if(str[i] >= '0' && str[i] <= '9'){
            num = str[i] - '0';
            hist[num]++;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d"
            ,hist[0]
            ,hist[1]
            ,hist[2]
            ,hist[3]
            ,hist[4]
            ,hist[5]
            ,hist[6]
            ,hist[7]
            ,hist[8]
            ,hist[9]
           );
    return 0;
}
