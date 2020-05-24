
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("草鱼",({"caoyu"}));
	set_weight(80);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一尾活蹦乱跳的草鱼。\n");
                set("unit", "尾");
        }
}