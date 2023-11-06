/*
** EPITECH PROJECT, 2023
** high score
** File description:
** display the actuel high score
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

int arg_is_h_score(char *argv)
{
    if (strcmp(argv, "high_score") == 0) {
        display_champion_best_score();
        return 1;
    }
    return 0;
}

void display_champion_best_score(void)
{
    FILE *fb;
    char champ[100];
    char h_score[100];

    fb = fopen("champion.txt", "r");
    fgets(champ, 100, fb);
    fclose(fb);
    fb = fopen("high_score.txt", "r");
    fgets(h_score, 100, fb);
    fclose(fb);
    printf("\033[0;36m%s \033[0;34m has the actual best score with \033[0;33m%s \033[0;34m!\n", champ, h_score);
    printf("\33[0;0m");
}

int main(void)
{
    display_champion_best_score();
    return 0;
}
