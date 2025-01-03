COMMAND := cc -c -Wall -Werror -Wextra

BONUS_OBJECTS := bonus_part/fn_atoi_bonus.o \
		 bonus_part/fn_flag_hash_bonus.o bonus_part/fn_flag_plus_bonus.o \
		 bonus_part/fn_flags_bonus_bonus.o bonus_part/fn_flags_section_bonus_bonus.o \
		 bonus_part/fn_fn_bonus.o bonus_part/fn_global_bonus.o \
		 bonus_part/fn_global_length_bonus.o bonus_part/fn_isdigit_bonus.o \
		 bonus_part/fn_itoa_bonus.o bonus_part/fn_length_bonus.o \
		 bonus_part/fn_printf_bonus_bonus.o bonus_part/fn_printf_bonus.o \
		 bonus_part/fn_putchar_bonus.o \
		 bonus_part/fn_putchar_length_bonus.o bonus_part/fn_puthex_bonus.o \
		 bonus_part/fn_puthex_length_bonus.o bonus_part/fn_puthexptr_bonus.o \
		 bonus_part/fn_putnbr_bonus.o bonus_part/fn_putnbr_length_bonus.o \
		 bonus_part/fn_putptr_bonus.o bonus_part/fn_putptr_length_bonus.o \
		 bonus_part/fn_putstr_bonus.o bonus_part/fn_putstr_length_bonus.o \
		 bonus_part/fn_putus_bonus.o bonus_part/fn_putus_length_bonus.o \
		 bonus_part/fn_strlen_bonus.o bonus_part/fn_tolower_bonus.o bonus_part/fn_toupper_bonus.o


#objects for the Mandatorydatory part
OBJECTS := Mandatory/fn_printf.o Mandatory/fn_global.o Mandatory/fn_putchar.o Mandatory/fn_itoa.o \
	   Mandatory/fn_putstr.o Mandatory/fn_putptr.o Mandatory/fn_puthex.o Mandatory/fn_puthexptr.o \
	   Mandatory/fn_putnbr.o Mandatory/fn_putus.o Mandatory/fn_tolower.o Mandatory/fn_toupper.o


NAME = libftprintf.a

all: ${NAME}

HEADER = fn_printf_bonus.h

${NAME}: ${OBJECTS}
	ar rcs $@ $^

bonus: ${BONUS_OBJECTS}
	ar rcs ${NAME} $^


%.o: %.c
	${COMMAND} $< -o $@

clean:
	rm -f ${BONUS_OBJECTS} ${OBJECTS}

fclean: clean
	rm -f ${NAME}

re: fclean ${NAME}

.PHONEY: clean
