#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_alunos;
    float *notas;
}Notas;

int main(){
    Notas _2c;
    scanf("%d", &_2c.num_alunos);

    _2c.notas = (float *) malloc(_2c.num_alunos * sizeof(float));
    if(_2c.notas == NULL) exit(1);

    for(int i=0; i<_2c.num_alunos; i++) scanf("%f", &_2c.notas[i]);

    float maior_nota = _2c.notas[0];
    for(int i=1; i<_2c.num_alunos; i++) if(_2c.notas[i] > maior_nota) maior_nota = _2c.notas[i];
    
    printf("Maior nota: %.2f\n", maior_nota);
    free(_2c.notas);

    return 0;
}