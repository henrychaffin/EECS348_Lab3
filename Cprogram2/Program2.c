#include <stdio.h>
int main() {
    int score;
    do {
    	//USER INPUT
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if (score <= 1) {
        	break;
        }
        //PRINT POSSIBILITIES
        printf("Possible combinations of scoring plays:\n");
        for (int i = 0; i <= (score / 8); i++) {
            for (int j = 0; j <= (score / 7); j++) {
                for (int k = 0; k <= (score / 6); k++) {
                    for (int l = 0; l <= (score / 3); l++) {
                        for (int m = 0; m <= (score / 2); m++) {
                            if (i * 8 + j * 7 + k * 6 + l * 3 + m * 2 == score) {
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", i, j, k, l, m);
                            }
                        }
                    }
                }
            }
        }
    } while (1);
    return 0;
}
