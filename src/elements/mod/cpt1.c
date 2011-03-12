#include <element.h>

int update_CPT1(UPDATE_FUNC_ARGS)
{
    int r,rx,ry,rp,rt,ct;

    for(rx=-1;rx<2;rx++)
        for(ry=-1;ry<2;ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
                rp = r>>8;
                rt = (r&0xFF);
                ct = parts[rp].ctype;
				if((r>>8)>=NPART || !r)
    				continue;
                if(parts[i].tmp==0)
                {
                    if(rt==PT_SPRK && parts[rp].life==4 && ct==PT_METL)
                    {
                        parts[rp].type=parts[rp].ctype;
                        parts[rp].life=4;
                        parts[i].life++;
                    }

                    if(parts[i].life>parts[rp].life)
                        parts[rp].life=parts[i].life;

                    if(rt==PT_SPRK && ct==PT_PTCT && parts[i].tmp==0)
                        parts[i].tmp=5;
                }
                else if(parts[i].tmp==5)
                {
                    if(parts[i].life && rt==PT_INWR && parts[rp].life==0)
                    {
                        parts[rp].ctype=parts[rp].type;
                        parts[rp].life=4;
                        parts[rp].type=PT_SPRK;
                        parts[i].life--;
                    }
                    if(parts[i].life<parts[rp].life)
                        parts[rp].life=parts[i].life;
                    if(rt==PT_SPRK && ct==PT_NTCT && parts[rp].tmp==5)
                        parts[i].tmp=4;
                }
				if(rt==PT_CPT1)
				{
					if(parts[i].tmp==5&&parts[r>>8].tmp<5&&parts[r>>8].tmp>0)
						parts[i].tmp = 4;
					else if(parts[i].tmp==0&&parts[r>>8].tmp==4)
						parts[i].tmp = 5;
				}
                if(parts[i].tmp>0&&parts[i].tmp<5)
                    parts[i].tmp--;
            }
}
