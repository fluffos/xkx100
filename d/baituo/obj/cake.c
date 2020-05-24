//dangao.c
inherit F_FOOD;
inherit ITEM;
void create()
{
	set_name("蛋糕", ({ "cake" }) );
	set_weight(200);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一块香喷喷的大蛋糕。\n");
		set("unit","块");
		set("value",200);
		set("food_remaining",4);
		set("food_supply",20);
	}
	setup();
}
