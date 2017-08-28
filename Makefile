ASM = asm/asm
WM = wm/corewar

all: $(ASM) $(WM)
	@echo "\033[32;1m<corewar>  | done"

$(ASM):
	@make -C asm

$(WM):
	@make -C wm

clean:
	@make clean -C asm
	@make clean -C wm
	@echo "\033[32;1m<corewar>  | clean succes"

fclean: clean
	@make fclean -C asm
	@make fclean -C wm
	@echo "\033[32;1m<corewar>  | fclean succes"

re: fclean all
	@echo "\033[32;1m<corewar>  | re succes"
