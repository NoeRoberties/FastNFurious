/*
** EPITECH PROJECT, 2023
** main 
** File description:
** main file
*/

#include "my.h"
#include <stdio.h>
#include <ncurses.h>

int main(void)
{
    int try = 1;
    char username[100];

    printf("\033[1;0m");
    printf("\nEnter username : ");
    scanf("%s",username);
    while (try <= 5) {
        initscr();
        printw("Try %d/5", try);
        refresh();
        sleep(1);
        addstr("...");
        endwin();
        printf("%s : Try %d/5 !\n", username, try);
        refresh();
        if (game_inf(username) == 1)
            break;
        try++;
    }
    return (0);
}
