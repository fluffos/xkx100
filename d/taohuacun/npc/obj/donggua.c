#include <ansi.h>	
inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("冬瓜",({"donggua"}));
	set_weight(1000);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一篮冬瓜。\n");
                set("unit", "篮");
        }
}