#ifndef LEX_H
#define LEX_H

#define ENDFILE		256
#define ERROR		259
#define FILE_ERR 	"Error opening file\n"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * file_position - struct to hold the current position of the file
 * @file_name: name of input file
 * @line_num: line number
 * @char_num: Nth character in the file
 */
typedef struct {
	char *file_name;
	int line_num;
	int char_num;
} file_position;

/**
 * token_type - stores information about a token
 * @class: id of token (int, char *, keyword, etc..)
 * @repr: string representation of the class
 * @pos: position of the token in the file
 */
typedef struct {
	int class;
	char *repr;
	file_position pos;
} token_type;
FILE *open_file(int arg_num, char **args);
#endif
