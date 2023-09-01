#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h> /* ncurses.h includes stdio.h */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

typedef struct single_linked_list
{
	struct array *Next;
	int Index;
	char *String;
} array;

int main(int argc, char **argv) /* ./vi ELFile */
{
	WINDOW *my_window;
	int file, InputStringSize, ch;
	FILE *fp;
	int WindowHieght, WindowWidth, Currenty, Currentx;
	char **InputString;

	if (argc < 2)
	{
		printf("No File Name!\n");
		return (1);
	}
	initscr();
	getmaxyx(stdscr, WindowHieght, WindowWidth);
	my_window = newwin(WindowHieght, WindowWidth, 0, 0);
	raw();
	keypad(stdscr, TRUE);
	noecho();
	/*//refresh();
	ch = getch();
	if (ch == KEY_F(2))
		printw("F2\n");
	else
	printw("%c", ch);
	getch();*/
	while (ch = getch())   /* scanw("%s", ) */
	{
		getyx(stdscr, Currenty, Currentx);
		switch (ch)
		{
		case KEY_F(2):
			printw("F2 pressed");
			refresh();
			endwin();
			return (0);

		case KEY_LEFT:
			move(Currenty, --Currentx);
			refresh();
			break;

		case KEY_RIGHT:
			move(Currenty, ++Currentx);
			refresh();
			break;

		case KEY_UP:
			move(--Currenty, Currentx);
			refresh();
			break;

		case KEY_DOWN:
			move(++Currenty, Currentx);
			refresh();
			break;

		case KEY_BACKSPACE:
			//printw("w");
			if (Currentx == 0)
			{
				move(--Currenty, 0);
				break;
			}
			move(Currenty, --Currentx);
			delch();
			break;
			
		case '\n':
			move(++Currenty, 0);
			refresh();
			break;

		default:
			insch(ch);
			move(Currenty, ++Currentx);
			//printw("%c", ch);
			refresh();
		}
		//  if(ch == KEY_F(2))
		//  {
		//  	printw("F2 pressed");
		// 	endwin();
		// 	break;
		// }
		// else
		// {
		// printw("%c", ch);
		// }
		refresh();
	}
	

	
	fp = fopen(argv[1], "rw");
	if (fp < 0)
	{
		fprintf(stderr, "file didnt open\n");
	}

	return (0);
}