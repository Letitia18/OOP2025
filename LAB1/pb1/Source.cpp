#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int my_atoi(const char* str) {
    int result = 0;
    while (*str) {
        if (isdigit(*str)) {
            result = result * 10 + (*str - '0');
        }
        str++;
    }
    return result;
}

int main() {
    FILE* file;
    errno_t err = fopen_s(&file, "ini.txt", "r");
    if (err != 0) {
        printf("Could not open file ini.txt\n");
        return 1;
    }

    char line[256];
    int sum = 0;

    while (fgets(line, sizeof(line), file)) {
        sum += my_atoi(line);
    }
    fclose(file);

    printf("The sum is: %d\n", sum);

    system("pause");

    return 0;
}
