COMMAND := cc -c -Wall -Werror -Wextra

OBJECTS := fn_itoa.o fn_putchar.o fn_puthex.o fn_putnbr.o fn_putptr.o fn_putstr.o fn_tolower.o fn_toupper.o fn_printf.o fn_global.o fn_puthexptr.o fn_putus.o fn_flags.o\
	fn_flags.o fn_flag_plus.o fn_flag_hash.o  fn_flags_section_bonus.o fn_atoi.o fn_isdigit.o\
	fn_putstr_length.o fn_putchar_length.o fn_global_length.o fn_strlen.o fn_putptr_length.o fn_putnbr_length.o\
	fn_putus_length.o fn_length.o fn_puthex_length.o fn_fn.o

NAME = libftprintf.a

all: ${NAME}

HEADER = fn_printf.h

${NAME}: ${OBJECTS}
	ar rcs $@ $^


%.o: %.c fn_printf.h
	${COMMAND} $<

clean:
	rm -f ${OBJECTS}

fclean: clean
	rm -f ${NAME}
re: fclean ${NAME}
.PHONEY: clean
