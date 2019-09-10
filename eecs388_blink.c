#include <stdint.h>

#include "eecs388_lib.h"

/*
  Task 2.1: Review eecs388_lib.h and eecs388_lib.c 

  Task 2.2: Implement RGB blinky. 

    - set red, green, and blue leds as output mode, using gpio_mode() function
    - in the main loop, turn on/off a different LED at each iteration. 
      for example, 
         at 1st iteration
            turn on RED led
	    delay 500 ms 
	    turn off RED led
	    delay 300 ms.
	 at 2nd iteration
	    do the same but for GREEN led
	 at 3rd iteration
	    do the same but for BLUE led
	 at 4th iteration
	    back to RED led. 
	    ...
    - use array and modulo (%) operator to change the color. 

  Task 2.3. Implement RGBA (bonus: +1 point)
    - rotate red, green, blue, and white (all LEDs are enabled) colors.
*/

int main()
{
    int gpioG = GREEN_LED; //variable for green led
    int gpioR = RED_LED; //variable for red led
    int gpioB = BLUE_LED; //variabe for blue led

    int ledArray[3] = {gpioG, gpioR, gpioB}; //array of ints, from eecs388_lib.h gpios are of type int

    gpio_mode(gpioG, OUTPUT); //Initializes the mode of the three leds
    gpio_mode(gpioR, OUTPUT); //to OUTPUT, allowing the board to produce
    gpio_mode(gpioB, OUTPUT); //light via gpio LEDs

   while(1)
   {
      for(int i = 0; i < 4; i++)
      {
         if(i%4 == 0) //branch controlling green led, turns G led on, waits 500ms, turns off
         {
            gpio_write(ledArray[i], ON);
            delay(500);
            gpio_write(ledArray[i], OFF);
            delay(300);
         }
         else if(i%4 == 1) //branch controlling red led, turns R led on, waits 500ms, turns off
         {
            gpio_write(ledArray[i], ON);
            delay(500);
            gpio_write(ledArray[i], OFF);
            delay(300);
         }
         else if(i%4 == 2) //branch controlling blue led, turns B led on, waits 500ms, turns off
         {
            gpio_write(ledArray[i], ON);
            delay(500);                     
            gpio_write(ledArray[i], OFF);
            delay(300);
         }
         else if(i%4 == 3) //branch controlling white led, turns all RGB lights on/off same time
         {
            for(int j = 0; j < 3; j++) //turn on all LEDs
            {
               gpio_write(ledArray[0], ON);
               gpio_write(ledArray[1], ON);
               gpio_write(ledArray[2], ON);
            }
            delay(500);

            for(int j = 0; j < 3; j++) //turn off all LEDs
            {
               gpio_write(ledArray[0], OFF);
               gpio_write(ledArray[1], OFF);
               gpio_write(ledArray[2], OFF);
            }
            delay(300);
         }
      }
   }
}
