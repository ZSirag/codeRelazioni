//fix della libreria
void TaskSchedule::sleepNow(){
power_adc_disable();
power_spi_disable();
power_timer0_disable();
power_twi_disable();
set_sleep_mode(SLEEP_MODE_IDLE);
cli();
_schedLock = true;
sleep_enable();
sei();
sleep_cpu();
sleep_disable();
power_all_enable();
}
