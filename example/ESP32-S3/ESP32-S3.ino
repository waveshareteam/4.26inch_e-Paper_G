#include "EPD_4in26g.h"
#include "GUI_Paint.h"
#include "fonts.h"
#include "ImageData.h"

void setup() {
    printf("EPD_4IN26G_test Demo\r\n");
    DEV_Module_Init();

    printf("e-Paper Init and Clear...\r\n");
    EPD_4IN26G_Init();
    EPD_4IN26G_Clear(EPD_4IN26G_WHITE); // White
    DEV_Delay_ms(2000);

    //Create a new image cache
    UBYTE *BlackImage;
    UDOUBLE Imagesize = ((EPD_4IN26G_WIDTH % 4 == 0)? (EPD_4IN26G_WIDTH / 4 ): (EPD_4IN26G_WIDTH / 4 + 1)) * EPD_4IN26G_HEIGHT;
    if((BlackImage = (UBYTE *)malloc(Imagesize)) == NULL) {
        printf("Failed to apply for black memory...\r\n");
    }
    printf("Paint_NewImage\r\n");
    Paint_NewImage(BlackImage, EPD_4IN26G_WIDTH, EPD_4IN26G_HEIGHT, 0, EPD_4IN26G_WHITE);
    Paint_SetScale(4);

#if 1   // show bmp
    printf("show bmp--------------\r\n");
    EPD_4IN26G_Init_Fast();
    EPD_4IN26G_Display(Image4color);
    DEV_Delay_ms(5000);
#endif

#if 1   // Drawing on the image
    //1.Select Image
    EPD_4IN26G_Init();
    printf("SelectImage:BlackImage\r\n");
    Paint_NewImage(BlackImage, EPD_4IN26G_WIDTH, EPD_4IN26G_HEIGHT, 0, EPD_4IN26G_WHITE);
    Paint_SetScale(4);
    Paint_SelectImage(BlackImage);
    Paint_Clear(EPD_4IN26G_WHITE);

    // 2.Drawing on the image
    printf("Drawing:BlackImage\r\n");
    Paint_DrawPoint(10, 80, EPD_4IN26G_RED, DOT_PIXEL_1X1, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 90, EPD_4IN26G_YELLOW, DOT_PIXEL_2X2, DOT_STYLE_DFT);
    Paint_DrawPoint(10, 100, EPD_4IN26G_BLACK, DOT_PIXEL_3X3, DOT_STYLE_DFT);
    Paint_DrawLine(20, 70, 70, 120, EPD_4IN26G_RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawLine(70, 70, 20, 120, EPD_4IN26G_RED, DOT_PIXEL_1X1, LINE_STYLE_SOLID);
    Paint_DrawRectangle(20, 70, 70, 120, EPD_4IN26G_YELLOW, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawRectangle(80, 70, 130, 120, EPD_4IN26G_YELLOW, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawCircle(45, 95, 20, EPD_4IN26G_BLACK, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
    Paint_DrawCircle(105, 95, 20, EPD_4IN26G_BLACK, DOT_PIXEL_1X1, DRAW_FILL_FULL);
    Paint_DrawLine(85, 95, 125, 95, EPD_4IN26G_RED, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawLine(105, 75, 105, 115, EPD_4IN26G_YELLOW, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
    Paint_DrawString_EN(10, 0, "Red,yellow,white and black", &Font16, EPD_4IN26G_RED, EPD_4IN26G_YELLOW);
    Paint_DrawString_EN(10, 20, "Four color e-Paper", &Font12, EPD_4IN26G_YELLOW, EPD_4IN26G_BLACK);
    Paint_DrawString_CN(150, 20, "微雪电子", &Font24CN, EPD_4IN26G_RED, EPD_4IN26G_WHITE);
    Paint_DrawNum(10, 35, 123456, &Font12, EPD_4IN26G_RED, EPD_4IN26G_WHITE);

    printf("EPD_Display\r\n");
    EPD_4IN26G_Display(BlackImage);
    DEV_Delay_ms(3000);
#endif

    printf("Clear...\r\n");
    EPD_4IN26G_Init();
    EPD_4IN26G_Clear(EPD_4IN26G_WHITE);
    DEV_Delay_ms(2000);

    printf("Goto Sleep...\r\n");
    EPD_4IN26G_Sleep();
    free(BlackImage);
    BlackImage = NULL;
    DEV_Delay_ms(2000);//important, at least 2s
    // close 5V
    printf("close 5V, Module enters 0 power consumption ...\r\n");
    DEV_Module_Exit();

}

void loop() {
  

}
