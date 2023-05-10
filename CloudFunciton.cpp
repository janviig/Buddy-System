int ledBlink = D7;
int action = 0;

void setup() 
{
    pinMode(ledBlink, OUTPUT);
}

void loop() 
{
    Particle.subscribe("buddy system", motionSensor);
    action = rand()%3;
    if(action == 1) 
    {
        Particle.publish("buddy system", "wave sensed");
    }
    else if(action == 2) 
    {
        Particle.publish("buddy system", "pat sensed");
    }
    else if(action == 0) 
    {
        Particle.publish("buddy system", "nothing sensed");
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
        display(1000);
        display(1000);
	}
}
