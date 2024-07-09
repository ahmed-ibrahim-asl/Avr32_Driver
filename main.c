#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint16_t t1 = 0;
volatile uint16_t t2 = 0;
volatile uint16_t period = 0;
volatile uint8_t capture_flag = 0;

ISR(TIMER1_CAPT_vect) {
    if (capture_flag == 0) {
        t1 = ICR1;
        capture_flag = 1;
        TCCR1B &= ~(1 << ICES1); // Switch to falling edge
    } else {
        t2 = ICR1;
        period = t2 - t1;
        capture_flag = 0;
        TCCR1B |= (1 << ICES1); // Switch to rising edge
    }
}

void timer1_init() {
    TCCR1A = 0x00;
    TCCR1B = (1 << ICES1) | (1 << CS10); // Rising edge, no prescaler
    TIMSK = (1 << TICIE1); // Enable input capture interrupt
    sei(); // Enable global interrupts
}

int main() {
    DDRB &= ~(1 << PB0); // Set PB0 as input (ICP1 pin)
    timer1_init();

    while (1) {
        if (capture_flag == 0 && period != 0) {
            // Do something with the period
        }
    }

    return 0;
}
