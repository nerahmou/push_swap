/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libft.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: nerahmou <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 13:51:21 by nerahmou     #+#   ##    ##    #+#       */
/*   Updated: 2018/03/01 14:56:40 by nerahmou    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 32
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <wchar.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);

void				ft_bzero(void *s, size_t n);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
char				*ft_itoa_base_upp(int n, int base);
char				*ft_itoa_base_low(int n, int base);

void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new_elem);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

int					ft_putchar(char c);
int					ft_putwchar(wchar_t c);
int					ft_putstr(const char *str);
int					ft_putwstr(const wchar_t *str);
void				ft_putnbr(long n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(wchar_t c, int fd);
void				ft_putstr_fd(const char *str, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);

void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);

void				ft_swap(int *a, int *b);
size_t				ft_list_size(t_list *list);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_sqrt(int nb);
void				ft_lstdisplay_str(t_list *list);
void				ft_lstpushback_str(t_list **list, char *str);
void				ft_lstclear(void *content, size_t size);
size_t				ft_char_pos(char *str, char c);
long				ft_abs(long nbr);
int					ft_intlen(long nbr, int base);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_ischar(char c, char to_find);
int					ft_countwords(char *str, char c);

int					get_next_line(const int fd, char **line);

void				ft_putnbr_base(uintmax_t nbr, char *base, size_t baselen);
int					ft_putwchar(wchar_t c);
int					ft_putwstr(const wchar_t *str);
int					ft_wstrlen(const wchar_t *str);
int					ft_wcharlen(wchar_t c);

#endif
