/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:28:29 by evocatur          #+#    #+#             */
/*   Updated: 2024/04/10 16:12:21 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *nptr);
char		*ft_itoa(int temp);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
void		ft_bzero(void *s, size_t n);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_tolower(int ch);
int			ft_toupper(int ch);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memchr(const void *str, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
const char	*ft_strnstr(const char *X, const char *Y, size_t len);
char		*ft_strrchr(const char *str, int c);
char		*ft_strchr(const char *str, int ch);
char		*ft_substr(char const *s, unsigned int start, unsigned int len);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s);
char		**ft_split(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
int			ft_lstsize(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void*));
int			ft_isprint(int c);
int			ft_printf(const char *format, ...);
int			printstring(char *s);
int			printdigit(int n);
int			printchars(int c);
int			flag(const char *str, va_list ap);
char		*ft_uitoa(unsigned int temp);
char		*ft_itoa(int temp);
int			convertunsigned(int n);
void		reverse(char *s);
int			string_length(char *pointer);
int			print_address_hex(void *p0);
char		hex_digit(int v);
int			ft_print_ptr(unsigned long long ptr);
void		ft_put_ptr(uintptr_t num);
int			ft_ptr_len(uintptr_t num);
int			printhex(const char *str, va_list ap);
int			flag_sharp(const char *str, unsigned int j);
int			flag_space(const char *s, va_list ap);
int			flag_plus(const char *str, va_list ap);
int			ft_len_hex(unsigned int num);
void		ft_put_hex(unsigned int num, char c);
char		*get_next_line(int fd);
char		*ft_statstr(int fd, char *statstr);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char *backup, char *buff);
char		*ft_backup(char *backup);
char		*ft_get_line(char *backup);
const char	*ft_strstr(const char *X, const char *Y);
bool		is_onstr(const char *str, int ch);
char		*ft_strncpy(char *dest, const char *src, size_t n);
void		free_matrix(char **matrix);
void		safe_free(void *_ptr);
size_t		matrix_height(char **matrix);
size_t		matrix_width(char **matrix);
bool		is_all_digits(const char *str);
bool		streq(char *str1, char *str2);
bool		is_spaces(char c);
bool		only_spaces(const char *str);
void		print_matrix(char **matrix);
#endif