#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <wchar.h>

typedef struct s_data
{

    // Characters printed before and after % //

    int         printed_char_counter;

    // Start and residuals of the ftm  //

    char        *f_s;
    char        *f_r;

    /*------- All the fields -------*/

    int         grp;
    int         wtp;            // Wtp =  What to print? //  by default it is 1 = string  || 2 = string unicode || 3 = char || 4 = char unicode || 5 = pointer
    char        spe;

    // [1] Flags //

    char        *fla;
    int         fla_len;

    // [2] Width //

    char        *wid_raw;
    int         wid_int;
    int         wid_gap;

    // [3] Precision //

    char        *pre_raw;
    int         pre_int;

    // [4] Length //

    char        *len;


    /*------- Store all the argument types -------*/

    int          arg_char_conv;             // only for normal character!
    unsigned int arg_uni_char_conv;         // only for unicode character!
    int          arg_atoi_int;
    char         *arg_str_conv;             // only for normal string!
    unsigned int *arg_uni_str_conv;         // only for unicode string!
    int	         arg_len;

    /*------- Args for group1 (s_S_c_C) -------*/

    char                    *a_g1_s_hs;
    int                     a_g1_c_hc;
    unsigned int            *a_g1_S_ls;
    unsigned int            a_g1_C_lc;
    void                    *a_g1_p;


    /*------- Args for group2 (o_O_x_X_u_U) -------*/

    unsigned int            a_g2_o_u_x_X;
    unsigned char           a_g2_hh;
    unsigned long int       a_g2_O_U_l;
    unsigned short          a_g2_h;
    unsigned long long int  a_g2_ll;
    uintmax_t               a_g2_j;
    size_t                  a_g2_z;


    /*-------  Args for group3 (d_D_i) -------*/

    int                     a_g3_h;
    signed char             a_g3_hh;
    long int                a_g3_D_l;
    long long int           a_g3_ll;
    intmax_t                a_g3_j;
    size_t                  a_g3_z;


}              t_data;



    /*-------  Cleaning structures functions -------*/


    /*-------  Library functions -------*/


void	*ft_memset(void *dst, int c, size_t n);
int	    ft_atoi(const char *str);
int		ft_isdigit(int a);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *dst, const char *src);
char	*ft_strdup(const char *s1);
size_t		ft_strlen(const char *str);
char	*ft_strnew(size_t size);
int    ft_printf(char* fmt,...);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_isalpha(int a);




    /*-------  PROCESSES -------*/

/* Step 0: Set Structure element to zero */

void ft_set_everything_to_zero(t_data *a);

    /* Step 1: Find '%' */

int	    ft_find_percent_glued_percent(char *s);
int	    ft_find_percent_to_percent(char *s);
int	    ft_find_percent_to_wrong_type(char *s);
int	    ft_find_percent_is_alone(char *s);

char  *ft_print_percent_glued_percent(char *s, t_data *a);
char  *ft_print_percent_to_percent(char *s, t_data *a);
char  *ft_print_percent_to_wrong_type(char *s);


char	*ft_find_spe(char *s);

    /* Step 2: Find appropriate group ---  group 1 ===> // s_S_c_C_p) || for group 2 ===> // o_O_x_X_u_U || for group 3 ===> // d_D_i */

void    ft_find_group(char spe, t_data *a);

    /* Step 3: Store the entire format in struct */

int	    ft_find_format(char *s, char c, t_data *a);

    /* Step 4: From the format, find and store each separate fields in struct */

void    ft_find_all_fields(t_data *a, char c);

char	*ft_find_fla(t_data *a);
char	*ft_find_wid(t_data *a);
char	*ft_find_pre(t_data *a);
char	*ft_find_len(t_data *a);

char    *ft_search_fla(t_data *a);
char    *ft_search_wid(t_data *a);
char    *ft_search_pre(t_data *a);
char    *ft_search_len(t_data *a);

char	*ft_cpy_to_char(char *s, char c);

    /* Step 5: Validate the content for each fields */

int     ft_verify_all_fields(t_data *a, char c);

    /* Step 6: Get the right arg type in struct */

void    ft_get_arg_type(t_data *a, va_list arg);
char	*ft_itoa_base_unsigned(unsigned long long value, int base); // !!! this function was taken from the internet - I must do it again before submitting the project
char	*ft_itoa_base_signed(signed long long value, int base); // !!! this function was taken from the internet - I must do it again before submitting the project

    /* Step 7: Find the lengths of different args */

void    ft_find_arg_len(t_data *a);

    /* Step 8: Apply Field */

void    ft_apply_fields(t_data *a);
void    ft_apply_precision(t_data *a);
char	*ft_cpy_to_nb(char *dst, const char *src, size_t start, int n);

void    ft_apply_pre_grp1(t_data *a);

    /* Step 9: Count everything has been printed (selected based on the type) */

void    ft_count_printed_characters(t_data *a);

#endif
