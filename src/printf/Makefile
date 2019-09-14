NAME = libftprintf.a

HFILES = ../../include

CFLAGS = -c -Wall -Wextra -Werror
SOURCES =   c_conversions.c \
            conversion_flags.c \
            convert_flags.c \
            d_conversions.c \
            div_10_longnum.c \
            f_conversions.c \
            float_to_str.c \
            ft_after_num.c \
            ft_before_num.c \
            ft_itoa_base.c \
            ft_itoa_base_hex_long.c \
            ft_printf.c \
            get_conv_glags.c \
            get_conversion.c \
            get_first_digit.c \
            get_flags.c \
            get_sizes.c \
            large_arythmetics.c \
            make_double.c \
            make_ldouble.c \
            mod_conversions.c \
            o_conversions.c \
            p_conversions.c \
            print_conversion.c \
            s_conversion.c \
            sum_longnum.c \
            u_conversion.c \
            x_conversions.c \
            fill_with_chars.c \
            ft_lst_to_str.c \
            ft_realloc.c \
            ft_strappend.c \
            ft_create_node.c \
            ft_lstadd.c \
            ft_lstnew.c \
            ft_lstadd.c \
            ft_lstnew.c \

OBJECTS =     c_conversions.o \
              conversion_flags.o \
              convert_flags.o \
              d_conversions.o \
              div_10_longnum.o \
              f_conversions.o \
              float_to_str.o \
              ft_after_num.o \
              ft_before_num.o \
              ft_itoa_base.o \
              ft_itoa_base_hex_long.o \
              ft_printf.o \
              get_conv_glags.o \
              get_conversion.o \
              get_first_digit.o \
              get_flags.o \
              get_sizes.o \
              large_arythmetics.o \
              make_double.o \
              make_ldouble.o \
              mod_conversions.o \
              o_conversions.o \
              p_conversions.o \
              print_conversion.o \
              s_conversion.o \
              sum_longnum.o \
              u_conversion.o \
              x_conversions.o \
              fill_with_chars.o \
              ft_lst_to_str.o \
              ft_realloc.o \
              ft_strappend.o \
              ft_create_node.o \
              ft_lstadd.o \
              ft_lstnew.o \
              ft_lstadd.o \
              ft_lstnew.o \
              ft_lstadd.o \
              ft_lstnew.o \

all: $(NAME)

$(NAME):
	echo "$(NAME) compiling... \c"; \
	gcc $(CFLAGS) $(SOURCES) -I$(HFILES)
	ar rc $(NAME) $(OBJECTS)
	echo "$(NAME) is ready!... \c"; \

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all