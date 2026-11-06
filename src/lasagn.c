#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int printLineNum() {

}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        char argsFailure[] = "ERROR: At least one argument is required!\n";
        write(1, argsFailure, sizeof(argsFailure));
        return 1;
    }
    
    int isPrintLineNum = 0;
    int fileArgPos = 1;

    if (strcmp(argv[1], "-n") == 0) {
        if (argc < 3) {
            char argsFileFailure[] = "ERROR: File name must be specified!\n";
            write (1, argsFileFailure, sizeof(argsFileFailure));
            return -1;
        }
        isPrintLineNum = 1;
        fileArgPos = 2;
    }

    int file = open(argv[fileArgPos], O_RDONLY);
    if (file == -1) {
        char fileOpenFailure[] = "ERROR: Failed to open the file!\n";
        write(1, fileOpenFailure, sizeof(fileOpenFailure));
        return -1;
    }

    char buffer[4097];
    ssize_t readBytes;
    
    int lineNum = 1;
    int atLineStart = 1;
    while(isPrintLineNum && (readBytes = read(file, buffer, 4096)) > 0) {
        for (ssize_t i = 0; i < readBytes; i++) {
            if (atLineStart) {
                char lineNumBuffer[19];
                int lenLNB = snprintf(lineNumBuffer, sizeof(lineNumBuffer), "%6d | ", lineNum);
                
                if (lenLNB < 0) {
                    char encFailure[] = "ERROR: Encoding failure!";
                    write(1, encFailure, sizeof(encFailure));
                    return -1;
                }

                if (lenLNB >= sizeof(lineNumBuffer)) {
                    char truncFailure[] = "ERROR: Truncation occured!";
                    write(1, truncFailure, sizeof(truncFailure)); 
                    return -1;
                }

                write(1, lineNumBuffer, lenLNB);
                lineNum++;
                atLineStart = 0;
            }

            write(1, &buffer[i], 1);

            if (buffer[i] == '\n') {
                atLineStart = 1;
            }
        }
    }

    while((readBytes = read(file, buffer, 4096)) > 0) {
        buffer[readBytes] = '\0';
        write(1, buffer, readBytes);
    }
    
    if (readBytes == -1) {
        char errorRead[] = "ERROR: Failed to read file!\n";
        write(1, errorRead, sizeof(errorRead));
        return -1;
    }
    
    if (close(file) == -1) {
        char fileCloseFailure[] ="ERROR: Failed to close file properly!"; 
        write(1, fileCloseFailure, sizeof(fileCloseFailure));
        return -1;
    }

    return 0;
}
