#include <stdio.h>
#include<String.h>
#include<stdbool.h>
//-c �ַ���
//-w ������
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("����%d:%s\n", i, argv[i]);
    }
    //char* str = argv[2];
    //printf("%s",str);

    //��������
    bool f1 = strcmp(argv[1], "-w") == 0;
    bool f2 = strcmp(argv[1], "-c") == 0;
    if (argc == 3 && (f1 || f2)) {
        //printf("����");
        char* path = argv[2];
        /*printf("�ļ�·����%s", path);*/
        FILE* fp;
        errno_t err = fopen_s(&fp, path, "r");
        if (fp == NULL) {
            printf("�ļ�������");
        }
        else {
            printf("\npath:%s\n", path);
            int count;
            //ͳ�Ƶ�����
            if (f1) {
                char c;
                count = 0;
                int a = 0;
                printf("�ļ����ݣ�\n");
                while (!feof(fp)) {
                    c = fgetc(fp);
                    printf("%c", c);
                    if (c == ' ' || c == ',' || c == EOF) {
                        a = 0;
                        continue;
                    }
                    else {
                        if (a == 0) {
                            count++;
                            a = 1;
                        }
                    }
                }
                printf("\n������:%d", count);
            }
            //ͳ���ַ���
            else {
                char c;
                count = 0;
                printf("�ļ����ݣ�\n");
                while (!feof(fp)) {
                    c = fgetc(fp);
                    printf("%c", c);
                    if (c != EOF)
                        count++;
                    fflush(stdin);
                }
                printf("\n�ַ���:%d", count);
            }
            //�ر��ļ�
            fclose(fp);
            fp = NULL;
        }
    }
    else {
        printf("��ʽ��WordCount.exe [ѡ��] TXT�ļ�\n");
        printf("ѡ�\t-c �ַ���\n\t-w ������");
    }
    return 0;
}