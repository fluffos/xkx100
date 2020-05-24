#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(YEL "母鸡" NOR,({"hen"}));
	set_weight(200);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一只嫩母鸡。\n");
                set("unit", "只");
        }
}