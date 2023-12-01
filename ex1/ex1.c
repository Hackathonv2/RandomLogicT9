/*
** EPITECH PROJECT, 2023
** RandomLogicT9
** File description:
** ex1
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int check_file(char *file_name)
{
    FILE *file = fopen(file_name, "r");
        if (file != NULL) {
            close(file);
            return 0;
        } else {
            close(file);
            return 1;
        }
}

int check_access(char *file_name)
{
    if (access(file_name, F_OK) != -1) {
        return check_file(file_name);
    } else {
        return 1;
    }
}

int check_error(int argc, char **argv)
{
    if (argc != 2) 
        return 1;
    return check_access(argv[1]);
}

int power_after(int month, int power)
{
    for (int i = 0; i < month; i += 1) {
        if (power % 3 == 0)
            power /= 3;
        else if (power % 2 == 0)
            power /= 2;
        else
            power -= 1;
    }
    return power;
}

int my_get_number(char *number)
{
    int num_result = 0;
    int absolute_value = 1;
    for (int i = 0; number[i] != '\0'; i += 1) {
        if (number[i] == '-')
            absolute_value *= -1;
        else {
            num_result *= 10;
            num_result += number[i] - 48;
        }
    }
    return num_result;
}

char *get_content(char *file_name)
{
    FILE *file = fopen(file_name, "r");
    struct stat file_stat;
    stat(&file_stat, file_name);
    char *file_content = (char *)malloc(file_stat.st_size + 1);
    fread(file_content, 1, file_stat.st_size, file);
    file_content[file_stat.st_size] = '\0';
    return file_content;
}

int main(int argc, char **argv)
{
    if (check_error(argc, argv) == 1)
        return 84;
    char *file_content = get_content(argv[1]);
    int base_power = my_get_number(file_content);
    printf("%d\n", power_after(4, base_power));
    return 0;
}