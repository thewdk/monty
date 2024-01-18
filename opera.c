#include "monty.h"

/**
 * setopTokerr - Sets last element of op_toks to be an error code.
 * @errCode: Integer to store as a string in op_toks.
 */
void setopTokerr(int errCode)
{
	int toks_len = 0, i = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_err();
		return;
	}
	while (i < toks_len)
	{
		new_toks[i] = op_toks[i];
		i++;
	}
	exit_str = get_int(errCode);
	if (!exit_str)
	{
		free(new_toks);
		malloc_err();
		return;
	}
	new_toks[i++] = exit_str;
	new_toks[i] = NULL;
	free(op_toks);
	op_toks = new_toks;
}
