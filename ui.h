#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#define MAX 4
#define TP 3
#define LP 5
#define RP 110

extern int BP;

void gotoxy(int x,int y);
float centerText(int left, int right, int len);
void clearLine(int left, int right, int y);
void clearContent();
void borders();
void removeBottomBorder();
void placeBottomBorder();
void clearExtraBorders();
void startContent();
void newLineContent(int y);
void endProgram();
int menu(void);

#endif // UI_H_INCLUDED
