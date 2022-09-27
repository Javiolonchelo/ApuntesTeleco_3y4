
HAL_Init();

SystemClock_Config();

SystemCoreClock = X; // la frecuencia de reloj con la que queramos trabajar

HSE_VALUE = 8000000; // Definir como etiqueta del compilador.

/* Segunda transparencia de GPIOs : entender bien antes de seguir */

__HAL_RCC_GPIOA_CLK_ENABLE();

GPIO_InitStruct.Pin  = GPIO_PIN_3;
GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; // Configura el pin para utilizar la parte push-pull (los mosfet de la
                                            // salida digital, ver diapositiva 8 de GPIOs)
GPIO_InitStruct.Pull  = NOPULL;             // Las resistencias de pull-up y pull-down no están conectadas
GPIO_InitStruct.Speed = NOPULL;

/* Funciones alternativas */

__HAL_RCC_GPIOA_CLK_ENABLE();

GPIO_InitStruct.Pin        = GPIO_PIN_0;             // Mirar qué funciones alternativas acepta el pin
GPIO_InitStruct.Mode       = GPIO_MODE_OUTPUT_AF_PP; // Configura el pin para utilizar las funciones alternativas
GPIO_InitStruct.Pull       = NOPULL;                 // Las resistencias de pull-up y pull-down no están conectadas
GPIO_InitStruct.Speed      = NOPULL;
GPIO_InitStruct.Altternate = GPIO_AF1_TIM2;
HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

/* SysTick Timer se ejecutará cada 1 ms en el NVIC (gestor de interrupciones). Las rutinas de atención a la interrupción
 * (ISR) deben ser pequeñas y simples, pero tampoco lo demasiado como para cargar al main con todas las tareas */

/* Después del reset, todas las interrupciones están deshabilitadas excepto Reset, NMI y Hard Fault. Las etiquetas se
 * habilitan como aparece a continuación */
void HAL_NVIC_EnableIrq(IRQn_Type_ IRQn);
void HAL_NVIC_DisableIrq(IRQn_Type_ IRQn);