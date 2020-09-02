/**
 * wgrep
 * Created by Talib Pierson on 9/1/20.
 * Wisconsin grep looks through a file, line by line.
 * If a line has the user-specified search term in it, it is printed out.
 */
#include <stdio.h>
#include <string.h>


void wgrep(FILE *in, const char *searchterm) {
    size_t size = 0;
    char *buffer;
    // read (lines can be arbitrarily long)
    while (getline(&buffer, &size, in) >= 0) {
        for (int i = 0; i < (int) strlen(buffer) - (int) strlen(searchterm); ++i) {
            int found = 1;
            for (int j = 0; j < (int) strlen(searchterm); ++j) {
                if (buffer[i + j] != searchterm[j]) {
                    found = 0;
                }
            }
            if (found == 1) {
                // print
                printf("%s", buffer);
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        char *searchterm = argv[1];
        if (argc > 2) {
            for (int i = 2; i < argc; ++i) {
                // open
                FILE *fp = fopen(argv[i], "r");
                if (fp == NULL) {
                    // If wgrep encounters a file that it cannot open
                    // it should print "wgrep: cannot open file\n"
                    printf("wgrep: cannot open file\n");
                    return 1;  // and exit with status 1
                }

                wgrep(fp, searchterm);

                // close
                fclose(fp);
            }
        } else {
            wgrep(stdin, searchterm);
        }
    } else {
        // If wgrep is passed no command-line arguments
        // it should print "wgrep: searchterm [file ...]\n"
        printf("wgrep: searchterm [file ...]\n");
    }
}
