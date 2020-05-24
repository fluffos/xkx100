
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name(RED "栗子" NOR,({"lizi"}));
	set_weight(100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一篮栗子。\n");
                set("unit", "篮");
        }
}