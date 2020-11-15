/*
 * view_plot.c
 *
 *  Created on: 13.11.2020
 *      Author: M.Sobol
 */
#include "view_plot.h"


static void delay(__IO uint32_t nCount)
{
  volatile __IO uint32_t index = 0;
  for(index = nCount; index != 0; index--)
  {
  }
}

void InitLCD(){
	LCD_Init();
	/* LCD Layer initiatization */
	LCD_LayerInit();
	/* Enable the LTDC */
	LTDC_Cmd(ENABLE);
	/* Set LCD foreground layer */
	LCD_SetLayer(LCD_FOREGROUND_LAYER);
	LCD_Clear(LCD_COLOR_WHITE);
}
void PlotChart(double** data, int N){
	InitLCD();
	Point startCoorditanateAxis = { .X = 30, .Y = 10 };
	MinMaxUnit maxMinAxisRange = {.min_X = 0, .min_Y = 0, .max_X = 10, .max_Y = 2.5};
	PlotChartAxes(startCoorditanateAxis, maxMinAxisRange, 0.1);
}
void PlotLineBeetwenPoints(PointReal p1, PointReal p2){

}
Point ConvertDataToPixelData(PointReal p1, PointReal p2,MinMaxUnit units, Point axes_coordinates){
	Point p = {
			.X = 1, .Y = 1
	};
	return p;
}
void PlotChartAxes(Point axis_coordinates, MinMaxUnit units, double interval_indicate){
	volatile double x_axis_interval = 0;
	volatile double y_axis_interval = 0;
	double index = 0;

	LCD_DrawLine(axis_coordinates.X, axis_coordinates.Y, WIDTH_PLOT_PIXEL, LCD_DIR_VERTICAL);
	LCD_DrawLine(axis_coordinates.X, axis_coordinates.Y, HEIGHT_PLOT_PIXEL, LCD_DIR_HORIZONTAL );

	char* str_temp = malloc(12 * sizeof(char));
	while(index < 1){
		index += interval_indicate;
		x_axis_interval = (units.max_X - units.min_X) * index;
		y_axis_interval = (units.max_Y - units.min_Y) * index;
		DoubleToString(str_temp, 2, y_axis_interval);
		LCD_DisplayStringLine(1, (uint8_t*)str_temp);
		delay(10000000);
	}
	free(str_temp);
}


