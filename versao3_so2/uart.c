#include "types.h"
#include "memlayout.h"

//registradores do uart:
#define RHR 0 //REGISSTRADOR PARA LEITURA
#define THR 0 //TRANSMISSÃO
#define IER 1 //HABILITA/DESABILITA INTERRUPÇÃO
#define FCR 2 //BUFFER FIFO  
#define ISR 2 //STATUS DA INTERRUPÇÃO
#define LCR 3 //
#define LSR 5 //STATUS DA LINHA

void write_reg(uint64, char);
char read_reg(uint64);


char read_reg(uint64 reg){
    //leitura de um registrador UART
    char c;
    volatile uint8 *base= (uint8 *)UART;
    c = *(base + reg);
    return c;
}
void write_reg(uint64 reg, char c){
    volatile uint8 *base= (uint8*) UART;
    *(base+reg)=c; 
}

void uartinit(){
    //tamanho dos dados:8bits
    write_reg(LCR,0x3);
    //habilita buffer
    write_reg(FCR, 0x1);
    //habilita a interrupção de recebimento de dados
    write_reg(IER,0x1);
}
//imprime caracter no terminal
void uartputc(char c){
    while((read_reg(LSR)&(1<<5))==0);
    write_reg(THR,c);
}
//fazer uartget
int uartgetc(){
    int c;
    //verificar se ha dados disponiveis para leitura no registrador lsr 
    if((read_reg(LSR) & 0x1) ==0)
        return -1;
    c= read_reg(RHR);
    return c;
}