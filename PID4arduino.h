#include <Arduino.h>

namespace PID4Arduino {
typedef struct PIDGain_t {
  double KP = 0, KI = 0, KD = 0;
};

template <typename T>  // intまたはdoubleを想定
class PID4arduino {
 private:
  PIDGain_t PIDGains;
  T P = 0, I = 0, D = 0, PID = 0;
  T prevPV = 0;
  unsigned long prevTime = 0;

 public:
  PID4arduino() {}
  ~PID4arduino() {}

  void setGains(PIDGain_t Gains) { memcpy(&PIDGains, &Gains, sizeof(Gains)); }

  // SVが目標値、PVが測定値
  void update(T SV, T PV) {
    T error = SV - PV;
    unsigned long now = millis(), dt = now - prevTime;

    P = error * PIDGains.KP;
    I += dt * error * PIDGains.KI;
    D = error / dt * PIDGains.KD;

    PID = P + I + D;

    prevTime = now;
    prevPV = PV;
  }

  T GetValue() { return PID; }
};
}  // namespace PID4Arduino