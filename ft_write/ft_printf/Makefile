NAME = libftprintf.a

LIBFT = "../../"
CC = cc

CFLAGS = -Wall -Wextra -Werror 

CFILES = ft_printf.c \
conv_writers_1.c \
conv_writers_2.c \
ft_printf_utils.c \
ft_printf_utils_2.c

BFILES = conv_writers_1_bonus.c \
conv_writers_2_bonus.c \
ft_printf_bonus.c \
ft_printf_dec_utils_1_bonus.c \
ft_printf_dec_utils_2_bonus.c \
ft_printf_dec_utils_3_bonus.c \
ft_printf_string_utils_1_bonus.c \
ft_printf_string_utils_2_bonus.c \
ft_printf_utils_2_bonus.c \
ft_printf_utils_bonus.c \
hex_utils_2_bonus.c \
hex_utils_bonus.c \
width_utils_bonus.c \
ft_printf_dec_utils_4_bonus.c \
hex_utils_3_bonus.c 

OBJECTS = $(CFILES:.c=.o)

BOBJECTS = $(BFILES:.c=.o)

$(NAME): $(OBJECTS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./
	mv ./libft.a ./$(NAME)
	ar -rc $(NAME) $(OBJECTS)

bonus: $(NAME) $(BOBJECTS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a ./
	mv ./libft.a ./$(NAME)
	ar -rc $(NAME) $(BOBJECTS)

all: $(NAME) 

clean: 
	rm -f $(OBJECTS)
	rm -f $(BOBJECTS)
	make clean -C $(LIBFT)

fclean: clean 
	rm -f $(NAME)
	rm -f $(LIBFT)/libft.a
	
re: fclean all 
