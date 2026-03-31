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