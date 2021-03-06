/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-1____alpha_mirror.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/08 21:10:32 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Напишите программу с именем alpha_mirror, которая принимает строку и отображает
эту строку после замены каждого алфавитного символа противоположным буквенным 
символом, за которым следует новая строка.

«a» становится «z», «Z» становится «A»
«d» становится «w», «M» становится «N»

и так далее.

Если количество аргументов не равно 1, отображается только новая строка.


Примеры:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_alpha_miror(char *str)					/* принимаем адресс массива символов в указатель */
{
	int		i;										/* Обьявим переменную для счетчика */
	char	ltr;									/* Обьявляем переменную временного хранения символа для печати */

	i = 0;											/* Инициализируем счетчик нулем чтобы начать с нулевой ячейки массива */
	while (str[i])									/* Запускаем цикл который идет по массиву и печатает противоположные буквы пока не дойдет до конца */
	{
		if ('A' <= str[i] && 'Z' >= str[i])			/* Если буква Верхнего регистра */
			ltr = (('Z' - *str) + 'A');				/* то вычисляем ее противоположный символ и сохраняем в "ltr" */
		else if ('a' <= *str && 'z' >= *str)		/* Если буква нижнего регистра */
			ltr = (('z' - *str) + 'a');				/* то вычисляем ее противоположный символ и сохраняем в "ltr" */
		else
			ltr = str[i];							/* Если символ не является буквой то сохраняем его в переменной для последующей печати */
		write(1, &ltr, 1);							/* Печатаем символя хранящийся в переменной "ltr" */
		str++;										/* Переходим к след ячейке массива */
	}
}

int		main(int argc, char *argv[])				/* Здесь принимаем количество строк в массиве и сам массив со строками */
{
	if (argc == 2)									/* Проверяем есть ли кроме имени программы в аргументах еще и нужная нам строка */
		ft_alpha_miror(argv[1]);					/* Выполняем функкцию */
	write(1, "\n", 1);								/* Печатаем символ перехода на новую строку */
	return (0);										/* Завершаем программу */
}
