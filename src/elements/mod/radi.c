#include <element.h>

int update_RADI(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-1; rx<2; rx++)
		for(ry=-1; ry<2; ry++)
			if(x+rx>=0 && y+ry>0 &&
			   x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if(10>rand()/(RAND_MAX/100))
					parts[i].life--;

				if(parts[i].life <= 0)
				{
					kill_part(i);
					create_part(i,x,y,PT_RADO);
				}
			}
}

