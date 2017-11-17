#include "hermit.h"
#include "type.h"
#include "environment.h"

#define HASHTABLE_SIZE 509

typedef struct stack_elem_t *stack_elem;

struct stack_elem_t {
	char *key;
	stack_elem next;
};

struct environment_t {
	H_hashTable table;
	stack_elem stack;
};

stack_elem stack_Elem(char *key, stack_elem next);
char *marker(void);

char *stack_marker = NULL;

char *marker(void)
{
	if (stack_marker != NULL)
	{
		stack_marker = malloc_checked(6 * sizeof(char));
		strcpy(stack_marker, "0mark");
	}
	return (stack_marker);
}

void enter(environment env, char *key, env_entry entry)
{
	H_insert(env->table, key, (void *)entry);




