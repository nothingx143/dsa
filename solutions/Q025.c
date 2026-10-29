#include <stdio.h>

char mat[1005][1005];

int main() {
    int p, q;
    scanf("%d %d", &p, &q);
    int top = 0, bottom = p - 1, left = 0, right = q - 1;
    char ch = 'Y';
    while(top<=bottom && right>=left) {
        for (int j = left; j <= right; j++) mat[top][j] = ch;
        top++;
        for (int i = top; i <= bottom; i++) mat[i][right] = ch;
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--) mat[bottom][j] = ch;
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--) mat[i][left] = ch;
            left++;
        }
        ch = (ch == 'Y') ? '0' : 'Y';
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q - 1; j++) printf("%c ", mat[i][j]);
        printf("%c\n", mat[i][q - 1]);
    }
    return 0;
}
