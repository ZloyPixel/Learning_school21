/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-2____camel_to_snake.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/11 23:53:58 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 

Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Напишите программу, которая принимает одну строку в формате lowerCamelCase и 
преобразует ее в строку в формате snake_case.

Строка lowerCamelCase - это строка, в которой каждое слово начинается с 
заглавной буквы, кроме первого.

Строка snake_case - это строка, в которой каждое слово написано в нижнем 
регистре и разделено подчеркивание "_".


Примеры:

$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

void	camel_to_snake(char *str)
{
	while (*str)
	{
		if (*str >= 'A' && *str <= 'Z')
		{
			write(1, "_", 1);
			*str = *str + ('a' - 'A');
		}
		write(1, str, 1);
		str++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	write(1, "\n", 1);
	return (0);
}
