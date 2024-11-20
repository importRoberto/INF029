//Testes isolados da Questão 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RobertoBarreto20241160031.h"

DataQuebrada quebraData(char data[]);

int bissexto(int ano){

}

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






DataQuebrada quebraData(char data[]){
	DataQuebrada dq;
  	char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];
	}
	if (i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	} else {
		dq.valido = 0;
    return dq;
	}  
	

	int j = i + 1; //anda 1 casa para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if (i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	} else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for (; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if (i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	} else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
