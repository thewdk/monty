#include "monty.h"


/**
 * push_wd - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineFig: The current working line number of a Monty bytecodes file.
 */
void push_wd(stack_t **stack, unsigned int lineFig)
{
	stack_t *tmp, *new;
	int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		setopTokerr(malloc_err());
		return;
	}

	if (op_toks[1] == NULL)
	{
		setopTokerr(no_int_err(lineFig));
		return;
	}

	for (i = 0; op_toks[1][i]; i++)
	{
		if (op_toks[1][i] == '-' && i == 0)
			continue;
		if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
		{
			setopTokerr(no_int_err(lineFig));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK) /* STACK mode insert at front */
	{
		tmp = (*stack)->next;
		new->prev = *stack;
		new->next = tmp;
		if (tmp)
			tmp->prev = new;
		(*stack)->next = new;
	}
	else /* QUEUE mode insert at end */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		new->next = NULL;
		tmp->next = new;
	}
}

/**
 * pall_wd - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineFig: The current working line number of a Monty bytecodes file.
 */
void pall_wd(stack_t **stack, unsigned int lineFig)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)lineFig;
}

/**
 * pint_wd - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineFig: The current working line number of a Monty bytecodes file.
 */
void pint_wd(stack_t **stack, unsigned int lineFig)
{
	if ((*stack)->next == NULL)
	{
		setopTokerr(pint_err(lineFig));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * pop_wd - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineFig: The current working line number of a Monty bytecodes file.
 */
void pop_wd(stack_t **stack, unsigned int lineFig)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		setopTokerr(pop_err(lineFig));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * swap_wd - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineFig: The current working line number of a Monty bytecodes file.
 */
void swap_wd(stack_t **stack, unsigned int lineFig)
{
	stack_t *tmp;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(lineFig, "swap"));
		return;
	}

	tmp = (*stack)->next->next;
	(*stack)->next->next = tmp->next;
	(*stack)->next->prev = tmp;
	if (tmp->next)
		tmp->next->prev = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
}
