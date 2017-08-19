cmake_minimum_required(VERSION 3.7)
project(cw_ir)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c cw_error_mess.c cw_new_ch.c cw_read_args.c cw_struct_null.c cw_decryptor.c cw_prefight.c cw_battle.c cw_fight.c cw_get_number.c cw_get_arg.c cw_the_end.c cw_output.c cw_put_inmem.c cw_set_pause.c cw_arg_func.c cw_cpy_ch.c ft_atoi_base.c libft/ft_putchar.c libft/ft_atoi.c libft/ft_isdigit.c libft/ft_putnbr.c libft/ft_putstr.c libft/ft_strdup.c libft/ft_strequ.c libft/ft_strnew.c libft/ft_strlen.c libft/ft_ustrnew.c cw_vis_output.c cw_decrypt_options.c cw_function_pack2.c cw_function_pack3.c cw_function_pack4.c cw_function_pack1.c cw_read_args2.c)

add_executable(cw_ir ${SOURCE_FILES})