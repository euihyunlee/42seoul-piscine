/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euihlee <euihlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:18:26 by euihlee           #+#    #+#             */
/*   Updated: 2022/09/11 22:55:56 by jpark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define SUCCESS 1
# define ERROR 0
# define DICT "numbers.dict"

typedef struct s_ainfo
{
	int	big_u;
	int	sm_u;
	int	str_i;
	int	idx;
	int	len;
	int	count;
}	t_ainfo;

typedef struct s_node
{
	char			*key;
	char			*val;
	struct s_node	*next;
}	t_node;

int		parse_dict(int fd1, int fd2, t_node **list);
char	*read_key(int fd1, int fd2, char *c);
int		skip_to_val(int fd1, int fd2, char *c);
char	*read_val(int fd1, int fd2, char *c);
void	trim_space(char *str, int is_space);

int		load(char *dict, t_node **list);
int		load_entry(char *key, char *val, t_node **list);
void	unload(t_node **list);

int		word_count(int len, char *str);
char	*ten_variation(char *n);
char	**unit_seperate(char *str);

int		str_len(char *str);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *src);

int		find_key_in_list(char *key, char *value, t_node *list);
void	print_value_in_list(t_node *list, int idx);

int		write_in_file(int fd, char *str, int len);
void	add_line_in_file(char *file, char *key, char *value);
void	rewrite_file(char *file, t_node *list);

#endif
