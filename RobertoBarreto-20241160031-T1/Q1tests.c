//Testes isolados da Questão 1

#include <stdio.h>
#include "RobertoBarreto20241160031.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*---------------------------------- Q1 = validar data -------------------------------
@objetivo
    Validar uma data
@entrada
    Uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa = ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno


  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}
