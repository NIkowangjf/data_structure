#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} SeqList;

// ��ֵ�ǵݼ�����˳���
void SortSeqList(SeqList *L) {
    for (int i = 0; i < L->length - 1; i++) {
        for (int j = 0; j < L->length - i - 1; j++) {
            if (L->data[j] > L->data[j + 1]) {
                int temp = L->data[j];
                L->data[j] = L->data[j + 1];
                L->data[j + 1] = temp;
            }
        }
    }
}

int main() {
    SeqList L;
    L.length = 5;
    L.data[0] = 5;
    L.data[1] = 2;
    L.data[2] = 4;
    L.data[3] = 1;
    L.data[4] = 3;

    printf("ԭ˳���");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }

    SortSeqList(&L);

    printf("\n�����");
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    system("pause");
    return 0;
}
