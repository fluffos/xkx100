// bing2.c

inherit F_FOOD;
inherit ITEM;

void create()
{
	set_name("红豆饼", ({ "hongdou bing2","bing2"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块刚出炉，热气腾腾的红豆饼。\n");
		set("unit", "块");
		set("value", 100);
		set("food_remaining", 2);
		set("food_supply", 20);
	}
	setup();
}
