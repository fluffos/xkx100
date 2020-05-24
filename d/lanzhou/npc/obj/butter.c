// butter.c 
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(YEL"酥油"NOR, ({"butter", "suyou"}));
	set_weight(60);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗用牦牛奶炼制的酥油。\n");
		set("unit", "碗");
		set("value", 100);
		set("food_remaining", 3);
		set("food_supply", 100);
	}
}
