void changeParticle(int from, int to, int r, int reverse, int chance);

void changeParticle(int from, int to, int r, int reverse, int chance) //Saves a ton of IF statements later.
{
	if((r&0xFF)==from && chance>(rand()/(RAND_MAX/100)))
	parts[r>>8].type = to;
	if(reverse)
	if(((r&0xFF)==to) && chance>(rand()/(RAND_MAX/100)))
		parts[r>>8].type = from;
}

