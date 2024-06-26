#ifndef COUNTFREQ_H_INCLUDED
#define COUNTFREQ_H_INCLUDED

extern int chars[256];
extern int size;
extern char *filename;

void initializeChars();
void countFile(FILE *fp);
void printFreq();

#endif // COUNTFREQ_H_INCLUDED
