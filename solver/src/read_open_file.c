/*
** EPITECH PROJECT, 2021
** read_open_file
** File description:
**
*/

#include <solver.h>

char *read_file(int fd, char const *path)
{
    struct stat buf;
    char *string;

    stat(path, &buf);
    string = malloc(sizeof(char)*(buf.st_size+1));

    if (!string)
        perror("malloc");

    if (read(fd, string, buf.st_size) == -1) {
        write(2, "maze can't be read\n", 18);
        exit(84);
    }

    string[buf.st_size] = '\0';

    return string;
}

char *open_read_file(char const *filepath)
{
    char *string;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        write(2, "maze not found\n", 14);
        exit(84);
    }

    string = read_file(fd, filepath);

    close(fd);

    return string;
}