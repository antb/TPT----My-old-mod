#include <powder.h>

int update_REMX(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    for(rx=-2;rx<3;rx++)
        for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if(parts[r>>8].type==PT_VIRU && parts[r>>8].tmp == 650)
				{
					parts[r>>8].tmp=510;
				}
			}
}
