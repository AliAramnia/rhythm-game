#include <avr/io.h>
#include <avr/interrupt.h>

#include "timer1.h"
#include "game_state.h"
#include "lcg.h"

// Configure Timer1 in CTC mode with a 3-second interrupt period.
void setupTimer1(void)
{
    cli();

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    // CTC mode
    TCCR1B |= (1 << WGM12);

    // Prescaler = 1024
    TCCR1B |= (1 << CS12) | (1 << CS10);

    // Interrupt every 3 seconds
    OCR1A = 46874;

    // Enable Timer1 Compare Match A interrupt
    TIMSK1 |= (1 << OCIE1A);

    sei();
}

// Disable Timer1 Compare Match A interrupt.
void stopTimer1(void)
{
    TIMSK1 &= ~(1 << OCIE1A);
}
ISR(TIMER1_COMPA_vect)
{
    if (lcgIndex < 10) {
        lcgValue = nextElementLCG(lcgValue, 131, 7, lcgIndex, 255);

        currentDirection = lcgValue % 4;
        movementDetected = false;

        newValue = true;

        lcgIndex++;

        if (lcgIndex == 10) {
            gameActive = true;
        }
    }
    else {
        gameActive = false;
        gameFinished = true;
        TIMSK1 &= ~(1 << OCIE1A);
    }
}
