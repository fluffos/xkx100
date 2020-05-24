// jinshechui.c 金蛇锤

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("金蛇锤", ({ "jinshe chui", "chui","hammer" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一柄金光闪闪的锤柄呈蛇形的大铁锤，后面带着长长
奶础n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N「哗啷」的一声,取出一柄$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n挂回腰间。\n");
	}
	init_hammer(80);
	setup();
}
