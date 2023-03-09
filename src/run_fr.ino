bool flag;
bool cross_line;
char stat;
struct Head *head;
int val,temp;
int tot;
int cnt;
bool prev;

#include"cons.h"
#include"time.h"
#include"motor.h"
#include"sensor.h"
#include"pid.h"
#include"branch.h"
#include"stack.h"

#include"track.h"

//#define debug

#include"setup.h"

void loop()
{
#ifndef debug
	if (dR(D80NK) == LOW)
		MotorRun(STOP,STOP);
	else
	{
#endif
		stat = BranchStat();
		switch(stat)
		{
			case STRAIGHT:
				Track(STRAIGHT);
				prev = false;
				break;
			case _LEFT:
				Track(LEFT);
				prev = false;
				break;
			case _RIGHT:
				Track(RIGHT);
				prev = false;
				break;
			case LEFT:
				if (!head->tot){
					StackIn(LEFT);
					Track(LEFT);
				}
				else if (!head->first->returning){
					if (head->first->x >= 3)
						head->first->x++;
					else if (head->first->x <= -3)
						head->first->x--;
					StackIn(LEFT);
					Track(LEFT);
				}
				else if (head->first->x == 3){
					Track(STRAIGHT);
					head->first->x = -3;
					head->first->returning = false;
				}
				else if (head->first->x == -3){
					Track(StackOut());
					if (head->tot)
						set(head->first);
				}
				else if (head->first->x > 3){
					head->first->x--;
					Track(STRAIGHT);
				}
				else if (head->first->x < -3){
					head->first->x++;
					Track(STRAIGHT);
				}
				else
					Track(STRAIGHT);
				prev = false;
				break;
			case RIGHT:
				if (!head->tot){
					StackIn(RIGHT);
					Track(RIGHT);
				}
				else if (!head->first->returning){
					if (head->first->x >= 3)
						head->first->x++;
					else if (head->first->x <= -3)
						head->first->x--;
					StackIn(RIGHT);
					Track(RIGHT);
				}
				else if (head->first->x == 3){
					Track(STRAIGHT);
					head->first->x = -3;
					head->first->returning = false;
				}
				else if (head->first->x == -3){
					Track(StackOut());
					if (head->tot)
						set(head->first);
				}
				else if (head->first->x > 3){
					head->first->x--;
					Track(STRAIGHT);
				}
				else if (head->first->x < -3){
					head->first->x++;
					Track(STRAIGHT);
				}
				else
					Track(STRAIGHT);
				prev = false;
				break;
			case MULTI:
				if (!head->tot || !head->first->returning)
				{
					if (digitalRead(fsr) == LOW){
						StackIn(PRE);
						head->first->x = 3;
						Track(PRE);
					}
					else{
						StackIn(PRE);
						head->first->x = 1;
						Track(PRE_);
					}
				}
				else
				{
					if (digitalRead(fsr) == LOW)
						Track(StackOut());
					else
						if (head->first->x == 1){
							Track(STRAIGHT);
							head->first->side = !PRE;
							head->first->x = -1;
							head->first->returning = false;
							delay(EXTRA_TIME);
						}
						else if (head->first->x == -1){
							Track(!PRE);
							head->first->x = 2;
							head->first->returning = false;
						}
						else if (head->first->x == 2){
							Track(STRAIGHT);
							StackOut();
						}
				}
				prev = false;
				break;
			case END:
				if (prev && (++cnt == BNDR)){
					set(head->first);
					Track(RETURN);
					cnt = 0;
				}
				else if (!prev)
				{
					Track(STRAIGHT);
					cnt = 0;
				}
				prev = true;
		}
#ifndef debug
	}
#endif
	if(dR(volt)<min_v)
		digitalWrite(ener_led,HIGH);
	else
		digitalWrite(ener_led,LOW);
	delay(DELAY_TIME);
}
void set(struct Node *ptr)
{
	ptr->returning = true;
	if (ptr->x == 2 && ptr->next != NULL){
		struct Node *pre,*cur;
		for(pre=ptr,cur=pre->next;cur->x==2 && cur->next!=NULL;pre=cur,cur=cur->next)
			cur->returning = true;
		cur->returning = true;
	}
}
