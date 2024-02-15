/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiyapan <npiyapan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:22:31 by npiyapan          #+#    #+#             */
/*   Updated: 2024/01/03 17:18:28 by npiyapan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct s_swap
{
	int		i;
	int		j;
	int		k;
	int		sign;
	int		ans;
	int		error;
	int		len;
	int		len2;
	int		len3;
	int		tmp_len;
	int		mul;
	long	res;
	char	**tmp;
	char	**tmp2;
	char	*tmp3;
}	t_swap;

typedef struct s_list_int
{
	int					val;
	char				name;
	long				index;
	long				target_node;
	int					diff_val;
	long				max_val_index;
	long				min_val_index;
	struct s_list_int	*next;
	struct s_list_int	*prev;
	int					direction;
}	t_list_int;

typedef struct s_parse
{
	t_list_int	*new_l;
	char		**tmp;
	int			i;
	int			j;
	int			error;
	long		ans;
	long		ind;
}	t_parse;

typedef struct s_tmp
{
	t_list_int	*tmp_a;
	t_list_int	*tmp_b;
	t_list_int	*stack_a;
	t_list_int	*stack_b;
	long		max_ind_a;
	long		max_ind_b;
	long		min_ind_a;
	long		min_ind_b;
	long		min_index;
	long		minval;
	long		push_index;
	long		min_cost;
	long		i;
	long		tmp_c;
	long		mean_a;
	long		mean_b;
	long		max;
	long		min;
	int			fin;
	int			size;
	int			size_a;
	int			size_b;
	int			found;
	int			tmp_diff;
	int			cost;
	int			cost_a;
	int			cost_b;
	int			new_cost;
	int			do_err;
}	t_tmp;

typedef struct s_rotate
{
	int			n;
	t_list_int	*head_a;
	t_list_int	*tail_a;
	t_list_int	*head_b;
	t_list_int	*tail_b;
}	t_rotate;

typedef struct s_operate
{
	long		i;
	long		max_val;
	long		min_val;
	long		mean;
	t_list_int	*tmp;
}	t_operate;

typedef struct s_do_rev
{
	t_list_int	*tmp_a;
	long		i;
	long		times_a;
	long		times_b;
}	t_do_rev;

t_list_int	*ft_lstnew_int(int val);
t_list_int	*ft_lstlast_int(t_list_int *lst);

void		ft_lstadd_front_int(t_list_int **lst, t_list_int *new);
void		ft_lstadd_back_int(t_list_int **lst, t_list_int *new);
void		free_list(t_list_int *stack);
void		ft_lstclear_int(t_list_int *lst);
void		swap(t_list_int **stack, int prnt);
void		sort_three(t_list_int **stackA);
void		rotate(t_list_int **stack, int times, int print);
void		rotate_both(t_list_int **stackA, t_list_int **stackB, int my_times);
void		reverse_rotate(t_list_int **stack, int my_times, int print);
void		re_rotate_both(t_list_int **stackA, t_list_int **stackB, int my_t);
void		make_min_first(t_list_int **stack, long index);
void		re_index(t_list_int **stack, long *maxInd, long *minInd);
void		find_tar_node(t_list_int **stackA, t_list_int **stackB, long maxIn);
void		find_min_index(t_list_int **stackA, long *index);
void		target_to_top(t_list_int **stack, long index, long size);
void		target_to_top2(t_list_int **stackA, t_list_int **stackB, long ind);
void		print_stack(t_list_int **stack);
void		print_operation(char *operate, char stack_name);
void		print_target_node(t_list_int **stack);
void		min_to_top(t_list_int **stack, long index);
void		ss(t_list_int **stackA, t_list_int **stackB);
void		free_all_list(t_list_int **stackA, t_list_int **stackB);
void		target_top_b(t_tmp *s, t_list_int **stack_a, t_list_int **stack_b);
void		check_diff_a(t_tmp *s, long maxIndex);
void		set_stack(t_list_int **stackA, t_list_int **stackB, t_rotate *s);
void		dual_rotate(t_list_int **stackA, t_list_int **stackB, long index);
void		set1(t_operate *s);
void		set_calcost(t_tmp *s);
void		do_reverse(t_list_int **stackA, t_list_int **stackB, long index);
void		do_reverse2(t_list_int **stackA, t_list_int **stackB, long index);
void		to_top(t_list_int **stackA, t_list_int **stackB, long index);
void		dual_reverse(t_list_int **stackA, t_list_int **stackB, long index);
void		set_push_b(t_tmp *s, t_list_int **stackA, t_list_int **stackB);
void		checker_rotate(t_tmp *s, t_list_int **stack);

int			push_to_a(t_list_int **stack_a, t_list_int **stack_b, long *min_a);
int			push_to_b(t_list_int **stack_a, t_list_int **stack_b, long *max_b);
int			push(t_list_int **src, t_list_int **dest);
int			cal_cost(t_list_int **stackA, t_list_int **stackB, long *tar_ind);
int			parse_int(char **argv, t_list_int **stack);
int			ft_lstsize_int(t_list_int **st);
int			check_digit(char **tmp);
int			check_digit_all(int argc, char **argv);
int			check_dup(t_list_int **stackA);
int			is_sort(t_list_int **stackA);
int			ft_atoi_2(const char *str, int *error);
int			check_only_one_sign(char **tmp, t_swap *s);
int			check_swap(char *line, t_list_int **stack_a, t_list_int **stack_b);
int			check_ro(char *line, t_list_int **stack_a, t_list_int **stack_b);
int			check_push(char *line, t_list_int **stack_a, t_list_int **stack_b);
int			check_rev(char *line, t_list_int **stack_a, t_list_int **stack_b);
int			set_error_checker(t_tmp *s);
int			display_err(char *line);
int			set_err(int *err);

#endif