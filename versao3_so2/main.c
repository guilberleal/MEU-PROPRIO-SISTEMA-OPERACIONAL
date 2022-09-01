#define uart_base 0x10000000
#include "defs.h"
#include "console.h"
void puts(char *s){
   while(*s!=0){ 
    uartputc(*s++);
}}

void entry(){
    puts(CURSOR_TOP_LEFT);
    puts(CLEAR_SCREEN);
    puts("-- Roncador Operating System --\n");
    int c;
    //configuracao inicial do dispositivo uart
    uartinit();
    for(;;){
        c=uartgetc();
        if(c==-1)
            continue;
        switch (c)
        {
            case '\r':
                uartputc('\r');
                uartputc('\n');
            case 127://del
                //uartputc('\b');
                //uartputc(' ');
                //uartputc('\b');
                puts(BS);
                break;
            case '\x1B':
                puts(CURSOR_TOP_LEFT);
            default:
                uartputc(c);
       
         }
    }
}