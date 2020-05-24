// shegeng.c 蛇羹
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("蛇羹", ({"shegeng", "geng"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗浓浓的蛇羹。「哇!」\n");
		set("unit", "碗");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
