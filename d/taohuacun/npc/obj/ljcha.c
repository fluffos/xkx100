#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "龙井茶" NOR,({"ljcha"}));
	set_weight(50);
	set( "value", 10000 );
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋龙井茶叶。\n");
                set("unit", "袋");
        }
}