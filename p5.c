/* CS100 Fall 2026 - HW2 Problem 5: CPU emulator
 *
 * Emulate a toy CPU with registers x0..x5 (16-bit signed, x0 always 0)
 * executing add/sub/mul/div/let/print instructions read as hex words.
 * Do not use <math.h>. Do not rename this file.
 */
#include <stdio.h>
#include <stdint.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1) return 1;

    int16_t x[6] = {0};                  

    for (int k = 0; k < n; k++) {
        unsigned code;
        if (scanf("%x", &code) != 1) break;

        unsigned op  = (code >> 13) & 0x7;  
        unsigned r1  = (code >> 10) & 0x7;
        unsigned r2  = (code >>  7) & 0x7;
        unsigned imm =  code        & 0x7F; 
        switch (op) {
        case 0: if (r1) x[r1] = (int16_t)(x[r1] + x[r2]); break;   
        case 1: if (r1) x[r1] = (int16_t)(x[r1] - x[r2]); break;  
        case 2: if (r1) x[r1] = (int16_t)(x[r1] * x[r2]); break;   
        case 3: if (r1) x[r1] = (int16_t)(x[r1] / x[r2]); break;   
        case 4: if (r1) x[r1] = (int16_t)imm;             break;   
        case 5: printf("x%u = %d\n", r1, x[r1]);          break;  
        }
    }
    return 0;
}
