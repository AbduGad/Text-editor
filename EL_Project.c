#include "lists.h"


int main(int argc, char **argv) /* ./vi ELFile */
{
	WINDOW *my_window;
	int file, TempStringIndex = 0, ch, CurrentArrayIndex;
	FILE *fp;
	int WindowHieght, WindowWidth, Currenty, Currentx;
	char *TempString, *PrevLine, tmp[2], *Holder;
	size_t PrevLineSize;
	array *BufferHead = NULL;
	array *BufferPointer = NULL;
	int CurserPosY = 0;

	TempString = malloc(sizeof(char) * 128);
	if (TempString == NULL)
		printw("Malloc fail!!!!");
	TempString[0] = '\0';

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
	//CreateList(&BufferHead);

	while (ch = getch())   /* scanw("%s", ) */
	{
		ssize_t linecounter = 0;
		getyx(stdscr, Currenty, Currentx);
		switch (ch)
		{
		case KEY_F(2):
			free(TempString);
			free_listint2(&BufferHead);
			printw("F2 pressed");
			refresh();
			endwin();
			return (0);

		case KEY_LEFT:
			if (Currentx == 0)
				break;
			move(Currenty, --Currentx);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d  ", CurserPosY);
			move(Currenty, Currentx);
			refresh();
			break;

		case KEY_RIGHT:
			if (Currentx == WindowWidth)
				break;
			move(Currenty, ++Currentx);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d  ", CurserPosY);
			move(Currenty, Currentx);
			refresh();
			break;

		case KEY_UP:
			if (Currenty == 0)
				break;
			CurserPosY--;
			move(--Currenty, Currentx);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d  ", CurserPosY);
			move(Currenty, Currentx);
			refresh();
			break;

		case KEY_DOWN:
			CurserPosY++;
			move(++Currenty, Currentx);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d   ", CurserPosY);
			move(Currenty, Currentx);
			refresh();
			break;

		case KEY_BACKSPACE:
			//printw("w");
			if (Currentx == 0)
			{
				if (Currenty == 0)
					break;
				CurserPosY--;
				move(--Currenty, BufferPointer->LineLen);
				mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d  ", CurserPosY);
				move(Currenty, BufferPointer->LineLen);
				CurrentArrayIndex -= 1;
				BufferPointer = BufferHead;
				while (BufferPointer->Index < CurrentArrayIndex && CurrentArrayIndex >= 0)
				{
					BufferPointer = BufferPointer->Next;
				}
				/* Handle deleting the previous line */
				break;
			}
			/*kan bymsa7 bl 3araby*/
			move(Currenty, --Currentx);
			/*printw("\b \b");*/
			delch();
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d   ", CurserPosY);
			move(Currenty, Currentx);
			refresh();
			break;
			
		case '\n':
			/*when user tries to pass the maximum window height window should close and open a new one with more space*/

			/*when thers an input of a newline we will create a new node in the list*/
			
			BufferPointer = add_node_end(&BufferHead, TempString);
			CurrentArrayIndex = BufferPointer->Index;

			TempStringIndex = 0;
			free(TempString);
			TempString = malloc(sizeof(char) * 128);
			if (TempString == NULL)
				printw("Malloc fail!!!!");
			TempString[0] = '\0';

			
			if (Currenty == WindowHieght)
				break;
			CurserPosY++;
			printw("%d %d", WindowHieght, WindowWidth);
			//move(WindowHieght - 1, WindowWidth - 1);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d  ", CurserPosY);
			move(Currenty, Currentx);
			printw("\n");
			//printw("%d", Currenty);
			//move(++Currenty, 0);
			refresh();
			break;

		default:
			insch(ch);
			TempStringIndex++;
			if (TempStringIndex % 128 == 0) /*'\0' at 127 index*/
			{
				Holder = realloc(TempString, sizeof(char) * (TempStringIndex + 128)); /* 127 + 128 = 255 256*/
				TempString = Holder;
				//printw("%s", TempString);	
			}
			tmp[0] = ch;
			tmp[1] = '\0';
			strcat(TempString, tmp);
			move(Currenty, ++Currentx);
			mvprintw(WindowHieght-2, WindowWidth - 30, "Curser position: %d   ", CurserPosY);
			mvprintw(WindowHieght-3, WindowWidth - 30, "Colomun position: %d   ", TempStringIndex);
			move(Currenty, Currentx);
			//printw("%c", ch);
			refresh();
		}
	
		refresh();
	}
	

	
	fp = fopen(argv[1], "rw");
	if (fp < 0)
	{
		fprintf(stderr, "file didnt open\n");
	}

	return (0);
}