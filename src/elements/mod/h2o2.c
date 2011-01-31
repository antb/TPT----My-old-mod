#include <powder.h>

int update_H2O2(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-2; rx<3; rx++)
		for(ry=-2; ry<3; ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
	    			continue;
				if((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM)
				{
					if(10>(rand()/(RAND_MAX/100)))  
					{
						pv[y/CELL][x/CELL] += 50.0f; //It is a kind of rocket fuel
					}
					else
					{
						parts[i].temp = 3500.0f;
					}
				}
			}
}

