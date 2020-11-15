/*
 * view_plot.h
 *
 *  Created on: 13.11.2020
 *      Author: M.Sobol
 */


#ifndef VIEW_PLOT_H_
#define VIEW_PLOT_H_

#include "stm32f429i_discovery_lcd.h"
#include "number_string_operations.h"

#include "stdio.h"
#include "stdlib.h"
#include "float.h"


#define PLOT_HEIGHT_PLOT_PIXEL 280
#define PLOT_WIDTH_PLOT_PIXEL 180
#define PLOT_INDICATE_LEN 10

#define LCD_FOREGROUND_LAYER 0x0001

typedef struct MinMaxUnit{
	double min_X;
	double max_X;
	double min_Y;
	double max_Y;
}MinMaxUnit;


typedef struct PointReal{
	double x;
	double y;
}PointReal;

void InitLCD();
void PlotChart(double** data, int N);
void PlotChartAxes(Point axis_coordinates, MinMaxUnit units, double interval_indicate);// internal_indicate in percentage


#endif /* VIEW_PLOT_H_ */
