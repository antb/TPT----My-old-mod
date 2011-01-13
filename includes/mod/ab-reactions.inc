/* AntB's Fork - Element Reactions > powder.c */
if (t==PT_NEUT || t==PT_MUNE)
	if ((r&0xFF)==PT_LEAD || (r&0xFF)==PT_LLED)
	{
		kill_part(i);
		if(!legacy_enable)
			parts[r>>8].temp = restrict_flt(parts[r>>8].temp+parts[i].temp/2, MIN_TEMP, 650.0f);//3.0f;
	}

if(t==PT_CLOU)
    for(nx=-5;nx<6;nx++)
        for(ny=-5;ny<6;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
    				continue;  
                int xClou, yClou;
                if((r&0xFF)==PT_CLOU)
/*                {
    // ---Movement--- (Fails)
                    xClou = rand()/(RAND_MAX/7.8f)-3.9f;
                    yClou = rand()/(RAND_MAX/7.8f)-3.9f;
                    if(nx < 0)
                        parts[i].vx-=xClou;
                    else if(nx > 0)
                        parts[i].vx-=;

                    if(ny < 0)
                        parts[i].vx-=(rand()/(RAND_MAX/7.8f)-3.9f);
                    else if(ny > 0)
                        parts[i].vx-=(rand()/(RAND_MAX/7.8f)-3.9f);
                }//*/
    // ---Production ---
                
                if(10 > (rand()/(RAND_MAX/10000)))
                {
/*                    if(pv[y/CELL][x/CELL] <= -40.0f)
                        create_part(i,x,y,PT_FOG);
                    else if(pv[y/CELL][x/CELL] <= -2.0f)
                        create_part(-1,x+xClou,y+yClou, PT_SNOW);
                    else if(pv[y/CELL][x/CELL] >= 40.0f)
                    {
                        if(50 > rand()/(RAND_MAX/100))
                        {
                            xClou = partgen();
                            yClou = partgen();
                            create_part(-1,x+xClou,y+yClou, PT_WATR);
                        }
                        else
                        {
                            xClou = partgen();
                            yClou = partgen();
                            create_part(-1,x+xClou,y+yClou, PT_THDR);
                        }
                    }
                    else
*/                        xClou = partgen();
                        yClou = partgen();
                        create_part(-1,xClou+x,yClou+y, PT_WATR);
                }
            }

if(t==PT_DBTY)
    for(nx=-2;nx<3;nx++)
        for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
    				continue;
                if(ptypes[(r&0xFF)].properties&PROP_CONDUCTS && parts[r>>8].type!=PT_SPRK && parts[i].life>0 && parts[r>>8].life==0)
                {
                    create_part(r>>8, x+nx, y+ny, PT_SPRK);
                    parts[i].life--;
                    continue;
                }
            }

if(t==PT_SBTY)
    for(nx=-2;nx<3;nx++)
        for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
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
					{
						parts[i].life = 9;
					}
					else if(parts[i].life==0&&parts[r>>8].life==10)
					{
						parts[i].life = 10;
					}
				}

                if(ptypes[(parts[r>>8].type)].properties&PROP_CONDUCTS && parts[r>>8].type!=PT_PSCN && parts[r>>8].type!=PT_NSCN && parts[r>>8].life==0)
                {
                    create_part(r>>8, x+nx, y+ny, PT_SPRK);
                    continue;
                }
           }


if(t==PT_SOIL && pv[y/CELL][x/CELL]>=6.0f)
    parts[i].type=PT_ERTH;
if(t==PT_ERTH && pv[y/CELL][x/CELL]<=-6.0f)
    parts[i].type=PT_SOIL;

if(t==PT_SOIL)
	for(nx=-2; nx<3; nx++)
		for(ny=-2; ny<3; ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
    				continue;
                if(parts[r>>8].type==PT_WATR || parts[r>>8].type==PT_DSTW)
                {
                    parts[i].tmp++;
                    kill_part(r>>8);
                }
                if(parts[i].tmp>=3)
                {
                    parts[i].tmp=0;
                    parts[i].type=PT_PLNT;
                }
            }

if(t==PT_ZINC || t==PT_SLTW || t==PT_METL)
	for(nx=-2; nx<3; nx++)
		for(ny=-2; ny<3; ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
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
	for(nx=-2; nx<3; nx++)
		for(ny=-2; ny<3; ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
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

if(t==PT_H2O2)
{
	for(nx=-2; nx<3; nx++)
		for(ny=-2; ny<3; ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
	    			continue;
				if((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM)
				{
					if(10>(rand()/(RAND_MAX/100)))  
					{
						pv[y/CELL][x/CELL] += 70.0f; //It is a kind of rocket fuel
					}
					else
					{
						pt = parts[i].temp = 3500.0f;
					}
				}
			}
}
if(t==PT_GROW)
{
	for(nx=-1;nx<2;nx++)
		for(ny=-1;ny<2;ny++)
			if(x+nx>=0 && y+ny>0 &&
			   x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if((r&0xFF)!=PT_GROW && (r&0xFF)!=PT_CLNE && (r&0xFF)!=PT_PCLN && (r&0xFF)!=PT_NONE && (r&0xFF)!=PT_DMND && (r&0xFF))
					create_part(i,x+nx,y+ny,(r&0xFF));			   
			}
}

if(t==PT_RADI)
{
	for(nx=-1; nx<2; nx++)
		for(ny=-1; ny<2; ny++)
			if(x+nx>=0 && y+ny>0 &&
			   x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if(10>rand()/(RAND_MAX/100))
					parts[i].life--;

				if(parts[i].life <= 0)
				{
					kill_part(i);
					create_part(-1,x,y,PT_RADO);
				}
			}
}
if(t==PT_RADO)
{
	for(nx=-1; nx<2; nx++)
		for(ny=-1; ny<2; ny++)
			if(x+nx>=0 && y+ny>0 &&
			   x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if(10>(rand()/(RAND_MAX/1000)))
					create_part(r>>8, x+nx, y+ny, PT_NEUT);
			}
}
if(t==PT_LO2)
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
		{		  
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
			r=pmap[y+ny][x+nx];
				if ((r&0xFF)==PT_LH2)
				{
					parts[i].type=PT_H2O2;
					parts[r>>8].type=PT_H2O2;
				}
			}
		}
}
else if(t==PT_O2)
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
		{		  
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
			r=pmap[y+ny][x+nx];
				if ((r&0xFF)==PT_H2)
				{
					parts[i].type=PT_WATR;
					parts[r>>8].type=PT_WATR;
				}
			}
		}
}

if(t==PT_SUWR)
	if(parts[i].life!=0)
		parts[i].life = 4;

if(t==PT_VIRU)
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if(parts[r>>8].type!=PT_VIRU && parts[r>>8].tmp!=512)
				{
					parts[r>>8].ctype=parts[r>>8].type;
					parts[r>>8].type=PT_VIRU;
				}
				if(parts[r>>8].tmp==512)
					parts[i].tmp=512;
				if(parts[i].tmp==512)
					parts[i].type=parts[i].ctype;
			}
}

if(t==PT_PHOT)
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if(parts[r>>8].type==PT_VIRU)
				{
					parts[r>>8].tmp=512;
				}
			}
}

if(t==PT_MUPT || t==PT_MUNE)
{
	for(nx=-2; nx<3; nx++)
		for(ny=-2; ny<3; ny++)
		{
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				//change_particle(PT_FROM,PT_TO,r,Reversable?,Chance in 100)
				change_particle(PT_GUNP,PT_DUST,r,0,15);
				change_particle(PT_DYST,PT_DUST,r,0,15);
				change_particle(PT_WATR,PT_DSTW,r,0,5);
				change_particle(PT_PLEX,PT_GOO,r,0,15);
				change_particle(PT_NITR,PT_DESL,r,0,10);
				change_particle(PT_PLNT,PT_WOOD,r,0,15);
				change_particle(PT_DESL,PT_GAS,r,0,5);
				change_particle(PT_COAL,PT_WOOD,r,0,20);
				change_particle(PT_BHOL,PT_WHOL,r,1,50);
				change_particle(PT_SMKE,PT_DUST,r,0,15);
				change_particle(PT_BTRY,PT_METL,r,0,15);
				change_particle(PT_PTCT,PT_NTCT,r,1,100);
				change_particle(PT_PSCN,PT_NSCN,r,1,100);
				change_particle(PT_NBLE,PT_O2,r,1,15);
				change_particle(PT_WTRV,PT_SLTW,r,0,15);
				change_particle(PT_BRMT,PT_BMTL,r,0,15);
				change_particle(PT_BGLA,PT_GLAS,r,0,15);
				change_particle(PT_PLSM,PT_URAN,r,0,15);
				change_particle(PT_ACID,PT_DSTW,r,1,15);
                change_particle(PT_NP2, PT_DESL,r,0,25);
				change_particle(PT_STKM,PT_BAGL,r,0,5);

				if((r&0xFF)==PT_YEST)
				{
				if(15>(rand()%100000)&&isplayer==0)
					parts[r>>8].type = PT_STKM;
				else 
					parts[r>>8].type = PT_DYST;
				}
			}
		}
}
if(t==PT_YEST || t==PT_DYST)
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r=pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
				if((r&0xFF)==PT_BGLA)
				{
					parts[i].type = PT_BAGL;
					parts[r>>8].type = PT_BAGL;
				}
			}
}


else if(t==PT_NP2)
{
    if(parts[i].life<=0)
    {
        t = PT_NONE;
        kill_part(i);
        create_part(-1, x, y, PT_FIRE);
        goto killed;
    }
    for(nx=-2; nx<3; nx++)
        for(ny=-2; ny<3; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if(parts[i].tmp == 1 && !r)
                {
                    parts[i].life--;
                    create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_FIRE);
                }
                if((r>>8)>=NPART || !r)
                    continue;
                if(((r&0xFF)==PT_LAVA && parts[r>>8].ctype==PT_THRM) || ((r&0xFF)==PT_NP2 && parts[r>>8].tmp==1) && !parts[i].tmp)
                {
                    parts[i].tmp = 1;
                    if((r&0xFF)==PT_LAVA)
                        kill_part(r>>8);
                }
            }
}

if(t==PT_DESL)
    for(nx=-2; nx<3; nx++)
        for(ny=-2; ny<3; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART || !r)
                    continue;
                if((r&0xFF)==PT_GOO)
                {
                    create_part(-1,x,y,PT_NP2);
                    create_part(r>>8,x+nx,y+ny,PT_NP2);
                }
            }

if(t==PT_SPRK && parts[i].ctype==PT_EMIT)
    create_part(-1,x+rand()%3-1,y+rand()%3-1, PT_PHOT);

if(t==PT_FIRE && parts[i].life<=5 && parts[i].tmp==1)
    parts[i].type=PT_NONE;

if(t==PT_FART)
    for(nx=-2; nx<3; nx++)
        for(ny=-2; ny<3; ny++)
            if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
            {
                if(parts[i].tmp<10 && !parts[i].life)
                    parts[i].life=rand()/(RAND_MAX/50)+20;

                r = pmap[y+ny][x+nx];
                if((r>>8)>=NPART)
                    continue;
                if((r&0xFF)==PT_FIRE || (r&0xFF)==PT_PLSM)
                {
                    pv[y/CELL][x/CELL]=(parts[i].tmp*2);
                    create_part(i,x,y,PT_FIRE);
                    parts[i].life=rand()/(RAND_MAX/25)+20;
                    parts[i].tmp=1;
                    continue;
                }

                if(!r && parts[i].tmp >= 10)
                {
                    int tempX = x+rand()%3-1;
                    int tempY = y+rand()%3-1;                    
                    if(create_part(-1, tempX, tempY, PT_FART))
                    {
                        r = pmap[tempY][tempX];
                        parts[r>>8].tmp=parts[i].tmp*0.9;
                        parts[i].tmp*=0.9;
                        nx=3;
                        ny=3;
                    }
                }
            }
//Neons
if((t==PT_NEUT || t==PT_MUNE) && (
   (r&0xFF)==PT_RNEO || (r&0xFF)==PT_GNEO || (r&0xFF)==PT_BNEO ||
   (r&0xFF)==PT_CNEO || (r&0xFF)==PT_YNEO || (r&0xFF)==PT_MNEO )
  )
{
	for(nx=-2;nx<3;nx++)
		for(ny=-2;ny<3;ny++)
			if(x+nx>=0 && y+ny>0 && x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r=pmap[y+ny][x+nx];
				if((r>>8)>=NPART || !r)
					continue;
            
            rt = rand()/(RAND_MAX/5);
            parts[i].type = PT_RNEO+rt;

            }
}

if(t==PT_RNEO || t==PT_GNEO || t==PT_BNEO || t==PT_CNEO || t==PT_YNEO || t==PT_MNEO)
{
	for(nx=-1; nx<2; nx++)
		for(ny=-1; ny<2; ny++)
			if(x+nx>=0 && y+ny>0 &&
					x+nx<XRES && y+ny<YRES && (nx || ny))
			{
				r = pmap[y+ny][x+nx];
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
				if(rt==PT_RNEO || rt==PT_GNEO || rt==PT_BNEO || rt==PT_CNEO || rt==PT_YNEO || rt==PT_MNEO)
				{
					if(parts[i].life==10&&parts[r>>8].life<10&&parts[r>>8].life>0)
					{
						parts[i].life = 9;
					}
					else if(parts[i].life==0&&parts[r>>8].life==10)
					{
						parts[i].life = 10;
					}
				}
			}
}

