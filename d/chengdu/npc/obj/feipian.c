// Room: /d/chengdu/npc/obj/piang.c 夫妻肺片
// Last Modifyed by Winder on Jan. 4 2002

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("夫妻肺片", ({"piang"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碟夫妻肺片。\n");
		set("unit", "碟");
		set("value", 200);
		set("food_remaining", 6);
		set("food_supply", 120);
	}
}
