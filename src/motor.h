//motor
#define LFS 65
#define RFS 70
#define LLS
#define RLS
#define SLOW -70
#define QUICK 70
#define BACKL -80
#define BACKR -90

#define SPEED 60
#define LENGTH 5

void MotorRun(int lo, int ro) 
{
	if (lo == FORWARD) 
	{
		digitalWrite(MotorLeftIn1,HIGH);
		digitalWrite(MotorLeftIn2,LOW);
	}
	else if (lo == BACKWARD) 
	{
		digitalWrite(MotorLeftIn1,LOW);
		digitalWrite(MotorLeftIn2,HIGH);
	}
	else 
	{
		digitalWrite(MotorLeftIn1,LOW);
		digitalWrite(MotorLeftIn2,LOW);
	}

	if (ro == FORWARD)
	{
		digitalWrite(MotorRightIn1,HIGH);
		digitalWrite(MotorRightIn2,LOW);
	}
	else if (ro == BACKWARD)
	{
		digitalWrite(MotorRightIn1,LOW);
		digitalWrite(MotorRightIn2,HIGH);
	}
	else
	{
		digitalWrite(MotorRightIn1,LOW);
		digitalWrite(MotorRightIn2,LOW);
	}
}
void MotorSpeed(int lval, int rval)
{
	MotorRun((lval>0)? FORWARD : BACKWARD,(rval>0)? FORWARD : BACKWARD);
	if (lval > 255 || lval < -255) 
		lval = 255;
	if (rval > 255 || rval < -255)
		rval = 255;
	analogWrite(MotorLeftEnable,Abs(lval));
	analogWrite(MotorRightEnable,Abs(rval));
}
