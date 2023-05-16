#include <stdlib.h>
#include <stdio.h>
#include <allegro.h>

void checkPtrNull(void *ptr, char *string)
{
    if (ptr == NULL) {
        printf("%s\n", string);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
}