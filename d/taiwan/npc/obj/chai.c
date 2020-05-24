// chai.c
// Last Modifyed by Ahda on Jan. 4 2002

inherit ITEM;
void create()
{
	set_name( "木柴", ({ "mu chai"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "捆");
		set("long","这是一捆木柴。\n");
		set("value", 0);
		set("material", "wood");
	}
}
