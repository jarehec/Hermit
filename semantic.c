#include "hermit.h"
#include "environment.h"
#include "type.h"
#include "semantic.h"

/**
 * analyze_program - semantic analysis entry point
*/
void analyze_program(A_program program)
{
	environment type_env;
	environment function_env;

	type_env = environ();
	function_env = environ();

	add_builtin_types(type_env);
	add_builtin_functions(function_env);

	analyze_function_dec_list(type_env, function_env, program->function_decs);
}

/**
 * analyze_function_dec - analyzes a function declaration
 */
analyze_function_dec(A_func_dec function)
{



}

/**
 * analyze_function_dec_list - analyzes function declarations
*/
analyze_function_dec_list(environment type_env, environment func_env, A_func_dec_list functions)
{
	

}
