// a simple interpreter for brainf*ck using brainf.h
#include "brainf.h"
#include <unistd.h>
#include <ctype.h>

void print_help(void) {
    printf("BrainF*ck Interpreter Options:\n-s <input>: interpret a string of brainf*ck code\n-f <file>: interpret a file of brainf*ck code\n");
}

char* read_file(char* file) {
    char* buffer;
    long length;
    FILE* f = fopen(file, "rb");
    if(f) {
        fseek(f, 0, SEEK_END);
        length = ftell(f);
        fseek(f, 0, SEEK_SET);
        buffer = malloc(length + 1);
        if(buffer) fread(buffer, 1, length, f);
        else return NULL;
        buffer[length] = 0;
        fclose(f);
        return buffer;
    }
    return NULL;
}

int main(int argc, char** argv) {
    char* string = NULL;
    char* file = NULL;

    int c;
    opterr = 0;
    while((c = getopt(argc, argv, "s:f:h")) != -1) {
        switch(c) {
            case 's':
                string = optarg;
                break;
            case 'f':
                file = optarg;
                break;
            case 'h':
                print_help();
                return 1;
            case '?':
                if(optopt == 's' || optopt == 'f') fprintf(stderr, "Option -%c requires an argument, exiting...\n", optopt);
                else if(isprint(optopt)) fprintf(stderr, "Unknown option `-%c', exiting...\n", optopt);
                else fprintf(stderr,"Unknown option character `\\x%x', exiting...\n", optopt);
                return 1;
            default:
                abort();
        }
    }

    char* brainf = NULL;
    if(string != NULL) brainf = string;
    else if(file != NULL) { // read file
        brainf = read_file(file);
        if(brainf == NULL) {
            fprintf(stderr, "Failed to read file!\n");
            return 1;
        }
    }
    if(brainf != NULL) BRAINF(brainf);
    if(file != NULL) free(brainf);

    return 1;
}