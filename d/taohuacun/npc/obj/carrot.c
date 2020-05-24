
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(HIR"胡萝卜"NOR,({"carrot","huluobo"}));
	set_weight(300);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一篮胡萝卜。\n");
                set("unit", "篮");
        }
}