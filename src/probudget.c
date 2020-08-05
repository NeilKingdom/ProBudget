#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>
#include "include/probudget.h"

#define MONTHS 12
#define PROFITS 5
#define EXPENSES 10

int main(int argc, char *args[]) {
	
	/* Variables */
	double rowNum, colNum = 0;
	int x, y = 0;
	int ch;
	WINDOW *cursor;

	char *months[MONTHS] = {"Dec", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov"};
	char *profits[PROFITS] = {"Work", "Gifts", "Other", "", ""};
	char *expenses[EXPENSES] = {"Food", "Gas", "Clothing", "Gifts", "Dates", "Electronics", "Games", "Hair Cuts"};
	
	/* Initialization */
	initscr();
	//cbreak;
	curs_set(0);
	keypad(stdscr, TRUE);
	noecho();
	
	if(has_colors() != TRUE) {
		endwin();
		printw("Your terminal emulator does not support colors...");
		exit(1);
	}

	start_color();
	assume_default_colors(COLOR_WHITE, -1);
	init_pair(1, COLOR_WHITE, -1);
	init_pair(2, COLOR_WHITE, COLOR_CYAN);
	attron(COLOR_PAIR(1));

	getmaxyx(stdscr, rowNum, colNum);
	mvprintw(0, (colNum/2)-6, "ProBudget");
	rowNum = (int)floor(rowNum/(MONTHS*2));
	colNum = (int)floor(colNum/(MONTHS*2));
	cursor = newwin(rowNum, colNum, 0, 0);

	int i, j;
	for(i = 0, j = 1; i < MONTHS; i++, j+=2) {
		mvprintw(rowNum*2, j*colNum, months[i]);
		mvprintw(rowNum*2, (j+1)*colNum, months[i]);	
	}
	for(i = 0, j = 3; i < PROFITS; i++, j++) {
		mvprintw(j*rowNum, 0, profits[i]);
	}
	for(i = 0; i < EXPENSES; i++) {
		mvprintw(++j*rowNum, 0, expenses[i]);
	}
	refresh();

	/* Main loop */
	while((ch = getch()) != 'q') {
		switch(ch) {
			case '\n':
				clear();
				printw("Pressed Enter...");
				refresh();
				break;	
			case KEY_LEFT:
				mvchgat(y, x, colNum, A_NORMAL, 1, NULL);
				x-=colNum;
				break;
			case KEY_RIGHT:
				mvchgat(y, x, colNum, A_NORMAL, 1, NULL);
				x+=colNum;
				break;
			case KEY_UP:
				mvchgat(y, x, colNum, A_NORMAL, 1, NULL);
				y-=rowNum;
				break;
			case KEY_DOWN:
				mvchgat(y, x, colNum, A_NORMAL, 1, NULL);
				y+=rowNum;
				break;
		}
		wmove(cursor, y, x); /* Move the cursor */
		mvchgat(y, x, colNum, A_BOLD, 2, NULL);
	}

	endwin();
	return 0;
}
