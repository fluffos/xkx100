// Room: /d/huijiang/obj/xiangcha.c 香茶
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
void init();

void create()
{
	set_name("香茶",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯热茶，悠悠地冒着香气～～～\n");
		set("unit", "杯");
		set("value", 30);
		set("remaining",10);
		set("drink_supply", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "茶",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}

