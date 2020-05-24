#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW "兔肉" NOR, ({"turou"}));
	set_weight(300);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一块鲜血淋漓的野兔肉。\n");
		set("unit", "块");
	}
}
