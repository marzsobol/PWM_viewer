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
static void PlotLineBeetwenPoints(PointReal p1, PointReal p2) {

}
static Point ConvertDataToPixelData(PointReal p1, PointReal p2,
		MinMaxUnit units, Point axes_coordinates) {
	Point p = {
			.X = 1, .Y = 1
	};
	return p;
}
void PlotChartAxes(Point axis_coordinates, MinMaxUnit units, double interval_indicate){
	double x_axis_interval = 0;
	double y_axis_interval = 0;

	Point axis_coordinate_of_interval_indicate_line = { axis_coordinates.X,
			axis_coordinates.Y };

	double index = interval_indicate;
	LCD_DrawLine(axis_coordinates.X, axis_coordinates.Y, PLOT_HEIGHT_PLOT_PIXEL,
	LCD_DIR_VERTICAL);
	LCD_DrawLine(axis_coordinates.X, axis_coordinates.Y, PLOT_WIDTH_PLOT_PIXEL,
	LCD_DIR_HORIZONTAL);

	int pixel_interval_y = PLOT_HEIGHT_PLOT_PIXEL * interval_indicate;
	int pixel_interval_x = PLOT_WIDTH_PLOT_PIXEL * interval_indicate;

	char* str_temp = malloc(12 * sizeof(char));
	while (index <= (1 - 1e-6)) {
		// line indicates
		axis_coordinate_of_interval_indicate_line.X += pixel_interval_x;
		axis_coordinate_of_interval_indicate_line.Y += pixel_interval_y;
		LCD_DrawLine(axis_coordinates.X,
				axis_coordinate_of_interval_indicate_line.Y, PLOT_INDICATE_LEN,
				LCD_DIR_HORIZONTAL);
		LCD_DrawLine(axis_coordinate_of_interval_indicate_line.X,
				axis_coordinates.Y, PLOT_INDICATE_LEN,
				LCD_DIR_VERTICAL);

		//number indicates
		LCD_SetFont(Font8x8);
		x_axis_interval = (units.max_X - units.min_X) * index;
		y_axis_interval = (units.max_Y - units.min_Y) * index;
		DoubleToString(str_temp, 2, y_axis_interval);
		index += interval_indicate;
//		for(int i = 0; i <)


		delay(10000000);
	}
	free(str_temp);
}


