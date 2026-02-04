#include "rna_transcription.h"
#include <string.h>
#include <stdlib.h>

char *to_rna(const char *dna) {
    char *rna = (char *)malloc(strlen(dna) * sizeof(char));

    for (size_t i = 0; i < strlen(dna); i++) {
        if (dna[i] == 'G') {
            rna[i] = 'C';
        }
        else if (dna[i] == 'C') {
            rna[i] = 'G';
        }
        else if (dna[i] == 'T') {
            rna[i] = 'A';
        }
        else if (dna[i] == 'A') {
            rna[i] = 'U';
        }
        else {
            rna[i] = dna[i];
        }
    }
    
    return rna;
}