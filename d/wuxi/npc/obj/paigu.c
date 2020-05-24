// paigu.c 烤鸭

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("无锡酱排骨", ({"jiang paigu", "paigu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块喷香的无锡酱排骨。\n");
		set("unit", "块");
		set("value", 150);
		set("food_remaining", 3);
		set("food_supply", 60);
	}
}
