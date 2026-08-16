#ifndef TIMER1_H
#define TIMER1_H

// Configure Timer1 to generate an interrupt every 3 seconds.
void setupTimer1(void);

// Disable the Timer1 Compare Match A interrupt.
void stopTimer1(void);

#endif
