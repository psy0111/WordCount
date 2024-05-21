#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

int count_characters(FILE *file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }
    return count;
}

int count_words(FILE *file) {
    int count = 0;
    char buffer[MAX_BUFFER_SIZE];
    char *word;
    
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        word = strtok(buffer, " ,\t\n");
        while (word != NULL) {
            count++;
            word = strtok(NULL, " ,\t\n");
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [-c or -w] [input_file_name]\n", argv[0]);
        return 1;
    }

    char *option = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 1;
    }

    int count = 0;
    if (strcmp(option, "-c") == 0) {
        count = count_characters(file);
        printf("×Ö·ûÊý£º%d\n", count);
    } else if (strcmp(option, "-w") == 0) {
        count = count_words(file);
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Error: Invalid option %s. Please use -c or -w\n", option);
        return 1;
    }

    fclose(file);
    return 0;
}


