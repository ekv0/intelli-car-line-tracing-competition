//setup
void setup()
{
	pO(MotorLeftIn1);
	pO(MotorLeftIn2);
	pO(MotorRightIn1);
	pO(MotorRightIn2);
	pO(MotorLeftEnable);
	pO(MotorRightEnable);
	pI(D80NK);
	pI(llsr);
	pI(lsr);
	pI(msr);
	pI(rsr);
	pI(rrsr);
	pI(fsr);

	pO(ener_led);
	pO(mem_led);

	StackCreate();
	data = {0,0,0,0};
	cnt = 0;
}
