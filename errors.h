#ifndef ERROR_H
#define ERROR_H

void Error(int lineno, char *message, ...);
int any_errors();
int num_errors();

#endif
