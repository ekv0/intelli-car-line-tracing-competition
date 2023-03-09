//stack
struct Head {
	int tot;
	struct Node * first;
};
struct Node {
  bool side;
  bool returning;
  int x;
  struct Node * next;
};

void StackCreate(void)
{
	if ((head = (struct Head *) malloc(sizeof(struct Head))) != NULL)
	{
		head->tot = 0;
		head->first = NULL;
	}
	else
	{
		digitalWrite(mem_led,HIGH);
		MotorRun(STOP,STOP);
		while(1);
	}
}
void StackIn(bool side)
{
	struct Node *new_ptr;
	if ((new_ptr = (struct Node *) malloc(sizeof(struct Node))) != NULL)
	{
		new_ptr->side = side;
		new_ptr->returning = false;
		new_ptr->x = 0;
		new_ptr->next = head->first;
		head->first = new_ptr;
		head->tot++;
	}
	else
	{
		digitalWrite(mem_led,HIGH);
		MotorRun(STOP,STOP);
		while(1);
	}
}
bool StackOut(void)
{
	bool val = head->first->side;
	struct Node *first = head->first->next;
	free(head->first);
	head->first = first;
	head->tot--;
	return val;
}
