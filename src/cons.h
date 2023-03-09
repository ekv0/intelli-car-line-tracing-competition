//pin
#define MotorLeftIn1 3
#define MotorLeftIn2 4
#define MotorRightIn1 5
#define MotorRightIn2 6
#define MotorLeftEnable 9
#define MotorRightEnable 10
#define D80NK 2
#define llsr A0
#define lsr A1
#define msr A2
#define rsr A3
#define rrsr A4
//#define Lsr
//#define Rsr
#define fsr 0

#define volt A5
#define ener_led
#define mem_led

//constant
#define FORWARD 0
#define BACKWARD 1
#define STOP 2

#define LEFT 0
#define RIGHT 1
#define _LEFT 2
#define _RIGHT 3
#define LEFT_ 4
#define RIGHT_ 5
#define STRAIGHT 6
#define END 7
#define RETURN 7
#define MULTI 8

#define PRE RIGHT
#define PRE_ (PRE+4)

#define min_v (3.3*1024.0/5.0)

//macro
#define pI(X) pinMode(X,INPUT)
#define pO(X) pinMode(X,OUTPUT)
#define dR(X) digitalRead(X)
#define aR(X) analogRead(X)
#define InLine(X) (aR(X)>INLINE_SETPOINT)  
#define OffLine(X) (aR(X)<OFFLINE_SETPOINT)
#define diff(X,Y) (Abs(aR(X)-aR(Y))<=DIFF)
#define Abs(X) ((X>=0)? X : -X)
