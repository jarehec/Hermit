#ifndef TYPE_H
#define TYPE_H

typedef struct type_t *type;
typedef struct type_list_t *type_list;

struct type_t {
	enum {Integer, Void} type;
	union {
		type array;
	} self;
};

struct type_list_t {
	type first;
	type_list next;
};

type integer_type();
type void_type();
type_list type_List(type first, type_list next);

#endif
