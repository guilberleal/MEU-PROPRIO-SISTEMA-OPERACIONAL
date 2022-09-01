PRE= riscv64-linux-gnu-
CC = $(PRE)gcc
LD = $(PRE)ld 
#parametros para o compilador c
CFLAGS += -ffreestanding # nao ha um SO No ambiente de execucao
CFLAGS += -march=rv64gc #arquitetura risc-v de 64 bits 
CFLAGS += -mabi=lp64 #tipos longos e ponteiros são de 64 bits e inteiros de 32 bits
CFLAGS += -Wall # mostra mais mensagens de warning
CFLAGS += -g #GERA INFOMAÇÕES EXTRA P DEPURAÇÃO
CFLAGS +=  -O0 #otimiza o codigo o minimo possivel
CFLAGS += -c #compila mas não invoca o linkes
#parametros para o linkes
LDFLAGS += -nostdlib # não vincul-Wall -g -O0 -c unções de terceiros 
LDFLAGS += -Tkernel.ld
#emulador
QEMU=qemu-system-riscv64 
OBJ= \
	boot.o\
	main.o\
	uart.o
kernel: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ)
%.o: %.c
	$(CC) $(CFLAGS) $<
%.o: %.s
	$(CC) $(CFLAGS) $<

#main.o: main.c 
#	$(CC) $(CFLAGS) main.c 
#boot.o: boot.s 
#	$(CC) $(CFLAGS) boot.s 
#uart.o: uart.c

run: kernel 
	$(QEMU) -append 'console=ttyS0'  -nographic -serial mon:stdio -smp 4 -machine virt -bios none -kernel kernel
clean:
	rm -f $(OBJ) kernel

