#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// ÄæÖÃË³Ðò±í
void ReverseSeqList(SeqList *L) {
    int left = 0;
    int right = L->length - 1;
    while (left < right) {
        int temp = L->data[left];
        L->data[left] = L->data[right];
        L->data[right] = temp;
        left++;
        right--;
    }
}

int main() {
    SeqList L;
    L.length = 5;
    L.data[0] = 1;
    L.data[1] = 2;
    L.data[2] = 3;
    L.data[3] = 4;
    L.data[4] = 5;

    printf("Ô­Ë³Ðò±í£º");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }

    ReverseSeqList(&L);

    printf("\nÄæÖÃºó£º");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    system("pause");
    return 0;
}
