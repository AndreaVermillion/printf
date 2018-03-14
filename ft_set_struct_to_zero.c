#include "printf.h"

void ft_set_everything_to_zero(t_data *a)
{
    a->f_s = NULL; // char *
    a->f_r = NULL; // char *
    a->grp = 0; // int
    a->spe = '0'; //char
    a->wtp = 1;
    a->fla = NULL; //char        *
    a->fla_len = 0; // int
    a->wid_raw = NULL;  // char *
    a->wid_int = 0;    // int
    a->wid_gap = 0;    // int
    a->pre_raw = NULL;   // char *
    a->pre_int = 0;    // int
    a->len = NULL;       // char *
    a->arg_char_conv = 0;  // int
    a->arg_uni_char_conv = 0;    // unsigned int
    a->arg_atoi_int = 1;          // int
    a->arg_str_conv = NULL;             // char *
    a->arg_uni_str_conv = 0;         // unsigned int
    a->arg_len = 0;                   // int
    a->a_g1_s_hs = NULL;     // char *
    a->a_g1_c_hc = 0;      // int
    a->a_g1_S_ls = NULL;     // unsigned int *
    a->a_g1_C_lc = 0;      // unsigned int
    a->a_g1_p = NULL;        // void *
    a->a_g2_o_u_x_X = 0;   // unsigned int
    a->a_g2_hh = 0;        // unsgined char
    a->a_g2_O_U_l = 0;     // unsinged long
    a->a_g2_h = 0;         // unsigned short
    a->a_g2_ll = 0;        // unsgihed long long int
    a->a_g2_j = 0;         // unintmax_t
    a->a_g2_z = 0;         // sitze t
    a->a_g3_h = 0;     // int
    a->a_g3_hh = 0;    //signed char
    a->a_g3_D_l = 0;       // long int
    a->a_g3_ll = 0;        // long long int
    a->a_g3_j = 0;         // intmax_t
    a->a_g3_z = 0;         // size_t
}
