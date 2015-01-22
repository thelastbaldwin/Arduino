/* ATtiny85 Low-Power Timer */

#include <avr/sleep.h>
#include <avr/wdt.h>

// Utility macros
#define adc_disable() (ADCSRA &= ~(1<<ADEN)) // disable ADC (before power-off)
#define adc_enable()  (ADCSRA |=  (1<<ADEN)) // re-enable ADC



// constants 
const int Lamp = 0;
//60 * num_minutes * 1000
const unsigned long alarm = 9000 ; // alarm time - 5 minutes
unsigned long time = 0;       // start time

/*
from: http://www.barrgroup.com/Embedded-Systems/How-To/C-Volatile-Keyword
 C's volatile keyword is a qualifier that is applied to a 
 variable when it is declared. It tells the compiler that the
 value of the variable may change at any time--without any 
 action being taken by the code the compiler finds nearby */
volatile boolean f_wdt=1;

void setup()
{
  pinMode(Lamp, OUTPUT);
  adc_disable(); // ADC uses ~320uA
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  setup_watchdog(7);
}

void enterSleep(void)
{
  sleep_enable();
  sleep_cpu();
}

void playBeep(void)
{
  for (int i=0; i < 500; i++)
  {
    digitalWrite(Lamp, HIGH);
    delay(1);
    digitalWrite(Lamp, LOW);
    delay(1);
  }
}

void flashLed(int wait)
{
  digitalWrite(Lamp, HIGH);
  delay(wait);
  digitalWrite(Lamp, LOW);
}

// Main loop ----------------------------------------------

void loop()
{
 
  if(f_wdt == 1){
    f_wdt = 0;
    //make the interval equal to how long the sleep timer is
    time += 1000;
    
    if( time  > alarm){
      flashLed(1000);
    } else{
      flashLed(1);
    }
  }
   enterSleep();
}

//****************************************************************
// 0=16ms, 1=32ms,2=64ms,3=128ms,4=250ms,5=500ms
// 6=1 sec,7=2 sec, 8=4 sec, 9= 8sec
void setup_watchdog(int ii) {

  byte bb;
  int ww;
  if (ii > 9 ) ii=9;
  bb=ii & 7;
  if (ii > 7) bb|= (1<<5);
  bb|= (1<<WDCE);
  ww=bb;


  MCUSR &= ~(1<<WDRF);
  // start timed sequence
  //WDTCR us WDTSCR on newer tiny chips
  WDTCR |= (1<<WDCE) | (1<<WDE);
  // set new watchdog timeout value
  WDTCR = bb;
  WDTCR |= _BV(WDIE);
}
//****************************************************************  
// Watchdog Interrupt Service / is executed when  watchdog timed out
ISR(WDT_vect) {
  f_wdt=1;  // set global flag
}

