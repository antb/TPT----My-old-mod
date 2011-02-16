#include <powder.h>

int update_SBTY(UPDATE_FUNC_ARGS)
{
    int r,rt,ry,rx;
    for(rx=-2;rx<3;rx++)
        for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;

				rt = parts[r>>8].type;
				if(rt==PT_SPRK)
				{
					if(parts[r>>8].ctype==PT_PSCN)
					{
						parts[i].life = 10;
					}
					else if(parts[r>>8].ctype==PT_NSCN)
					{
						parts[i].life = 9;
					}
				}
				if(rt==PT_SBTY)
				{
					if(parts[i].life==10&&parts[r>>8].life<10&&parts[r>>8].life>0)
						parts[i].life = 9;
					else if(parts[i].life==0&&parts[r>>8].life==10)
						parts[i].life = 10;
				}

                if((r&0xFF)==PT_METL && parts[i].life==10)
                {
                    create_part(r>>8, x+rx, y+ry, PT_SPRK);
                    continue;
                }
           }
    return 0;
}
