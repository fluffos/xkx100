// shaobing.c

inherit ITEM;
inherit F_FOOD;
#include <ansi.h>
void create()
{
	set_name(YEL"肉末烧饼"NOR, ({"roumo shaobing", "bing"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "只");
		set("value", 100);
		set("food_remaining", 10);
		set("food_supply", 5);
	}
}

