/* ******** Display.h ************** 
 * Samuel Zhang, Zi Zhou Wang
 * 2/3/2018
 * Display and screen print functions
 * Lab 4
 * Saadallah
 * 2/10/2018
 */


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
void displaySec(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

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
void displayMin(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

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
void displayHour(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);


//*************displayMain********************************************
// Draws the Main Screen
// Input: str, the mode to display at bottom center of screen
//  Output: none
void displayMain(char* str);

