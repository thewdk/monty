#include "monty.h"



/**
 * add_wd - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void add_wd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	pop_wd(stack, line_number);
}

/**
 * sub_wd - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void sub_wd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	pop_wd(stack, line_number);
}

/**
 * div_wd - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void div_wd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setopTokerr(div_err(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	pop_wd(stack, line_number);
}

/**
 * mul_wd - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mul_wd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	pop_wd(stack, line_number);
}

/**
 * mod_wd - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void mod_wd(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setopTokerr(short_stack_err(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setopTokerr(div_err(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	pop_wd(stack, line_number);
}
