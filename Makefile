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

# compiler options
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I ./$(INCDIR)\
	-I ./$(LIBFT_PATH)/includes\

LIBS = -L ./$(LIBFT_PATH) -lft

# srcs
SRC_FT_PRINTF = ft_printf.c\

SRC_TAGS = init_tags.c\
	flag.c\
	width.c\
	precision.c\
	length.c\

SRC_ARG_LENGTH = num_length.c\
	arg_d_length.c\
	arg_u_length.c\
	arg_f_length.c\

SRC_ARG_SIGN = num_sign.c\
	arg_d_sign.c\
	arg_f_sign.c\
	arg_no_sign.c\

# objs
#OBJS = $(addprefix $(OBJDIR)/, $(SRC_FT_PRINTF:.c=.o))
OBJS = $(addprefix $(OBJDIR)/, $(SRC_TAGS:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_LENGTH:.c=.o))
OBJS += $(addprefix $(OBJDIR)/, $(SRC_ARG_SIGN:.c=.o))

# compile objs
HEADERS = $(INCDIR)/ft_printf.h\
	$(LIBFT_PATH)/includes/libft.h\

$(OBJDIR)/%.o : $(SRCDIR)/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/parse_tags/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_length/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

$(OBJDIR)/%.o : $(SRCDIR)/arg_sign/%.c $(HEADERS)
	@$(call compile_obj,$<,$@)

# build
all : $(NAME)

$(NAME) : deps pre_build $(OBJDIR) $(OBJS) post_build
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

deps :
	@$(MAKE) -C $(LIBFT_PATH) all

pre_build :
	@printf "$(KGRN)[ft_printf] $(KYEL)build $(NAME)\n$(KNRM)"

post_build :
	@printf "$(KGRN)[ft_printf] $(KYEL)$(COUNTER) files compiled\n$(KNRM)"

$(OBJDIR) :
	@mkdir -p $(OBJDIR)

# commands
test : all
	@$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(SRCDIR)/__tests__/*.c $(SRCDIR)/__tests__/*/*.c test_main.c $(OBJS) -o test

clean :
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJDIR)/$(OBJS)

fclean :
	@rm -f $(NAME)

re : fclean all

.PHONY : pre_build post_build deps all clean fclean re test
