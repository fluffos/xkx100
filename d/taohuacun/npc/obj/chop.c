
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(YEL"排骨"NOR,({"chop","paigu"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一块新鲜的猪排骨。\n");
                set("unit", "块");
        }
}