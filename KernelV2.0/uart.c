#include "types.h"
#include "memlayout.h"

//registradores do UART:
#define RHR 0 // para leitura
#define THR 0 // transmissao
#define IER 1 // habilita/desabilita interrupcao
#define FCR 2 // Buffer FIFO
#define ISR 2 // Status da interrupcao
#define LCR 3
#define LSR 5 // Status da linha

void write_reg(uint64,char);
char read_reg(uint64);
void uartinit();

char read_reg(uint64 reg ){
    //leitura de um registrador UART
    char c;
    volatile uint8 * base = (uint8 *)UART;
    c = *(base + reg);
    return c;
}

void write_reg(uint64 reg,char c){
    volatile uint8 *base = (uint8*) UART;
    *(base + reg) = c;

}
//
void uartinit(){
    //tamanho dos dados:8 bits
    write_reg(LCR, 0x3);
    //habilita o buffer
    write_reg(FCR, 0x1);
    //habilita interrupcao de recebimentos de dados
    write_reg(IER,0x1);
}
//imprime caracter no terminal
void uartputc(int c){
    while((read_reg (LSR) & (1<<5)) == 0 ){

    }
    
    white_reg(THR,c);
}

