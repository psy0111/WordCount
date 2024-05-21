#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// 函数：统计字符数
int count_characters(FILE *file) {
    int count = 0;
    char ch;
    // 逐字符读取文件，直到文件结束
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// 函数：统计单词数
int count_words(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    char *word;
    
    // 逐行读取文件
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        // 使用 strtok 函数按照空格、逗号、制表符或换行符分割单词
        word = strtok(buffer, " ,\t\n");
        while (word != NULL) {
            count++; // 统计单词数
            word = strtok(NULL, " ,\t\n");
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    // 检查命令行参数数量
    if (argc != 3) {
        printf("Usage: %s [-c or -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // 选项参数
    char *filename = argv[2]; // 文件名参数
    FILE *file = fopen(filename, "r"); // 打开文件
    
    // 检查文件是否成功打开
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    int count = 0;
    // 根据选项调用相应的计数函数，并输出结果
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file); // 统计字符数
        printf("字符数：%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file); // 统计单词数
        printf("单词数：%d\n", count);
    } else {
        printf("Error: Invalid option %s. Please use -c or -w\n", option);
        return 1;
    }

    fclose(file); // 关闭文件
    return 0;
}

