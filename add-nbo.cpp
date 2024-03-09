#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>

uint32_t read_nbo(FILE *file) {
    uint32_t num;
    fread(&num, sizeof(uint32_t), 1, file);
    return ntohl(num);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        return 1;
    }

    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");

    uint32_t num1 = read_nbo(file1);
    uint32_t num2 = read_nbo(file2);
    fclose(file1);
    fclose(file2);

    printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", num1, num1, num2, num2, num1 + num2, num1 + num2);

    return 0;
}
