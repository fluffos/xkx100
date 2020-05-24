#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"樱桃"NOR,({"yingtao"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一袋鲜红的樱桃。\n");
                set("unit", "袋");
        }
}