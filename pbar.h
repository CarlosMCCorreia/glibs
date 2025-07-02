#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <stdint.h>

#define MAXSIZE 100

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

// Struct exposed to the user
typedef struct {
    int8_t status;
    int8_t size;
    int8_t mxsize;
} progressbar;

// Public functions
progressbar* pbar_init(int8_t mxsize);
void pbar_update(progressbar *pbar, const int8_t increment);
void pbar_delete(progressbar **pbar);

#endif // PROGRESSBAR_H