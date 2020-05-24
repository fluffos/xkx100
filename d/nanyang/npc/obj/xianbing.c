// Room: /d/nanyang/npc/obj/xianbing.c
// Last Modified by winder on Nov. 20 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("馅饼", ({"xian bing", "bing"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块煎得焦黄焦黄的馅饼。\n");
		set("unit", "块");
		set("value", 50);
		set("food_remaining", 2);
		set("food_supply", 40);
	}
}

