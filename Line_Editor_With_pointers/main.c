#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);

int main()
{
    int size;
    printf("enter size: ");
    scanf("%d", &size);
    char *sentence, ch;
    sentence = (char *) malloc(size);
    int x = 0, y = 1, len = 0;
    ch = getch();
    gotoxy(x,y);
    do
    {
        if (ch == -32)
        {
            ch = getch();
            if (ch == 77 && x < size && x < len)
            {
                x++;
            }
            else if (ch == 75 && x > 0)
            {
                x--;
            }
            else if (ch == 71)
            {
                x = 0;
            }
            else if (ch == 79)
            {
                x = len;
            }
            else if (ch == 83)
            {
                if (x == len)
                {
                    x--;
                    len--;
                    gotoxy(x,y);
                    printf(" ");
                }
                else
                {
                    for (int i = x; i < (len - 1); i++)
                    {
                        printf("%c",sentence[i+1]);
                        sentence[i] = sentence[i+1];
                    }
                    printf(" ");
                    len--;
                }
            }
            gotoxy(x,y);
        }
        else if (ch == 13 && len > 0)
        {
            y++;
            x = 0;
            gotoxy(x,y);
            printf("Sentence is: ");
            for (int i = 0; i < len; i++)
            {
                printf("%c", sentence[i]);
            }
            y++;
            x = len = 0;
            gotoxy(x,y);
        }
        else if (ch > 31 && ch < 127 && x < size)
        {
            sentence[x] = ch;
            printf("%c", sentence[x]);
            if (len == x)
            {
                len++;
            }
            x++;
            gotoxy(x,y);

        }
        else if (ch == 8 && len > 0)
        {

            if (x == len)
            {
                x--;
                len--;
                gotoxy(x,y);
                printf(" ");
                gotoxy(x,y);
            }
            else
            {
                for (int i = x; i < (len - 1); i++)
                {
                    printf("%c",sentence[i+1]);
                    sentence[i] = sentence[i+1];
                }
                printf(" ");
                len--;
                gotoxy(x,y);
            }
        }
        ch = getch();
    }while (ch != 27);

    free(sentence);

    return 0;
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
