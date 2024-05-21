#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// ������ͳ���ַ���
int count_characters(FILE *file) {
    int count = 0;
    char ch;
    // ���ַ���ȡ�ļ���ֱ���ļ�����
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

// ������ͳ�Ƶ�����
int count_words(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    char *word;
    
    // ���ж�ȡ�ļ�
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        // ʹ�� strtok �������տո񡢶��š��Ʊ�����з��ָ��
        word = strtok(buffer, " ,\t\n");
        while (word != NULL) {
            count++; // ͳ�Ƶ�����
            word = strtok(NULL, " ,\t\n");
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    // ��������в�������
    if (argc != 3) {
        printf("Usage: %s [-c or -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1]; // ѡ�����
    char *filename = argv[2]; // �ļ�������
    FILE *file = fopen(filename, "r"); // ���ļ�
    
    // ����ļ��Ƿ�ɹ���
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    int count = 0;
    // ����ѡ�������Ӧ�ļ�����������������
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file); // ͳ���ַ���
        printf("�ַ�����%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file); // ͳ�Ƶ�����
        printf("��������%d\n", count);
    } else {
        printf("Error: Invalid option %s. Please use -c or -w\n", option);
        return 1;
    }

    fclose(file); // �ر��ļ�
    return 0;
}

