#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "pbar.h"

static void pbar_print(progressbar *pbar);


progressbar* pbar_init(int8_t mxsize) {
    progressbar* pbar = malloc(sizeof(progressbar));
    if(!pbar) {
        fprintf(stderr, "Error alocating progress bar memory\n");
        pbar = NULL;
        return NULL;
    }
    pbar->status = 0;
    pbar->size = 0;
    pbar->mxsize = (mxsize > 0 && mxsize <= MAXSIZE) ? mxsize : 10;
    pbar_print(pbar);
    return pbar;
}

void pbar_update(progressbar *pbar, const int8_t increment) {

    if(!pbar || pbar->status == 100) return;

    int8_t new_status = pbar->status + increment;
    
    if(new_status > 100) new_status = 100;

    pbar->status = new_status;

    float tmp_size = pbar->status * pbar->mxsize / 100.0f;
    int8_t new_size = round(tmp_size);

    if(tmp_size != 100 && new_size == 100)
        new_size = 99;
    
    pbar->size = new_size;

    pbar_print(pbar);
    
    if(new_status == 100) printf("\n");
}

void pbar_delete(progressbar** pbar) {
    if(pbar && *pbar) {
        free(*pbar);
        *pbar = NULL;
    }
}

static void pbar_print(progressbar *pbar) {
    printf(GREEN "\r[" BLUE);
    for(uint8_t i = 0; i < pbar->size; i++) printf("=");
    uint8_t leftover = pbar->mxsize - pbar->size;
    for(uint8_t i = 0; i < leftover; i++) printf(" ");
    printf(GREEN"] %3d%%\t" RESET, pbar->status);
    fflush(stdout);
}




