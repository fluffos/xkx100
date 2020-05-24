// hougan.c 猴肝
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("猴肝", ({ "hou gan", "gan" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", "这是一颗紫黑色的猴肝。\n");
		set("value", 1000);
		set("medicine", 1);
	}
	setup();
}
