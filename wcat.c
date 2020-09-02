/**
 * wcat
 * Created by Talib Pierson on 8/31/20.
 * Wisconsin cat reads a file and prints its contents
 */
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    for (int i = 1; i < argc; ++i) {
        // open
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            return 1;
        }

        size_t size = 0;
        char *buffer;
        // read (lines can be arbitrarily long)
        while (getline(&buffer, &size, fp) >= 0) {
            // print
            printf("%s", buffer);
        }

        // close
        fclose(fp);
    }
}
