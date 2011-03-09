#include <element.h>

int update_SOIL(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-2; rx<3; rx++)
		for(ry=-2; ry<3; ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;
                if(parts[r>>8].type==PT_WATR || parts[r>>8].type==PT_DSTW)
                {
                    parts[i].tmp++;
                    kill_part(r>>8);
                }
                if(parts[i].tmp>=3)
                {
                    parts[i].type=PT_VINE;
                    if((r&0xFF)==PT_SOIL)
                    {
                        parts[i].tmp=0;
                        parts[r>>8].tmp++;
                    }    
                }
            }
    return 0;
}
