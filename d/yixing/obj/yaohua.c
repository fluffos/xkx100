// /d/yixing/obj/yaohua.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("爆炒腰花", ({"yaohua", "yao"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘爆炒腰花。\n");
		set("unit", "盘");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
