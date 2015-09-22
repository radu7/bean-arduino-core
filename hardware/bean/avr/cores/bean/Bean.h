#ifndef BEAN_BEAN_BEAN_H
#define BEAN_BEAN_BEAN_H
#include "BeanSerialTransport.h"

// Accel Events.
#define FLAT_EVENT 0x80
#define ORIENT_EVENT 0x40
#define SINGLE_TAP_EVENT 0x20
#define DOUBLE_TAP_EVENT 0x10
#define ANY_MOTION_EVENT 0x04
#define HIGH_G_EVENT 0x02
#define LOW_G_EVENT 0x01

typedef ACC_READING_T AccelerationReading;
typedef LED_SETTING_T LedReading;

class BeanClass {
 public:
  void enableMotionEvent(uint8_t events);
  void disableMotionEvents();
  bool checkMotionEvent(uint8_t events);

  int16_t getAccelerationX(void);
  int16_t getAccelerationY(void);
  int16_t getAccelerationZ(void);
  AccelerationReading getAcceleration(void);
  void accelRegisterWrite(uint8_t reg, uint8_t value);
  int accelRegisterRead(uint8_t reg, uint8_t length, uint8_t* value);
  uint8_t getAccelerationRange(void);
  void setAccelerationRange(uint8_t range);
  void setAccelerometerPowerMode(uint8_t mode);
  uint8_t getAccelerometerPowerMode();
  void accelerometerConfig(uint16_t interrupts, uint8_t power_mode);
  void enableWakeOnAccelerometer(uint8_t sources);
  uint8_t checkAccelInterrupts();

  int8_t getTemperature(void);
  uint8_t getBatteryLevel(void);
  uint16_t getBatteryVoltage(void);
  void enableConfigSave(bool enableSave);

  void setLed(uint8_t red, uint8_t green, uint8_t blue);
  LedReading getLed(void);
  uint8_t getLedRed(void);
  uint8_t getLedGreen(void);
  uint8_t getLedBlue(void);
  void setLedRed(uint8_t intensity);
  void setLedGreen(uint8_t intensity);
  void setLedBlue(uint8_t intensity);

  bool setScratchData(uint8_t bank, const uint8_t* data, uint8_t dataLength);
  bool setScratchNumber(uint8_t bank, uint32_t data);
  ScratchData readScratchData(uint8_t bank);
  long readScratchNumber(uint8_t bank);

  void sleep(uint32_t duration_ms);
  void keepAwake(bool enable);

  void attachChangeInterrupt(uint8_t pin, void (*userFunc)(void));
  void detachChangeInterrupt(uint8_t pin);
  void setAdvertisingInterval(uint16_t interval_ms);
  void enableAdvertising(bool enable, uint32_t timer);
  void enableAdvertising(bool enable);
  bool getConnectionState(void);
  bool getAdvertisingState(void);
  void setBeanName(const String& s);
  const char* getBeanName(void);
  void setBeaconParameters(uint16_t uuid, uint16_t major_id, uint16_t minor_id);
  void setBeaconEnable(bool beaconEnable);
  void enableWakeOnConnect(bool enable);
  void disconnect(void);

  BeanClass() {}

 private:
  bool attemptSleep(uint32_t duration_ms);
  int16_t convertAcceleration(uint8_t high_byte, uint8_t low_byte);
};

extern BeanClass Bean;

#endif
