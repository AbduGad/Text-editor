#include <ncurses.h>                    /* ncurses.h includes stdio.h */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

void PutInFile(char *str) /* Hello */
{
	int fp;
	char *output;

	output = malloc(8);

	fp = open("/mnt/c/Users/pc/OneDrive/Desktop/Alx/ALX Programing/Text-editor/File", O_CREAT | O_WRONLY | O_RDONLY);
	if (fp < 0)
		perror("Error\n");
	write(fp, str, strlen(str));

	read(fp, output, 8);
	output[8] = '\0';
	printf("1234\n");
	printf("%s\n", output);
	write(1, output, strlen(output));
	close(fp);
}
                                                                                                 
int main2()
{
        char mesg[]="Enter a string: ";         /* message to be appeared on the screen */
        char str[80];
        int row,col;                            /* to store the number of rows and *
                                                 * the number of colums of the screen */
        initscr();                              /* start the curses mode */
        getmaxyx(stdscr,row,col);               /* get the number of rows and columns */
        mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
                                        /* print the message at the center of the screen */
        getstr(str);
		PutInFile(str);
        mvprintw(LINES - 2, 0, "You Entered: %s", str);
        getch();
        endwin();
                                                                                                 
        return 0;
}
int main()
{
	char *str = "OLAAAA";
	
	PutInFile(str);
	
return 0;

}