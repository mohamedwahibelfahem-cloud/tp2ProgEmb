#include "stm32f407xx.h"

void delay(volatile uint32_t time)
{
    while (time--)
    {
        __NOP();
    }
}

int main(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /* PA5 rouge, PA6 jaune, PA7 vert */
    GPIOA->MODER &= ~(3U << 10);
    GPIOA->MODER &= ~(3U << 12);
    GPIOA->MODER &= ~(3U << 14);

    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER |= (1U << 12);
    GPIOA->MODER |= (1U << 14);

    while (1)
    {
        /* Rouge */
        GPIOA->ODR = (1U << 5);
        delay(9000000);

        /* Jaune  */
        GPIOA->ODR = (1U << 6);
        delay(4000000);

        /* Vert */
        GPIOA->ODR = (1U << 7);
        delay(9000000);

        /* Jaune */
        GPIOA->ODR = (1U << 6);
        delay(4000000);
    }
}