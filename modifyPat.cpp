int ledBlink = D7;
int boardLed = D6;
int action = 0;

void setup() 
{
    pinMode(ledBlink, OUTPUT);
    pinMode(boardLed, OUTPUT);
}

void loop() 
{
    Particle.subscribe("task 3.3D particle - buddy system", motionSensor);
    action = rand()%3;
    if(action == 1) 
    {
        Particle.publish("task 3.3D particle - buddy system", "wave sensed");
    }
    else if(action == 2) 
    {
        Particle.publish("task 3.3D particle - buddy system", "pat sensed");
    }
    else if(action == 0) 
    {
        Particle.publish("task 3.3D particle - buddy system", "nothing sensed");
    }
    delay(5000);
}

void display(int time)
{
    digitalWrite(ledBlink, HIGH);
	delay(time);
	digitalWrite(ledBlink, LOW);
	delay(time);
}
void displayPat(int time)
{
    digitalWrite(boardLed, HIGH);
	delay(time);
	digitalWrite(boardLed, LOW);
	delay(time);
}

void motionSensor(const char *event, const char *data)
{

	if (strcmp(data, "wave") == 0)
	{
	    display(500);
	    display(500);
	    display(500);
	}
	else if (strcmp(data, "pat") == 0)
	{
        displayPat(1000);
        displayPat(1000);
        displayPat(1000);
        displayPat(1000);
	}
}


