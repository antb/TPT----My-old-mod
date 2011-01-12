/* AntB's TPT Fork - Custom functions > powder.c */
#if defined(WIN32) && !defined(__GNUC__)
_inline void change_particle(int from, int to, int r, int reverse, int chance);
#else
inline void change_particle(int from, int to, int r, int reverse, int chance);
#endif

int partgen();

void change_particle(int from, int to, int r, int reverse, int chance) //Saves a ton of IF statements later.
{
    if((r&0xFF)==from && chance>(rand()/(RAND_MAX/100)))
    	parts[r>>8].type = to;
	if(reverse)
    	if(((r&0xFF)==to) && chance>(rand()/(RAND_MAX/100)))
    		parts[r>>8].type = from;
}

int partgen()
{
    int xyloc = rand()/(RAND_MAX/2);
    if(xyloc == 1)
        return -3;
    if(xyloc == 2)
        return 3;
}
