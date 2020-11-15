/*
 * number_string_operations.c
 *
 *  Created on: 15.11.2020
 *      Author: M.Sobol
 */

#include "number_string_operations.h"

void DoubleToString(char* outstring, int digits_after_comma, double number){
	int ten_multipier_after_comma = pow(10.0,(double)digits_after_comma);
	int round_whats_not_wanted = (int)(round(number * ten_multipier_after_comma));
	int before_comma = round_whats_not_wanted / ten_multipier_after_comma;
	int after_comma = round_whats_not_wanted % (ten_multipier_after_comma * before_comma);

	char* str_after_comma = (char *)malloc(12 * sizeof(char));
	sprintf(str_after_comma,"%d", after_comma);
	if(after_comma == 0){
		for(int i = 1; i < digits_after_comma; i ++){
			strcat(str_after_comma, "0");
		}
	}
	sprintf(outstring, "%d.%s", before_comma, str_after_comma);
	free(str_after_comma);
}
