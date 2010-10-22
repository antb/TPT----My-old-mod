/* AntB's Fork - Element Properties > powder.h */

{"MUTP",  PIXPACK(0x800000),  0.0f,	0.00f * CFDS,	1.00f,	1.00f, -0.99f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  0,  1, -1,  SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	251,  "Nuclear - Mutagenic Photons - Mutates elements", TYPE_ENERGY},  
{"BAGL",  PIXPACK(0xA6543E),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,  0.00f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  1,    0,  0,  0,  0, 100, SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	70,   "Solid - Bagel!", TYPE_SOLID},   
{"MUNE",  PIXPACK(0xF78DEE),  0.0f,	0.00f * CFDS,	1.00f,	1.00f, -0.99f,	0.00f,	0.25f,	0.002000f * CFDS, 0,  0,    0,  0,  0,  1, -1,  SC_CUSTOM,	R_TEMP+4.0f     +273.15f,	60,   "Nuclear - Mutagenic Neutrons - Mutates elements", TYPE_ENERGY},
{"RBRI",  PIXPACK(0x990F20),  0.0f,	0.00f * CFDS,	0.90f,	0.00f,  0.00f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  1,  1,  1, 100, SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	150,  "Solid - Red Brick - Solid Construction material, insulates wires.", TYPE_SOLID},  
{"LH2",   PIXPACK(0x5070EF),  0.6f,	0.01f * CFDS,	0.98f,	0.95f,  0.00f,	0.10f,	0.05f,	0.000000f * CFDS, 2,  0,    0,  0,  0,  1, 30,  SC_CUSTOM,	0.0f,				        10,   "Liquid - Liquid Hydrogen. Absolute 0, Highy Explosive when mixed with LOX", TYPE_LIQUID},  
{"H2",    PIXPACK(0x5070FF),  2.0f,	0.00f * CFDS,	0.99f,	0.30f, -0.10f,	0.00f,	3.00f,	0.000000f * CFDS, 0,  1000, 0,  0,  0,  1, 1,   SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	70,   "Gas - Combines with O2 to make WATR", TYPE_GAS},    
{"H202",  PIXPACK(0x6585EF),  0.6f,	0.01f * CFDS,	0.98f,	0.95f,  0.00f,	0.10f,	0.00f,	0.000000f * CFDS, 2,  9999, 0,  0,  0,  1, 37,  SC_CUSTOM,	R_TEMP-283.15f  +273.15f,	70,   "Liquid - Hydrogen Peroxide - Rocket fuel.", TYPE_LIQUID},
{"SUWR",  PIXPACK(0x8080A0),  0.0f,	0.00f * CFDS,	0.90f,	0.00f,  0.00f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  1,  1,  1, 100, SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	251,  "Electrics - Single use wire.", TYPE_SOLID|PROP_CONDUCTS},
{"RADI",  PIXPACK(0x505020),  0.0f,	0.00f * CFDS,	0.90f,	0.00f,  0.00f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  0,  1, 100, SC_CUSTOM,	R_TEMP+30.0f    +273.15f,	251,  "Nuclear - Solid Radioactive substance. Decays into Radon Gas.", TYPE_SOLID},
{"RADO",  PIXPACK(0x50FF20),  1.0f,	0.01f * CFDS,	0.99f,	0.30f, -0.10f,	0.00f,	0.75f,	0.001000f * CFDS, 0,  0,    0,  0,  1,  0, 1,   SC_CUSTOM,	R_TEMP+2.0f     +273.15f,	106,  "Nuclear - Radioactive Gas: Releases the occasional Neutron", TYPE_GAS},
{"GROW",  PIXPACK(0x008000),  2.0f,	0.02f * CFDS,	0.96f,	0.80f,  0.00f,	1.00f,	0.50f,	0.000000f * CFDS, 1,  0,    0,  0,  30, 1, 65,  SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	70,   "Powder - Growth particles, expands whatever element it hits", TYPE_PART|PROP_NEUTPENETRATE},
{"LEAD",  PIXPACK(0x201E1E),  0.0f,	0.00f * CFDS,	0.90f,	0.00f,  0.00f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  1,  1,  1, 100, SC_CUSTOM,	R_TEMP+0.0f	    +273.15f,	255,  "Electrics - Absorbs neutrons and heats up; doubles as a resistor.", TYPE_SOLID|PROP_CONDUCTS},
//Neons
{"R",	  PIXPACK(0x200000),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f	    +273.15f,	106,	"Red Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
{"G",	  PIXPACK(0x002000),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f	    +273.15f,	106,	"Green Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
{"B",	  PIXPACK(0x000020),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f 	+273.15f,	106,	"Blue Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
{"C",	  PIXPACK(0x002020),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f 	+273.15f,	106,	"Cyan Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
{"M",     PIXPACK(0x200020),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f 	+273.15f,	106,	"Magenta Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
{"Y",	  PIXPACK(0x202000),  0.0f,	0.00f * CFDS,	0.00f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  0,  1,  1, 100, SC_NEON,	R_TEMP+0.0f 	+273.15f,	106,	"Yellow Neon - Conductive - Glows when charged with PSCN, Discharge with NSCN", TYPE_SOLID|PROP_NEUTPENETRATE},
//End Neons

{"LLED",  PIXPACK(0x170D0D),  0.5f,	0.05f * CFDS,	0.90f,	0.00f,  0.00f,	3.00f,	0.00f,	0.000000f * CFDS, 2,  0,    0,  0,  1,  1, 100, SC_CUSTOM,	R_TEMP+650.61f	+273.15f,	255,  "Electrics - Molten Lead", TYPE_LIQUID|PROP_CONDUCTS},
{"X",     PIXPACK(0xC000C0),  0.5f,	0.05f * CFDS,   0.90f,  0.50f,  0.10f,  0.20f,  0.00f,  0.000000f * CFDS, 2,  0,    0,  0,  0,  1, 65,  SC_CUSTOM,	R_TEMP+0.0f     +273.15f,	100,  "Unknown?", TYPE_PART},
{"ZINC",  PIXPACK(0x8080A0),  0.0f,	0.00f * CFDS,	0.90f,	0.00f,	0.50f,	0.00f,	0.00f,	0.000000f * CFDS, 0,  0,    0,  1,  20, 1, 100, SC_CUSTOM,	R_TEMP+0.0f 	+273.15f,	70,   "Conductive, reacts with SLTW, meltable", TYPE_SOLID|PROP_CONDUCTS},
{"GSTL",  PIXPACK(0x404070),  0.0f, 0.00f * CFDS,   0.90f,  0.00f,  0.50f,  0.00f,  0.00f,  0.000010f * CFDS, 0,  0,    0,  1,  10, 0, 100, SC_CUSTOM,	R_TEMP+0.0f 	+273.15f,	70,   "Galvanised Steel.", TYPE_SOLID|PROP_CONDUCTS},
//Name    Colour              Advec	Airdrag		Airloss	Loss	Collid	Grav	Diffus	Hotair		  Fal Burn  Exp Mel Hrd M  W    Section 	H       			Ins(real world, by triclops200) Description

/* fal --> 0=Solid/Gas 1=Powder 2 = Liquid  */

