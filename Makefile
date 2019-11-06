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

$(NAME) : deps pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all
	@$(MAKE) -C $(LIBBIGINT_PATH) all
	@$(MAKE) -C $(LIBFIXEDPOINT_PATH) all

pre_build :
	@printf "$(KGRN)[ft_printf] $(KYEL)build $(NAME)\n$(KNRM)"
	@cd ./$(INCDIR)
	@ln -f $(LIBFT_PATH)/includes/libft.h ./$(INCDIR)/
	@ln -f $(LIBBIGINT_PATH)/includes/bigint.h ./$(INCDIR)/
	@ln -f $(LIBFIXEDPOINT_PATH)/includes/fixedpoint.h ./$(INCDIR)/

post_build :
	@printf "$(KGRN)[ft_printf] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
test : all
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(SRCDIR)/__tests__/*.c $(SRCDIR)/__tests__/*/*.c test_main.c -o test

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

.PHONY : pre_build post_build deps all clean fclean re test
