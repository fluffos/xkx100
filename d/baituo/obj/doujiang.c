// DOUJIANG.C 豆浆

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("豆浆",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一杯热气腾腾的豆浆～～～\n");
		set("unit", "杯");
		set("value", 500);
        set("max_liquid", 4);
	}
	set("liquid", ([
		"type": "water",
		"name": "豆浆",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	setup();
}

