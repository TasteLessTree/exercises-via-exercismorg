#include <string.h>

#include "protein_translation.h"

bool codon_to_amino_acid(const char *codon, amino_acid_t *amino_acid, bool *is_stop) {
    // Set default
    if (!codon || !amino_acid || !is_stop) { 
        return false;
    }

    *is_stop = false;

    if (strcmp(codon, "AUG") == 0) {
        *amino_acid = Methionine;
        return true;
    } else if (strcmp(codon, "UUU") == 0 || strcmp(codon, "UUC") == 0) {
        *amino_acid = Phenylalanine;
        return true;
    } else if (strcmp(codon, "UUA") == 0 || strcmp(codon, "UUG") == 0) {
        *amino_acid = Leucine;
        return true;
    } else if (
        strcmp(codon, "UCU") == 0 ||
        strcmp(codon, "UCC") == 0 ||
        strcmp(codon, "UCA") == 0 ||
        strcmp(codon, "UCG") == 0
      ) {
        *amino_acid = Serine;
        return true;
    } else if (strcmp(codon, "UAU") == 0 || strcmp(codon, "UAC") == 0) {
        *amino_acid = Tyrosine;
        return true;
    } else if (strcmp(codon, "UGU") == 0 || strcmp(codon, "UGC") == 0) {
        *amino_acid = Cysteine;
        return true;
    } else if (strcmp(codon, "UGG") == 0) {
        *amino_acid = Tryptophan;
        return true;
    } else if (
        strcmp(codon, "UAA") == 0 ||
        strcmp(codon, "UAG") == 0 ||
        strcmp(codon, "UGA") == 0
    ) {
        *is_stop = true;
        return true;
    }
    return false; // unknown codon
}

protein_t protein(const char *const rna) {    
    protein_t result = { .valid = true, .count = 0 };

    if (!rna || strlen(rna) == 4) {
        return (protein_t){ .valid = false };
    }

    size_t len = strlen(rna);

    for (size_t i = 0; i + 2 < len; i += 3) {
        if (result.count >= MAX_AMINO_ACIDS) {
            break;
        }
        char codon[4] = {0};
        strncpy(codon, &rna[i], 3);
        amino_acid_t aa;
        bool is_stop;
        if (!codon_to_amino_acid(codon, &aa, &is_stop)) {
            result.valid = false;
            return result;
        }
        if (is_stop) {
            break;
        }
        result.amino_acids[result.count++] = aa;
    }
    
    return result;
}