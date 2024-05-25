# ifndef MINISHELL_H
# define MINISHELL_H

# include <errno.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

/* gc.c */
typedef struct s_gc
{
	struct s_gc	*next;
	void			*data;
}					t_gc;

void				*gc_malloc(t_gc **gc, size_t size);
void				gc_push(t_gc **gc, void *data);
t_gc				*gc_init(void);
void				gc_clear(t_gc **gc);

int	len(char *s1);
int	count_words(char const *s1, char *sep);
char	**handle_null_malloc(char const *s, char *sep, t_gc **gc);
int	is_sep(char c, char *sep);
char	**ft_split(char const *s, char *sep, t_gc **gc);

#endif
