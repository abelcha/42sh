/*
** wildcards.c for sh in /home/chalie_a/rendu/PSU_2013_minishell2/globbing
** 
** Made by chalie_a
** Login   <chalie_a@epitech.eu>
** 
** Started on  Sun Mar  9 22:42:13 2014 chalie_a
** Last update Sun Mar  9 22:42:13 2014 chalie_a
*/

#include	<sys/stat.h>
#include	<stdlib.h>
#include	<dirent.h>
#include	<unistd.h>
#include	"mysh.h"
#include	"my_strings.h"
#include	"globbing.h"

static int		match(char *s1, char *s2)
{
  if (*s1 != '\0' && *s2 == '*')
    return (match(s1 + 1, s2) || match(s1, s2 + 1));
  if (*s1 == '\0' && *s2 == '*')
    return (match(s1, s2 + 1));
  if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
    return (match(s1 + 1, s2 + 1));
  if (*s1 == *s2 && *s1 == '\0' && *s2 == '\0')
    return (1);
  return (0);
}

static char		**find_matches(char *cmp, char *path,
				       char **stock, int i)
{
  DIR			*dirp;
  struct dirent		*d;
  char			**tmp;
  int			x;

  x = -1;
  if ((dirp = opendir(path)) == NULL)
    return (stock);
  if (!(tmp = malloc(MEM_POOL * sizeof(char *))))
    return (stock);
  while ((d = readdir(dirp)))
    if (match(d->d_name, cmp) && d->d_name[0] != '.'  && ++x < MEM_POOL - 10)
      tmp[x] = my_strdup(d->d_name);
  tmp[x + 1] = NULL;
  free(cmp);
  free(path);
  closedir(dirp);
  if (x == -1 && x_free(tmp))
    return (stock);
  return (realmove(stock, tmp, i, x));
}

char		**wildcard_handler(char **stock, int i)
{
  int		s;
  char		*path;
  char		*cmp;

  s = my_strlen(stock[i]);
  while (stock[i][s] != '/' && s > 0)
    --s;
  if (i == 0 || stock[i][s] != '/')
    {
      cmp = my_strdup(stock[i]);
      path = my_strdup("./");
    }
  else
    {
      path = my_strdup(stock[i]);
      path[s + 1] = 0;
      cmp = my_strdup(&stock[i][s + 1]);
    }
  return (find_matches(cmp, path, stock, i));
}
