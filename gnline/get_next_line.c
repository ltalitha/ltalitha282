/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalitha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:57:48 by ltalitha          #+#    #+#             */
/*   Updated: 2019/09/24 21:07:16 by ltalitha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	get_next_line(const int fd, char **line);

char *what_is_in_remain (char *remain, char **line) //то что осталось в остатке
{
    char *sigh_of_new_string; // сохраняем указатель на новую линию

    sigh_of_new_string = NULL; //очищаем
    if (remain) //если remain != 0
        if ((sigh_of_new_string = ft_strchr(remain, '\n'))) //нашли в remain новую линию - копируем эту строку и удаляем её из остатка,
            // а то что осталось снова копируем в ремейн
        {
            *sigh_of_new_string = '\0'; //скопируется только та часть, которая до конца строки
            *line = ft_strdup(remain); // скорпировали в лайн все то, что до новой линии
            ft_strcpy(remain, ++sigh_of_new_string); //вернуть остаток в remain,
        }
        else // если remain пустой - создаеми новую аллокацию памяти
        {
            *line = ft_strdup(remain);
            ft_strclr(remain);
        }
    else
        *line = ft_strnew(1);
    return (sigh_of_new_string);
}

int get_next_line(const int fd, char **line)
{
    char buffer[BUFFER_SIZE + 1]; //записываем прочитаные read символы
    int what_read; // то что прочитали функцией read (10 символов)
    char *sign_of_new_string; // указатель на \n
    static char *remain; //осататок, сохранит и приклеить к следующей строке
    char *tmp;

    if (fd < 0 || !line || read(fd, buffer, 0) < 0)
        return (-1);
    sign_of_new_string = what_is_in_remain(remain, line);
    while (!sign_of_new_string && (what_read = read(fd, buffer, BUFFER_SIZE)))
    {
        buffer[what_read] = '\0'; // конец строки ставим после последнего символа, но мы не знаем сколько всего поступает символов.
        // Поэтому переменная what_read
        if ((sign_of_new_string = ft_strchr(buffer, '\n')))
        {
            *sign_of_new_string = '\0';
            sign_of_new_string++;
            remain = ft_strdup(sign_of_new_string);
        }


        //read функция, которая читает/ читаем по 10 символов из переменнной//отправляем ячейку памяти,
        // работает не символами, а с памятью. 1 вызов - читаем 10 символов
        tmp = *line;
        *line = ft_strjoin(*line, buffer);
        free(tmp);
        //возвращаем указатель на строку для которой аллоцировали память и копировали буфер
        // копируем из buffer в line. Используем strdup т.к. она аллоцирует память, а потом записывает.
        // Меняем на strjoin так она склеивает
    }
    return ((what_read || ft_strlen(remain) || ft_strlen(*line)) ? 1 : 0); // what_read != 0 - значит, что-то было прочитано || или что еще есть  remain != 0, или длина line != 0

}
int main (void)
{
    char *line;
    int fd; // файловый дескриптор - это цифра int
    fd = open("test.txt", O_RDONLY);//open("имяфайла.txt" и флаги O_READONLY )// open работает не с символами, а с памятью
    get_next_line(fd, &line);
    printf("%s\n", line);
    get_next_line(fd, &line);
    printf("%s\n", line);\
	get_next_line(fd, &line);
    printf("%s\n", line);

    //while (get_next_line(4, &line)) //в цикле пока есть, что читать. Передаем адрес, чтобы запись изменененного
    // значения шла из функции уже сюда в main
}