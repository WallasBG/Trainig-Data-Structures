#ifndef complexo_h
#define complexo_h

typedef struct{
    float real;
    float img;
}complexo;

complexo complexo_novo(float real, float imag);// comentario da funcao, ola
complexo complexo_soma(complexo a, complexo b);
double complexo_absoluto(complexo a);
complexo complexo_le();
void complexo_imprime(complexo a);
int complexos_iguais(complexo a, complexo b);
complexo complexo_multiplicacao(complexo a, complexo b);
complexo complexo_conjugado(complexo a);//inverte o sinal da parte imaginaria. Equivalente a uma reflexao em relacao ao eixo real

#endif

/*
se complexo_h nao estiver definido eu defino, onde todo o conteudo abaixo do #define
vai esta atrelado ao nome complexo_h

usar ifndef eh bom para que evite loop de inclusao, 
pois se em uma implementacao.c precise utilar o complexo.h, algo que o cliente nao tem controle,
e no cliente.c uso funcoes da implementacao.h, e para outra coisa uso incluo o complexos.h,
vou esta utilizado duas vezes.

entao use #ifndef
*/
