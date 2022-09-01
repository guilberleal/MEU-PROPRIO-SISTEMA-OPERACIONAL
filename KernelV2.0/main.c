#define uart_base 0x10000000

static void putc(char c){
    char *reg = (char *) uart_base;
    *reg = c;

}

void puts(char *s){
    while(*s != 0 ){
        putc(*s);
        s++;
    }
}
void entry(){
    puts("Ola mundo! <disse o karnel>");
}
