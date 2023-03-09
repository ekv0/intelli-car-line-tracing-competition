//track
//
//设想1：
//除了MULTI外都用STRAIGHT pid
//设想2：
//转弯函数：
//process();
//MotorSpeed(LFS-data.eff-TURN_FACTOR,RFS+data.eff+TURN_FACTOR);
//or
//MotorSpeed(LFS-data.eff,RFS+data.eff+TURN_FACTOR);
//设想3：
//转弯时转动小角度，再使用pid
void Track(int mode)
{
	switch(mode)
	{
		case RETURN:
			MotorRun(STOP,STOP);
			delay(STOP_TIME1);
			MotorSpeed(BACKL,BACKR);
			delay(RETURN_TIME);
			MotorRun(STOP,STOP);
			delay(STOP_TIME1);

			MotorSpeed(LFS,-RFS);
			for (cross_line=false,tot=0;tot<=4*SPIN_TIME;tot+=DELAY_TIME)		//或许可以去掉条件
			{
				if (InLine(rrsr))
					cross_line = true;
				else if (cross_line && InLine(rsr))
					break;
				delay(DELAY_TIME);
			}
			MotorRun(STOP,STOP);
			delay(STOP_TIME2);
			break;
		case STRAIGHT:
			process();
			MotorSpeed(LFS-data.eff,RFS+data.eff);
			break;
		case LEFT:		//直角弯
			MotorSpeed(SLOW,QUICK);
			delay(TURN_TIME);
			break;
		case RIGHT:
			MotorSpeed(QUICK,SLOW);
			delay(TURN_TIME);
			break;
		case LEFT_:
			MotorSpeed(SLOW,QUICK);
			flag = cross_line = false;
			while (!cross_line)
			{
				if (OffLine(rsr) && !flag)
					flag = true;
				else if (flag && InLine(rsr))
					cross_line = true;
				delay(DELAY_TIME);
			}
			delay(SLIDE_TIME);
			break;
		case RIGHT_:
			MotorSpeed(QUICK,SLOW);
			flag = cross_line = false;
			while (!cross_line)
			{
				if (OffLine(lsr) && !flag)
					flag = true;
				else if (flag && InLine(lsr))
					cross_line = true;
				delay(DELAY_TIME);
			}
			delay(SLIDE_TIME);
	}
}
