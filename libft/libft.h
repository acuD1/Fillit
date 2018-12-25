/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsciand <arsciand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 11:08:12 by arsciand          #+#    #+#             */
/*   Updated: 2018/12/25 14:32:18 by arsciand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

/*
**		Structures
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
**		Part I
*/

int					ft_atoi(char const *s);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memchr(void const *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
void				*ft_memccpy(void *dst, void const *s, int c, size_t n);
void				*ft_memcpy(void *dst, void const *s, size_t n);
void				*ft_memmove(void *dst, void const *s, size_t len);
void				*ft_memset(void *s, int c, size_t len);
char				*ft_strcat(char *dst, char const *s);
char				*ft_strchr(char const *s, int c);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, char const *s);
char				*ft_strdup(char const *s);
size_t				ft_strlcat(char *dst, char const *s, size_t len);
size_t				ft_strlen(char const *s);
char				*ft_strncat(char *dst, char const *s, size_t n);
int					ft_strncmp(char const *s1, char const *s2, size_t n);
char				*ft_strncpy(char *dst, char const *s, size_t n);
char				*ft_strnstr(char const *s, char const *ndl, size_t len);
char				*ft_strstr(char const *s, char const *ndl);
char				*ft_strrchr(char const *s, int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**		Part II
*/

char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int nb);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
void				ft_strclr(char *s);
void				ft_strdel(char **as);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				**ft_strsplit(char const *s, char c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);

/*
**		BONUS
*/

void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstpushback(t_list **begin_list, t_list *new);

/*
**		My fonctions
*/

int					ft_isspace(int c);
t_list				*ft_lstfind(t_list *lst, void *content_ref, int (*cmp)());
void				ft_lstmerge(t_list **alst1, t_list *alst2);
int					ft_lstlen(t_list *lst);
char				*ft_strrev(char *s);

#endif
