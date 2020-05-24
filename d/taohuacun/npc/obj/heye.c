#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "荷叶" NOR,({"heye"}));
	set_weight(10);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一片荷叶。\n");
                set("unit", "片");
        }
}