#include <stdio.h>

int main(){
    register double x = 0.000, ret;
    register int i, k;
    for(i = 0; i <= 2000; i++){
        ret = 0;
        for(k = 1; k < 20000; k++){
            ret += (1 - x) / (k*(k+1)*(k+x));
        }
        ret += (1 - x) / (2 * 20000 * 20000);
        printf("%5.3f %16.12f\n", x, ret + 1);
        x += 0.001;
    }
    return 0;
}
