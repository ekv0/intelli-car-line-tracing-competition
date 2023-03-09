//branch
//
//设想：
//单侧一个及以上传感器在阈值之内就触发;
//Lsr/Rsr在阈值之内时，根据中间5传感器的值决定90°转弯或小角度矫正偏离
int BranchStat()
{
	if (OffLine(llsr) && OffLine(lsr) && OffLine(msr) && OffLine(rsr) && OffLine(rrsr) && diff(lsr,rsr) && diff(llsr,rrsr) && (digitalRead(fsr) == LOW))
		return END;
	if (OffLine(llsr) && OffLine(rrsr))
		return STRAIGHT;
	if (InLine(llsr) && OffLine(rrsr))
		if (digitalRead(fsr) == LOW)
			return _LEFT;
		else
			return LEFT;
	if (OffLine(llsr) && InLine(rrsr))
		if (digitalRead(fsr) == LOW)
			return _RIGHT;
		else
			return RIGHT;
	if (InLine(llsr) && InLine(rrsr))
		return MULTI;
}
