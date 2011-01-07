/* AntB's TPT Fork - Life values > powder.c */

if(t==PT_RADI)
    parts[i].life = 1000;

if(t==PT_DBTY)
    parts[i].life = 10;

if(t==PT_MUPT)
{
    float a = (rand()%8) * 0.78540f;
    parts[i].life = 680;
    parts[i].vx = 3.0f*cosf(a);
    parts[i].vy = 3.0f*sinf(a);
}

if(t==PT_CLOU)
{
    parts[i].tmp = (rand()/(RAND_MAX/150))+50;
    float a = (rand()/(RAND_MAX/15))*0.5;
    parts[i].vx = (rand()/(RAND_MAX/6))*cosf(a);
}
if(t==PT_NP2)
    parts[i].life=200;

if(t==PT_MUNE)
{
    float r = (rand()%128+128)/127.0f;
    float a = (rand()%360)*3.14159f/180.0f;
    parts[i].life = rand()%480+480;
    parts[i].vx = r*cosf(a);
    parts[i].vy = r*sinf(a);
}

if(t==PT_FART)
    parts[i].tmp=rand()/(RAND_MAX/200)+500;


