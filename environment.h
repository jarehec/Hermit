#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

typedef struct environment_t *environment;
typedef struct env_entry_t *env_entry;

environment environ(void);

void add_builtin_types(environment env);
void add_builtin_functions(environment env);
void begin_scope(environment env);
void end_scope(environment env);
void enter(environment env, char *key, env_entry entry);
env_entry find(environment env, char *key);


struct env_entry_t {
	enum {FunctionEntry, TypeEntry} type;
	union {
		struct {
			type return_typ;
			type_list params;
		} function_entry;
		struct {
			type typ;
		} type_entry;
	} self;
};

#endif
