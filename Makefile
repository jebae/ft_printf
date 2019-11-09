# compiler
CC = gcc

# lib name
NAME = libftprintf.a

# path
SRCDIR = srcs

INCDIR = includes

OBJDIR = objs

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
	arg_sc_length.c\
	arg_e_length.c\

SRC_ARG_SIGN = num_sign.c\
	arg_d_sign.c\
	arg_f_sign.c\
	arg_no_sign.c\

SRC_ARG_PREFIX = arg_o_prefix.c\
	arg_x_prefix.c\
	arg_upper_x_prefix.c\
	arg_p_prefix.c\
	arg_no_prefix.c\
	write_prefix.c\

SRC_ARG_LEADING_ZERO = arg_leading_zero.c\

SRC_BUFFER = buffer.c\

SRC_ARG_WRITE = int_write.c\
	double_write_parts.c\
	double_write_scientific_parts.c\
	arg_d_write.c\
	arg_u_write.c\
	arg_f_write.c\
	arg_x_write.c\
	arg_upper_x_write.c\
	arg_o_write.c\
	arg_sc_write.c\
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
	parse_sc.c\
	parse_p.c\
	parse_e.c\
	float_utils.c\
	double_get_parts.c\
	double_get_scientific_parts.c\
	double_get_bcd_fraction_part.c\
	double_get_bcd_int_part.c\

SRC_LIBFT = ft_extract_double.c\
	ft_mem.c\
	ft_bzero.c\
	ft_str.c\
	ft_utf8.c\
	ft_is_nan_inf.c\
	ft_math.c\

SRC_BIGINT = bi_mem.c\
	bi_mem2.c\
	bi_abs_compare.c\
	bi_op_utils.c\
	bi_add_bi.c\
	bi_sub_bi.c\
	bi_mul_bi.c\
	bi_bit.c\
	bi_left_shift.c\
	bi_right_shift.c\
	bi_double_dabble.c\
	bi_rev_double_dabble.c\
	bi_bcd.c\
	bcd_round.c\
	bcd_add_digit.c\

SRC_FIXEDPOINT = fxp_mem.c\
	fxp_op.c\
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

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/parse_tags/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_length/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_sign/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_prefix/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_leading_zero/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/buffer/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_write/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/arg_write/float/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/parse_percent/float/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/parse_percent/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/libft/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/bigint/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o : $(SRCDIR)/fixedpoint/%.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
