// mapo-doufu.c 麻婆豆腐
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("麻婆豆腐", ({"mapo doufu", "doufu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盆颜色红亮，细中带嫩，香辣可口的麻婆豆腐。\n");
		set("unit", "盆");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
