.global _start
.equ STACK_SIZE, 4096
#configurando a pilha
_start:
    csrr t0, mhartid # 
    bnez t0, park #salta se nao eh igual a zero, para park , salta condicional(se)
    la sp, stack_end #carrega sp com endereço stack_end
    j entry #funcao em C
#coloca os demais cores em espera
park:
    wfi #esperando por uma interrupcao
    j park #volta para park novamente, ficando esperando, gerando loop infinito (nao tem condicao)


.skip STACK_SIZE
stack_end:
