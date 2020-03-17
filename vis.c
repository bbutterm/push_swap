#include "push_swap.h"

void init_ncur(t_lis *p)
{
	//chtype ch;
	//int i;
	int x;

	printf("pered initom\n");
	/*if (!initscr())
    {
		printf("shta\n");
        printf("%s: %s \n", "initscr", strerror(errno));
    }*/
	//initscr();
	printf("posle inita\n");
	start_color();
	curs_set(0);
	x = 0;
	noecho();
	printf("noecho\n");
	//move(10, 30);
	//mvaddstr(LINES/2, (COLS-strlen(a)) / 2, a);
	if (has_colors())
    {
        // Инициализация цветовых пар
        init_pair(1,  COLOR_RED,     COLOR_BLACK);
        init_pair(2,  COLOR_GREEN,   COLOR_BLACK);
        init_pair(3,  COLOR_YELLOW,  COLOR_BLACK);
        init_pair(4,  COLOR_BLUE,    COLOR_BLACK);
        init_pair(5,  COLOR_MAGENTA, COLOR_BLACK);
        init_pair(6,  COLOR_CYAN,    COLOR_BLACK);
        init_pair(7,  COLOR_BLUE,    COLOR_WHITE);
        init_pair(8,  COLOR_WHITE,   COLOR_RED);
        init_pair(9,  COLOR_BLACK,   COLOR_GREEN);
        init_pair(10, COLOR_YELLOW,    COLOR_BLUE);
        init_pair(11, COLOR_WHITE,   COLOR_BLUE);
        init_pair(12, COLOR_WHITE,   COLOR_MAGENTA);
        init_pair(13, COLOR_BLACK,   COLOR_CYAN);
    }
	//attron(COLOR_PAIR(10));
	attron(COLOR_PAIR(11) | A_BOLD);
	while (x < LINES)
	{
		mvhline(x, 0, ' ', COLS);
		x++;
	}
	x = 0;
	while (x < COLS)
	{
		move(1, x);
		addch(ACS_HLINE);
		x++;
	}
	x = 0;
	while (x < COLS)
	{
		move(LINES - 3, x);
		addch(ACS_HLINE);
		x++;
	}
	x = 0;
	while (x < LINES - 4)
	{
		move(x + 2, COLS  / 2);
		addch(ACS_VLINE);
		x++;
	}
	//mvvline(2, COLS / 2, '|', LINES - 4);
	//mvhline(LINES - 3, 0, '_', COLS);
	mvprintw(7 / 10, COLS / 2 - 13, "Push_swap - Copyright (C) 2020");
	mvprintw(2, COLS - COLS/4 - 7, "Stack B");
	mvprintw(LINES - 2, COLS / 7 - 6, "Quit");
	printf("Quit\n");
	refresh();
	keypad(stdscr, TRUE);
	mvprintw(2, COLS/4, "Stack A");
	printf("pered p\n");
	pri(p);
	printf("posle p\n");
	/*while (1)
	{
		ch = getch();
		if (ch == KEY_DOWN)
		{
			attron(COLOR_PAIR(8) | A_BOLD);
			mvprintw(LINES - 2, COLS / 7 - 6, "Quit");
			while (1)
			{
				ch = getch();
				if (ch == 10)
				{
					endwin();
					exit(0);
				}
				if (ch == KEY_UP)
				{
					attron(COLOR_PAIR(11) | A_BOLD);
					mvprintw(LINES - 2, COLS / 7 - 6, "Quit");
					break ;
				}
			}
		}
	}*/
}
