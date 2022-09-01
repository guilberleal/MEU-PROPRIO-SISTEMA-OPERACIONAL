.global _start
.equ STACK_SIZE,4096
_start:
    csrr t0,mhartid
    bnez t0, park #salta se nao for igual a 0
    la sp,stack_end  #carrega sp com o endereço stack_end
    j entry #salta para funcao em C


park:
    wfi     #espera por interrupção
    j park # volta para linha 8

.skip STACK_SIZE
stack_end:


