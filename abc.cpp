#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fpr, *fpw;
    int w, h, i, j;
    char str_temp[100];
    char chsfname[50], chsn_fname[50];
    unsigned char **chsimg_in, **chsimg_ou;

    printf("���� ������ �̸�: ");
    scanf("%s", chsfname);
    printf("���纻 ������ �̸�: ");
    scanf("%s", chsn_fname);


    fpr = fopen(chsfname, "r");
    if (fpr == NULL) {
        printf("���� ������ ���� ���߽��ϴ�.\n");
        exit(1);
    }
    fpw = fopen(chsn_fname, "w");
    if (fpw == NULL) {
        printf("���纻 ������ ���� ���߽��ϴ�.\n");
        exit(1);
    }


    fgets(str_temp, 100, fpr);
    fputs(str_temp, fpw);

    fgets(str_temp, 100, fpr);
    fputs(str_temp, fpw);

    fscanf(fpr, "%d", &w);
    fscanf(fpr, "%d", &h);
    fprintf(fpw, "%d %d\n", w, h);

    fscanf(fpr, "%d", &i);
    fprintf(fpw, "%d\n", i);


    chsimg_in = (unsigned char **)malloc(h * sizeof(unsigned char *));
    for (i = 0; i < h; i++)
        chsimg_in[i] = (unsigned char *)malloc(w * sizeof(unsigned char));

    chsimg_ou = (unsigned char **)malloc(h * sizeof(unsigned char *));
    for (i = 0; i < h; i++)
        chsimg_ou[i] = (unsigned char *)malloc(w * sizeof(unsigned char));

    if (chsimg_in == NULL || chsimg_ou == NULL) {
        printf("�̹��� �迭�� ���� �޸� �Ҵ��� �����߽��ϴ�.\n");
        exit(1);
    }


    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            fscanf(fpr, "%hhu", &chsimg_in[i][j]);
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            chsimg_ou[i][j] = chsimg_in[i][j];
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++)
            fprintf(fpw, "%d ", chsimg_ou[i][j]);
        fprintf(fpw, "\n");
    }

    fclose(fpr);
    fclose(fpw);

    for (i = 0; i < h; i++)
        free(chsimg_in[i]);
    free(chsimg_in);

    for (i = 0; i < h; i++)
        free(chsimg_ou[i]);
    free(chsimg_ou);

    return 0;
}
