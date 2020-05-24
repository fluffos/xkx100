// /d/yixing/obj/tipang.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("卤猪蹄膀", ({"tipang", "ti"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盘卤猪蹄膀。\n");
		set("unit", "盘");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
	}
}
