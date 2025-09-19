#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int maxV(int values[]) {
    int max = values[0];
    size_t n = sizeof(values) / sizeof(values[0]);
    for (size_t i = 0; i < n; i++)
        max = (max < values[i]) ? values[i] : max;
    return max;
}

void drawGistogramme(int values[]) {
    size_t n = sizeof(values) / sizeof(values[0]);
    size_t g_n = n*2;
    size_t max = maxV(values);
    char gistogramme[max][g_n];

    // INITIALIZATION
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < max; j++)
            gistogramme[j][i] = ' ';

    // LOGICS
    size_t n_v = 0;
    size_t i_g = 1;
    while (n_v <= n) {
        for (int j = 0; j < max; j++)
            gistogramme[i_g][j] = '#';
        i_g += 2;
        ++n_v;
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < max; j++) {
            printf("%c ", gistogramme[j][i]);
        }
        printf("\n");
    }
}

int main() {
    int a[3] = { 5, 4, 6, 7 };
    drawGistogramme(a);

    return 0;
}
