//pid
#define added_pid

#define K_p 0.0608
#define K_i 0.032
#define K_d 0.021

struct Added_PID {
  int cur;
  int prev;
  int prev_prev;
  int eff;
};
struct Pos_PID {
  int cur;
  int prev;
  long long accum;
  int eff;
};

#ifdef added_pid
Added_PID data;
#else
Pos_PID data;
#endif

void process()
{
	temp = aR(lsr) - aR(rsr) + SLIDE;
	if ((val=aR(msr)) <= l_THRE && temp >= 0)
		data.cur = 2 * l_MAX - temp;
	else if (val <= r_THRE && temp <= 0)
		data.cur = -2 * r_MAX - temp;
	else
		data.cur = temp;

#ifdef added_pid
	data.eff = K_p * (data.cur - data.prev) + K_i * data.cur + K_d * (data.cur - 2*data.prev + data.prev_prev);
	data.prev_prev = data.prev;
	data.prev = data.cur;
#else
	data.accum += data.cur;
	data.eff = K_p * data.cur + K_i * data.accum + K_d * (data.cur - data.prev);
	data.prev = data.cur;
#endif
}
//若用5路pid，将左右两边处理后的数据相加，每边增加l/2有效宽度
