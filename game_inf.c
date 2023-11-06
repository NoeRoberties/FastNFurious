/*
** EPITECH PROJECT, 2023
** game inf
** File description:
** you have to stop the infinite loop the quickest possible
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "my.h"
#include <time.h>
#include <ncurses.h>

int game_inf(char *argv)
{
    int out = 0;
    int count = 3;
    int i = 0;
    int add = 3;
    int key = ERR;

    key = my_clock();
    printf("\033[0;32m");
    initscr();
    nodelay(stdscr, TRUE);
    while (key == ERR) {
        key = getch();
        clear();
        refresh();
        i = i + add;
        if (i <= 1000)
            init_pair(1, COLOR_CYAN, COLOR_BLACK);
        if (i <= 2000 && i > 1000) {
            add = 4;
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
        }
        if (i > 2000 && i < 8000) {
            add = 5;
            init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        }
        if (i >= 8000) {
            add = 6;
            init_pair(1, COLOR_RED, COLOR_BLACK);
        }
        game_display(i);
        refresh();
    }
    endwin();
    out = score_display(i);
    printf("\033[1;0m");
    score_and_high_score(argv, i);
    clear();
    return out;
}

void score_and_high_score(char *argv, int i)
{
    char str1[100];
    char str2[100];
    FILE *fb;
    
    fb = fopen("score.txt", "w");
    fprintf(fb, "%d", i);
    fclose(fb);
    fb = fopen("score.txt", "r");
    fgets(str1, 100, fb);
    fclose(fb);
    fb = fopen("high_score.txt", "r");
    fgets(str2, 100, fb);
    fclose(fb);
    if (lowest_score(str1, str2) == 1 && i > 2) {
        fb = fopen("high_score.txt", "w");
	fprintf(fb, "%d", i);
        fclose(fb);
        replace_champion(argv);
        display_best_score(argv, i);
    }

}

void replace_champion(char *argv)
{
    FILE *fb;

    fb = fopen("champion.txt", "w");
    fprintf(fb, "%s", argv);
    fclose(fb);
}

int score_display(int i)
{
    int out = 0;

    if (i <= 1000)
        printf("\033[0;36m");
    if (i <= 3000 && i > 1000)
        printf("\033[0;32m");
    if (i > 3000 && i < 10000)
        printf("\033[0;33m");
    if (i >= 10000)
	printf("\033[1;31m");
    if (i == 0 || i == 2) {
        out = 1;
        printf("To soon loser !\n\n");
        troll_face();
    }
    else if (i > 2)
        printf("Your score : %d\n\n",i);
    return out;
}

int lowest_score(char* str1, char* str2)
{
    int i = 0;

    if (strlen(str1) < strlen(str2)) {
        return 1;
    } else if (strlen(str2) < strlen(str1)) {
        return 2;
    }
    while (i <= strlen(str1)) {
        if (str1[i] < str2[i]) {
            return 1;
        } else if (str1[i] > str2[i]) {
            return 2;
        }
        i++;
    }
}

int my_clock(void)
{
    int count = 3;
    int key = ERR;

    initscr();
    nodelay(stdscr, TRUE);
    while (count > 0) {
        key = getch();
        if (key != ERR)
            return key;
        start_color();
        attron(COLOR_PAIR(1));
        if (count == 3) {
            sleep(1);
            addstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            init_pair(1, COLOR_RED, COLOR_BLACK);
            addstr("                                                                             ####\n");
            addstr("                                                                            ##  ##\n");
            addstr("                                                                                ##\n");
            addstr("                                                                              ###\n");
            addstr("                                                                                ##\n");
            addstr("                                                                            ##  ##\n");
            addstr("                                                                             ####\n\n");
            refresh();
            sleep(1);
            clear();
            refresh();
        }
        if (count == 2){
            addstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            init_pair(1, COLOR_YELLOW, COLOR_BLACK);
            addstr("                                                                             ####\n");
            addstr("                                                                            ##  ##\n");
            addstr("                                                                                ##\n");
            addstr("                                                                               ##\n");
            addstr("                                                                              ##\n");
            addstr("                                                                             ##\n");
            addstr("                                                                            ######\n\n");
            refresh();
            sleep(1);
            clear();
            refresh();
        }
        if (count == 1){
            addstr("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            init_pair(1, COLOR_GREEN, COLOR_BLACK);
            addstr("                                                                                ##\n");
            addstr("                                                                               ###\n");
            addstr("                                                                                ##\n");
            addstr("                                                                                ##\n");
            addstr("                                                                                ##\n");
            addstr("                                                                                ##\n");
            addstr("                                                                              ######\n");
        }
        count--;
        attroff(COLOR_PAIR(1));
    }
    return random_wait();
    endwin();
}
