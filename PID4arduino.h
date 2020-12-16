#include <Arduino.h>

// intまたはdoubleを想定
template <typename T>
class PID4arduino {
 private:
  double kp = 0, ki = 0, kd = 0;
  T P = 0, I = 0, D = 0,PID = 0;
  T prevPV;
  unsigned long prevTime;

 public:
  PID4arduino() {}
  ~PID4arduino() {}

  void setGains(double kp, double ki, double kd) {
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
  }
  // SVが目標値、PVが測定値、MVが出力
  void update(T SV, T PV, unsigned long now) {
    T MV, error = SV - PV;
    unsigned long dt = (now - prevTime);
    P = error * kp;
    I += dt * error;
    D = error / dt;

    prevTime = now;
    prevPV = PV;
    PID = P + I + D;
  }

  T write() { return PID; }
};
