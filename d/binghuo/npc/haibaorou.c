// haibaorou.c 海豹肉

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("海豹肉", ({"haibao rou", "rou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块鲜血淋漓肥嫩的海豹肉。\n");
		set("unit", "块");
		set("value", 200);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}
