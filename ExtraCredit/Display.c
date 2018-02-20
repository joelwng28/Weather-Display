/* ******** Display.c ************** 
 * Samuel Zhang, Zi Zhou Wang
 * 2/3/2018
 * Display and screen print functions
 * Lab 4
 * Saadallah
 * 2/10/2018
 */

#include <stdint.h>
#include "main.h"
#include "ST7735.h"
#include <string.h>
#include "Globals.h"



//*************drawSec********************************************
//  Draws one thin line on the ST7735 color LCD (Seconds hand)
//  Inputs: (x1,y1) is the start point
//          (x2,y2) is the end point
// x1,x2 are horizontal positions, columns from the left edge
//               must be less than 128
//               0 is on the left, 126 is near the right
// y1,y2 are vertical positions, rows from the top edge
//               must be less than 160
//               159 is near the wires, 0 is the side opposite the wires
//        color 16-bit color, which can be produced by ST7735_Color565() 
// Output: none
void drawSec(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {
    float slope = 0;
    if (x2 == x1) { //if vertical line
        if(y2 >= y1) {
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1, yPt, color);
            }
        }
        else {
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2, yPt, color);
            }
        }
    }
    else if (y2 == y1) { //if horizontal line
        if(x2 >= x1) {
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, y1, color);
            }
        }
        else {
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, y2, color);
            }
        }
    }
    
    //all other cases have to do with relative positions of x1 and x2
    else if(x2 > x1 && y2 > y1) {
        if((x2 - x1) >= (y2 - y1)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color);    //slope point formula
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);;
            }
        }
    }
    else if (x2 > x1 && y1 > y2) {
        if((x2 - x1) >= (y1 - y2)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color); //slope point formula
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);       
            }
        }
    }
    else if (x1 > x2 && y2 > y1) {
        if((x1 - x2) >= (y2 - y1)) {
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + ((slope)*((float)(xPt-x2)))),color); //slope point formula
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);
            }
        }
    }
    else if (x1 > x2 && y1 > y2){
        if((x1 - x2) >= (y1 - y2)) {    
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + (uint16_t)((slope)*((float)(xPt-x2)))),color); //slope point formula
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);          
            }
        }
    }
}

//*************drawMin*******************************************
//  Draws two-pixel wide line on the ST7735 color LCD (Minutes hand)
//  Inputs: (x1,y1) is the start point
//          (x2,y2) is the end point
// x1,x2 are horizontal positions, columns from the left edge
//               must be less than 128
//               0 is on the left, 126 is near the right
// y1,y2 are vertical positions, rows from the top edge
//               must be less than 160
//               159 is near the wires, 0 is the side opposite the wires
//        color 16-bit color, which can be produced by ST7735_Color565() 
// Output: none
void drawMin(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {
    float slope = 0;
    if (x2 == x1) { //if vertical line
        if(y2 >= y1) {
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1, yPt, color);
                ST7735_DrawPixel(x1+1, yPt, color);
            }
        }
        else {
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2, yPt, color);
                ST7735_DrawPixel(x2+1, yPt, color);
            }
        }
    }
    else if (y2 == y1) { //if horizontal line
        if(x2 >= x1) {
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, y1, color);
                ST7735_DrawPixel(xPt+1, y1, color);
            }
        }
        else {
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, y2, color);
                ST7735_DrawPixel(xPt+1, y2, color);
            }
        }
    }
    
    //all other cases have to do with relative positions of x1 and x2
    else if(x2 > x1 && y2 > y1) {
        if((x2 - x1) >= (y2 - y1)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color);    //slope point formula
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1)))),color);
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt, color);
            }
        }
    }
    else if (x2 > x1 && y1 > y2) {
        if((x2 - x1) >= (y1 - y2)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1)))),color);
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt, color);         
            }
        }
    }
    else if (x1 > x2 && y2 > y1) {
        if((x1 - x2) >= (y2 - y1)) {
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + ((slope)*((float)(xPt-x2)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y2 +((slope)*((float)(xPt-x2)))),color);
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt, color);
            }
        }
    }
    else if (x1 > x2 && y1 > y2){
        if((x1 - x2) >= (y1 - y2)) {    
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + (uint16_t)((slope)*((float)(xPt-x2)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y2 + (uint16_t)((slope)*((float)(xPt-x2)))),color);
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt, color);        
            }
        }
    }

}

//*************drawHour********************************************
//  Draws four-pixel wide line on the ST7735 color LCD (Hour hand)
//  Inputs: (x1,y1) is the start point
//          (x2,y2) is the end point
// x1,x2 are horizontal positions, columns from the left edge
//               must be less than 128
//               0 is on the left, 126 is near the right
// y1,y2 are vertical positions, rows from the top edge
//               must be less than 160
//               159 is near the wires, 0 is the side opposite the wires
//        color 16-bit color, which can be produced by ST7735_Color565() 
// Output: none
void drawHour(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color) {
    float slope = 0;
    if (x2 == x1) { //if vertical line
        if(y2 >= y1) {
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1, yPt, color);
                ST7735_DrawPixel(x1+1, yPt, color);
                ST7735_DrawPixel(x1, yPt+1, color);
                ST7735_DrawPixel(x1+1, yPt+1, color);
            }
        }
        else {
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2, yPt, color);
                ST7735_DrawPixel(x2+1, yPt, color);
                ST7735_DrawPixel(x2, yPt+1, color);
                ST7735_DrawPixel(x2+1, yPt+1, color);
            }
        }
    }
    else if (y2 == y1) { //if horizontal line
        if(x2 >= x1) {
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, y1, color);
                ST7735_DrawPixel(xPt+1, y1, color);
                ST7735_DrawPixel(xPt, y1+1, color);
                ST7735_DrawPixel(xPt+1, y1+1, color);
            }
        }
        else {
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, y2, color);
                ST7735_DrawPixel(xPt+1, y2, color);
                ST7735_DrawPixel(xPt, y2+1, color);
                ST7735_DrawPixel(xPt+1, y2+1, color);
            }
        }
    }
    
    //all other cases have to do with relative positions of x1 and x2
    else if(x2 > x1 && y2 > y1) {
        if((x2 - x1) >= (y2 - y1)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color);    //slope point formula
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1)))),color);
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1))))+1,color);
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1))))+1,color);
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt+1, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt+1, color);
            }
        }
    }
    else if (x2 > x1 && y1 > y2) {
        if((x2 - x1) >= (y1 - y2)) {
            slope = ((float)y2-(float)y1)/((float)x2-(float)x1);    //calculate slope
            for(uint16_t xPt = x1; xPt <= x2; xPt++) {
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1)))),color);
                ST7735_DrawPixel(xPt, (y1 + ((slope)*((float)(xPt-x1))))+1,color);
                ST7735_DrawPixel(xPt+1, (y1 + ((slope)*((float)(xPt-x1))))+1,color);
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt+1, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt+1, color);            
            }
        }
    }
    else if (x1 > x2 && y2 > y1) {
        if((x1 - x2) >= (y2 - y1)) {
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + ((slope)*((float)(xPt-x2)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y2 +((slope)*((float)(xPt-x2)))),color);
                ST7735_DrawPixel(xPt, (y2 + ((slope)*((float)(xPt-x2))))+1,color);
                ST7735_DrawPixel(xPt+1, (y2 + ((slope)*((float)(xPt-x2))))+1,color);
            }
        }
        else {
            slope = ((float)x2-(float)x1)/((float)y2-(float)y1);
            for(uint16_t yPt = y1; yPt <= y2; yPt++) {
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1))), yPt+1, color);
                ST7735_DrawPixel(x1 + ((slope)*((float)(yPt-y1)))+1, yPt+1, color);
            }
        }
    }
    else if (x1 > x2 && y1 > y2){
        if((x1 - x2) >= (y1 - y2)) {    
            slope = ((float)y1-(float)y2)/((float)x1-(float)x2);    //calculate slope
            for(uint16_t xPt = x2; xPt <= x1; xPt++) {
                ST7735_DrawPixel(xPt, (y2 + (uint16_t)((slope)*((float)(xPt-x2)))),color); //slope point formula
                ST7735_DrawPixel(xPt+1, (y2 + (uint16_t)((slope)*((float)(xPt-x2)))),color);
                ST7735_DrawPixel(xPt, (y2 + (uint16_t)((slope)*((float)(xPt-x2))))+1,color);
                ST7735_DrawPixel(xPt+1, (y2 + (uint16_t)((slope)*((float)(xPt-x2))))+1,color);
            }
        }
        else {
            slope = ((float)x1-(float)x2)/((float)y1-(float)y2);
            for(uint16_t yPt = y2; yPt <= y1; yPt++) {
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2))), yPt+1, color);
                ST7735_DrawPixel(x2 + ((slope)*((float)(yPt-y2)))+1, yPt+1, color);            
            }
        }
    }

}



//*************displayMain********************************************
// Draws the Main Screen
// Input: str, the mode to display at bottom center of screen
//  Output: none
void displayMain(char* str){
	uint16_t mode = 0;
	//Prints clock based on clock mode

		ST7735_FillScreen(ST7735_BLACK);
		ST7735_SetTextColor(ST7735_WHITE);

			ST7735_DrawBitmap(24, 119, clock, 80, 80);
		
		mode = 0xFFFF;
	drawSec(62 ,79, secX[global_Sec], secY[global_Sec], mode);
	drawMin(62 ,79, minX[global_Min], minY[global_Min], mode);
	drawHour(62 ,79, hourX[(global_Hour%12)*5+(global_Min/12)], hourY[(global_Hour%12)*5+(global_Min/12)], mode);
	
	//Prints time in top left
	ST7735_SetCursor(0,0);
	if(global_Hour < 10){
		ST7735_OutUDec(0);
		ST7735_OutUDec(global_Hour);
	}
	else{
		ST7735_OutUDec(global_Hour);
	}
	ST7735_OutString(":");
	if(global_Min < 10){
		ST7735_OutUDec(0);
		ST7735_OutUDec(global_Min);
	}
	else{
		ST7735_OutUDec(global_Min);
	}
	ST7735_OutString(":");
	if(global_Sec < 10){
		ST7735_OutUDec(0);
		ST7735_OutUDec(global_Sec);
	}
	else{
		ST7735_OutUDec(global_Sec);
	}
	
	
	//Prints "Home in top right
	ST7735_DrawString(17, 0, "Home", mode);
	

}


