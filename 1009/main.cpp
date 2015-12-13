/**
 * Enigma decrypt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define DEBUG

int m = 0;
int rotor[3][26] = {0};
int steps[3] = {0};

int main() {
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    char map[27] = {0};
    int cases = 1;
    while (scanf("%d", &m) && m > 0) {
        if (cases > 1) printf("\n");

        steps[0] = 1, steps[1] = m, steps[2] = m * m;
        for (int i = 0; i < 3; ++i) {
            bzero(map, sizeof(map));
            scanf("%s", map);
            for (int j = 0; j < m; j++) {
                // rotor is reversed
                rotor[i][ map[j] - 'A' ] = ('A' + j) - map[j];
            }
        }

        printf("Enigma %d:\n", cases);

        int n = 0;
        scanf("%d", &n);
        while (n-- > 0) {
            char text[10240] = {0};
            scanf("%s", text);
            int len = strlen(text);
            for (int i = 0; i < len; ++i) {
                int ch = text[i] - 'A';
                for (int j = 2; j >= 0; --j) {
                    int offset = (ch - i / steps[j] + m) % m;
                    ch = (ch + rotor[j][offset] + m) % m;
                }    
                text[i] = ch + 'a';
            }
            printf("%s\n", text);
        }

        cases ++;
    }
    return 0;
}
