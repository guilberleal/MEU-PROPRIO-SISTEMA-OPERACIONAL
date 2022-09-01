PRE = riscv64-linux-gnu-
CC = $(PRE)gcc
LD = $(PRE)ld

#parametros para o compilador
CFLAGS += -ffreestanding #Nao há um SO no ambiente de execucao
CFLAGS += -march=rv64gc #arquitetura RISC-V de 64 bits
CFLAGS += -mabi=lp64	#tipos longos e ponteiros sao de 64bits. Inteiros sao de 32 bits
CFLAGS += -Wall #Mensagens de Warning
CFLAGS += -g 	#gera informacoes extras p/ depuracao	  
CFLAGS += -O0	#Otimiza o codigo o minimo possivel 
CFLAGS += -c  #compila mas nao invoca o linker

#parametros para o linker
LDFLAGS = -nostdlib #Nao vincula funcoes de terceiros
LDFLAGS = -Tkernel.ld  #Script para o linker

#emulador
QEMU = qemu-system-riscv64 

kernel: boot.o main.o 
	$(LD) $(LDFLAGS)-o  kernel boot.o main.o

main.o: main.c 
	$(CC) $(CFLAGS) main.c 
	
boot.o: boot.s 
	$(CC) $(CFLAGS) boot.s

clean: 
	rm -f boot.o main.o kernel

run: kernel
	$(QEMU) -append 'console=ttyS0'  -nographic -serial mon:stdio -smp 4 -machine virt -bios none -kernel kernel 

