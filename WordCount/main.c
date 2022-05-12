#include <stdio.h>
#include<String.h>
#include<stdbool.h>
//-c 字符数
//-w 单词数
int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; i++) {
        printf("参数%d:%s\n", i, argv[i]);
    }
    //char* str = argv[2];
    //printf("%s",str);

    //正常工作
    bool f1 = strcmp(argv[1], "-w") == 0;
    bool f2 = strcmp(argv[1], "-c") == 0;
    if (argc == 3 && (f1 || f2)) {
        //printf("正常");
        char* path = argv[2];
        /*printf("文件路径：%s", path);*/
        FILE* fp;
        errno_t err = fopen_s(&fp, path, "r");
        if (fp == NULL) {
            printf("文件不存在");
        }
        else {
            printf("\npath:%s\n", path);
            int count;
            //统计单词数
            if (f1) {
                char c;
                count = 0;
                int a = 0;
                printf("文件内容：\n");
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
                printf("\n单词数:%d", count);
            }
            //统计字符数
            else {
                char c;
                count = 0;
                printf("文件内容：\n");
                while (!feof(fp)) {
                    c = fgetc(fp);
                    printf("%c", c);
                    if (c != EOF)
                        count++;
                    fflush(stdin);
                }
                printf("\n字符数:%d", count);
            }
            //关闭文件
            fclose(fp);
            fp = NULL;
        }
    }
    else {
        printf("格式：WordCount.exe [选项] TXT文件\n");
        printf("选项：\t-c 字符数\n\t-w 单词数");
    }
    return 0;
}