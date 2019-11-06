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

OBJDIR = objs

LIBDIR = libs

LIBFT_PATH = $(LIBDIR)/libft

LIBBIGINT_PATH = $(LIBDIR)/libbigint

LIBFIXEDPOINT_PATH = $(LIBDIR)/libfixedpoint

# compiler options
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./$(INCDIR)

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

SRC_LIBFT = ft_bzero.c\
	ft_extract_double.c\
	ft_extract_ldouble.c\
	ft_is_inf.c\
	ft_is_inf_l.c\
	ft_is_nan.c\
	ft_is_nan_l.c\
	ft_isdigit.c\
	ft_memdel.c\
	ft_memcpy.c\
	ft_memnegate.c\
	ft_memset.c\
	ft_memalloc.c\
	ft_pow.c\
	ft_strcpy.c\
	ft_strlen.c\
	ft_min_int.c\
	ft_max_int.c\
	ft_to_utf8.c\
	ft_utf8_byte_len.c\

SRC_BIGINT = bi_del.c\
	bi_memalloc.c\
	bi_init.c\
	bi_erase.c\
	bi_expand.c\
	bi_expand_at_least.c\
	bi_push.c\
	bi_copy.c\
	bi_abs_compare.c\
	bi_max_bit.c\
	bi_op_utils.c\
	bi_add_bi.c\
	bi_sub_bi.c\
	bi_update_occupied.c\
	bi_left_shift.c\
	bi_abs.c\
	bi_mul_bi.c\
	bi_right_shift.c\
	bi_get_bit.c\
	bi_set_bit.c\
	bi_double_dabble.c\
	bi_rev_double_dabble.c\
	bcd_len.c\
	bcd_get_digit.c\
	bcd_set_digit.c\
	bcd_rm_trailing_zero.c\
	bcd_iter.c\
	bcd_round.c\
	bcd_add_digit.c\

SRC_FIXEDPOINT = fxp_init.c\
	fxp_del.c\
	fxp_compact.c\
	fxp_mul_fxp.c\
	fxp_double_get_int_part.c\
	fxp_double_get_fraction_part.c\
	fxp_ldouble_get_int_part.c\
	fxp_ldouble_get_fraction_part.c\

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
OBJS += $(addprefix $(OBJDIR)/, $(SRC_LIBFT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_BIGINT:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_FIXEDPOINT:.c=.o))

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

$(OBJDIR)/%.o : $(LIBFT_PATH)/srcs/memory/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(LIBFT_PATH)/srcs/math/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(LIBFT_PATH)/srcs/string/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(LIBBIGINT_PATH)/srcs/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(LIBFIXEDPOINT_PATH)/srcs/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : $(OBJDIR) $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
clean :
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
