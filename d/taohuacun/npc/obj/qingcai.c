#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG "青菜" NOR,({"qingcai"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一筐青菜。\n");
                set("unit", "筐");
        }
}