#include <element.h>

int update_SLUG(UPDATE_FUNC_ARGS)
{
    int r,rx,ry;
    for(rx=-3; rx<4; rx++)
        for(ry=-3; ry<4; ry++)
            if(x+rx>=0 && y+ry>0 &&
			   x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;

                if ((r&0xFF) == PT_SPRK && parts[r>>8].life == 4)
                {
                    parts[i].tmp+=1;
                }

                if (((r&0xFF)== PT_SPRK && parts[r>>8].ctype == PT_PSCN) || 
                    (((r&0xFF) == PT_SLUG) || (r&0xFF) == PT_ESLG) && (parts[r>>8].vx || parts[r>>8].vy))
                {
                    if(ry < 0)
                        parts[i].vy+=parts[i].tmp; 
                    else if(rx < 0)
                        parts[i].vx+=parts[i].tmp;
                    else if (ry > 0)
                        parts[i].vy-=parts[i].tmp;
                    else if (rx > 0)
                        parts[i].vx-=parts[i].tmp;
                    continue;
                }

           }

    if (parts[i].type==PT_ESLG && (parts[i].vx || parts[i].vy))
    {
        if(parts[i].tmp < 20)
            parts[i].tmp+=20;
        if(parts[i].tmp2 < parts[i].tmp)
            parts[i].tmp2++;
        else if (parts[i].tmp2 >= parts[i].tmp)
        {
            kill_part(i);
            create_part(i,x,y,PT_BOMB);
        }
    }

//remove obstacles. 
    if(parts[i].vx < 0)
    {
        for(rx=0;rx>(parts[i].vx*1.5f);rx--)
        {
            r = pmap[y][x+rx+1];
            if((r&0xFF) && (r&0xFF)!=PT_SLUG && (r&0xFF)!= PT_ESLG && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_VOID && (r&0xFF)!=PT_BHOL && (r&0xFF)!=PT_PRTI && (r&0xFF)!=PT_PRTO)
                kill_part(r>>8);
        }
    }
    else if(parts[i].vx > 0)
    {
        for(rx=0;rx<(parts[i].vx*1.5f);rx++)
        {
            r = pmap[y][x+rx-1];
            if((r&0xFF) && (r&0xFF)!=PT_SLUG && (r&0xFF)!= PT_ESLG && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_VOID && (r&0xFF)!=PT_BHOL && (r&0xFF)!=PT_PRTI && (r&0xFF)!=PT_PRTO)
                kill_part(r>>8);
        }
    }
    else if(parts[i].vy < 0)
    {
        for(ry=0;ry>(parts[i].vy*1.5f);ry--)
        {
            r = pmap[y+ry+1][x];
            if((r&0xFF) && (r&0xFF)!=PT_SLUG && (r&0xFF)!= PT_ESLG && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_VOID && (r&0xFF)!=PT_BHOL && (r&0xFF)!=PT_PRTI && (r&0xFF)!=PT_PRTO)
                kill_part(r>>8);
        }
    }
    else if(parts[i].vy > 0)
    {
        for(ry=0;ry<(parts[i].vy*1.5f);ry++)
        {
            r = pmap[y+ry-1][x];
            if((r&0xFF) && (r&0xFF)!=PT_SLUG && (r&0xFF)!= PT_ESLG && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_VOID && (r&0xFF)!=PT_BHOL && (r&0xFF)!=PT_PRTI && (r&0xFF)!=PT_PRTO)
                kill_part(r>>8);
        }
    }
    return 0;
}
