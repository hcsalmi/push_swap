/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsalmi <lsalmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:04:07 by lsalmi            #+#    #+#             */
/*   Updated: 2022/05/19 18:04:14 by lsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <unistd.h>
# include <stdarg.h>

//Regular colours
# define BLACK "\e[0;30m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[0;33m"
# define BLUE "\e[0;34m"
# define MAG "\e[0;35m"
# define CYAN "\e[0;36m"
# define WHITE "\e[0;37m"

//Regular colours in bold
# define BBLACK "\e[1;30m"
# define BRED "\e[1;31m"
# define BGREEN "\e[1;32m"
# define BYELLOW "\e[1;33m"
# define BBLUE "\e[1;34m"
# define BMAG "\e[1;35m"
# define BCYAN "\e[1;36m"
# define BWHITE "\e[1;37m"

//High intensity colours
# define HIBLACK "\e[0;90m"
# define HIRED "\e[0;91m"
# define HIGREEN "\e[0;92m"
# define HIYELLOW "\e[0;93m"
# define HIBLUE "\e[0;94m"
# define HIMAG "\e[0;95m"
# define HICYAN "\e[0;96m"
# define HIWHITE "\e[0;97m"
# define COLRESET "\e[0m"

//High intensity colours in bold
# define BHIBLACK "\e[1;90m"
# define BHIRED "\e[1;91m"
# define BHIGREEN "\e[1;92m"
# define BHIYELLOW "\e[1;93m"
# define BHIBLUE "\e[1;94m"
# define BHIMAG "\e[1;95m"
# define BHICYAN "\e[1;96m"
# define BHIWHITE "\e[1;97m"

/*
Struct includes the content as string and its accompanying length variable
(content_len), two pointers and a flag to indicate whether the node is
the first one or not. There will be as many structs created as there are
segments to be printed. Variable irreg_len is not boolean.
It is used when content length cannot be determined using ft_strlen().
With a value of -1, no node is created.
*/
typedef struct s_data
{
	char			*content;
	int				irreg_len;
	int				head_flag;
	unsigned long	content_len;
	struct s_data	*head;
	struct s_data	*next;
}				t_data;

typedef struct s_options
{
	int				hash;
	int				zero;
	int				dash;
	int				plus;
	int				space;
	int				percent;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				l_caps;
	int				is_neg;
	int				edge_case_len;
	long long		value;
	long double		float_value;
	int				width;
	int				precision;
	int				preci_f;
	int				preci_original;
	int				rounding;
	int				specifier;
	int				base;
	char			conversion;
	int				uppercase;
	unsigned long	str_len;
	int				no_precision;
	int				no_width;
	int				no_flags;
	int				pair_found;
	int				zero_padded;
	int				space_padded;
	int				space_added;
	int				added_0x;
	int				sign_added;
	int				inf_nan;
	int				nan;
}				t_options;

void		add_0x_to_address(char **content, t_options *options);
void		apply_dot(char **content);
void		apply_padding_conditions_di(char **content, char **temp, size_t len,
				t_options *options);
void		apply_precision_dioux(t_options *options, char **content);
int			apply_prefix_oux(va_list ap, t_options *options);
char		*apply_sign(t_options *options, char **content);
void		apply_sign_conditions_di(char **content, t_options *options);
void		apply_space_conditions_di(char **content, t_options *options);
void		apply_space_di(char **content, t_options *options);
void		apply_sign_conditions_f(char **content, t_options *options);
void		apply_space_conditions_f(char **content, t_options *options);
void		apply_width_cs(t_options *options, char **content);
void		apply_width_di(t_options *options, char **content);
void		apply_width_oux(t_options *options, char **content);
int			check_conversion(unsigned long *offset, char **content, va_list ap,
				t_options *options);
int			check_inf_nan(t_options *options);
int			check_preci_limits_f(t_options *options);
void		check_zero_edge_case(t_options *options, char **content);
int			create_node_hub(int *head_flag, t_data **head, char **content,
				int null_flag);
void		dash_flag_joining_rules(t_options *options, char **content,
				char **new_content, char *temp);
long double	determine_float_num(t_options *options);
void		determine_padding_di_f(t_options *options, char **temp, size_t len,
				char **content);
void		edge_case_add_space(t_options *options, char **content);
void		error_handling(int code);
void		find_end_of_dec_array(int *len, char *dec_array);
void		flag_overrides(t_options *options);
void		free_and_null_content(char **content);
void		free_whole_list(t_data *head);
char		*ft_create_pad_str(size_t len, char c);
char		*ft_itoa_base(unsigned long n, int base, int uppercase);
int			ft_printf(const char *format, ...);
char		*ft_strndup(const char *s1, size_t len, unsigned long start);
int			handle_c(char **content, va_list ap, t_options *options);
int			handle_di(char **content, va_list ap, t_options *options);
int			handle_f(char **content, va_list ap, t_options *options);
int			handle_o(char **content, va_list ap, t_options *options);
int			handle_p(char **content, va_list ap, t_options *options);
int			handle_prc(const char *format, unsigned long *offset,
				char **content);
int			handle_s(char **content, va_list ap, t_options *options);
int			handle_u(char **content, va_list ap, t_options *options);
int			handle_x(char **content, va_list ap, t_options *options);
void		initialize_flags(t_options *options);
void		initialize_head(t_data **head, char *content, int irreg_len,
				int *flag);
void		initialize_node(t_data *new, t_data *head);
void		initialize_options(t_options *options);
void		initialize_pointers_f(char	**int_str, char	**new_content,
				char **temp);
void		initialize_variables(char **content, int *flag, int *irreg_len);
void		join_int_and_decimal_part(t_options *options, char **content,
				char *int_str, char *float_str);
void		join_strings_cs(t_options *options, char **content, char **temp,
				char **new_content);
int			lf_rounding_edge_case(long double n, int rounding,
				t_options *options);
int			long_double_to_str(long double n, char *dec_array,
				t_options *options);
int			max_width_check(t_options *options);
void		multiply_temp(long double *temp, t_options *options);
void		null_char_exception(t_options *options, char **new_content,
				char **temp, size_t len);
int			options_hub(const char *format, unsigned long *offset,
				char **content, va_list ap);
void		percent_char_with_zero_flag(t_options *options, char **content,
				char **new_content, char **temp);
void		precision_to_str(const char *format, unsigned long *offset,
				char *num_string);
int			print_list(t_data *node);
void		regular_case_add_sign(t_options *options, char **content);
int			save_conversion_type(const char *format, unsigned long *offset,
				t_options *options);
void		sign_conditions_di(char **content, t_options *options);
void		space_conditions_di(char **content, t_options *options);
void		string_not_printed(t_options *options, char **content);
char		*strjoin_null_char(char const *str, t_options *options, size_t len);
void		switch_zero_to_sign(char **new_content, t_options *options);
void		switch_zero_to_space(char **new_content, t_options *options);
void		round_up_int_part(char **content, t_options *options);
void		rounding_int_precision_zero(char **content, t_options *options,
				int ret);
void		track_percentage_pairs(t_options *options, char **content);
void		value_is_inf(char **content, t_options *options, int ret);
void		value_is_nan(char **content, t_options *options);

#endif
