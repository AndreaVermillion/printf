/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancardi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 16:57:27 by ancardi           #+#    #+#             */
/*   Updated: 2018/03/30 21:00:22 by ancardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define IS_LETTER(x) ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
# define IS_MODIFIER(x) (x == 'h' || x == 'l' || x == 'j' || x == 'z')

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <wchar.h>
# include <limits.h>
# include <locale.h>

typedef struct				s_data
{
	int						printed_char_counter;
	char					*f_s;
	char					*f_r;
	char					wrong_type;
	int						grp;
	int						wtp;
	char					spe;
	char					*fla;
	int						fla_len;
	char					*wid_raw;
	int						wid_int;
	int						wid_gap;
	char					*pre_raw;
	int						pre_int;
	char					*len;
	int						len_len;
	int						arg_char_conv;
	unsigned int			arg_uni_char_conv;
	int						arg_atoi_int;
	char					*arg_str_conv;
	unsigned int			*arg_uni_str_conv;
	int						arg_len;
	char					*a_g1_s_hs;
	int						a_g1_c_hc;
	unsigned int			*a_g1_s_ls;
	unsigned int			a_g1_c_lc;
	void					*a_g1_p;
	unsigned int			a_g2_o_u_x;
	unsigned char			a_g2_hh;
	unsigned long int		a_g2_o_u_l;
	unsigned short			a_g2_h;
	unsigned long long int	a_g2_ll;
	uintmax_t				a_g2_j;
	size_t					a_g2_z;
	int						a_g3_h;
	signed char				a_g3_hh;
	long int				a_g3_d_l;
	long long int			a_g3_ll;
	intmax_t				a_g3_j;
	size_t					a_g3_z;
}							t_data;

int							ft_atoi(const char *str);
int							ft_isdigit(int a);
void						*ft_memset(void *dst, int c, size_t n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
char						*ft_strchr(const char *s, int c);
int							ft_strcmp(const char *dst, const char *src);
char						*ft_strcpy(char *dst, const char *src);
char						*ft_strdup(const char *s1);
size_t						ft_strlen(const char *str);
char						*ft_strncpy(char *dst, const char *src, size_t n);
char						*ft_strnew(size_t size);
char						*ft_itoa_base_unsigned(unsigned long long int
							n, int base);
char						*ft_itoa_base_signed(signed long long int
							n, int base);
void						ft_memdel (void **ap);
int							ft_check_if_there_is_a_char(char *str);
void						ft_set_everything_to_zero(t_data *a);
int							ft_find_percent_with_percent(char *s);
int							ft_find_percent_to_percent(char *s);
int							ft_find_percent_is_alone(char *s);
int							ft_verify_all_wid(t_data *a);
char						*ft_find_spe(char *s, t_data *a, int i);
void						ft_verify_fla_group2_array_part2(char **checker,
							char *array, t_data *a);
void						ft_verify_fla_group2_array_part1(char
							*array, t_data *a);
int							ft_verify_fla_group2(t_data *a, char c);
int							ft_verify_fla_group1(t_data *a);
void						ft_verify_fla_group3_array_part2(char
							**checker, char *array,
							t_data *a);
void						ft_verify_fla_group3_array_part1(char
							*array, t_data *a);
int							ft_verify_fla_group3(t_data *a);
void						ft_find_group(t_data *a);
int							ft_find_format(char *s, char c, t_data *a);
void						ft_find_all_fields(t_data *a, char c);
char						*ft_find_fla(t_data *a, char c);
char						*ft_find_wid(t_data *a, char c);
char						*ft_find_pre(t_data *a, char c);
char						*ft_find_len(t_data *a, char c);
char						*ft_search_fla(t_data *a, char c);
char						*ft_search_wid(t_data *a, char c);
char						*ft_search_pre(t_data *a, char c);
char						*ft_search_len(t_data *a, char c);
char						*ft_cpy_to_char(char *s, char c);
int							ft_verify_all_fields(t_data *a, char c);
void						ft_get_arg_type_len_len_0(t_data *a, va_list arg);
void						ft_get_arg_type_len_len_1(t_data *a, va_list arg);
void						ft_get_arg_type_len_len_2(t_data *a, va_list arg);
void						ft_select_args_group1_len_1(t_data *a, va_list arg);
void						ft_select_args_group1_len_0(t_data *a, va_list arg);
int							ft_find_arg_len_string_unicode(t_data *a);
int							ft_find_arg_len_char_unicode(t_data *a);
void						ft_select_args_group1_len_0_s(t_data
							*a, va_list arg);
void						ft_get_arg_type(t_data *a, va_list arg);
void						ft_select_args_group1_len_0_c(t_data
							*a, va_list arg);
void						ft_select_args_group1_len_0_s(t_data
							*a, va_list arg);
void						ft_select_args_group1_len_2(t_data *a, va_list arg);
void						ft_select_args_group3_len_2(t_data *a, va_list arg);
void						ft_select_args_group3_len_1(t_data *a, va_list arg);
void						ft_select_args_group3_len_0(t_data *a, va_list arg);
void						ft_select_args_group2_len_0(t_data *a, va_list arg);
void						ft_select_args_group2_len_1(t_data *a, va_list arg);
void						ft_select_args_group2_len_2(t_data *a, va_list arg);
void						ft_apply_fields(t_data *a);
void						ft_apply_pre_grp1(t_data *a);
void						ft_apply_pre_grp2(t_data *a);
void						ft_apply_pre_grp3(t_data *a);
void						ft_apply_pre_grp2_grp3_positive_value_no_flags(
							t_data *a);
void						ft_apply_precision(t_data *a);
void						ft_apply_width_grp_1(t_data *a);
void						ft_apply_width_grp_1_p(t_data *a);
void						ft_apply_width_grp_1_c(t_data *a);
void						ft_apply_width_grp_2(t_data *a, int i);
void						ft_apply_width_grp_3(t_data *a);
void						ft_apply_special_0_wid_bigger_than_1_part_2(t_data
							*a, char *temp);
void						ft_apply_special_0_conditions_wid_bigger_1_part_1(
							t_data *a, char *temp);
void						ft_apply_special_0_wid_smaller_to_1(t_data *a);
void						ft_apply_special_0_wid_bigger_than_1(t_data *a);
void						ft_apply_pre_grp2_hash_x_zero_condition(t_data *a);
void						ft_apply_pre_grp2_hash_o_zero_condition(t_data *a);
void						ft_apply_special_zero_conditions_for_c(t_data *a);
void						ft_apply_special_zero_conditions_for_s(t_data *a);
void						ft_apply_special_zero_conditions(t_data *a);
void						ft_find_diff_arg_len_vs_wid_vs_pre(t_data *a);
void						ft_apply_width(t_data *a);
void						ft_apply_width_lc_c(t_data *a);
void						ft_apply_width_ls_s(t_data *a);
void						ft_apply_width_pre_small_arg_len(t_data *a);
void						ft_apply_fields_wtp_1(t_data *a);
void						ft_apply_fields_wtp_2(t_data *a);
void						ft_apply_fields_wtp_4(t_data *a);
int							ft_len_to_char(char *s, char c);
char						*ft_cpy_to_nb(char *dst,
							const char *src, size_t start, int n);
int							ft_find_nb_prtble_bytes(
							unsigned int *tab, int size);
int							ft_find_nb_prtble_char(
							unsigned int *tab, int size);
void						ft_unicode_convert(unsigned int nb);
void						ft_print_per_wr_type_no_flag(t_data *a, int i);
void						ft_print_per_wr_type_flag_only_0(t_data *a, int i);
void						ft_print_per_wr_type_flag_mins_0(t_data *a, int i);
void						ft_print_per_wr_type_flag_minus(t_data *a, int i);
void						ft_print_per_wr_type_with_flag(
							char *temp, t_data *a, int i);
char						*ft_print_per_to_wr_type(
							char *s, t_data *a, char c);
char						*ft_print_percent_with_percent(char *s, t_data *a);
void						ft_print_no_format_characters(
							t_data *a, char **temp);

#endif
