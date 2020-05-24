// longzao.c

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIR"龙枣"NOR, ({"long zao"}));
	set_weight(700000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个株皇宫中的珍贵树木。\n");
		set("unit", "株");
		set("no_get", 1);
	}
}

