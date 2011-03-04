#include <element.h>

int update_DBTY(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;

    for(rx=-2;rx<3;rx++)
        for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;
                if(ptypes[(r&0xFF)].properties&PROP_CONDUCTS && parts[r>>8].type!=PT_SPRK && parts[i].life>0 && parts[r>>8].life==0)
                {
                    create_part(r>>8, x+rx, y+ry, PT_SPRK);
                    parts[i].life--;
                    continue;
                }
            }
    return 0;
}
