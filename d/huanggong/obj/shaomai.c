// shaomai.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(HIR"烧卖"NOR, ({"shao mai", "mai"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value", 50);
		set("food_remaining", 5);
		set("food_supply", 5);
	}
}

