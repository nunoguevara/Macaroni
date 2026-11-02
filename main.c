#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHOULD_COLOR() (getenv("NO_COLOR") == NULL)

#define GREEN         (SHOULD_COLOR() ? "\033[32m" : "")
#define RED           (SHOULD_COLOR() ? "\033[31m" : "")
#define RESET_COLOR   (SHOULD_COLOR() ? "\033[0m" : "")

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "ERROR: At least one argument is required!\n");
        return 1;
    }

    if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0) {
        printf("Macaroni\n"); 
        printf("A simple and stupid file creation utility for terminal\n");
        printf("Version: v0.1.0\n");
        printf("Copyright (C) 2026 Nuno G. Permana\n");
        printf("Licensed under the MIT License\n");
        return 0;
    }
    
    for (int i = 1; i < argc; i++) {
        FILE *create = fopen(argv[i], "a+");
        if (create == NULL) {
            perror("ERROR: Failed to create file!");
            continue;
        }
        printf("%sFile %s created successfully!%s\n", GREEN, argv[i], RESET_COLOR);
        fclose(create);
    }

    return 0;
}
