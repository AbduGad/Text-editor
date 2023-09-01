#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>                    /* ncurses.h includes stdio.h */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void PutInFile(char *str) {
    int fp;
    char *output;

    output = malloc(9);  // Increase buffer size to hold null terminator
    if (output == NULL) {
        perror("Malloc failed");
        return;
    }

    fp = open("File", O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);  // Use O_RDWR for read/write access, add mode for file creation
    if (fp < 0) {
        perror("Error opening file");
        free(output);
        return;
    }

    ssize_t bytes_written = write(fp, str, strlen(str));
    if (bytes_written < 0) {
        perror("Error writing to file");
        free(output);
        close(fp);
        return;
    }

    // // off_t offset = lseek(fp, 0, SEEK_SET);  // Move back to the beginning of the file
    // // if (offset == (off_t) -1) {
    // //     perror("Error seeking in file");
    // //     free(output);
    // //     close(fp);
    // //     return;
    // // }

    // ssize_t bytes_read = read(fp, output, 8);
    // if (bytes_read < 0) {
    //     perror("Error reading from file");
    //     free(output);
    //     close(fp);
    //     return;
    // }
    // output[bytes_read] = '\0';  // Null-terminate the string

    // printf("%s\n", output);
    // write(1, output, strlen(output));

    free(output);
    close(fp);
}
int main()
{
	char *str = NULL;
    size_t strsize = 0;

    getline(&str, &strsize, stdin);
	
	PutInFile(str);
	
return 0;
}