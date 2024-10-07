/* Copyright (C) 2017, 2018, 2019, 2020, 2021 Julian Pieles */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *translate_latin_trivial(char *latin_text);
char *translate_trivial_latin(char *trivial_text);
char *trivial_translator(int dir, char *text);
char *translate(char *text, char *alphabet0, char *alphabet1);

char *latin_alphabet =
"aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
char *trivial_alphabet =
"oOyYwWtTeErRpPmMuUkKhHfFcCzZiIxXvVsSqQnNaAlLjJgGdDbB";

char *translate(char *text, char *alphabet0, char *alphabet1) {
    for (int i = 0; i < strlen(text); i++)
        for (int j = 0; j < (26*2); j++)
            if (text[i] == alphabet0[j]) {
                text[i] = alphabet1[j];
                break;
            }
    return text;
}

char *translate_latin_trivial(char *latin_text) {
    return translate(latin_text, latin_alphabet, trivial_alphabet);
}

char *translate_trivial_latin(char *trivial_text) {
    return translate(trivial_text, trivial_alphabet, latin_alphabet);
}

char *trivial_translator(int dir, char *text) {
    return dir == 0 ? translate_trivial_latin(text) :
    translate_latin_trivial(text);
}

int main(int argc, char *argv[]) {
    printf("%s\n", argc == 3 ?
    trivial_translator(strcmp(argv[1], "-l"), argv[2]) :
    "[error] too few arguments.");
    return 0;
}
