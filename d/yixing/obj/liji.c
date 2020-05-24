// /d/yixing/obj/liji.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("滑熘里脊", ({"liji", "li"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘滑熘里脊。\n");
		set("unit", "盘");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
