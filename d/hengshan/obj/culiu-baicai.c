// culiu-baicai.c 醋溜白菜
// Last Modified by Sir on May. 22 2001

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name("醋溜白菜", ({"culiu baicai", "baicai"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一盆红白相间，脆嫩爽口，清香诱人的醋溜白菜。\n");
		set("unit", "盆");
		set("value", 150);
		set("food_remaining", 4);
		set("food_supply", 40);
	}
}
