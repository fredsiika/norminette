/*
** EPITECH PROJECT, 2017
** int_to_str
** File description:
** prints a number given as argument
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "my.h"
#include "functions.h"

int del_neg(char *str, int nb, int *pos)
{
	if (nb < 0) {
		str[*pos] = '-';
		(*pos)++;
		nb = -nb;
	}
	return (nb);
}

char    *int_to_str(int nb)
{
	int	length_of_the_number;
	int	current_digit;
	int	digit_pos;
	int	number_left;
	int	pos = 0;
	char	*str = malloc(12);

	if (str == 0) {
                printf("Error while adding stack trace entry :\n\t\tCouldn't malloc 12B\n");
                exit(84);
        }
	nb = del_neg(str, nb, &pos);
	number_left = nb;
	length_of_the_number = get_nbrlen(nb);
	digit_pos = length_of_the_number - 1;
	while (digit_pos >= 0) {
		current_digit = number_left / pow(10, digit_pos);
		str[pos] = current_digit + 48;
		pos++;
		number_left -= current_digit * pow(10, digit_pos);
		digit_pos--;
	}
	str[pos] = 0;
	return (str);
}
