//TCRT5000
#define INLINE_SETPOINT_0 60
#define OFFLINE_SETPOINT_0 60
#define l_MAX_0 252
#define r_MAX_0 398
#define l_THRE_0 84
#define r_THRE_0 76

//设想：
//给每个传感器命名,Lsr,llsr,lsr,msr,rsr,rrsr,Rsr,fsr
//单独测定每个传感器在固定位置的阈值，使用普通宏规定每个InLine(sensorx),OffLine(sensorx)
#define FACTOR 1

#define INLINE_SETPOINT (FACTOR*INLINE_SETPOINT_0)
#define OFFLINE_SETPOINT (FACTOR*OFFLINE_SETPOINT_0)
#define l_MAX (FACTOR*l_MAX_0)
#define r_MAX (FACTOR*r_MAX_0)
#define l_THRE (FACTOR*l_THRE_0)
#define r_THRE (FACTOR*r_THRE_0)

#define DIFF 5
#define SLIDE 0

#define BNDR 50
