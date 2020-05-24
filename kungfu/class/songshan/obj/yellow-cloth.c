
// yellow-cloth.c
// 嵩山赫黄袍

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(YEL"赫黄袍"NOR, ({ "yellow cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("value", 100);
		set("armor_prop/armor", 5);
	}
	setup();
}

