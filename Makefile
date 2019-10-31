# utils
KRED=\033[0;31m
KGRN=\033[0;32m
KYEL=\033[0;33m
KNRM=\033[0m
COUNTER = 0

define compile_obj
	@printf "$(KGRN)[ft_printf]$(KNRM) compile $(1)\n"
	$(CC) $(CFLAGS) $(INCLUDES) -c $(1) -o $(2)
	$(eval COUNTER=$(shell echo $$(($(COUNTER) + 1))))
endef

# compiler
CC = gcc

# lib name
NAME = libftprintf.a

# path
SRCDIR = srcs

INCDIR = includes

LIBDIR = libs

OBJDIR = objs

LIBFT_PATH = $(LIBDIR)/libft

LIBBIGINT_PATH = $(LIBDIR)/libbigint

LIBFIXEDPOINT_PATH = $(LIBDIR)/libfixedpoint

# compiler options
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./$(INCDIR)\
	-I ./$(LIBFT_PATH)/includes\
	-I ./$(LIBBIGINT_PATH)/includes\
	-I ./$(LIBFIXEDPOINT_PATH)/includes\

LIBS = -L . -lftprintf\
	-L ./$(LIBFT_PATH) -lft\
	-L ./$(LIBBIGINT_PATH) -lbigint\
	-L ./$(LIBFIXEDPOINT_PATH) -lfixedpoint\

# srcs
SRC_FT_PRINTF = ft_printf.c\

SRC_PARSE_TAGS = init_tags.c\
	flag.c\
	width.c\
	precision.c\
	length.c\

SRC_ARG_LENGTH = num_length.c\
	arg_d_length.c\
	arg_u_length.c\
	arg_f_length.c\
	arg_x_length.c\
	arg_o_length.c\
	arg_s_length.c\
	arg_c_length.c\
	arg_e_length.c\

SRC_ARG_SIGN = num_sign.c\
	arg_d_sign.c\
	arg_f_sign.c\
	arg_no_sign.c\

SRC_ARG_PREFIX = arg_o_prefix.c\
	arg_x_prefix.c\
	arg_p_prefix.c\
	arg_no_prefix.c\

SRC_ARG_LEADING_ZERO = arg_leading_zero.c\
	arg_o_leading_zero.c\
	arg_no_leading_zero.c\

SRC_BUFFER = buffer.c\

SRC_ARG_WRITE = int_write.c\
	double_write_int_part.c\
	double_write_fraction_part.c\
	double_write_scientific_parts.c\
	arg_d_write.c\
	arg_u_write.c\
	arg_f_write.c\
	arg_x_write.c\
	arg_upper_x_write.c\
	arg_o_write.c\
	arg_s_write.c\
	arg_c_write.c\
	arg_e_write.c\

SRC_PARSE_PERCENT = write_percent_format.c\
	parse_specifier.c\
	parse_percent.c\
	parse_d.c\
	parse_u.c\
	parse_f.c\
	parse_x.c\
	parse_upper_x.c\
	parse_o.c\
	parse_s.c\
	parse_c.c\
	parse_p.c\
	parse_e.c\
	float_utils.c\
	double_get_parts.c\
	double_get_scientific_parts.c\
	double_get_bcd_fraction_part.c\
	double_get_bcd_int_part.c\

# objs
OBJS = $(addprefix $(OBJDIR)/, $(SRC_FT_PRINTF:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PARSE_TAGS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_LENGTH:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_SIGN:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_PREFIX:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_LEADING_ZERO:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_BUFFER:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_WRITE:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_PARSE_PERCENT:.c=.o))

LIBFT_OBJS = ft_bzero.o\
	ft_extract_double.o\
	ft_extract_ldouble.o\
	ft_is_inf.o\
	ft_is_inf_l.o\
	ft_is_nan.o\
	ft_is_nan_l.o\
	ft_isdigit.o\
	ft_memdel.o\
	ft_memcpy.o\
	ft_memnegate.o\
	ft_memset.o\
	ft_memalloc.o\
	ft_pow.o\
	ft_strcpy.o\
	ft_strlen.o\
	ft_strcmp.o\
	ft_memcmp.o\
	ft_min_int.o\
	ft_max_int.o\
	ft_isalpha.o\
	ft_to_utf8.o\
	ft_utf8_byte_len.o\

LIBBIGINT_OBJS = bi_del.o\
	bi_memalloc.o\
	bi_init.o\
	bi_erase.o\
	bi_expand.o\
	bi_expand_at_least.o\
	bi_push.o\
	bi_copy.o\
	bi_abs_compare.o\
	bi_max_bit.o\
	bi_op_utils.o\
	bi_add_bi.o\
	bi_sub_bi.o\
	bi_update_occupied.o\
	bi_left_shift.o\
	bi_abs.o\
	bi_mod_n_pow_of_2_plus_1.o\
	bi_mod_n_pow_of_2_plus_1_utils.o\
	bi_array.o\
	bi_mul_bi.o\
	bi_right_shift.o\
	bi_get_bit.o\
	bi_set_bit.o\
	bi_double_dabble.o\
	bi_rev_double_dabble.o\
	bcd_len.o\
	bcd_get_digit.o\
	bcd_set_digit.o\
	bcd_rm_trailing_zero.o\
	bcd_iter.o\
	bcd_round.o\
	bcd_add_digit.o\

LIBFIXEDPOINT_OBJS = fxp_init.o\
	fxp_del.o\
	fxp_compact.o\
	fxp_mul_fxp.o\
	fxp_strassen_mul_fxp.o\
	fxp_round.o\
	fxp_double_get_int_part.o\
	fxp_double_get_fraction_part.o\
	fxp_ldouble_get_int_part.o\
	fxp_ldouble_get_fraction_part.o\

OBJS += $(addprefix $(LIBFT_PATH)/objs/, $(LIBFT_OBJS))
OBJS += $(addprefix $(LIBBIGINT_PATH)/objs/, $(LIBBIGINT_OBJS))
OBJS += $(addprefix $(LIBFIXEDPOINT_PATH)/objs/, $(LIBFIXEDPOINT_OBJS))


# compile objs
HEADERS = $(INCDIR)/ft_printf.h\
	$(LIBFT_PATH)/includes/libft.h\
	$(LIBBIGINT_PATH)/includes/bigint.h\
	$(LIBFIXEDPOINT_PATH)/includes/fixedpoint.h\

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/parse_tags/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_length/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_sign/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_prefix/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_leading_zero/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/buffer/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_write/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_write/float/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/parse_percent/float/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/parse_percent/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : deps $(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all
	@$(MAKE) -C $(LIBBIGINT_PATH) all
	@$(MAKE) -C $(LIBFIXEDPOINT_PATH) all

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(MAKE) -C $(LIBBIGINT_PATH) clean
	@$(MAKE) -C $(LIBFIXEDPOINT_PATH) clean
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean : clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(MAKE) -C $(LIBBIGINT_PATH) fclean
	@$(MAKE) -C $(LIBFIXEDPOINT_PATH) fclean
	@rm -f $(NAME)

re : fclean all

.PHONY : deps all clean fclean re test
