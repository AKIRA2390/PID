# PID制御ライブラリ
PID制御を完全に理解したので書いてみた  
"4arduino"とあるように、arduinoで使うために書いた  
だけど、arduinoに依存するものは使ってない、ので別にarduino専用ってわけでもない  
ちなみにtemprateを初めて使ってみた  
temprateも完全に理解した


# 使い方



## 宣言
```cpp:実はまだ試していないので本当にこれでいいのかはわからない.cpp
 PID4arduino pid = PID4arduino<int>;
 PID4arduino pid = PID4arduino<double>;

```
intやdouble,floatを使って宣言できる  
この型は入出力に使われる

## ゲイン設定
```cpp:hogehoge.cpp
pid.setGains(kp,ki,kd);
``` 
これを忘れるとゲインはすべてゼロになる  
## 入力
```cpp:fugafuga.cpp
update(int SV, int PV, millis());
update(double SV, double PV, millis());
```
SVが目標値、PVが測定値

## 出力
```cpp:piyopiyo.cpp
analogWrite(pin,pid.write());
```


# info
## 書いた人
 **†*akira2390*†**

## 書き始めた日
 2020/12/16

## 書き終わった日
 2020/12/16