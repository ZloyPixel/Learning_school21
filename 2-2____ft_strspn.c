/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-2____ft_strspn.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/11 15:57:14 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** **


Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Точно воспроизведите поведение функции 'strspn' (man strspn).


Функция должна быть обьявлена следующим образом:

size_t	ft_strspn(const char *s, const char *accept);


** ************************************************************************** */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((void *)0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i])
	{
		if (!ft_strchr(accept, s[i]))
			break;
		i++;
	}
	return (i);
}

/* ************************************************************************** **


P.S 


Функция 'strspn()' выполняет поиск символов строки 'accept' в строке 's'. 
и возвращает длину начального участка строки 's' которая состоит только 
из символов, которые являются частью строки 'accept'.

Если все символы строки 's' входят в строку 'accept', функция возвращает длину 
всей строки 's'.

Если первый символ в строке 's' не входит в строку 'accept', то функция 
возвращает ноль.


#include <stdio.h>

int		main(void)
{
   // Массив со строкой для поиска
   char str[] = "9876543210";

   // Набор символов, которые должны входить в искомый сегмент
   char sym[] = "6789";

   // Определяем длину начального сегмента строки, содержащего символы "6789"
   printf ("Длина сегмента: %ld\n", ft_strspn(str, sym));

   return (0);
}



Вывод в консоль:
Длина сегмента: 6



** ************************************************************************** */