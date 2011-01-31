/* AntB's Fork - Element Reactions > powder.c */
//Leftovers what I can't figureout where to place, or modify other files

if(t==PT_ZINC || t==PT_SLTW || t==PT_METL)
	for(rx=-2; rx<3; rx++)
		for(ry=-2; ry<3; ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;

                int range=3;

                if(t==PT_SLTW && parts[r>>8].type==PT_ZINC)
                {
                    parts[i].tmp=(range*10)+range;
                    break;
                }
                if(t==PT_SLTW && parts[r>>8].type==PT_METL)
                {
                    parts[i].tmp=(range*10)+range;
                    break;
                }
                if(parts[i].tmp<=range)
                    parts[i].tmp=0;
                
                if(t==PT_SLTW && parts[i].tmp>range+1 && parts[r>>8].tmp==0)
                {
                    parts[r>>8].tmp=parts[i].tmp--;
                }

            }
    

if(t==PT_LAVA && parts[i].ctype==PT_ZINC)
{
	for(rx=-2; rx<3; rx++)
		for(ry=-2; ry<3; ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
    				continue;
                if( parts[r>>8].ctype==PT_BMTL ||
                    parts[r>>8].ctype==PT_BRMT ||
                    parts[r>>8].ctype==PT_METL
                  )
                {
                    parts[i].ctype=PT_GSTL;
                    parts[r>>8].ctype=PT_GSTL;
                }
            }
}

if(t==PT_SUWR)
	if(parts[i].life!=0)
		parts[i].life = 4;

if((parts[i].ctype==PT_VIRU || t==PT_VIRU) && parts[i].tmp > 0 && parts[i].tmp <= 510)
{
    parts[i].tmp--;
    for(rx=-2;rx<3;rx++)
        for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
                if(parts[r>>8].tmp == 650)
                    parts[r>>8].tmp== 505;
            }
}


if(t==PT_YEST || t==PT_DYST)
{
	for(rx=-2;rx<3;rx++)
		for(ry=-2;ry<3;ry++)
			if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
			{
				r=pmap[y+ry][x+rx];
				if((r>>8)>=NPART || !r)
					continue;
				if((r&0xFF)==PT_BGLA)
				{
					parts[i].type = PT_BAGL;
					parts[r>>8].type = PT_BAGL;
				}
			}
}

if(t==PT_DESL)
    for(rx=-2; rx<3; rx++)
        for(ry=-2; ry<3; ry++)
            if(x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry))
            {
                r = pmap[y+ry][x+rx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)==PT_GOO)
                {
                    create_part(-1,x,y,PT_NP2);
                    create_part(r>>8,x+rx,y+ry,PT_NP2);
                }
            }

