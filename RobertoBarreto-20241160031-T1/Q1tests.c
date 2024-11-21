//Testes isolados da Questão 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RobertoBarreto20241160031.h"

DataQuebrada quebraData(char data[]);

//Função para verificar se o ano é bissexto
int bissexto(int ano){
	if (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0){
		return 1;
	}
	return 0;
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
    DataQuebrada dq = quebraData(data);

	//Checa se o tamanho é compatível
	if (strlen(data)>10 || strlen(data)<6){
		return 0;
	}

    // Verifica se a data foi quebrada corretamente
    if (dq.valido == 0) {
        return 0; // Data inválida se a quebra falhou
    }

    // Verificar se o mês está no intervalo de 1 a 12
    if (dq.iMes < 1 || dq.iMes > 12) {
        return 0; // Mês inválido
    }

    // Verificar se o dia está dentro do intervalo válido para o mês
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // Para meses com 31 dias
    if (dq.iMes == 2) { // Se for fevereiro, verifica o ano bissexto
        if (isBissexto(dq.iAno)) {
            diasPorMes[1] = 29; // Fevereiro tem 29 dias no ano bissexto
        }
    }

    if (dq.iDia < 1 || dq.iDia > diasPorMes[dq.iMes - 1]) {
        return 0; // Dia inválido para o mês
    }

    // Se passar por todas as validações
    return 1; // Data válida
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

int main() {
    // Testes para verificar se a função q1 está funcionando corretamente
    char data[] = "29/02/2024";
    if (q1(data)) {
        printf("Data %s é válida.\n", data);
    } else {
        printf("Data %s é inválida.\n", data);
    }

    char data2[] = "31/04/2023";
    if (q1(data2)) {
        printf("Data %s é válida.\n", data2);
    } else {
        printf("Data %s é inválida.\n", data2);
    }

    return 0;
}