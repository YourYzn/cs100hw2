/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>
#include <string.h>

static const char*file_desc(const char*name){
    const char *dot = strrchr(name,'.');
    if(dot==NULL)return NULL;
    if(strcmp(dot,".c")==0)return"C source code";
    if(strcmp(dot,".h")==0)return"C/C++ header file";
    if(strcmp(dot,".cpp")==0||strcmp(dot,".C")==0||strcmp(dot,".cc")==0||strcmp(dot,".cxx")==0)return"C++ source code";
    if(strcmp(dot,".hpp")==0||strcmp(dot,".hxx")==0)return"C++ header file";
    return NULL;
}

static void print_std(const char *arg){
    const char *v=arg +5;
    if(strncmp(v,"gnu++",5)==0)
        printf("%s: Set the language standard to GNU dialect of C++%s.\n",arg,v+5);
    else if (strncmp(v, "gnu", 3) == 0)
        printf("%s: Set the language standard to GNU dialect of C%s.\n", arg, v + 3);
    else if (strncmp(v, "c++", 3) == 0)
        printf("%s: Set the language standard to ISO C++%s.\n", arg, v + 3);
    else
        printf("%s: Set the language standard to ISO C%s.\n", arg, v + 1);
}


int main(int argc, char *argv[])
{
    for(int i=1;i<argc;i++){
        const char *arg=argv[i];

        if (strcmp(arg, "-Wall") == 0) {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        } else if (strcmp(arg, "-Wpedantic") == 0) {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        } else if (strcmp(arg, "-Wextra") == 0) {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        } else if (strcmp(arg, "-Werror") == 0) {
            printf("-Werror: Make all warnings into errors.\n");
        } else if (strcmp(arg, "-o") == 0) {
            if (i + 1 < argc) {
                printf("-o %s: Place the primary output in file %s.\n",
                       argv[i + 1], argv[i + 1]);
                i++;
            }
        } else if (strcmp(arg, "-I") == 0) {
            if (i + 1 < argc) {
                printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n",
                       argv[i + 1], argv[i + 1]);
                i++;
            }
        } else if (strncmp(arg, "-std=", 5) == 0) {
            print_std(arg);
        } else {
            const char *desc = file_desc(arg);
            if (desc != NULL) printf("%s: %s as input file.\n", arg, desc);
        }


    }
   
    return 0;
}
