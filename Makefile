SRC = main.c functions.c functions1.c

LIBFT = libft/libft.a

main:
	cc $(SRC) libft/libft.a -lreadline -lhistory 
