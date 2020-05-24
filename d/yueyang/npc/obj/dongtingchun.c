// dongtingchun.c 洞庭春茶

#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG"洞庭春茶"NOR, ({"dongtingchun cha", "cha", "tea"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗洞庭春茶，热乎乎地冒着一股茶香味。\n");
		set("unit", "碗");
		set("value", 100);
		set("max_liquid", 15);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "tea",
		"name": "洞庭春茶",
		"remaining"  : 5,
		"drunk_apply": 2,
	]));
}
