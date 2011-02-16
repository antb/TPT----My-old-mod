#include <powder.h>

int update_GROW(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
	for(rx=-1;rx<2;rx++)
		for(ry=-1;ry<2;ry++)
			if(x+rx>=0 && y+ry>0 &&
			   x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if((r&0xFF)!=PT_GROW && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_NONE && (r&0xFF)!=PT_DMND && (r&0xFF))
					create_part(i,x+rx,y+ry,(r&0xFF));			   
			}
    return 0;
}

