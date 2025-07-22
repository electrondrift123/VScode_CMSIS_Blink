#include "stm32f411xe.h"
#include "core_cm4.h"
#include "system_stm32f4xx.h"

int main(void){

    // Initialize the system clock
    SystemInit();

    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN; // Enable GPIOA clock
    GPIOC->MODER  &= ~(3 << (13 * 2)); // Clear mode for PC13
    GPIOC->MODER  |= (1 << (13 * 2)); // Set

    while (1) {
        GPIOC->ODR ^= (1 << 13); // Toggle PC13
        for (volatile int i = 0; i < 100000; i++); // Simple delay
    }
}