#include "beer_song.h"
#include <stdio.h>

#define MAX_LINE_LENGTH (1024)
#define MAX_LINE_COUNT (299)

void recite(int start_bottle_count, int verses_count, char **song) {
    int verse_idx = 0;

    for (int current_bottle = start_bottle_count; verses_count > 0; current_bottle--, verses_count--) {
        // Line 1: "X bottles of beer on the wall, X bottles of beer."
        if (current_bottle > 1) {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "%d bottles of beer on the wall, %d bottles of beer.", current_bottle, current_bottle);
        } else if (current_bottle == 1) {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "1 bottle of beer on the wall, 1 bottle of beer.");
        } else {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "No more bottles of beer on the wall, no more bottles of beer.");
        }

        // Line 2: "Take one down and pass it around, X-1 bottles of beer on the wall."
        if (current_bottle > 2) {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "Take one down and pass it around, %d bottles of beer on the wall.", current_bottle - 1);
        } else if (current_bottle == 2) {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "Take one down and pass it around, 1 bottle of beer on the wall.");
        } else if (current_bottle == 1) {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "Take it down and pass it around, no more bottles of beer on the wall.");
        } else {
            snprintf(song[verse_idx++], MAX_LINE_LENGTH, "Go to the store and buy some more, 99 bottles of beer on the wall.");
        }

        // Empty line between verses, but not after the last one
        if (verses_count > 1) {
            song[verse_idx++][0] = '\0'; // Blank line
        }
    }
}