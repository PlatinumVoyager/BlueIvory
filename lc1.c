#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// v0.2

/*
    GENERATE STRING OF TEXT OR ACQUIRE INPUT FROM STDIN
    TAKE THE TOTAL SUM OF STRING AND ALLOCATE (MALLOC) A BUFFER OF THE APPROPRIATE SIZE

    (FUTURE) RETAIN INFORMATION RELATING TO THE EXACT ADDRESS IN MEMORY OF EACH INDEX TO
        GENERATE BITS OF A TOTAL KEY FROM THE STRING BASED OFF THE UNIQUE ADDRESS OF EACH 
        CHAR (INDEX OF CHARACTER ARRAY BUFFER) IN MEMORY, ADD CHAR INDEX + BIT OF PARTIAL KEY GEN
        USE KEY GENERATED TO MASK STRING (COMMAND) FROM STDIN AS IT IS TRANSPORTED ACROSS THE NETWORK
*/

#define TARGET_STR argv[1]
typedef unsigned long U_LONG;

/* start */
int main(int argc, char *argv[])
{
    // setup
    int index;

    printf("++ Got TARGET_STR of \"%s\" addr(%p)\n", TARGET_STR, &TARGET_STR);

    char *buffer;
    if ((buffer = (char *) malloc((int) strlen(TARGET_STR) * sizeof(char))) == NULL)
    {
        fprintf(stderr, "!! Failed to allocate buffer of size \"%lu\" addr(%p)\n", sizeof(buffer), &buffer);
        exit(1);
    } 

    U_LONG BUFF_SIZE = sizeof(buffer);

    printf("++ Allocating buffer of \"%lu\" bytes...\n", BUFF_SIZE);

    char *input = TARGET_STR;
    if (!strcpy(buffer, input)) { printf("Failed to copy \"%s\" into buffer...\n", TARGET_STR); exit(1); }

    index = atoi(argv[2]);

    puts("<< SETTING BUFFER ALLOCATED FOR INPUT AS CHAR POINTER >>");
    char *p_raw = buffer;

    // *p_raw -> points to first index in character array that holds user input
    printf("++ Set INDEX %d\nVar => \"%c\" of INDEX: %d | Buffer start (INDEX 0) addr >> %p\n\n", index, *(p_raw + index), index, p_raw);

    int x = 0;

    while (*(p_raw + x) != !p_raw)
    {
        printf("[ INDEX ] Current index of: %d | VAL => %c (%p)\n", x, *(p_raw + x), &(*(p_raw + x)));
        x++;

        if (*(p_raw + x) == '\0')
        {
            printf("\nFINISHED.\n++ NULL_REACH (%p) @ INDEX_VALUE: %d\n", &(*(p_raw + x)), x);
            break;
        }
    }

    free(buffer);

    return 0;
}
/* end */
