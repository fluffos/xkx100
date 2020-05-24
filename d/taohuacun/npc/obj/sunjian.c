#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "笋尖" NOR,({"sunjian"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋笋尖。\n");
                set("unit", "袋");
        }
}