# PID制御ライブラリ
~~PID制御を完全に理解したので書いてみた  
"4arduino"とあるように、arduinoで使うために書いた  
だけど、arduinoに依存するものは使ってない、ので別にarduino専用ってわけでもない  
ちなみにtemprateを初めて使ってみた  
temprateも完全に理解した~~
いろいろとアレだったので修正しました
当時はmbedとの互換性を考えてたみたいだけど、普通にarduinoに依存してるので捨てました

# 使い方



## 宣言
```cpp:実はまだ試していないので本当にこれでいいのかはわからない_テストくらいしなさい.cpp
 PID4arduino pid = PID4arduino<int>;
 PID4arduino pid = PID4arduino<double>;

```
intやdouble,floatを使って宣言できる  
この型は入出力に使われる

## ゲイン設定
```cpp:hogehoge.cpp
PID4Arduino::PIDGain_t Gains;

Gains.KP = P_Gain;
Gains.KI = I_Gain;
Gains.KD = D_Gain

pid.setGains(Gains);
``` 
これを忘れるとゲインはすべてゼロになる  
## 入力
```cpp:fugafuga.cpp
update(int SV, int PV);
update(double SV, double PV);
```
SVが目標値、PVが測定値

## 出力
```cpp:piyopiyo.cpp
analogWrite(pin,pid.GetValue());
```


# info
## 書いた人
 akira2390

## 書き始めた日
 2020/12/16

## 書き終わった日
 2020/12/16

## 修正し始めた日
 2020/10/20